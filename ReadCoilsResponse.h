#pragma once
#include "ModbusPDU.h"

#define MAX_COIL_RESPONSE_BYTES 250

class ReadCoilsResponse :
	public ModbusPDU
{
public:
	ReadCoilsResponse(uint8_t* message, int length);

protected:
	

	struct ReadCoilsResponseData {
		uint8_t byteCount;
		uint8_t coilStatus[MAX_COIL_RESPONSE_BYTES];
	};

	struct ReadCoilsResponseData response;
};

