/*
 * Program:		value.h
 * Author:		Chris Langford
 * Date:		2014/05/09
 * Description:		Component for ECS-Test. Stores an integer value
 */

#ifndef VALUE_H
#define VALUE_

#include "../CLD-CES/component.h"

namespace ECS_Test {
	class Value : public CLD_CES::Component {
		public:
			Value() : value(0) {}
			Value(int v) {value = v;}
			int value;
	};
}

#endif
