#include <string.h> /* for memory related functions */
#include <sys/types.h> /* for stat() function */
#include <sys/stat.h>  /* for stat() function */

#include "updatelang.h" /* Internal header to declare functions defined in this file */

typedef struct 
{
	unsigned long long total_size;
	unsigned long long c_size;
	unsigned long long cpp_size;
	unsigned long long sh_size;
	unsigned long long py_size;
	unsigned long long pl_size;
	unsigned long long java_size;
	unsigned long long html_size;
	unsigned long long css_size;
	unsigned long long java_size;
}project_stat;

/*
 * Making as global variable 
 * as variable will reside in data segment not in stack
 * */
static unsigned char file_path[550];


static void update_parsed_stat( const char* file_extension, unsigned int extn_length, unsigned int file_size)
{
	char* extension;
	
	extension = (char *)malloc( ( extn_length + 1 ) * sizeof(char) );
	(void)memset(&extension[0], 0, extn_length + 1 );
	(void)memcpy(&extension[0], file_extension, extn_length);
	
	switch( (const char*)extension )
	{
		case "c":
			project_stat.c_size = project_stat.c_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
			
		case "cpp":
			project_stat.cpp_size = project_stat.cpp_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "html":
			project_stat.html_size = project_stat.html_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "sh":
			project_stat.sh_size = project_stat.sh_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "py":
			project_stat.py_size = project_stat.py_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "pl":
			project_stat.pl_size = project_stat.pl_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "css":
			project_stat.css_size = project_stat.css_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case "java":
			project_stat.java_size = project_stat.java_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		default:
			break;
	}
}

void update_file_type(const char* folder, const char* file_name)
{
	unsigned int length = strlen(file_name);
	struct stat file_stat;
	
	(void)memset( &file_path[0], 0, sizeof(file_path) );
	
	for( unsigned int index = ( length - 1 ) ; index >= 0 ; index-- )
	{
		if( file_name[index] == "." )
		{
			/**
			 * extension found 
			 * */
			 (void)memcpy(&file_path[0], file_name, length );
			 printf("\nFile %s is having extension ", file_path);
			 break;
		}
		else
		{
			/**
			 * Continue to search for extension 
			 * */
		}
	}
	if( 0 == stat(file_path, file_stat) )
	{
		update_parsed_stat( &file_name[index + 1], length - index - 1 , file_stat->st_size );
	}
	else
	{
		printf("\nfile %s is not valid ", file_path);
	}
	
}

