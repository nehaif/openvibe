# ---------------------------------
# Finds GTK toolkit
#
# Sets GTK_FOUND
# Sets GTK_LIBRARIES
# Sets GTK_LIBRARY_DIRS
# Sets GTK_LDFLAGS
# Sets GTK_LDFLAGS_OTHERS
# Sets GTK_INCLUDE_DIRS
# Sets GTK_CFLAGS
# Sets GTK_CFLAGS_OTHERS
# ---------------------------------

INCLUDE("FindThirdPartyPkgConfig")
IF(WIN32)
	pkg_check_modules(GTK "gtk+-win32-2.0")
ELSE(WIN32)
	pkg_check_modules(GTK "gtk+-2.0")
ENDIF(WIN32)
pkg_check_modules(GTHREAD gthread-2.0)

IF(GTK_FOUND AND GTHREAD_FOUND)
	MESSAGE(STATUS "  Found GTK+...")
	INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS} ${GTHREAD_INCLUDE_DIRS})
	ADD_DEFINITIONS(${GTK_CFLAGS} ${GTHREAD_CFLAGS})
	ADD_DEFINITIONS(${GTK_CFLAGS_OTHERS} ${GTHREAD_CFLAGS_OTHERS})
	LINK_DIRECTORIES(${GTK_LIBRARY_DIRS} ${GTHREAD_LIBRARY_DIRS})
	IF(WIN32)
		SET( GTK_LIB_LIST ${GTK_LIBRARIES} ${GTHREAD_LIBRARIES} zdll)
	ELSE(WIN32)
		SET( GTK_LIB_LIST ${GTK_LIBRARIES} ${GTHREAD_LIBRARIES} z)
	ENDIF(WIN32)
	FOREACH(GTK_LIB ${GTK_LIB_LIST})
		SET(GTK_LIB1 "GTK_LIB1-NOTFOUND")
		FIND_LIBRARY(GTK_LIB1 NAMES ${GTK_LIB} PATHS ${GTK_LIBRARY_DIRS} ${GTK_LIBDIR} NO_DEFAULT_PATH)
		FIND_LIBRARY(GTK_LIB1 NAMES ${GTK_LIB})
		IF(GTK_LIB1)
			MESSAGE(STATUS "    [  OK  ] Third party lib ${GTK_LIB1}")
			TARGET_LINK_LIBRARIES(${PROJECT_NAME}-dynamic ${GTK_LIB1})
		ELSE(GTK_LIB1)
			MESSAGE(STATUS "    [FAILED] Third party lib ${GTK_LIB}")
		ENDIF(GTK_LIB1)
	ENDFOREACH(GTK_LIB)
ELSE(GTK_FOUND AND GTHREAD_FOUND)
	MESSAGE(STATUS "  FAILED to find GTK+...")
ENDIF(GTK_FOUND AND GTHREAD_FOUND)