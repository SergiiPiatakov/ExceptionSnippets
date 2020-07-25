CXX		= g++
CXXflags = -Wall -Wextra
PLIB_DIR=$(PWD)/Person/build

.PHONY all: 001 002 003 004

001:
	$(CXX) 001_main.cpp $(CXXflags) -o 001_main

002:
	$(CXX) 002_main.cpp $(CXXflags) -o 002_main

003:
	$(CXX) 003_main.cpp $(CXXflags) -o 003_main


# Person library should be compiled first in build directory inside Person
004: main.o person_library
	$(CXX) $< $(PLIB_DIR)/libperson.a -Wl,-rpath=$(PLIB_DIR) -o 004_main

#Compile the main executable file: USED ONLY AS DEPENDENCY FOR 004
main.o: 004_person_test.cpp
	$(CXX) -fPIC -c $(CXXflags) -IPerson $^ -o $@

#Compile the library using CMake : USED ONLY AS DEPENDENCY FOR 004
person_library:
	cmake -HPerson -B$(PLIB_DIR)
	cmake --build $(PLIB_DIR)

.PHONY clean:
	$(RM) 001_main
	$(RM) 002_main
	$(RM) 003_main
	$(RM) main.o
	$(RM) 004_main
