/*
 * Program:		library.cxx
 * Author:		Chris Langford
 * Date:		2014/05/06
 * Description:		Definitions for the member functions of the Library class in the CLD_ECS framework
 *
 */

#include <typeinfo>
#include <unordered_map>
#include <vector>
#include <iostream>

#include "library.h"
#include "component.h"

using namespace CLD_ECS;

//---------------------------------------------------------------------------------------

/*
 * Function:		~Library()
 * Description:		Deletes all pointers and values in the Library
 * Arguments:		none
 * Returns:		none
 */

Library::~Library() {
	//we need to loop through everything in entities to remove EVERYTHING allocated in memory, so we'll need a couple iterators
	for(auto id = entities.begin(); id != entities.end(); ++id) {
		//now loop through each component
		for(auto c = id->second.begin(); c != id->second.end(); ++c) {
			//delete away!
			delete c->second;
		}
	}
}
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
	//create a new entry in entities
	entities[e][&typeid(BasicComp)] = new BasicComp();
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
		//loop through all it's components and delete them
		for(auto c = entities[e].begin(); c != entities[e].end(); ++c) {
			delete c->second;
		}
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
			return true;
		}
	} else {
		//ERROR: e is not a valid Entity ID
		return false;
	}
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
