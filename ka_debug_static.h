#ifndef _KA_DEBUG_H
#define _KA_DEBUG_H

//#define KAKA_DEBUG 0
#define KAKA_DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "ka_debug.h"
#include "unistd.h"
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#if KAKA_DEBUG
#define MARK() \
	do { \
		sprintf(kaka_buffer, "kaka: file -- %s, line -- %d, function -- %s\n", __FILE__, __LINE__, __FUNCTION__); \
		print_debug(kaka_buffer, strlen(kaka_buffer)); \
	}while(0)

#define PRINTF(fmt, arg...) \
	do { \
		sprintf(kaka_buffer, "kaka: file -- %s, line -- %d, function -- %s: ", __FILE__, __LINE__, __FUNCTION__); \
		sprintf(kaka_buffer + strlen(kaka_buffer), fmt, ##arg); \
		print_debug(kaka_buffer, strlen(kaka_buffer)); \
	}while(0)

static char kaka_buffer[500] = "";

static void print_debug(const char *fmt, unsigned int size)
{
/*
	struct tm* p;
	time_t timep;
	time(&timep);
	p = gmtime(&timep);
*/
	struct timeval tv;
        struct timezone tz;  
	struct tm *t;
	char s[500] = "";

	int fd = open("/tmp/kaka.log",O_RDWR | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR );

//	sprintf(s+strlen(s), "%d/%d/%d/ %d:%d:%d :",
//			(1900+p->tm_year),(1+p->tm_mon),p->tm_mday,
//			p->tm_hour,      p->tm_min,    p->tm_sec);
	gettimeofday(&tv, &tz);
	t = localtime(&tv.tv_sec);
	sprintf(s+strlen(s), "[%d-%d-%d %d:%d:%d.%ld]", 1900+t->tm_year, 1+t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, tv.tv_usec);

	memcpy(s+strlen(s), fmt, size);
	s[strlen(s) + size] = '\0';

	write(fd,s,strlen(s));
	close(fd);
}

/*
static void print_trace (void)
{
	void    * array[10];
	size_t  size;
	char    ** strings;
	size_t  i;

	size = backtrace(array, 10);
	strings = backtrace_symbols (array, size);
	if (NULL == strings)
	{
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
		PRINTF("%s\n", strings[i]);

	free (strings);
	strings = NULL;
}
*/


#else
#define MARK() \
	do {} while(0)
#define PRINTF(fmt, arg...) \
	do {} while(0)
#endif //KAKA_DEBUG

#endif
