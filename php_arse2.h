
#ifndef PHP_ARSE2_H
#define PHP_ARSE2_H

extern zend_module_entry arse2_module_entry;
#define phpext_arse2_ptr &arse2_module_entry

#ifdef PHP_WIN32
#	define PHP_ARSE2_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_ARSE2_API __attribute__ ((visibility("default")))
#else
#	define PHP_ARSE2_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(arse2);
PHP_MSHUTDOWN_FUNCTION(arse2);
PHP_RINIT_FUNCTION(arse2);
PHP_RSHUTDOWN_FUNCTION(arse2);
PHP_MINFO_FUNCTION(arse2);

PHP_FUNCTION(confirm_arse2_compiled);	/* For testing, remove later. */
PHP_FUNCTION(__construct);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(arse2)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(arse2)
*/

/* In every utility function you add that needs to use variables 
   in php_arse2_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as ARSE2_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define ARSE2_G(v) TSRMG(arse2_globals_id, zend_arse2_globals *, v)
#else
#define ARSE2_G(v) (arse2_globals.v)
#endif

#endif	/* PHP_ARSE2_H */

