# ---------------------------------
# Finds OBT toolkit
#
# Sets OBT_FOUND
# Sets OBT_LIBRARIES
# Sets OBT_LIBRARY_DIRS
# Sets OBT_LDFLAGS
# Sets OBT_LDFLAGS_OTHERS
# Sets OBT_INCLUDE_DIRS
# Sets OBT_CFLAGS
# Sets OBT_CFLAGS_OTHERS
#
# Adds library to target
# Adds include path
# ---------------------------------

IF(WIN32)
	FIND_PATH(PATH_OBT include/OBT.h PATHS $ENV{OV_DEP_OBT})
	IF(PATH_OBT)
		SET(OBT_FOUND TRUE)
		SET(OBT_INCLUDE_DIRS ${PATH_OBT}/include)
		IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
			SET(OBT_LIBRARIES OBT_d)
		ELSE(CMAKE_BUILD_TYPE STREQUAL "Debug")
			SET(OBT_LIBRARIES OBT)
		ENDIF(CMAKE_BUILD_TYPE STREQUAL "Debug")
		SET(OBT_LIBRARY_DIRS ${PATH_OBT}/lib )
	ENDIF(PATH_OBT)
ENDIF(WIN32)

IF(UNIX)
	INCLUDE("FindThirdPartyPkgConfig")
	pkg_check_modules(OBT OBT)
ENDIF(UNIX)

IF(OBT_FOUND)
	MESSAGE(STATUS "  Found Open Bunraku Tools (OBT)...")
	INCLUDE_DIRECTORIES(${OBT_INCLUDE_DIRS})
	ADD_DEFINITIONS(${OBT_CFLAGS})
	ADD_DEFINITIONS(${OBT_CFLAGS_OTHERS})
	LINK_DIRECTORIES(${OBT_LIBRARY_DIRS})
	FOREACH(OBT_LIB ${OBT_LIBRARIES})
		SET(OBT_LIB1 "OBT_LIB1-NOTFOUND")
		FIND_LIBRARY(OBT_LIB1 NAMES ${OBT_LIB} PATHS ${OBT_LIBRARY_DIRS} ${OBT_LIBDIR} NO_DEFAULT_PATH)
		FIND_LIBRARY(OBT_LIB1 NAMES ${OBT_LIB})
		IF(OBT_LIB1)
			MESSAGE(STATUS "    [  OK  ] Third party lib ${OBT_LIB1}")
			TARGET_LINK_LIBRARIES(${PROJECT_NAME}-dynamic ${OBT_LIB1})
		ELSE(OBT_LIB1)
			MESSAGE(STATUS "    [FAILED] Third party lib ${OBT_LIB}")
		ENDIF(OBT_LIB1)
	ENDFOREACH(OBT_LIB)

	ADD_DEFINITIONS(-DTARGET_HAS_ThirdPartyOBT)
ELSE(OBT_FOUND)
	MESSAGE(STATUS "  FAILED to find Open Bunraku Tools (OBT)...")
ENDIF(OBT_FOUND)