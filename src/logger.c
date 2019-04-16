#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static char buffer[500];

void log_info( int line, const char* function, const char* fmt, ... )
{
	unsigned int index = 0;
	va_list list;
	va_start(list,fmt);
	
	index = sprintf(&buffer[0], "\n%d ",line);
	index = index + sprintf(&buffer[index], "%s : ",function);
	index = index + sprintf(&buffer[index], fmt,list);
	
	printf("%s\n",buffer);
	va_end(list);
	memset( &buffer[0], 0, sizeof(buffer));
}

void log_fatal( int line, const char* function, const char* fmt, ... )
{
	unsigned int index = 0;
	va_list list;
	va_start(list,fmt);
	
	index = sprintf(&buffer[0], "\n%d ",line);
	index = index + sprintf(&buffer[index], "%s : ",function);
	index = index + sprintf(&buffer[index], fmt,list);
	
	printf("%s\n",buffer);
	va_end(list);
	
	fflush(stdout);	
	memset( &buffer[0], 0, sizeof(buffer));
}
