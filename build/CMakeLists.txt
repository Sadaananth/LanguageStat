#only Supports Unix Variants
if(UNIX AND NOT APPLE)
	set (PROJECT LanguageStat)
	project (${PROJECT})
	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
	
	set(BIN_PATH ./bin/)
	set(SOURCE_PATH ../src/)
	
	add_definitions( -DUSE_SYSTEM_CMD )
	
	include_directories(
		../inc/
	)
	
	set( SOURCES 
		${SOURCE_PATH}source.c
		${SOURCE_PATH}parse_dir.c
		${SOURCE_PATH}updatelang.c
		${SOURCE_PATH}logger.c
	)
	
	add_executable( ${PROJECT} ${SOURCES}  )

endif()
