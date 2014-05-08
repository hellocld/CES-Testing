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

using namespace CLD_CES;

//------------------------------------------------------------------------------

/*
 * Function:		addSystem()
 * Description:		Adds a new System to the systems vector
 * Arguments:
 * 	System* s:	A new System
 * Returns:		none
 */

void World::addSystem(System* s) {
	//we only want one of each System in the systems vector
	for(int i = 0; i < systems.size(); ++i) {
		if(&typeid(*systems[i]) == &typeid(*s)) {
			//the System already exists in systems, so we quit
			return;
		} else {
			systems.push_back(s);
		}
	}
}

//------------------------------------------------------------------------------

/*
 * Function:		removeSystem()
 * Description:		Removes a System from systems
 * Arguments:
 * 	typename T:	The type of the System you want to remove
 * Returns:		none
 */

template <typename T> void World::removeSystem() {
	//loop through systems, checking for a System of type T
	for(int i = 0; i < systems.size(); ++i) {
		if(&typeid(*systems[i]) == &typeid(T)) {
			//the System was found; erase it and return
			systems.erase(i);
			return;
		}
	}
}

//------------------------------------------------------------------------------

/*
 * Function:		systemsInit()
 * Description:		Runs the init() function on each System in systems
 * Arguments:		none
 * Returns:		none
 */

void World::systemsInit() {
	for(int i = 0; i < systems.size(); ++i) 
		systems[i].init();
}

//------------------------------------------------------------------------------

/*
 * Function:		systemsUpdate()
 * Description:		Runs the update() function on each System in systems
 * Arguments:		none
 * Returns:		none
 */

void World::systemsUpdate() {
	for(int i = 0; i < systems.size(); ++i)
		systems[i].update();
}
