/*
 * Program:		component.h
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	A base component class for the CLD-CES framework
 * 
 */
 
#ifndef COMPONENT_H
#define COMPONENT_H

namespace CLD_CES {
	class Component {
		public:
		Component () {};
		virtual ~Component() = default;
	};
}

#endif
