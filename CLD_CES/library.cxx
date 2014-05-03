/*
 * Program:		library.cxx
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	Definitions for the Library class in the CLD-CES framework
 * 
 */
 
#include <unordered_map>
#include <typeinfo>
#include <vector>
#include <iostream>
#include "library.h"
#include "component.h"

using namespace CLD_CES;

//---------------------------------------------------------------------

int Library::createEntity() {
	int e;
	//check if the buffer is empty
	if(entity_buffer.size() == 0) {
		//if the buffer is empty, return the current index and increase it by 1
		e = entity_index;
		entity_index++;
	} else {
		//otherwise get the last element from the buffer
		e = entity_buffer.back();
		entity_buffer.pop_back();
	}
	return e;
}
//---------------------------------------------------------------------

bool Library::destroyEntity(int e) {
	//if the entity e exists, it is erased from lib
	if(lib.count(e) != 0) {
		lib.erase(e);
		entity_buffer.push_back(e);
		return true;
	} else {
		return false;
	}
}

//---------------------------------------------------------------------

bool Library::addComponent(int e, Component * c) {
	if(lib.count(e) != 0) {
		//if e is found, add this new component (key and value) to
		//it's component unordered_map
		lib[e][&typeid(*c)] = c;
		return true;
	} else {
		return false;
	}
}
 
//---------------------------------------------------------------------

template <typename T> bool Library::removeComponent(int e) {
	if(lib.count(e) != 0) {
		//if lib[e] contains a key of type T, remove the entry
		if(lib[e].count(&typeid(T)) != 0) {
			lib[e].erase(&typeid(T));
		} else {
			return false;
		}
	} else {
		return false;
	}
}
 
//---------------------------------------------------------------------

template <typename T> T* Library::getComponent(int e) {
	if(lib.count(e) != 0) {
		if(lib[e].count(&typeid(T)) != 0) {
			return static_cast<T*>(lib[e][&typeid(T)]);
		} else {
			return nullptr;
		}
	} else {
		return nullptr;
	}
}
 
//---------------------------------------------------------------------

template <typename T> std::vector<int> Library::getEntitiesWithComponent() {
	//this might be a bit computationally expensive
	
	std::vector<int> entities;
	
	//iterate through lib
	for(auto i = lib.begin(); i != lib.end(); ++i) {
		//if i->second (the components unordered_map) contains a key of 
		//type T, add i->first (the entity ID/key) to the entities vector
		if(i->second.count(&typeid(T)) != 0) {
			entities.push_back(i->first);
		}
	}
	
	return entities;
}

 
