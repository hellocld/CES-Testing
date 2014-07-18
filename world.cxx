/*
 * Program:		world.cxx
 * Author:		Chris Langford
 * Date:		2014/05/07
 * Description:		The World class is a container for a Library and all Systems that interact with it
 */

#include <vector>
#include <typeinfo>

#include "world.h"
#include "library.h"
#include "system.h"

using namespace CLD_ECS;

//------------------------------------------------------------------------------

World::~World() {
	//just need to iterate through systems and remove everything
	for(auto s = systems.begin(); s != systems.end(); ++s) {
		delete *s;
	}
}

//------------------------------------------------------------------------------

bool World::AddSystem(System* s) {
	//if systems isn't empty, we need to check it for possibly duplicate entries before adding a new System
	if(systems.size() != 0) {
		//a simple iterator for looping through systems
		std::vector<System*>::iterator i;
		//if a single System of s's type is found, return from the function without adding anything
		for(i = systems.begin(); i < systems.end(); ++i) {
			if(&typeid(*(*i)) == &typeid(*s)) {
				//the System already exists in systems, so we quit
				return false;
			}
		}
	}
	//if systems is empty or has no Systems of s's type, attach the library and add the new System
	s->LinkLibrary(library);
	systems.push_back(s);
	return true;
}

//------------------------------------------------------------------------------

void World::SystemsInit() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i) {
		(*i)->Init();
	}
}

//------------------------------------------------------------------------------

void World::SystemsUpdate() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i){
		(*i)->Update();
	}
}

//------------------------------------------------------------------------------

void World::SystemsShutdown() {
	//a simple iterator for looping through systems
	std::vector<System*>::reverse_iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.rbegin(); i < systems.rend(); ++i){
		(*i)->Shutdown();
	}
}
