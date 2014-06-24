/*
 * Program:		factory.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Factory System for ECS-Test. Creates a bunch of Entities with Name and Value components
 */

#include <vector>
#include <string>

#include "factory.h"

//the new Components used by the System
#include "../Components/name.h"
#include "../Components/value.h"

//the total number of entities init() creates
const int totalEntities = 5;

void ECS_Test::Factory::init() {


	//create some entities!
	std::vector<int> entities;
	for(int i = 0; i < totalEntities; ++i) {
		//create an entity and push it back into the entities vector
		entities.push_back(library->createEntity());
		//give the entity a Name and Value component
		library->addComponent(entities[i], new ECS_Test::Name("entity " + std::to_string(i)));
		library->addComponent(entities[i], new ECS_Test::Value(i*10));
	}
}

void ECS_Test::Factory::update() {
	//don't do anything :)
}

void ECS_Test::Factory::shutdown() {
	//nada
}
