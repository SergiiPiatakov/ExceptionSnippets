CXX		= g++

.PHONY all: 001 002 003

001:
	$(CXX) 001_main.cpp -Wall -Wextra -o 001_main

002:
	$(CXX) 002_main.cpp -Wall -Wextra -o 002_main

003:
	$(CXX) 003_main.cpp -Wall -Wextra -o 003_main

.PHONY clean:
	$(RM) 001_main
	$(RM) 002_main
	$(RM) 003_main
