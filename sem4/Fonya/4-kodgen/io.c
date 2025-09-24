#include "stdio.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

unsigned read_unsigned()
{
	unsigned ret;
	fscanf( stdin, "%u", &ret );
	return ret;
}

int read_signed()
{
	int ret;
	fscanf( stdin, "%d", &ret );
	return ret;
}

int read_boolean()
{
	char ret[256];
	fscanf( stdin, "%s", ret );
	return !strcmp(ret,"true");
}

void write_unsigned( unsigned num )
{
	fprintf( stdout, "%u\n", num );
}

void write_signed( int num )
{
	fprintf( stdout, "%d\n", num );
}

void write_boolean( int num )
{
	num &= 1;
	if( num )
		fprintf( stdout, "true\n" );
	else
		fprintf( stdout, "false\n" );
}

void write_char(char c) {
    fprintf(stdout, "%c\n", c);
}

void write_str(char* cs, size_t len) {
    write(1, cs, len);
}
