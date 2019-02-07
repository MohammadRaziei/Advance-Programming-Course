CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o Queue.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp Queue.h
	$(CXX) $(CXXFLAGS) main.cpp 
Queue.o: Queue.cpp
	$(CXX) $(CXXFLAGS) Queue.cpp 
clean:
	rm -f $(TARGET) $(OBJECTS)
