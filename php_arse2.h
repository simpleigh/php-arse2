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
PHP_METHOD(arse2, __construct);
PHP_METHOD(arse2, output);

#endif	/* PHP_ARSE2_H */
