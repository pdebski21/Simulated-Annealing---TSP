cROOT_DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))

CXX = g++
CFLAGS = -g -Wall 
SRC = src
OBJ = obj
SRCS= $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/main
SUBMITNAME = project.zip

all:$(BIN)

define print_cxx_target
@echo 'CXX $(notdir $(1))'
endef

$(BIN): $(OBJS)
	@$(CXX) $(CFLAGS) $(OBJS) -o $@
	$(call print_cxx_target, $@)

$(OBJ)/%.o: $(SRC)/%.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@
	$(call print_cxx_target, $@)

release: CFLAGS = -Wall -O2 -DNDEBUG
release: clean
release: $(BIN)

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submit: 
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)
