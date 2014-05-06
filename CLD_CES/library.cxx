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
 * Description:		Makes a new entry in the Entities unordered_map, allowing for the
 * 			addition of Components to said Entity. Increases entity_index by
 * 			one if entity_buffer is empty; otherwise uses last entry in
 * 			entity_buffer.
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
}

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

}

//---------------------------------------------------------------------------------------

/*
 * Function:		getAllEntitiesWithComponent()
 * Description:		Returns a vector of all Entities (by ID) containing a Component of
 * 			type T.
 * Arguments:
 * 	typename T:	Component type to find
 * Returns:
 * 	vector<int>:	A vector of Entity IDs
 */

template <typename T> std::vector<int> Library::getAllEntitiesWithComponent() {

}
