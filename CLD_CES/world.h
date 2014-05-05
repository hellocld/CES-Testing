/*
 * Program:		world.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the World class in the CLD_CES framework
 * 
 * 			The World is an all-encompassing object that holds a library and it's associated set of Systems
 *
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "library.h"
#include "system.h"

namespace CLD_CES {
	class World {
		public:
			//creating the world will generate a library and a vector for systems
			World() {};
			virtual ~World() = default;

			//add or remove a System to the world
			void addSystem(System s);
			template <typename T> void removeSystem();

			//run init() or update() on all Systems
			void systemsInit();
			void systemsUpdate();

		private:
			//Library to store all Entities and Components in this World
			Library library;

			//vector to store all Systems
			std::vector<System> systems;
	};
}

#endif

