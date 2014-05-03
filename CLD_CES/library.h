/* 
 * Program:		library.h
 * Author:		Chris Langford
 * Date:		2014/05/03
 * Description:	Header file for the library class in the CLD-CES framework
 * 
 */
 
#ifndef LIBRARY_H
#define LIBRARY_H
 
namespace CLD_CES {
	class Library {
		public:
		//functions for creating and destroying entities
		int createEntity();
		bool destroyEntity(int e);
		
		//functions to add and remove components
		bool addComponent(int e, Component* c);
		template <typename T> bool removeComponent(int e);
		
		//retrieve component from a specific entity
		template <typename T> T* getComponent(int e);
		
		//find all entities containing component type T
		template <typename T> int[] getEntitiesWithComponent();
		
		
		private:
		//the unordered map that stores all entities and components
		unordered_map<int, unordered_map<const type_info *, Component *>> lib;
		
		int entity_index = 0;
		
		vector<int> entity_buffer;
		
	};
}

#endif
