/*
 * Program:		ECS-Test.cxx
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		ECS-Test is the first test of the CLD-ECS (yep, that's the new name) framework. It (should) create a set of Entities containing Name and Value components,
 * 			increment each Value value by one during the main loop, and output all the values to the terminal.
 */

#include "../world.h"

#include "Systems/factory.h"
#include "Systems/incrementValue.h"
#include "Systems/outputData.h"

int main(int argc, char* argv[]) {
	//create the World
	CLD_ECS::World world;

	//add the necessary Systems
	world.AddSystem(new ECS_Test::Factory());
	world.AddSystem(new ECS_Test::IncrementValue());
	world.AddSystem(new ECS_Test::OutputData());

	//initialize the systems
	world.SystemsInit();

	//loop through the update functions a few times
	for(int i = 0; i < 5; ++i) {
		world.SystemsUpdate();
	};

	world.SystemsShutdown();

	return 0;
}
