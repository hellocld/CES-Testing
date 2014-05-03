/*
 * Program:		system.h
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	Header for the base System class in the CLD-CES framework
 * 
 */
 
#ifndef SYSTEM_H
#define SYSTEM_H

//might be a better way to do this
#include "library.h"

namespace CLD_CES { 
	class System {
		public:
		System() {};
		virtual ~System() = default;
		void init();
		void update();
		
		private:
		Library* lib; 
	};
}

#endif
