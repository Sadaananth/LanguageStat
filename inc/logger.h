
extern void log_info( int line, const char* function, const char* fmt, ... );
extern void log_fatal( int line, const char* function, const char* fmt, ... );
			
#define LOG_INFO( fmt, ... ) 	log_info( __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
#define LOG_FATAL( fmt, ... ) 	log_fatal( __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
							
