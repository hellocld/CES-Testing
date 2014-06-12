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

#include "library.h"
#include "system.h"

namespace CLD_ECS {
	class World {
		public:
			//creating the world will generate a library and a vector for systems
			World() {std::cerr<<"New World Created\n";};
			virtual ~World();

			//add or remove a System to the world
			void addSystem(System* s);
			template <typename T> void removeSystem();
			
			//wrapper functions that give World access to it's Library
			int createEntity(){ return library.createEntity(); };
			bool destroyEntity(int e){ return library.destroyEntity(e); };
			bool addComponent(int e, Component* c){ return library.addComponent(e, c); };
			template <typename T> T* removeComponent(int e){ return library.removeComponent<T>(e); };
			template <typename T> T* getComponent(int e){ return library.getComponent<T>(e); };
			template <typename T> bool hasComponent(int e){ return library.hasComponent<T>(e); };
			std::vector<int> allEntityIDs(){return library.allEntityIDs(); };

			//run init(), update() or shutdown() on all Systems
			void systemsInit();
			void systemsUpdate();
			void systemsShutdown();

		private:
			//Library to store all Entities and Components in this World
			Library library;

			//vector to store all Systems
			std::vector<System*> systems;
	};

	//include definitions for the template functions
	#include "world.txx"
}

#endif

