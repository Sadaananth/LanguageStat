#include <string.h> /* for memory related functions */
#include <sys/types.h> /* for stat() function */
#include <sys/stat.h>  /* for stat() function */
#include <stdlib.h> /* for malloc() and free() functions */
#include <stdio.h> /* for input and output buffer handling */
#include <errno.h> /* to check error status set by gnu library calls */

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
}project_stat_t;

typedef  struct
{
	unsigned int key;
	const char* lang_ext;
}lang_key_hashtable_t;

/*
 * Making as global variable 
 * as variable will reside in data segment not in stack
 * */
static unsigned char file_path[550];
static lang_key_hashtable_t lang_key_hashtable[] = 
{
	{ 0, "c" },
	{ 1, "cpp" },
	{ 2, "py" },
	{ 3, "pl" },
	{ 4, "java" },
	{ 5, "html" },
	{ 6, "sh" },
	{ 7, "css" }
};

static unsigned int hastable_size = sizeof(lang_key_hashtable) / sizeof(lang_key_hashtable_t);
static project_stat_t project_stat = { 0 };

unsigned int getlanguage_key(const char* extension)
{
	unsigned int index = hastable_size;
		
	for( index = 0; index <= ( hastable_size - 1 ); index++ )
	{
		if( strcmp( extension, lang_key_hashtable[index].lang_ext ) == 0 )
		{
			return index;
		}
	}
	return index;
}

static void update_parsed_stat( const char* file_extension, unsigned int extn_length, unsigned int file_size)
{
	char* extension;
	
	extension = (char *)malloc( ( extn_length + 1 ) * sizeof(char) );
	(void)memset(&extension[0], 0, extn_length + 1 );
	(void)memcpy(&extension[0], file_extension, extn_length);
		
	switch( getlanguage_key( extension ) )
	{
		case 0:
			project_stat.c_size = project_stat.c_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
			
		case 1:
			project_stat.cpp_size = project_stat.cpp_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
		
		case 2:
			project_stat.py_size = project_stat.py_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 3:
			project_stat.pl_size = project_stat.pl_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 4:
			project_stat.java_size = project_stat.java_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
												
		case 5:
			project_stat.html_size = project_stat.html_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 6:
			project_stat.sh_size = project_stat.sh_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
									
		case 7:
			project_stat.css_size = project_stat.css_size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		default:
			break;
	}
	free(extension);
}

void update_file_type(const char* folder, const char* file_name)
{
	unsigned int file_name_length = strlen(file_name);
	unsigned int folder_name_length = strlen(folder);
	int index;
	struct stat file_stat;
	
	(void)memset( &file_path[0], 0, sizeof(file_path) );
	
	for( index = ( file_name_length - 1 ) ; index >= 0 ; index-- )
	{
		if( file_name[index] == '.' )
		{
			/**
			 * extension found 
			 * */
			 (void)memcpy(&file_path[0], folder, folder_name_length );
			 file_path[folder_name_length] = '/';
			 (void)memcpy(&file_path[folder_name_length + 1], file_name, file_name_length );
			 if( 0 == stat(file_path, &file_stat) )
			 {
				update_parsed_stat( &file_name[index + 1], file_name_length - index - 1 , file_stat.st_size );
			 }
			 else
			 {
				printf("\nfile %s is not valid : error num %s", file_path, strerror(errno) );
			 }			 
			 break;
		}
		else
		{
			/**
			 * Continue to search for extension 
			 * */
		}
	}
	
}

void finish_activity()
{
	printf("\nConsolidated Values ");
	printf("\nTotal Size in bytes : %llu", project_stat.total_size );
	printf("\nC Size in bytes : %llu", project_stat.c_size );
	printf("\nCPP Size in bytes : %llu", project_stat.cpp_size );
	printf("\nsh Size in bytes : %llu", project_stat.sh_size );
	printf("\nPython Size in bytes : %llu", project_stat.py_size );
	printf("\nPerl Size in bytes : %llu", project_stat.pl_size );
	printf("\nHTML Size in bytes : %llu", project_stat.html_size );
	printf("\nJava Size in bytes : %llu", project_stat.java_size );
	printf("\nCSS Size in bytes : %llu", project_stat.css_size );
}
