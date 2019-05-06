
#define Black 			"\x1b[30m"
#define Red 			"\x1b[31m"
#define Green 			"\x1b[32m"
#define Yellow			"\x1b[33m"
#define Blue			"\x1b[34m"	
#define Magenta			"\x1b[35m"
#define Cyan			"\x1b[36m"	
#define White			"\x1b[37m"	
#define Default			"\x1b[39m"
#define LightGray		"\x1b[90m"	
#define LightRed		"\x1b[91m"	
#define LightGreen		"\x1b[92m"	
#define LightYellow		"\x1b[93m"	
#define LightBlue		"\x1b[94m"	
#define LightMagenta	"\x1b[95m"	
#define LightCyan		"\x1b[96m"	
#define LightWhite		"\x1b[97m"	

typedef  struct
{
	unsigned long long size;
	float percent;
	const char* lang_name;
	char zero;
	const char* color;
}lang_stat_t;

typedef struct 
{
	unsigned long long total_size;
	lang_stat_t c_stat;
	lang_stat_t cpp_stat;
	lang_stat_t sh_stat;
	lang_stat_t py_stat;
	lang_stat_t pl_stat;
	lang_stat_t java_stat;
	lang_stat_t html_stat;
	lang_stat_t css_stat;
	lang_stat_t make_stat;
	lang_stat_t cmake_stat;
}project_stat_t;


