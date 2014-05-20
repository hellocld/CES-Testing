exe = g++
flags = -std=c++11 -Wall

#compile CLD_ECS
library.o : library.cxx library.h system.h component.h
	$(exe) $(flags) -c $< -o $@

system.o : system.cxx system.h component.h
	$(exe) $(flags) -c $< -o $@

world.o : world.cxx world.h system.h library.h
	$(exe) $(flags) -c $< -o $@


