/*
 * Program:		library.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header file for the Library class in the CLD_ECS framework 
 */


#ifndef LIBRARY_H
#define LIBRARY_H

#include <typeinfo>
#include <unordered_map>
#include <vector>

#include "component.h"

namespace CLD_ECS {
	//! The Library class
	/*!
	 * The Library is a container for all Entities and Components. It
	 * handles the creation and destruction of Entities, the adding and
	 * removal of Components, and finds Components attached to Entities.
	 */

	class Library {
		public:
			//! The Library constructor
			Library() {};
			//! The Library destructor
			/*!
			 * Cleans up any remaining Entities or Components still 
			 * stored, removing them from the free store.
			 */
			~Library();
			//! Creates a new Entity
			/*!
			 * Adds a new Entity to entities and returns the Entity's 
			 * ID. It also attaches a single Component, BasicComp.
			 * \return The new Entity's ID
			 * \sa DestroyEntity()
			 */
			int CreateEntity();
			//! Destroys an Entity
			/*!
			 * Removes an Entity from entities. If the
			 * Entity has any remaining Components, they are removed
			 * from the free store. Additionally, the ID is pushed
			 * to entity_buffer for recycling.
			 * \param e an Entity ID
			 * \return True if Entity was found and destroyed
			 *         successfully
			 * \sa CreateEntity(), GetEntityIDs()
			 */
			bool DestroyEntity(int e);
			
			//! Adds a new Component to Entity e
			/*!
			 * AddComponent creates a new Component on the free
			 * store and associates it with the Entity ID e in
			 * entities. It's important to note you can't have more
			 * than one of any given Component type associated with
			 * an Entity.
			 * \param e the Entity ID
			 * \param c the Component
			 * \return True if successful
			 * \sa CreateEntity(), GetEntityIDs()
			 */
			bool AddComponent(int e, Component* c);
			//! Removes a Component from Entity e
			/*!
			 * Removes a Component of type T from Entity with ID e.
			 * This also removes the Component from the free store.
			 * \param T the type of Component to remove
			 * \param e the Entity ID
			 * \return True if successful
			 * \sa RemoveComponent(), GetComponent(), HasComponent()
			 */
			template <typename T> bool RemoveComponent(int e);

			//! Gets a Component from Entity e
			/*!
			 * Returns a pointer to Component T in Entity e, if the
			 * Entity contains a Component of type T.
			 * \param T the type of Component to get
			 * \param e the Entity ID
			 * \return pointer to the Component. nullptr if the
			 *         Component was not found
			 * \sa AddComponent(), GetComponent(), HasComponent()
			 */
			template <typename T> T* GetComponent(int e);
			
			//! Checks if Entity e has a Component of type T
			/*!
			 * \param T the type of Component to search for
			 * \param e the Entity ID
			 * \return True if Entity e has a Component of type T
			 * \sa AddComponent(), RemoveComponent(), GetComponent
			 */
			template <typename T> bool HasComponent(int e);

			//! Returns a vector of all active Entity IDs
			/*!
			 * \return a std::vector<int> of all active Entities by
			 *         ID
			 * \sa CreateEntity(), DestroyEntity()
			 */
			std::vector<int> GetEntityIDs();

		private:
			//! An unordered map that stores all entities
			/*!
			 * The Key field is for the Entity ID. The Value 
			 * stores an additional unordered map that contains the 
			 * Components of the Entity.
			 */
			std::unordered_map<int, std::unordered_map<const std::type_info *, Component*>> entities;
			
			//! An entity count, for creating new Entity ID
			/*!
			 * If entity_buffer is empty, CreateEntity() uses
			 * entity_index to create a new Entity ID, then
			 * increases entity_index by one.
			 */
			int entity_index = 0;
			//! A simple buffer to place destroyed entity keys in
			/*!
			 * If entity_buffer contains any values at all,
			 * CreateEntity() pops the back value and recycles it as
			 * a new Entity ID.
			 */
			std::vector<int> entity_buffer;
	};

	//the template function definitions
	#include "library.txx"

	//creating an entity requires a single basic Component, so here's one that every Entity can use
	class BasicComp : public Component {
		//doesn't do anything right now; might be worth it to convert this to
		//a Messaging Component at some point, or some other extremely useful Component
	};
}

#endif
