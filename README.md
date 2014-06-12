CLD-ECS
=======
CLD-ECS is a simple, barebones Entity-Component-System framework written in C++. It strives to be the bare minimum in what you need to get off the ground and rolling with your own applications using the ECS approach.

Parts
-----
CLD-ECS is broken into a few basic parts
*	**Components**  
	Simple data structures. Systems read and manipuate these to make things happen. They are stored in a Library, and each new Component is associated to an Entity ID
*	**Systems**  
	A basic set of functions that perform operations on Components. They are linked to a specific Library, which gives them access to a certain set of Components.
*	**Library**  
	All Components are stored in a Library. When you create an Entity, it is given a unique ID and given a location in the Library, along with it's own database for Components.
*	**Worlds**  
	A simple container object that comes with a Library and a container for Systems. Worlds also handle the initialization and updating of all their contained Systems.

Example
-------
Provided alongside the framework is a basic program that creates a set of Entities, each with two custom Components, and utilizes two custom Systems to manipulate and display the data stored in the Components. You can view the code for details, but the basic implementation steps are:

1.	Create a new World
2.	Add three custom Systems to the World (Factory, IncrementValue, and OutputData)
3.	Initialize the Systems
	*	Factory creates a set of Entities and attaches Components to each at this point
4.	Update the Systems
	*	In the example program this is a simple for() loop that runs 5 times
4.	Shut down the Systems
5.	Clean up everything and quit
	*	This is handled by the framework

This is obviously a very simple example; the true power of this framework is in the extensibility of custom Components and Systems. You can create Sub-Systems to run within Systems, or even place Worlds within Systems for a (theoretically) infinite degree of separation between program elements.

This is still very much a work-in-progress, so expect things to be changing/improving over time. If you have any questions or comments on the framework, feel free to hit me up at chris ( at ) hellocld.com. And if you use it in something cool, lemme know! I'd love to see it.

-Chris
