/*
 * Program:		ECS-Test.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		ECS-Test is the first test of the CLD-ECS (yep, that's the new name) framework. It (should) create a set of Entities containing Name and Value components,
 * 			increment each Value value by one during the main loop, and output all the values to the terminal.
 */

#include "..CLD_CES/world.h"

int main(int argc, char* argv[]) {
	//create the World
	CLD_CES::World world;

	//add the necessary Systems
	world.addSystem(new ECS-Test::Factory());
	world.addSystem(new ECS-Test::IncrementValue());
	world.addSystem(new ECS-Test::OutputData());

	//initialize the systems
	world.systemsInit();

	//loop through the update functions a few times
	for(int i = 0; i < 5; ++i) {
		world.systemsUpdate();
	};

	return 0;
}
