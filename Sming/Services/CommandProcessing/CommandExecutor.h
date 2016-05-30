/*
 * CommandExecutor.h
 *
 *  Created on: 2 jul. 2015
 *      Author: Herman
 */

#ifndef SERVICES_COMMANDPROCESSING_COMMANDEXECUTOR_H_
#define SERVICES_COMMANDPROCESSING_COMMANDEXECUTOR_H_

#include "WiringFrameworkIncludes.h"
#include "Network/TcpClient.h"
#include "CommandHandler.h"
#include "CommandOutput.h"

class CommandExecutor
{
public:
	CommandExecutor(TcpClient* cmdClient);
	CommandExecutor(Stream* reqStream);
	CommandExecutor(WebSocket* reqSocket);
	~CommandExecutor();

	int executorReceive(char *recvData, int recvSize);
	int executorReceive(char recvChar);
	int executorReceive(String recvString);
	void setCommandPrompt(String reqPrompt);
	void setCommandEOL(char reqEOL);

private :
	CommandExecutor();
	void processCommandLine(String cmdString);
	String commandBuf;
	CommandOutput* commandOutput;
};

#endif /* SERVICES_COMMANDPROCESSING_COMMANDEXECUTOR_H_ */
