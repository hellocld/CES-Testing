/*
 * Program:		outputData.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Definitions for the OutputData System class. OutputData pulls info from all Entities with a Name and Value Component and displays it in a terminal
 */

#include <iostream>
#include <vector>

#include "outputData.h"

#include "../Components/name.h"
#include "../Components/value.h"

void ECS_Test::OutputData::update() {
	//create a vector of all entities in the Library
	std::vector<int> entities = lib->allEntityIDs();

	//an iterator to search through entities
	std::vector<int>::iterator i;

	for(i = entities.begin(); i < entities.end(); ++i) {
		if(lib->hasComponent<ECS_Test::Name>(*i) && lib->hasComponent<ECS_Test::Value>(*i)) {
			//if the Entity has both Components, output their info
			std::cout<<"Name: "<<lib->getComponent<ECS_Test::Name>(*i)->name<<"\t Value: "<<lib->getComponent<ECS_Test::Value>(*i)->value<<std::endl;
		}
	}
	//just a line to break the multiple outputs of the system
	std::cout<<"--------------------------------------------------------------------------\n";
}
