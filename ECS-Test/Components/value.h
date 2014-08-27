/*
 * Program:		value.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Component for ECS-Test. Stores an integer value
 */

#ifndef ECS_TEST_COMPONENT_VALUE_H
#define ECS_TEST_COMPONENT_VALUE_H

#include "../../component.h"

namespace ECS_Test {
	class Value : public CLD_ECS::Component {
		public:
			Value() : value(0) {}
			Value(int v) {value = v;}
			int value;
	};
}

#endif
