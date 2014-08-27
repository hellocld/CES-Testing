/*
 * Program:		name.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Component for ECS-Test. Stores a name string
 */

#ifndef ECS_TEST_COMPONENT_NAME_H
#define ECS_TEST_COMPONENT_NAME_H

#include <string>

#include "../../component.h"

namespace ECS_Test {
	class Name : public CLD_ECS::Component {
		public:
			Name() {name = " ";}
			Name(std::string s) {name = s;}
			std::string name;
	};
}

#endif
