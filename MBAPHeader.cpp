#pragma comment(lib, "ws2_32.lib")

#include "MBAPHeader.h"
#include <wchar.h>
#include <winsock.h>

MBAPHeader::MBAPHeader(uint16_t transId, uint16_t length, uint8_t unitId, uint16_t protoId) : transactionId(transId), length(length), unitId(unitId), protocolId(protoId)
{
}

unsigned int MBAPHeader::getMBAPHeaderLength()
{
	return sizeof(transactionId) + sizeof(length) + sizeof(unitId) + sizeof(protocolId);
}

int MBAPHeader::copyHeader(uint8_t* dest)
{
	uint16_t nTransactionId = htons(transactionId);
	memcpy((void*)&dest[0], (void*)&nTransactionId, sizeof(nTransactionId));

	uint16_t nProtocolId = htons(protocolId);
	memcpy((void*)& dest[2], (void*)&nProtocolId, sizeof(nProtocolId));

	uint16_t nLength = htons(length);
	memcpy((void*)&dest[4], (void*)&nLength, sizeof(nLength));

	dest[6] = unitId;

	return 0;
}
