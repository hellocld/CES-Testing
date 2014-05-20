/*
 * Program:		system.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the System class, part of the CLD_ECS framework
 *
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>

#include "library.h"

namespace CLD_ECS {
	class System {
		public:
			System() {std::cerr<<"New System Created\n";};
			~System() = default;
			//upon initialization ALL Systems must be told what Library they are working with
			virtual void init(Library* l);
			virtual void update() = 0;

		protected:
			//reference to the Library in the World containing this system
			Library* lib;
	};
}

#endif