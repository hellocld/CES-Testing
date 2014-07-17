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

void System::Init() {
}

//-----------------------------------------------------------------------------
void System::Update() {
}

//-----------------------------------------------------------------------------

void System::Shutdown() {
}

//-----------------------------------------------------------------------------

void System::LinkLibrary(Library& l) {
	library = &l;	
}
