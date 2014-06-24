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
			virtual ~System() {
				lib = nullptr;
			};

			//init(), update() and shutdown() are all called by their World container via systemsInit(), systemsUpdate() and systemsShutdown()
			virtual void init() = 0;
			virtual void update() = 0;
			virtual void shutdown() = 0;

			//functions to link the System to a Library
			void linkLibrary(Library& l);



		protected:
			//reference to the Library in the World containing this system
			Library* library;
	};
}

#endif
