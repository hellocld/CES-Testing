vpath %.cxx ../CLD_ECS ./Systems ./Components
vpath %.h ../CLD_ECS ./Systems ./Components

exe = g++
flags = -std=c++11 -Wall

cldcesobj = library.o system.o world.o

ecsobj = factory.o incrementValue.o outputData.o 

#put everything together!
ECS-Test : main.cxx $(ecsobj) $(cldcesobj)
	$(exe) $(flags) -o ECS-Test main.cxx $(cldcesobj) $(ecsobj)

#compile the custom systems
factory.o : factory.cxx factory.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

incrementValue.o : incrementValue.cxx incrementValue.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

outputData.o : outputData.cxx outputData.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $@

#compile CLD_ECS
library.o : library.cxx library.txx library.h system.h component.h
	$(exe) $(flags) -c $< -o $@

system.o : system.cxx system.h component.h
	$(exe) $(flags) -c $< -o $@

world.o : world.cxx world.txx world.h system.h library.h
	$(exe) $(flags) -c $< -o $@


