/*
 * Program:		library.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header file for the Library class in the CLD_CES framework - template function
 * 			definitions included below
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

//---------------------------------------------------------------------------------------

/*
 * Function:		removeComponent()
 * Description:		Removes an existing Component from an existing Entity.
 * Arguments:
 * 	typename T:	Component type to be removed
 * 	int e:		Entity ID containing Component of type T
 * Returns:
 * 	bool:		True if successful; False if no such Component/Entity
 */

template <typename T> bool Library::removeComponent(int e) {
	//check to see if Entity e exists
	if(entities.count(e) != 0) {
		//check for the Component
		if(entities[e].count(&typeid(T)) != 0) {
			//it exists, so remove the Component
			entities[e].erase(&typeid(T));
			return true;
		} else {
			//the Component was not found
			return false;
		}
	} else {
		//ERROR: e is not a valid Entity ID
		return false;
	}
}

//---------------------------------------------------------------------------------------

/*
 * Function:		getComponent()
 * Description:		Provides a pointer to a particular Component in a particular Entity
 * Arguments:
 * 	typename T:	Component type to find
 * 	int e:		ID of Entity to search
 * Returns:
 * 	T*:		Pointer to Component
 */

template <typename T> T* Library::getComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			//return a pointer to the Component
			return static_cast<T*>(entities[e][&typeid(T)]);
		} else {
			//ERROR: no such Component exists in Entity e
			return nullptr;
		}
	} else {
		//ERROR: no such Entity exists
		return nullptr;
	}
}

//---------------------------------------------------------------------------------------

/*
 * Function:		hasComponent()
 * Description:		Determines if an Entity contains a Component of type T
 * Arguments:
 * 	typename T:	Component type to find
 * 	int e:		ID of Entity to search
 * Returns:
 * 	bool:		True if Component is found
 */

template <typename T> bool Library::hasComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			return true;
		}
	}

	return false;
}

#endif
