#ifndef _KA_DEBUG_H
#define _KA_DEBUG_H

#define MARK() pr_info("kaka: file -- %s, line -- %d, function -- %s\n", __FILE__, __LINE__, __FUNCTION__)

#define PRINTK(fmt, arg...) pr_info("kaka: file -- %s, line -- %d, function -- %s\t"fmt, __FILE__, __LINE__, __FUNCTION__, ##arg)

#define COMM_MARK(my_comm) \
do { \
	if (0 == strcmp(current->comm, my_comm)) \
		MARK(); \
} while(0)

#define COMM_PRINTK(my_comm, fmt, ...) \
do { \
	if (0 == strcmp(current->comm, my_comm)) \
		pr_info("kaka: file -- %s, line -- %d, function -- %s\t"fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
} while(0)

#endif
