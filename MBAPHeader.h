#pragma once
#include <cstdint>
class MBAPHeader
{
public:
	MBAPHeader(uint16_t transId, uint16_t length, uint8_t unitId, uint16_t protoId = 0);

	unsigned int getMBAPHeaderLength();
	int copyHeader(uint8_t* dest);

protected:
	uint16_t transactionId;
	uint16_t protocolId;
	uint16_t length;
	uint8_t unitId;
};

