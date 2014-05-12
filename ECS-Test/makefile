VPATH = ../CLD_CES:Systems:Components

exe = g++
flags = -Wall

cldces = library.o system.o world.o

ecsobj = factory.o incrementValue.o outputData.o 

#put everything together!
ECS-Test : main.cxx $(ecsobj) $(cldces)
	$(exe) $(flags) -o ECS-Test main.cxx $(objects)

#compile the custom systems
factory.o : factory.cxx factory.h $(cldces)
	$(exe) $(flags) -c factory.o 

incrementValue.o : incrementValue.cxx incrementValue.h $(cldces)
	$(exe) $(flags) -c incrementValue.cxx

outputData.o : outputData.cxx outputData.h ($cldces)
	$(exe) $(flags) -c outputData.cxx

#compile CLD_CES
library.o : library.cxx library.h system.h component.h
	$(exe) $(flags) -c library.cxx

system.o : system.o system.h component.h
	$(exe) $(flags) -c system.cxx

world.o : world.cxx world.h system.h library.h
	$(exe) $(flags) -c world.o

