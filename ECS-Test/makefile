vpath %.cxx ../ ./Systems ./Components
vpath %.h ../ ./Systems ./Components

exe = g++
flags = -std=c++11 -Wall -g

#cldcesobj = library.o system.o world.o

ecsobj = factory.o incrementValue.o outputData.o 

#put everything together!
ECS-Test : main.cxx $(ecsobj) 
	$(exe) $(flags) -o ECS-Test main.cxx $(ecsobj)

#compile the custom systems
factory.o : factory.cxx factory.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

incrementValue.o : incrementValue.cxx incrementValue.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

outputData.o : outputData.cxx outputData.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

#PROBABLY NOT NEEDED ANY MORE
#compile CLD_ECS
#library.o : library.cxx library.h system.h component.h
#	$(exe) $(flags) -c $< -o $@
#
#system.o : system.cxx system.h component.h
#	$(exe) $(flags) -c $< -o $@
#
#world.o : world.cxx world.h system.h library.h
#	$(exe) $(flags) -c $< -o $@
#

