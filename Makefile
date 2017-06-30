##########################################################


## to anyone using GCC on Windows, MINGW
## this programm needs MinGW-64
## build gtest in folder google test
## using cmake with MinGW Makefiles
## copy libgtest.dll and libgtest_main.dll to libs
## run cmake on folder build

## if using Visual Studio, make sure VS2013+
## 

## this makefile is to be done with unix only

# release build of LIBPRO
all:
	if test ! -d build; then mkdir build; fi; 		\
	cd build;										\
	cmake .. -DCMAKE_BUILD_TYPE=Release -DTEST=OFF;	\
	make;

# debug build of LIBPRO
debug:
	if test ! -d build; then mkdir build; fi; 		\
	cd build;										\
	cmake .. -DCMAKE_BUILD_TYPE=Debug -DTEST=OFF	\
	make;

# testing LIBPRO using test in test/src
# built in release mode
unittest:
	if test ! -d build; then mkdir build; fi; 		\
	if test ! -d googletest/build; then mkdir googletest/build; fi; 	\
	if test ! -d libs; then mkdir libs; fi; 		\
	cd googletest/build;							\
	cmake .. -DBUILD_SHARED_LIBS=ON;				\
	make;											\
	mv *.so ../../libs/;							\
	cd ../../build;									\
	cmake .. -DCMAKE_BUILD_TYPE=Release -DTEST=ON;	\
	make;


# testing LIBPRO using test in test/src
# built in debug mode
unittestdb:
	if test ! -d build; then mkdir build; fi; 		\
	if test ! -d googletest/build; then mkdir googletest/build; fi; 	\
	if test ! -d libs; then mkdir libs; fi; 		\
	cd googletest/build;							\
	cmake .. -DBUILD_SHARED_LIBS=ON;				\
	make;											\
	mv *.so ../../libs/;							\
	cd ../../build;									\
	cmake .. -DCMAKE_BUILD_TYPE=Debug -DTEST=ON;	\
	make;


# remove build result
clean:
	rm -rf build				\
	rm -rf bin/LIBPRO			\
	rm -rf bin/LIBPRO_TEST		\
	rm -rf libs					\
	rm -rf googletest/build		\