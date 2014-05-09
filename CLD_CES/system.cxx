/*
 * Program:		system.cxx
 * Author:		Chris Langford
 * Date:		2014/05/07
 * Description:		The System class is used to manipulate the data stored in Components in various ways
 */

#include "system.h"
#include "library.h"

using namespace CLD_CES;

//-----------------------------------------------------------------------------

/*
 * Function:		init()
 * Description:		Used to attach a Library to the System along with any other necessary initialization operations
 * Arguments:
 * 	Library* l:	The Library the System can search through
 * Returns:		none
 */

void System::init(Library l) {
	//the only thing the base System must do is connect to a Library for Component access
	lib = &l;
}

//-----------------------------------------------------------------------------

/*
 * Function:		update()
 * Description:		Run during the main program loop. Any operations that must be done repeatedly should go in here.
 * Arguments:		none
 * Returns:		none
 */

void System::update() {
	//The base System class doesn't do anything - create new Systems that inherit the base to manipulate components
}
