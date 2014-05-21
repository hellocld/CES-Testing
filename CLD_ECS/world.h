/*
 * Program:		world.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the World class in the CLD_ECS framework
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <iostream>
#include <memory>

#include "library.h"
#include "system.h"

namespace CLD_ECS {
	class World {
		public:
			//creating the world will generate a library and a vector for systems
			World() {std::cerr<<"New World Created\n";};
			virtual ~World() = default;

			//add or remove a System to the world
			void addSystem(System* s);
			template <typename T> void removeSystem();

			//run init() or update() on all Systems
			void systemsInit();
			void systemsUpdate();

		private:
			//Library to store all Entities and Components in this World
			Library library;

			//vector to store all Systems
			std::vector<std::unique_ptr<System>> systems;
	};

	//include definitions for the template functions
	#include "world.txx"
}

#endif

