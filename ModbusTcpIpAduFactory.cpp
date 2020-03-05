#include "ModbusTcpIpAduFactory.h"

ModbusTcpIpAdu* ModbusTcpIpAduFactory::buildAdu(uint8_t* buff, unsigned int length)
{
	ModbusTcpIpAdu *adu = new ModbusTcpIpAdu();
	MBAPHeader* hdr = new MBAPHeader(buff);
	ModbusPDU* pdu = nullptr;

	// function code of the PDU is the first octet after the MBAP header. 
	uint8_t* pduStart = buff + MBAPHEADER_SIZE;
	uint8_t functionCode = *pduStart;
	switch (functionCode) {
	case READ_COILS_FC:
		pdu = new ReadCoilsResponse(pduStart, hdr->getLength());
		break;
	default:
		;
	}

	adu->setHdr(hdr);
	adu->setPdu(pdu);
	return adu;
}
