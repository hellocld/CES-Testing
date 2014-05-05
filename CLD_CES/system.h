/*
 * Program:		system.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the System class, part of the CLD_CES framework
 *
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include "library.h"

namespace CLD_CES {
	class System {
		public:
			System() {};
			virtual ~System() = default;
			void init();
			void update();

		protected:
			//reference to the Library in the World containing this system
			Library* lib;
	};
}

#endif
