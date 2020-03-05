#include "ReadCoilsResponse.h"
#include <vcruntime_string.h>

ReadCoilsResponse::ReadCoilsResponse(uint8_t* message, int length) : ModbusPDU(message[0])
{
	// The +1 factor comes from the fact that the ModbusPDU length will include the functionCode
	// the -1 removes added byte
	int copyLength = length < sizeof(ReadCoilsResponseData) + 1 ? length - 1 : sizeof(ReadCoilsResponseData);
	memcpy(&response, &message[1], copyLength);
}
