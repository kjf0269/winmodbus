#pragma once
#include "ModbusTcpIpAdu.h"
#include "ReadCoilsResponse.h"
#include "modbus.h"
#include <cstdint>

class ModbusTcpIpAduFactory
{
public:
	
	ModbusTcpIpAdu* buildAdu(uint8_t* buff, unsigned int length);

protected:
	


};

