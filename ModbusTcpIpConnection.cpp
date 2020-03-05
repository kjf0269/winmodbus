#include "ModbusTcpIpConnection.h"
#include <winsock.h>

ModbusTcpIpConnection::ModbusTcpIpConnection()
{
	factory = new ModbusTcpIpAduFactory();

	// need to client socket and establish connection to server. Connection paramters to be
	// provided in constructor.
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// error handling

	// connect call 
}

void ModbusTcpIpConnection::setModbusTcpIpAduFactory(ModbusTcpIpAduFactory* newFactory)
{
	delete factory;
	factory = newFactory;
}

void ModbusTcpIpConnection::sendAdu(ModbusTcpIpAdu* adu)
{
}

void ModbusTcpIpConnection::receiveMessage()
{
	int result = recv(clientSocket, (char *)recvbuf, RECVBUFLEN, 0);
	// add error checking plus all the fun for dealing with TCP messages longer than the
	// default length.

	ModbusTcpIpAdu *adu = factory->buildAdu(recvbuf, result);

	// send ADU to client
}
