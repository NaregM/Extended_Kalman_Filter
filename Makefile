# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -I.

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o kalman_filter.o tracking.o
	$(CXX) $(CXXFLAGS) -o results main.o kalman_filter.o tracking.o

# The main.o target can be written more simply

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

kalman_filetr.o: kalman_filetr.cpp
	$(CXX) $(CXXFLAGS) -c kalman_filetr.cpp

tracking.o: tracking.cpp
	$(CXX) $(CXXFLAGS) -c tracking.cpp

clean:
	rm -f *~ *.o driver
