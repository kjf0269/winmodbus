#include "ModbusTcpIpAdu.h"

ModbusTcpIpAdu::ModbusTcpIpAdu()
{
}

void ModbusTcpIpAdu::setHdr(MBAPHeader* hdr)
{
	this->hdr = hdr;
}

void ModbusTcpIpAdu::setPdu(ModbusPDU* pdu)
{
	this->pdu = pdu;
}

int ModbusTcpIpAdu::getAdu(uint8_t* buffer, int bufferlength)
{
	// write out the full adu to the buffer.

	return 0;
}
