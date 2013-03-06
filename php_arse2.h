#ifndef PHP_ARSE2_H
#define PHP_ARSE2_H

extern zend_module_entry arse2_module_entry;
#define phpext_arse2_ptr &arse2_module_entry

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(arse2);
PHP_METHOD(arse2, output);

#endif	/* PHP_ARSE2_H */
