#include "ReadCoilsResponse.h"
#include <vcruntime_string.h>

ReadCoilsResponse::ReadCoilsResponse(uint8_t* message, int length) : ModbusPDU(message[0])
{
	// The +1 factor comes from the fact that the ModbusPDU length will include the functionCode
	// the -1 removes added byte
	int copyLength = length < sizeof(ReadCoilsResponseData) + 1 ? length - 1 : sizeof(ReadCoilsResponseData);
	memcpy(&response, &message[1], copyLength);
}

void ReadCoilsResponse::setBaseAddress(uint16_t address)
{
	baseAddress = address;
}

bool ReadCoilsResponse::getCoilStatus(uint16_t address)
{
	// TODO: need an error handling strategy out of range requests. For now out of range requests will return false.
	bool result = false;
	
	unsigned int byteNum = (address - baseAddress)/ 8;
	unsigned int bitNum = (address - baseAddress) % 8;

	if ((byteNum < response.byteCount) && (address >= baseAddress)) {
		result = response.coilStatus[byteNum] >> bitNum & 0x01;
	}
	return result;
}
