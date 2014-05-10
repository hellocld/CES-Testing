/*
 * Program:		library.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header file for the Library class in the CLD_CES framework
 *
 */


#ifndef LIBRARY_H
#define LIBRARY_H

#include <typeinfo>
#include <unordered_map>
#include <vector>

#include "component.h"

namespace CLD_CES {
	class Library {
		public:
			Library() {};
			~Library() = default;
			//create new entities in the Entity unordered_map
			int createEntity();
			bool destroyEntity(int e);
			
			//add or remove components from entities
			bool addComponent(int e, Component* c);
			template <typename T> bool removeComponent(int e);

			//get a component from an entity
			template <typename T> T* getComponent(int e);

			//returns true if entity contains component type T (useful for checking if an entity contains a set of components)
			template <typename T> bool hasComponent(int e);

			//provide a vector of all Entity IDs currently in use (the keys of entities)
			std::vector<int> allEntityIDs();

		private:
			//an unordered map that stores all entities
			//the Value stores an additional unordered map that contains the components of a particular entity
			std::unordered_map<int, std::unordered_map<const std::type_info *, Component *>> entities;
			
			//an entity count index and a simple buffer to place destroyed entity keys in
			int entity_index = 0;
			std::vector<int> entity_buffer;
	};
}

#endif
