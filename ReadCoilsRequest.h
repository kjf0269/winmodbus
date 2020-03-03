#pragma once
#include "ModbusRequest.h"
class ReadCoilsRequest :
	public ModbusRequest
{
public:
	ReadCoilsRequest();

	int setStartAddress(uint16_t startAddress);
	int setQuantity(uint16_t quantity);

protected:

	struct ReadCoilsRequest_t {
		uint16_t startAddress;
		uint16_t quantity;
	};
	
	// note this will be stored in network byte order
	struct ReadCoilsRequest_t request;
};

