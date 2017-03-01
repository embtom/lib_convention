project(lib_convention)

SET (SOURCES src/lib_convention__mem.c)

if (TARGET lib_FREERTOS)
    SET(PROJECT_DEFINES "-DCONFIG__FREERTOS_ALLOC")
    SET(PROJECT_LINK_LIBRARIES lib_FREERTOS)
else()
	SET(PROJECT_DEFINES "-DCONFIG__UNIX_ALLOC")
endif()


add_library(${PROJECT_NAME} STATIC ${SOURCES} )
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_DEFINES})

