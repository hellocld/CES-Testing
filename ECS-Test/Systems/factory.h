/*
 * Program:		factory.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for factory.cxx, the Factory System in ECS-Test
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "../CLD_CES/system.h"

namespace ECS_Test {
	class Factory : public CLD_CES::System {
		public:
			void init(Library l);
	};
}

#endif

