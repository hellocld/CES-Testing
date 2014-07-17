/*
 * Program:		system.h
 * Author:		Chris Langford
 * Date:		2014/05/05
 * Description:		Header for the System class, part of the CLD_ECS framework
 *
 */

#ifndef CLD_ECS_SYSTEM_H_INCLUDED
#define CLD_ECS_SYSTEM_H_INCLUDED

#include "library.h"

namespace CLD_ECS {
	//! The System class
	/*!
	 * Systems are what manipulate Components. Any and all data manipulation
	 * you'll want to do in your program will, for the most part, happen in
	 * custom-written Systems. Each System has three "phases": Init(),
	 * Update(), and Shutdown(). These phases can be called from the
	 * System's containing World by World::SystemsInit(),
	 * World::SystemsUpdate(), and World::SystemsShutdown(). Systems also
	 * have full access to Library's methods, specifically the Library
	 * contained in their World.
	 *
	 * NOTE: You cannot use the base System class on it's own. You must
	 * create your own custom Systems and inherit the base System class.
	 */
	class System {
		public:
			//! The System constructor
			/*!
			 * Important to note, System Initialization should go in
			 * Init(), not the constructor
			 */
			System() {};
			//! The System destructor
			/*!
			 * By default, the destructor sets library to nullptr to
			 * prevent any possible dangling pointer issues
			 */
			virtual ~System() {
				library = nullptr;
			};

			//! Initialization functions
			/*!
			 * Typically only run once, before Update() or
			 * Shutdown(). Possible things to include in Init() are 
			 * creating Entities, putting initial Components on 
			 * Entities, gathering specific Entities, etc.
			 *
			 * Called by World::SystemsInit()
			 *
			 * NOTE: Init() MUST be defined, even if it doesn't do
			 * anything.
			 * \sa World::SystemsInit(), Update(), Shutdown()
			 */
			virtual void Init() = 0;

			//! Update functions
			/*!
			 * In a typical program, Update() will be called
			 * repeatedly until the program is ready to end. Any
			 * regular updating of Components should be done here.
			 *
			 * Called by World::SystemsUpdate()
			 *
			 * NOTE: Update() MUST be defined, even if it doesn't do
			 * anything.
			 * \sa World::SystemsUpdate(), Init(), Shutdown()
			 */
			virtual void Update() = 0;

			//!Shutdown functions
			/*!
			 * Typically run once, after the program is no longer
			 * "updating". Things to do during Shutdown() could include 
			 * removal of Components that are no longer necessary,
			 * destruction of Entities, etc.
			 *
			 * Called by SystemsShutdown()
			 *
			 * NOTE: Shutdown() MUST be defined, even if it doesn't
			 * do anything.
			 * \sa World::SystemsShutdown(), Init(), Update()
			 */
			virtual void Shutdown() = 0;

			//! Connects the System to a Library
			/*!
			 * By default, when adding a System to a World with
			 * World::AddSystem(), LinkLibrary() is called with the
			 * World's Library as the passed argument. This grants
			 * the System access to that Library's methods.
			 * \param library the Library to connect to the System
			 * \sa World::AddSystem(), Library
			 */
			void LinkLibrary(Library& l);



		protected:
			//! reference to the Library in the World containing this system
			Library* library;
	};
}

#endif
