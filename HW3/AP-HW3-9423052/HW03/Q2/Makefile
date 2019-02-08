CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o line.o point.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp point.h line.cpp
	$(CXX) $(CXXFLAGS) main.cpp
point.o: point.cpp line.cpp
	$(CXX) $(CXXFLAGS) point.cpp
line.o: line.cpp point.h
	$(CXX) $(CXXFLAGS) line.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
