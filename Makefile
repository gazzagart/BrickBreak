# CXX		  := g++
# CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -F /Library/Frameworks
# LDFLAGSMAC	  := -framework SDL2 -F /Library/Frameworks -I /Library/Frameworks/SDL2.framework/Headers

# ASSETS := assets

# BIN		:= bin
# #* There are many ways to get this file to look for your files. Here we are telling the makefile to look in these folders from the root.
# SRC		:= src src/Utils src/graphics src/shapes
# $(wildcard ./neo/engine/*.cpp)  $(wildcard ./neo/engine/**/*.cpp)
# INCLUDE	:= include
# LIB		:= lib

# LIBRARIES	:=
# EXECUTABLE	:= main


# all: $(BIN)/$(EXECUTABLE)

# run: clean all
# 	clear
# 	mkdir ./$(BIN)/assets
# 	cp -rf src/$(ASSETS) ./$(BIN)/$(ASSETS)
# 	./$(BIN)/$(EXECUTABLE)
# 					#? Here we are looking foreach file in our SRC variable
# 					#? $(foreach var,list,text)
# 					#? The list here is found in SRC variable. It is the variable in this case. So both src and src/Utils. There are two items in our list
# 					#? Then the text is for each list item, apply this text to this. so it looks for all .cpp files basically.
# $(BIN)/$(EXECUTABLE): $(foreach SRC,$(SRC),$(wildcard $(SRC)/*.cpp))
# 	$(CXX) $(LDFLAGSMAC) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

# clean:
# 	-rm $(BIN)/*
# 	rm -rf ./$(BIN)/$(ASSETS)


CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
LDFLAGSWIN := -Wfatal-errors -I"C:\SDL2\i686-w64-mingw32\include" -L"C:\SDL2\i686-w64-mingw32\lib" -lmingw32 -lSDL2main -lSDL2

BIN		:= bin
SRC		:= $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

all: $(BIN)\$(EXECUTABLE)

run: clean all
	cls
	mkdir .\$(BIN)\assets
	.\$(BIN)\$(EXECUTABLE)

$(BIN)\$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB)  $^ $(LDFLAGSWIN) -o $@
clean:
	if exist  $(BIN)\ del /q $(BIN)\*
	if exist  $(BIN)\assets\ rmdir $(BIN)\assets
