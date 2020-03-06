#pragma once
#include "ModbusPDU.h"

#define MAX_COIL_RESPONSE_BYTES 250

class ReadCoilsResponse :
	public ModbusPDU
{
public:
	ReadCoilsResponse(uint8_t* message, int length);
	virtual ~ReadCoilsResponse() {}
	void setBaseAddress(uint16_t address);
	bool getCoilStatus(uint16_t address);

protected:

	uint16_t baseAddress = 0; // initially set to zero, may be overridden by object user 

	// Since the response does echo back the starting address from the request it is necessary to match 
	// the coil response data with the corresponding coil request in order to make sense of the result.
	struct ReadCoilsResponseData {
		uint8_t byteCount;
		uint8_t coilStatus[MAX_COIL_RESPONSE_BYTES];
	};

	struct ReadCoilsResponseData response;
};

