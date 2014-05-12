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
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//we only want one of each System in the systems vector
	for(i = systems.begin(); i < systems.end(); ++i) {
		if(&typeid(*(*i)) == &typeid(*s)) {
			//the System already exists in systems, so we quit
			return;
		} else {
			systems.push_back(s);
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
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i)
		(*i)->init(library);
}

//------------------------------------------------------------------------------

/*
 * Function:		systemsUpdate()
 * Description:		Runs the update() function on each System in systems
 * Arguments:		none
 * Returns:		none
 */

void World::systemsUpdate() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i)
		(*i)->update();
}
