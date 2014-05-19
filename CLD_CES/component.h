/*
 * Program:		component.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Component class header for CLD_CES framework
 *
 */

#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

namespace CLD_CES {
	class Component {
		public:
			Component() {std::cerr<<"New Component created\n";};
			virtual ~Component() = default;
	};
}

#endif
