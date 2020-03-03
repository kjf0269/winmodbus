#include "ModbusPDU.h"
#include <vcruntime_string.h>

ModbusPDU::ModbusPDU(uint8_t functionCode) : functionCode(functionCode), length(0), dataBuffer(NULL)
{
}

unsigned int ModbusPDU::getMessage(uint8_t* dst)
{
	// Notes to reviewers: I used the array indices instead of straight pointers
	// for extra clarity of intention, over the objections of the little voice in my head 
	// saying to code it as *dst and dst+1
	dst[0] = functionCode;
	memcpy(&dst[1], dataBuffer, length);
	return length;
}
