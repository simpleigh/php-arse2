
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_arse2.h"

/* True global resources - no need for thread safety here */
static int le_arse2;

/* Class entries */
zend_class_entry *php_arse2_sc_entry;

/* {{{ arse2_module_entry
 */
zend_module_entry arse2_module_entry = {
	STANDARD_MODULE_HEADER,
	"arse2",
	NULL,
	PHP_MINIT(arse2),
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_ARSE2_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

/* {{{ php_arse_class_methods */
static zend_function_entry php_arse_class_methods[] = {
	PHP_ME(arse2, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(arse2)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Arse", php_arse_class_methods);
	php_arse2_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}
/* }}} */

#ifdef COMPILE_DL_ARSE2
ZEND_GET_MODULE(arse2)
#endif

/* {{{ proto  int Arse::__construct()
   __constructor for Arse. */
PHP_METHOD(arse2, __construct)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_error(E_WARNING, "__construct: not yet implemented");
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
