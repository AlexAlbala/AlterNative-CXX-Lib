CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(sys)

##################################################
#Get files
##################################################
FILE(GLOB_RECURSE SysLib *.h *.cpp *.hpp)

##################################################
#LINK LIBRARIES
##################################################
SET_PROPERTY(GLOBAL PROPERTY SysSRC "${SysLib}")