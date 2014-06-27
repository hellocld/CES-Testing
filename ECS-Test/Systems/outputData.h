/*
 * Program:		outputData.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for the OutputData System class
 */

#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H

#include "../../system.h"

namespace ECS_Test {
	class OutputData : public CLD_ECS::System {
		public:
			void init();
			void update();
			void shutdown();
	};
}

#endif
