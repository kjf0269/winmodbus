#pragma once
#include <cstdint>

#define MBAPHEADER_SIZE 7

class MBAPHeader
{
public:
	MBAPHeader(uint16_t transId, uint16_t length, uint8_t unitId, uint16_t protoId = 0);
	MBAPHeader(uint8_t *msg);

	unsigned int getMBAPHeaderLength();
	int copyHeader(uint8_t* dest);

	uint16_t getTransactionId();
	uint16_t getProtocolId();
	uint16_t getLength();
	uint8_t getUnitId();

protected:
	uint16_t transactionId;
	uint16_t protocolId;
	uint16_t length;
	uint8_t unitId;
};

