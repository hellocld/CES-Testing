/*
 * Program:		incrementValue.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		IncrementValue System class definitions
 */

#include <vector>

#include "incrementValue.h"
#include "../Components/value.h"

void ECS_Test::IncrementValue::update() {
	//iterate through all the Entities in the Library
	//if an Entity has a component of type Value, add 1 to the value
	std::vector<int> entities = lib->allEntityIDs();

	std::vector<int>::iterator i;

	for(i = entities.begin(); i<entities.end(); ++i) {
		if(lib->hasComponent<ECS_Test::Value>(*i)) {
			lib->getComponent<ECS_Test::Value>(*i)->value++;
		}
	}
}
