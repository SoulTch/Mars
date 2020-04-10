SRC_DIR := cpp
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

CPPFLAGS := -I ../json/include -I ..
CXXFLAGS := -std=c++17

all: mars_core

mars_core: $(OBJ_FILES)
	g++ -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f obj/gateway/*.o
	rm -f obj/mars/*.o
	rm -f obj/model/*.o
	rm -f mars_core