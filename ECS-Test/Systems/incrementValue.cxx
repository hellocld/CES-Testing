/*
 * Program:		incrementValue.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		IncrementValue System class definitions
 */

#include <vector>

#include "incrementValue.h"
#include "../Components/value.h"

void ECS_Test::IncrementValue::Init() {}

void ECS_Test::IncrementValue::Update() {
	//iterate through all the Entities in the Library
	//if an Entity has a component of type Value, add 1 to the value
	std::vector<int> entities = library->GetEntityIDs();

	std::vector<int>::iterator i;

	for(i = entities.begin(); i<entities.end(); ++i) {
		if(library->HasComponent<ECS_Test::Value>(*i)) {
			library->GetComponent<ECS_Test::Value>(*i)->value++;
		}
	}
}

void ECS_Test::IncrementValue::Shutdown(){}
