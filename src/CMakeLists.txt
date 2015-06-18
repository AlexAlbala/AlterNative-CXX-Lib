##################################################
#Precompiled headers
##################################################
#SET (CMAKE_MODULE_PATH $ENV{ALTERNATIVE_TOOLS_PATH}/CMake)
#INCLUDE($ENV{ALTERNATIVE_TOOLS_PATH}/Cotire/CMake/cotire.cmake)

##################################################
#Macro for searching subdirectories
##################################################
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h *.hpp *.cpp)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        # remove ":" from path
        STRING(REGEX REPLACE ":" "_" dir_path ${dir_path})

        # convert "/" to "_"
        STRING(REGEX REPLACE "/" "_" dir_path ${dir_path})

        # remove build subdir from path
        STRING(REGEX REPLACE "${root}_" "" dir_path ${dir_path})
		
		# remove prefixes		
		STRING(REGEX REPLACE "public_" "" dir_path ${dir_path})
		STRING(REGEX REPLACE "private_" "" dir_path ${dir_path})		

		#insert again the "/" characters
		STRING(REGEX REPLACE "_" "\\\\" dir_path ${dir_path})
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

##################################################
#useful variables for make source groups
##################################################
SET(root ${CMAKE_CURRENT_SOURCE_DIR})
STRING(REGEX REPLACE ":" "_" root ${root})
STRING(REGEX REPLACE "/" "_" root ${root})

##################################################
#Enable C++11 mode
##################################################
INCLUDE($ENV{ALTERNATIVE_TOOLS_PATH}/Code/CMAKE-CXX11.cmake)

##################################################
#Add symbols definitions for GC and boost compatibilities
##################################################
#ADD_DEFINITIONS("-DAN_LIB")
ADD_DEFINITIONS("-DGC_THREADS")
IF(WIN32)
ADD_DEFINITIONS("-DWIN32_LEAN_AND_MEAN")
ENDIF()

##################################################
#Add subdirectories (public and private if exists)
##################################################
ADD_SUBDIRECTORY(public)
IF(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/private/CMakeLists.txt")
	MESSAGE("Private library found")
	ADD_SUBDIRECTORY(private)
ELSE()
	MESSAGE("Private library not found")
ENDIF()

##################################################
#Get System library code
##################################################
GET_PROPERTY(SysLib GLOBAL PROPERTY SysSRC)

##################################################
#Get files
##################################################
HEADER_DIRECTORIES(SUBDIRS)

##################################################
#Add groups
##################################################
FOREACH(subdir ${SUBDIRS})
	SET(subdir_cpp "Source Files\\${subdir}")
	SET(subdir_h "Header Files\\${subdir}")
	FILE(GLOB tmpcppPub "public/${subdir}/*.cpp")
	FILE(GLOB tmpcppPrv "private/${subdir}/*.cpp")
	SET(tmpcpp ${tmpcppPub} ${tmpcppPrv})
	SOURCE_GROUP(${subdir_cpp} FILES ${tmpcpp})
	FILE(GLOB tmphPub "public/${subdir}/*.h")
	FILE(GLOB tmphPrv "private/${subdir}/*.h")
	SET(tmph ${tmphPub} ${tmphPrv})
	SOURCE_GROUP(${subdir_h} FILES ${tmph})
ENDFOREACH()

INCLUDE_DIRECTORIES(public)
ADD_LIBRARY(System ${SysLib})
SET_TARGET_PROPERTIES(System PROPERTIES LINKER_LANGUAGE CXX)
#COTIRE(System)

##################################################
#Find boost libraries
##################################################
SET(PROJ_NAME System)
INCLUDE($ENV{ALTERNATIVE_TOOLS_PATH}/Code/CMAKE-BOOST.cmake)