/*
 * Program:		world.h
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	Header for the World class in the CLD_CES framework
 * 
 */

#ifndef WORLD_H
#define WORLD_H

#include "library.h"
#include "system.h"
#include <unordered_map>
#include <typeinfo>

namespace CLD_CES {
	class World {
		public:
		void init();
		void update();
		
		bool addSystem(System s);
		template <typename T> bool removeSystem();
		
		private:
		std::unordered_map<std::type_info *, System *> systems;
		Library lib;
	};
}

#endif
