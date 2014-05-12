vpath %.cxx ../CLD_CES ./Systems ./Components
vpath %.h ../CLD_CES ./Systems ./Components

exe = g++
flags = -std=c++11 -Wall

cldcesobj = library.o system.o world.o

ecsobj = factory.o incrementValue.o outputData.o 

#put everything together!
ECS-Test : main.cxx $(ecsobj) $(cldcesobj)
	$(exe) $(flags) -o ECS-Test main.cxx $(objects)

#compile the custom systems
factory.o : factory.cxx factory.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $(<D)/$@

incrementValue.o : incrementValue.cxx incrementValue.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $(<D)/$@

outputData.o : outputData.cxx outputData.h system.h library.h component.h
	$(exe) $(flags) -c $< -o $(<D)/$@

#compile CLD_CES
library.o : library.cxx library.h system.h component.h
	$(exe) $(flags) -c $< -o $(<D)/$@

system.o : system.o system.h component.h
	$(exe) $(flags) -c $< -o $(<D)/$@

world.o : world.cxx world.h system.h library.h
	$(exe) $(flags) -c $< -o $(<D)/$@


