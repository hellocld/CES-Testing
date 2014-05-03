/*
 * Program:		world.cxx
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	The World is an all-encompassing object that holds a vector
 * 				of Systems and a Library the Systems can reference.
 * 
 */

#include "world.h"
#include "system.h"
#include "library.h"

using namespace CLD_CES;

void World::init() {
	for(int i = 0; i < systems.size(); ++i) {
		systems[i].init();
	}
}

void World::update() {
	for(int i = 0; i < systems.size(); ++i) {
		systems[i].update();
	}
}

bool World::addSystem(System s) {
	if(systems.count(&typeid(*s)) == 0) {
		systems[&typeid(*s)] = s;
		return true;
	} else {
		return false;
	}
}

template <typename T> bool World::removeSystem() {
	if(systems.count(&typeid(T)) != 0) {
		systems.erase(&typeid(T));
		return true;
	} else {
		return false;
	}
}
