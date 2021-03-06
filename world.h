/*
 * world.h -- header for the World class, a part of CLD-ECS
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

#ifndef CLD_ECS_WORLD_H_INCLUDED
#define CLD_ECS_WORLD_H_INCLUDED

#include <vector>

#include "library.h"
#include "system.h"

namespace CLD_ECS {
	//! A container class for Systems and Libraries
	/*!
	 * The World class is designed to be a simple container for a set of
	 * Systems and their associated Library. You can add, Initialize,
	 * Update, and Shutdown Systems within the World. Worlds also have
	 * access to their Library through it's public methods.
	 */
	class World {
		public:
			//! The World destructor
			virtual ~World(){
				//just need to iterate through systems and remove everything
				for(auto s = systems.begin(); s != systems.end(); ++s) {
					delete *s;
				}
			}


			//! Adds a new System to the World
			/*!
			 * Creates a new System and adds it to systems. Keep in
			 * mind you can have no more than one of any custom
			 * System per World.
			 *
			 * NOTE: The order in which you add Systems is
			 * important. SystemsInit() and SystemsUpdate() run the
			 * Init() and Update() functions on each System in the
			 * order in which you added them. SystemsShutdown() runs
			 * Shutdown() on Systems in the reverse order.
			 * \param s A new System to add to the free store.
			 * \return True if System was added successfully
			 * \sa RemoveSystem()
			 */
			bool AddSystem(System* s){
				//if systems isn't empty, we need to check it for possibly duplicate 
				//entries before adding a new System
				if(systems.size() != 0) {
					//a simple iterator for looping through systems
					std::vector<System*>::iterator i;
					//if a single System of s's type is found, return from the function 
					//without adding anything
					for(i = systems.begin(); i < systems.end(); ++i) {
						if(&typeid(*(*i)) == &typeid(*s)) {
							//the System already exists in systems, so we quit
							return false;
						}
					}
				}
				//if systems is empty or has no Systems of s's type, attach the library 
				//and add the new System
				s->LinkLibrary(library);
				systems.push_back(s);
				return true;
			}

			//! Removes a System from the World
			/*!
			 * Removes a System from systems.
			 *
			 * NOTE: This does not run any System functions, so be
			 * sure you've handled any Initialization, Update, or
			 * Shutdown procedures accordingly.
			 * \param T the type of System to remove
			 * \return True of System was removed successfully
			 * \sa AddSystem()
			 */
			template <typename T> bool RemoveSystem(){
				//a simple iterator for looping through systems
				std::vector<System*>::iterator i;
				//loop through systems, checking for a System of type T
				for(i = systems.begin(); i < systems.end(); ++i){
					if(&typeid(*(*i)) == &typeid(T)) {
						//the System was found; erase it and return
						delete *i;
						systems.erase(i);
						return true;
					}
				}
				//the System was not found
				return false;
			}

			//! Creates a new Entity
			/*!
			 * Adds a new Entity to entities and returns the Entity's 
			 * ID. It also attaches a single Component, BasicComp.
			 * \return The new Entity's ID
			 * \sa DestroyEntity()
			 */
			int CreateEntity(){ return library.CreateEntity(); };
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
			bool DestroyEntity(int e){ return library.DestroyEntity(e); };
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
			bool AddComponent(int e, Component* c){ return library.AddComponent(e, c); };
			//! Removes a Component from Entity e
			/*!
			 * Removes a Component of type T from Entity with ID e.
			 * This also removes the Component from the free store.
			 * \param T the type of Component to remove
			 * \param e the Entity ID
			 * \return True if successful
			 * \sa RemoveComponent(), GetComponent(), HasComponent()
			 */
			template <typename T> T* RemoveComponent(int e){ return library.RemoveComponent<T>(e); };
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
			template <typename T> T* GetComponent(int e){ return library.GetComponent<T>(e); };
			//! Checks if Entity e has a Component of type T
			/*!
			 * \param T the type of Component to search for
			 * \param e the Entity ID
			 * \return True if Entity e has a Component of type T
			 * \sa AddComponent(), RemoveComponent(), GetComponent
			 */
			template <typename T> bool HasComponent(int e){ return library.HasComponent<T>(e); };
			//! Returns a vector of all active Entity IDs
			/*!
			 * \return a std::vector<int> of all active Entities by
			 *         ID
			 * \sa CreateEntity(), DestroyEntity()
			 */
			std::vector<int> GetEntityIDs(){return library.GetEntityIDs(); };

			//! Runs System::Init() on all Systems in systems
			/*!
			 * Runs System::Init() on each System added to systems,
			 * in the order in which they were added.
			 * \sa SystemsUpdate(), SystemsShutdown()
			 */
			void SystemsInit(){
				//a simple iterator for looping through systems
				std::vector<System*>::iterator i;
				//loop through systems, checking for a System of type T
				for(i = systems.begin(); i < systems.end(); ++i) {
					(*i)->Init();
				}
			}

			//! Runs System::Update() on all Systems in systems
			/*!
			 * Runs System::Update() on each System added to systems,
			 * in the order in which they were added.
			 * \sa SystemsInit(), SystemsShutdown()
			 */
			void SystemsUpdate(){
				//a simple iterator for looping through systems
				std::vector<System*>::iterator i;
				//loop through systems, checking for a System of type T
				for(i = systems.begin(); i < systems.end(); ++i){
					(*i)->Update();
				}
			}

			//! Runs System::Shutdown() on all Systems in systems
			/*!
			 * Runs System::Shutdown() on each System added to
			 * systems, in reverse order from which they were added.
			 * \sa SystemsInit(), SystemsUpdate()
			 */
			void SystemsShutdown(){
				//a simple iterator for looping through systems
				std::vector<System*>::reverse_iterator i;
				//loop through systems, checking for a System of type T
				for(i = systems.rbegin(); i < systems.rend(); ++i){
					(*i)->Shutdown();
				}
			}

		private:
			//Library to store all Entities and Components in this World
			Library library;

			//vector to store all Systems
			std::vector<System*> systems;
	};
}

#endif

