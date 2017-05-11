CC := g++

SRCDIR := src
BUILDDIR := build
TARGET := bin/LIBPRO
RELEASE := bin/LIBPRO_released
TEST  := test/bin/LIBPRO

SRCEXT := cpp
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
CFLAGS := -static -static-libgcc -static-libstdc++ -g -fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8 -std=c++11
INC := -I include

$(TARGET): $(OBJ_FILES)
	@echo " linking "
	@echo " $(CC) $(OBJ_FILES) -o $(TARGET) ";
	$(CC) $(OBJ_FILES)  -o $(TARGET)


$(RELEASE): $(OBJ_FILES)
	@echo " linking "
	@echo " $(CC) $(OBJ_FILES) -o $(RELEASE) ";
	$(CC) $(OBJ_FILES)  -o $(RELEASE)

test: $(OBJ_FILES)
	@echo " linking test "
	@echo " $(CC) $(OBJ_FILES) -o $(TEST) ";
	$(CC) $(OBJ_FILES) -o $(TEST)

#
#$test/%.o: $(SRCDIR)/%.$(SRCEXT)
#	@echo " $(CC) $(CFLAGS) $(INC) $< -o $@ ";
#	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " $(CC) $(CFLAGS) $(INC) $< -o $@ ";
	$(CC) $(CFLAGS) $(INC) -c $< -o $@