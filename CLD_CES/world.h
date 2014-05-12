/*
 * Program:		world.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the World class in the CLD_CES framework
 * 			Template function definitions included below
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
			void addSystem(System* s);
			template <typename T> void removeSystem();

			//run init() or update() on all Systems
			void systemsInit();
			void systemsUpdate();

		private:
			//Library to store all Entities and Components in this World
			Library library;

			//vector to store all Systems
			std::vector<System*> systems;
	};
}


//------------------------------------------------------------------------------

/*
 * Function:		removeSystem()
 * Description:		Removes a System from systems
 * Arguments:
 * 	typename T:	The type of the System you want to remove
 * Returns:		none
 */

template <typename T> void World::removeSystem() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i){
		if(&typeid(*(*i)) == &typeid(T)) {
			//the System was found; erase it and return
			systems.erase(i);
			return;
		}
	}
}

#endif

