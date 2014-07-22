/*
 * component.h -- header for the Component class, a part of CLD-ECS
 * version 1.0, July 22nd, 2014
 *
 * Copyright (c) 2014 cld
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source
 *    distribution.
 */

#ifndef CLD_ECS_COMPONENT_H_INCLUDED
#define CLD_ECS_COMPONENT_H_INCLUDED

namespace CLD_ECS {
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
