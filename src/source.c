#include <stdio.h> /* for input and output buffer handling */
#include "parse_dir.h" /* internal header to handle filesystem related functionalities */

void init_all()
{
	init_dir_core();
}

int main(int argc, char** argv)
{
	init_all();
	start_activity();
	finish_activity();
	printf("\x1b[39m\n");
	return 0;
}
