#include <string.h> /* for memory related functions */
#include <sys/types.h> /* for stat() function */
#include <sys/stat.h>  /* for stat() function */
#include <stdlib.h> /* for malloc() and free() functions */
#include <stdio.h> /* for input and output buffer handling */
#include <errno.h> /* to check error status set by gnu library calls */

#include "updatelang.h" /* Internal header to declare functions defined in this file */
#include "user_types.h"	/* Header to declare common user defined types */
#include "presenter.h" /* Header to call presenter functions */

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

project_stat_t project_stat = {
		0,
		{ 0, 0.0, "C", '\0', Yellow },
		{ 0, 0.0, "C++", '\0', Blue },
		{ 0, 0.0, "Shell" , '\0', Green },
		{ 0, 0.0, "Python", '\0', Magenta },
		{ 0, 0.0, "Perl", '\0',  Red },
		{ 0, 0.0, "Java", '\0', Cyan },
		{ 0, 0.0, "HTML", '\0', LightYellow },
		{ 0, 0.0, "CSS", '\0', LightBlue },
};

static unsigned int getlanguage_key(const char* extension);
static void update_parsed_stat( const char* file_extension, unsigned int extn_length, unsigned int file_size);
static void calculate_percent(void);

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
			project_stat.c_stat.size = project_stat.c_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
			
		case 1:
			project_stat.cpp_stat.size = project_stat.cpp_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
		
		case 2:
			project_stat.py_stat.size = project_stat.py_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 3:
			project_stat.pl_stat.size = project_stat.pl_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 4:
			project_stat.java_stat.size = project_stat.java_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
												
		case 5:
			project_stat.html_stat.size = project_stat.html_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		case 6:
			project_stat.sh_stat.size = project_stat.sh_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
									
		case 7:
			project_stat.css_stat.size = project_stat.css_stat.size + (unsigned long long)file_size;
			project_stat.total_size = project_stat.total_size + (unsigned long long)file_size;
			break;
						
		default:
			break;
	}
	free(extension);
}

static void calculate_percent()
{
	lang_stat_t* parse_ptr = &project_stat.c_stat;
	lang_stat_t* end_ptr = &project_stat.css_stat;
	
	while( parse_ptr <= end_ptr )
	{
		parse_ptr->percent = (double)parse_ptr->size / (double)project_stat.total_size;
		parse_ptr->percent = parse_ptr->percent * 100;
		parse_ptr++;
	}
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
	calculate_percent();
	present_output();
}
