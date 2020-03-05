#pragma once

#include "MBAPHeader.h"
#include "ModbusPDU.h"

class ModbusTcpIpAdu
{
public:
	ModbusTcpIpAdu();
	void setHdr(MBAPHeader* hdr);
	void setPdu(ModbusPDU* pdu);

	int getAdu(uint8_t* buffer, int bufferlength);

protected:
	MBAPHeader *hdr;
	ModbusPDU *pdu;

};

