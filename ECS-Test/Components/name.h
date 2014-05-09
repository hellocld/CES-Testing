/*
 * Program:		name.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Component for ECS-Test. Stores a name string
 */

#ifndef NAME_H
#define NAME_H

#include <string>

#include "../../CLD-CES/component.h"

namespace ECS_Test {
	class Name : public CLD_CES::Component {
		public:
			Name() : name(" "){}
			Name(string s) {name = s;}
			std::string name;
	};
}

#endif
