/*
 * Program:		incrementValue.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for the IncrementValue class
 */

#ifndef ECS_TEST_SYSTEM_INCREMENTVALUE_H
#define ECS_TEST_SYSTEM_INCREMENTVALUE_H

#include "../../system.h"

namespace ECS_Test {
	class IncrementValue : public CLD_ECS::System {
		public:
			void Init();
			void Update();
			void Shutdown();
	};
}

#endif
