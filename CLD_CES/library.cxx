/*
 * Program:		library.cxx
 * Author:		Chris Langford
 * Date:		2014/05/06
 * Description:		Definitions for the member functions of the Library class in the CLD_CES framework
 *
 */

#include <typeinfo>
#include <unordered_map>
#include <vector>

#include "library.h"
#include "component.h"

using namespace CLD_CES;

//---------------------------------------------------------------------------------------

/*
 * Function:		createEntity()
 * Description:		Creates a new Entity ID, or recycles an unused one
 * Arguments:		none
 * Returns:		
 * 	int:		New/recycled Entity ID
 */

int Library::createEntity() {
	//temporary storage for the Entity ID
	int e;

	if(entity_buffer.size() == 0) {
		//double-check to make sure entity_index isn't already in use as an ID
		while(entities.count(entity_index) != 0) {
			//if it is, just increase by one and check again
			entity_index++;
		}
		e = entity_index;
		entity_index++;
	} else {
		//since there's something in the buffer, remove the last entry from 
		//entity_buffer and return it
		e = entity_buffer.back();
		entity_buffer.pop_back();
	}
	return e;
};

//---------------------------------------------------------------------------------------

/*
 * Function:		destroyEntity()
 * Description:		Removes an Entity from the Entities unordered_map and pushes the ID into the entity_buffer
 * Arguments:
 * 	int e:		ID of Entity to remove
 * Returns:
 * 	bool:		True if successful
 */

bool Library::destroyEntity(int e) {
	//look in entities to see if there's a key that matches e
	if(entities.count(e) != 0) {
		//destroy the key and associated value
		entities.erase(e);
		//since e is now an unused ID, push it back into entity_buffer for reuse
		entity_buffer.push_back(e);

		return true;
	} else {
		//e was not a valid ID
		return false;
	}
}

//---------------------------------------------------------------------------------------

/*
 * Function:		addComponent()
 * Description:		Adds a Component to an existing Entity
 * Arguments:
 * 	int e:		ID of Entity
 * 	Component* c:	Component being added to Entity e
 * Returns:
 * 	bool:		True if successful
 */

bool Library::addComponent(int e, Component* c) {
	//check if e is a valid Entity ID
	if(entities.count(e) != 0) {
		//make sure the Entity doesn't already contain a Component of c's type
		if(entities[e].count(&typeid(*c)) != 0) {
			//ERROR: Entity e has a Component of c's type already
			return false;
		} else {
			//add the Component with it's typeid as the key
			entities[e][&typeid(*c)] = c;
		}
	} else {
		//ERROR: e is not a valid Entity ID
		return false;
	}
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

//---------------------------------------------------------------------------------------

/*
 * Function:		allEntityIDs()
 * Description:		Returns a list (vector) of all Entity IDs in the Library
 * Arguments:		none
 * Returns:
 * 	vector<int>:	A list of all Entity IDs in the Library
 */

std::vector<int> Library::allEntityIDs() {
	//an empty vector to fill with Entity IDs
	std::vector<int> id;

	//iterate through the keys in entities, pushing each one into id
	for(auto i = entities.begin(); i != entities.end(); ++i) {
		id.push_back(i->first);
	}

	return id;
}
