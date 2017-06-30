cmake_minimum_required(VERSION 3.8.1)


set(OTHER_FILES_EXTENSION "json")


	# thiet lap o day
	set(PROJECT_NAME "LIBPRO")

	set(SOURCE_FOLDER "src")
	set(INCLUDE_FOLDER "include")
	set(OUTPUT_FOLDER "bin")
	set(LIBS_FOLDER "libs")
	
	# vs only settings
	set(OTHER_FILES_FOLDER "bin")

	set(DEBUG_FOLDER "bin") # vs only

# output file exe location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../${OUTPUT_FOLDER})

# the project name
project (${PROJECT_NAME} CXX)

# The version number.
set (LIBPRO_VERSION_MAJOR 1)
set (LIBPRO_VERSION_MINOR 5)
set (LIBPRO_VERSION_FIX 10)
configure_file (
  "${PROJECT_SOURCE_DIR}/${SOURCE_FOLDER}/version.h.in"
  "${PROJECT_SOURCE_DIR}/${SOURCE_FOLDER}/version.h"
  )

# the included folder for <foo.h>
include_directories(${INCLUDE_FOLDER})


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
# using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

	file(GLOB_RECURSE SOURCES "${SOURCE_FOLDER}/*.cpp")
	file(GLOB_RECURSE HEADERS "${INCLUDE_FOLDER}/*.h" "${INCLUDE_FOLDER}/*.hpp")
	file(GLOB_RECURSE RESOURCE "${OTHER_FILES_FOLDER}/*.${OTHER_FILES_EXTENSION}")

	if(TEST)
		add_definitions(-DUNITTEST)

		file(GLOB_RECURSE TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "test/src/*.cpp")
		include_directories("googletest/include")

		set(ALL_FILES ${SOURCES} ${TEST_SOURCES})
		add_executable(${PROJECT_NAME}_TEST ${ALL_FILES})

		LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/${LIBS_FOLDER})
		if(WIN32)
			file(GLOB_RECURSE LIBRARIES "${LIBS_FOLDER}/*.a")
		elseif(UNIX)
			file(GLOB_RECURSE LIBRARIES "${LIBS_FOLDER}/*.so")
		endif()
		target_link_libraries(${PROJECT_NAME}_TEST ${LIBRARIES})

	else(TEST)

		set(ALL_FILES ${SOURCES})
		add_executable(${PROJECT_NAME} ${ALL_FILES})
		
	endif(TEST)
	

	set(WARNING "-Wall")
	set(PUBLIC "-static -static-libgcc -static-libstdc++")
	set(IDENTIFIER "-fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8")
	set(CPPVERSION "-std=c++11")

	set(CMAKE_CXX_FLAGS ${WARNING}\ ${IDENTIFIER}\ ${CPPVERSION})

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

	# the included folder for <foo.h>
	include_directories(${INCLUDE_FOLDER})
	file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${SOURCE_FOLDER}/*.cpp")
	file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${INCLUDE_FOLDER}/*.h" "${INCLUDE_FOLDER}/*.hpp")
	file(GLOB_RECURSE RESOURCE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${OTHER_FILES_FOLDER}/*.${OTHER_FILES_EXTENSION}")
	
	set(ALL_FILES ${SOURCES}\  ${HEADERS}\  ${RESOURCE})
	add_executable(${PROJECT_NAME} ${ALL_FILES})



	# using filter in VS
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# tạo folder cho project 
	foreach(FILE ${ALL_FILES}) 
		get_filename_component(PARENT_DIR "${FILE}" PATH)

		# skip src or include and changes /'s to \\'s
		string(REGEX REPLACE "(\\./)?(${SOURCE_FOLDER}|${INCLUDE_FOLDER}|${OTHER_FILES_FOLDER})/?" "" GROUP "${PARENT_DIR}")
		string(REPLACE "/" "\\" GROUP "${GROUP}")

		# group into "Source Files" and "Header Files"
		if ("${FILE}" MATCHES ".*\\.cpp")
			set(GROUP "Source Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.h")
			set(GROUP "Header Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.${OTHER_FILES_EXTENSION}")
			set(GROUP "Resource Files\\${GROUP}")
		endif()

		source_group("${GROUP}" FILES "${FILE}")
	endforeach()

	# thư mục khi chạy Debug
	set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/${DEBUG_FOLDER}")
endif()
