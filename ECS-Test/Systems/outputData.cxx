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

void ECS_Test::OutputData::Init() {}

void ECS_Test::OutputData::Update() {
	//create a vector of all entities in the Library
	std::vector<int> entities = library->GetEntityIDs();

	//an iterator to search through entities
	std::vector<int>::iterator i;

	for(i = entities.begin(); i < entities.end(); ++i) {
		std::cerr<<"Checking Entity "<<*i<<"...\n";
		if(library->HasComponent<ECS_Test::Name>(*i) && library->HasComponent<ECS_Test::Value>(*i)) {
			//if the Entity has both Components, output their info
			std::cout<<"Name: "<<library->GetComponent<ECS_Test::Name>(*i)->name<<"\t Value: "<<library->GetComponent<ECS_Test::Value>(*i)->value<<std::endl;
		}
	}
	//just a line to break the multiple outputs of the system
	std::cout<<"ECS_Test::OutputData::update() complete------------------------------------------\n";
}

void ECS_Test::OutputData::Shutdown() {}
