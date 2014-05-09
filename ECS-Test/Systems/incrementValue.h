/*
 * Program:		incrementValue.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for the IncrementValue class
 */

#ifndef INCREMENTVALUE_H
#define INCREMENTVALUE_H

#include "../../CLD_CES/system.h"

namespace ECS_Test {
	class IncrementValue : public CLD_CES::System {
		public:
			void update();
	};
}

#endif
