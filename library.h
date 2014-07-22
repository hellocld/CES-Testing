/*
 * Program:		library.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header file for the Library class in the CLD_ECS framework 
 */


#ifndef CLD_ECS_LIBRARY_H_INCLUDED
#define CLD_ECS_LIBRARY_H_INCLUDED

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
			~Library(){
				//we need to loop through everything in entities to remove EVERYTHING allocated in memory, so we'll need a couple iterators
				for(auto id = entities.begin(); id != entities.end(); ++id) {
					//now loop through each component
					for(auto c = id->second.begin(); c != id->second.end(); ++c) {
						//delete away!
						delete c->second;
					}
				}
			}
			//! Creates a new Entity
			/*!
			 * Adds a new Entity to entities and returns the Entity's 
			 * ID. It also attaches a single Component, BasicComp.
			 * \return The new Entity's ID
			 * \sa DestroyEntity()
			 */
			int CreateEntity(){
				//temporary storage for the Entity ID
				int e;

				if(entity_buffer.size() == 0) {
					//double-check to make sure entity_index isn't already in use as an ID
					while(entities.count(entity_index) != 0) {
						//if it is, just increase by one and check again
						entity_index++;
					}
					e = entity_index;
					entity_index++;
				} else {
					//since there's something in the buffer, remove the last entry from 
					//entity_buffer and return it
					e = entity_buffer.back();
					entity_buffer.pop_back();
				}
				//create a new entry in entities
				entities[e][&typeid(BasicComp)] = new BasicComp();
				return e;
			}

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
			bool DestroyEntity(int e){
				//look in entities to see if there's a key that matches e
				if(entities.count(e) != 0) {
					//loop through all it's components and delete them
					for(auto c = entities[e].begin(); c != entities[e].end(); ++c) {
						delete c->second;
					}
					//destroy the key and associated value
					entities.erase(e);
					//since e is now an unused ID, push it back into entity_buffer for reuse
					entity_buffer.push_back(e);

					return true;
				} else {
					//e was not a valid ID
					return false;
				}
			}

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
			bool AddComponent(int e, Component* c){
				//check if e is a valid Entity ID
				if(entities.count(e) != 0) {
					//make sure the Entity doesn't already contain a Component of c's type
					if(entities[e].count(&typeid(*c)) != 0) {
						//ERROR: Entity e has a Component of c's type already
						return false;
					} else {
						//add the Component with it's typeid as the key
						entities[e][&typeid(*c)] = c;
						return true;
					}
				} else {
					//ERROR: e is not a valid Entity ID
					return false;
				}
			}


			//! Removes a Component from Entity e
			/*!
			 * Removes a Component of type T from Entity with ID e.
			 * This also removes the Component from the free store.
			 * \param T the type of Component to remove
			 * \param e the Entity ID
			 * \return True if successful
			 * \sa RemoveComponent(), GetComponent(), HasComponent()
			 */
			template <typename T> bool RemoveComponent(int e){
				//check to see if Entity e exists
				if(entities.count(e) != 0) {
					//check for the Component
					if(entities[e].count(&typeid(T)) != 0) {
						//it exists, so remove the Component
						delete *entities[e][&typeid(T)];
						entities[e].erase(&typeid(T));
						return true;
					} else {
						//the Component was not found
						return false;
					}
				} else {
					//ERROR: e is not a valid Entity ID
					return false;
				}
			}

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
			template <typename T> T* GetComponent(int e){
				if(entities.count(e) != 0) {
					if(entities[e].count(&typeid(T)) != 0) {
						//return a pointer to the Component
						return dynamic_cast<T*>(entities[e][&typeid(T)]);
					} else {
						//ERROR: no such Component exists in Entity e
						return nullptr;
					}
				} else {
					//ERROR: no such Entity exists
					return nullptr;
				}
			}

			//! Checks if Entity e has a Component of type T
			/*!
			 * \param T the type of Component to search for
			 * \param e the Entity ID
			 * \return True if Entity e has a Component of type T
			 * \sa AddComponent(), RemoveComponent(), GetComponent
			 */
			template <typename T> bool HasComponent(int e){
				if(entities.count(e) != 0) {
					if(entities[e].count(&typeid(T)) != 0) {
						return true;
					} else {
						return false;
					}
				}
				return false;
			}

			//! Returns a vector of all active Entity IDs
			/*!
			 * \return a std::vector<int> of all active Entities by
			 *         ID
			 * \sa CreateEntity(), DestroyEntity()
			 */
			std::vector<int> GetEntityIDs(){
				//an empty vector to fill with Entity IDs
				std::vector<int> id;

				//iterate through the keys in entities, pushing each one into id
				for(auto i = entities.begin(); i != entities.end(); ++i) {
					id.push_back(i->first);
				}

				return id;
			}

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


	//creating an entity requires a single basic Component, so here's one that every Entity can use
	class BasicComp : public Component {
		//doesn't do anything right now; might be worth it to convert this to
		//a Messaging Component at some point, or some other extremely useful Component
	};
}

#endif
