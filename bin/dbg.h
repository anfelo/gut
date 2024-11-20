#ifndef DBG_H_
#define DBG_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>

// INFO: This debug log can be silenced with a compiler flag
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__);
#endif

// INFO: Shows a useful error message that corresponds to the errno
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// INFO: Logs errors
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// INFO: Logs warnings
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// INFO: Logs info messages
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// INFO: This check is similar to assert but it logs the error and jumps to error handler
#define check(A, M, ...) if (!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// INFO: This assert just writes directly to the null pointer crashing the program
// This one is used in handmade hero.
// #define myassert(A) if (!(A)) { *(int *)0 = 0; }

// INFO: The sentinel just goes directly to the error when there is an unwanted state
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// INFO: Checks that the memory allocated is not NULL
#define check_mem(A) check((A), "Out of memory.")

// INFO: The check debug is the same as the check but it performs a debug log
// which can be silenced by the compiler flag
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
