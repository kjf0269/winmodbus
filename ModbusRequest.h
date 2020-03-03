#pragma once
#include <cstdint>
class ModbusRequest
{
public:
	ModbusRequest(uint8_t functionCode);
	unsigned int getMessage(uint8_t* dst);

protected:
	uint8_t functionCode;
	uint8_t *dataBuffer; // must be initialized by the subclass to point to the functioncode specific data storage
	unsigned int length; // must be initialized by the subclass
};

