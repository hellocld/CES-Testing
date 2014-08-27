/*
 * Program:		outputData.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for the OutputData System class
 */

#ifndef ECS_TEST_SYSTEM_OUTPUTDATA_H
#define ECS_TEST_SYSTEM_OUTPUTDATA_H

#include "../../system.h"

namespace ECS_Test {
	class OutputData : public CLD_ECS::System {
		public:
			void Init();
			void Update();
			void Shutdown();
	};
}

#endif
