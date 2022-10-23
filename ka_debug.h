#ifndef _KA_DEBUG_H
#define _KA_DEBUG_H

//#define KAKA_DEBUG 0
#define KAKA_DEBUG 1

extern char kaka_buffer[500];
extern void print_debug(const char *fmt, unsigned int size);
void print_trace(void);
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

#else
#define MARK() \
	do {} while(0)
#define PRINTF(fmt, arg...) \
	do {} while(0)
#endif //KAKA_DEBUG

#endif
