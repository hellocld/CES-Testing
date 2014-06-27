/*
 * Program:		factory.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Header for factory.cxx, the Factory System in ECS-Test
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "../../system.h"

namespace ECS_Test {
	class Factory : public CLD_ECS::System {
		public:
			void init();
			void update();
			void shutdown();
	};
}

#endif

