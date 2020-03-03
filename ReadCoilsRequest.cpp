#include "ReadCoilsRequest.h"
#include "modbus.h"
#include <vcruntime_string.h>
#include <winsock.h>

ReadCoilsRequest::ReadCoilsRequest(): ModbusRequest(READ_COILS_FC)
{
	dataBuffer = (uint8_t*)&request;
	memset(&request, 0, sizeof(request));
	length = sizeof(functionCode) + sizeof(request);
}

int ReadCoilsRequest::setStartAddress(uint16_t startAddress)
{
	request.startAddress = htons(startAddress);
	return 0;
}

int ReadCoilsRequest::setQuantity(uint16_t quantity)
{
	int retval = -1;
	if ((quantity >= 1) & (quantity <= 2000)) {
		retval = 0;
		request.quantity = htons(quantity);
	}
	return retval;
}
