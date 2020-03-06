#pragma once
#include <cstdint>
class ModbusPDU
{
public:
	ModbusPDU(uint8_t functionCode);
	unsigned int getMessage(uint8_t* dst);
	virtual ~ModbusPDU() {}

protected:
	uint8_t functionCode;
	uint8_t *dataBuffer; // must be initialized by the subclass to point to the functioncode specific data storage
	unsigned int length; // must be initialized by the subclass
};

