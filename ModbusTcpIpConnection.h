#pragma once
#include "ModbusTcpIpAduFactory.h"
#include <cstdint>

#define RECVBUFLEN 2048

class ModbusTcpIpConnection
{
public:
	// TODO: needs addressing information as well as an option for AduFactory override.
	ModbusTcpIpConnection();
	void setModbusTcpIpAduFactory(ModbusTcpIpAduFactory* newFactory);

	void sendAdu(ModbusTcpIpAdu* adu);
	void receiveMessage();

protected:
	ModbusTcpIpAduFactory* factory;
	
	int clientSocket;
	uint8_t recvbuf[RECVBUFLEN];
};

