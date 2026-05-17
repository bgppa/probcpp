# TO DO
CXX	 := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
TARGET	 := probcpp
OBJ	 := bernoulli.o distribution.o

.PHONY: test clean run

$(TARGET): $(OBJ) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(OBJ) -o $(TARGET)

# Generate the distribution object
distribution.o: distribution.cpp distribution.hpp
	$(CXX) $(CXXFLAGS) -c distribution.cpp distribution.hpp

# Generate the bernoulli object
bernoulli.o: bernoulli.cpp bernoulli.hpp
	$(CXX) $(CXXFLAGS) -c bernoulli.cpp bernoulli.hpp

clean: $(TARGET)
	rm -rf $(TARGET) $(OBJ) *.pch

test: $(TARGET)
	echo "To do"

run: $(TARGET)
	./$(TARGET)
