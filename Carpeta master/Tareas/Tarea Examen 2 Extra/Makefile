CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

TARGET = examenExtra
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC) IIndexador.h IndexadorArbol.h IndexadorHash.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)


clean:
	rm -f $(TARGET)