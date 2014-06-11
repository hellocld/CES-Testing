/*
 * Program:		system.cxx
 * Author:		Chris Langford
 * Date:		2014/05/07
 * Description:		The System class is used to manipulate the data stored in Components in various ways
 */

#include "system.h"
#include "library.h"

using namespace CLD_ECS;

//-----------------------------------------------------------------------------

/*
 * Function:		init()
 * Description:		Used to attach a Library to the System along with any other necessary initialization operations
 * Arguments:
 * 	Library* l:	The Library the System can search through
 * Returns:		none
 */

void System::init() {
	//Like update() and shutdown(), init() is virtual and MUST be defined in inheriting Systems
}

//-----------------------------------------------------------------------------

/*
 * Function:		update()
 * Description:		Run during the main program loop. Any operations that must be done repeatedly should go in here.
 * Arguments:		none
 * Returns:		none
 */

void System::update() {
}

//-----------------------------------------------------------------------------

/*
 * Function:		shutdown()
 * Description:		Similar to init(), but normally run after update().
 * Arguments:		none
 * Returns:		none
 */

void System::shutdown() {
}

//-----------------------------------------------------------------------------

/*
 * Function:		linkLibrary()
 * Description:		Connects System to a Library (by address)
 * Arguments:
 * 	Library& l	address of the Library
 * Returns:		none
 */

void System::linkLibrary(Library& l) {
	lib = &l;	
}
