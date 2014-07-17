/*
 * Program:		component.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Component class header for CLD_ECS framework
 *
 */

#ifndef CLD_ECS_COMPONENT_H_INCLUDED
#define CLD_ECS_COMPONENT_H_INCLUDED

//! The basic Component class
/*!
 * Components are the building blocks of your Entities. They are essentially
 * nothing more than data structures that are manipulated by Systems. It's
 * usually best to keep them as simple as possible. Don't include too many
 * different uses for any particular Component; rather, design each Component to
 * be used for one specific purpose, so that multiple Components can be used
 * together to create more dynamic and varied Entities.
 *
 * NOTE: you cannot use a raw Component object. You must create your own
 * Components that inherit the base Component class.
 */
namespace CLD_ECS {
	class Component {
		public:
			//! The Component constructor
			Component() {};
			//! The Component destructor
			/*!
			 * A virtual destructor is used so that accessing
			 * Components in the Library acquires the correct
			 * Components, rather than the base class
			 */
			virtual ~Component() = default;
	};
}

#endif
