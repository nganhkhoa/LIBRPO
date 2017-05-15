#############################################################################################
# 									This is a makefile  									#
# 									to build file to o  									#
# 									and link them as exe									#
#############################################################################################


#	Missing things

#
#	Build all command
#
#	Build all and link command
#
#	Clean o files
#		can't understand why del return error


#	What this file does

#
#	Before reading this, 
#	requisties: gnu complier, and makefile
#	download from MINGW,
#	from MinGW, add g++ and make
#	add variable path:	
#		<MinGW installed path>\MinGW\bin
#		C:\MinGW\bin
#
#	for make, copy C:\MinGW\msys\1.0\bin\make.exe to the above
# 	or add variable path there
#	
#	to add variable path 
# 	run > control sysdm.cpl > Advanced > Environment Variables >
#	Choose > Path > Edit > Add > ...
#	OK
#
#	in commandline type
#	g++
#	to check g++ installed and configed or not
# 	make
# 	to check make installed and configed or not


#
#	Build cpp to o file by running command
#		make <filename>.o
#	make sure the file is anywhere in src
#	if the file is in src, and compile failed
#	add new folder to VPATH
#
#		make test/<filename>.o
#	to build from test/src
#	the file must be in src directory
#	output will be int test/build

#
#	link all o from build by running command
#		make libpro
#	output in bin/
#		make test
#	will collect o files from test/build as well
#	ouptut exe will be test/bin




#
# ─── VARIABLES ──────────────────────────────────────────────────────────────────
#

	

CC = g++

#CFLAGS = -static -static-libgcc -static-libstdc++ -fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8 -std=c++11

CFLAGS = -g -fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8 -std=c++11

INC = -I include


VPATH = src\
		src/Browse\
		src/History\
		src/Login\
		src/ReadBook\
		src/ReadData\
		src/Setting\
		src/Utilities\
			src/Utilities/Reader\
			src/Utilities/Accountant\
			src/Utilities/Admin\
			src/Utilities/Money\
		src/Welcome\

TEST_SRCDIR = test/src

SRCDIR = src
BUILDDIR = build
OUTPUT = bin/LIBPRO
TEST  = test/bin/LIBPRO_test

SRCEXT = cpp
OBJEXT = o
#CPP_FILES = $(wildcard *.cpp)
#OBJ_FILES = $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
OBJ = $(wildcard build/*.$(OBJEXT))
TEST_OBJ = $(wildcard test/buildtest/*.$(OBJEXT))



#
# ─── COMMANDS ───────────────────────────────────────────────────────────────────
#

	
libpro: $(OBJ)
	@echo " linking to LIBPRO.exe "
	@echo " test files will not be affected "
	$(CC) $(OBJ) -o $(OUTPUT)


test: $(OBJ) $(TEST_OBJ)
	@echo " linking to test "
	$(CC) $(OBJ) $(TEST_OBJ) -o $(TEST)

test/%.$(OBJEXT): $(TEST_SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c $< -o test/build$@

%.$(OBJEXT):%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c $^ -o build/$@


#clean: 
#	@echo DEL $(OBJ)
#	@echo DEL $(TEST_OBJ)