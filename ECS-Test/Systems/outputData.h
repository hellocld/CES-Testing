/*
 * Program:		outputData.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for the OutputData System class
 */

#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H

#include "../CLD_CES/system.h"

namespace ECS_Test {
	class OutputData : public CLD_CES::System {
		void update();
	};
}

#endif
