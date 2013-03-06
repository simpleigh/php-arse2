#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_arse2.h"

/* Class entries */
zend_class_entry *php_arse2_sc_entry;

/* {{{ php_arse_class_methods */
static zend_function_entry php_arse_class_methods[] = {
	PHP_ME(arse2, output, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
/* }}} */

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
	"0.1",
	STANDARD_MODULE_PROPERTIES
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

/* {{{ proto  Arse::output([int])
 */
PHP_METHOD(arse2, output)
{
	long l = 1;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &l) == FAILURE) {
		return;
	}

	if (l < 1) {
		php_error(E_ERROR, "Invalid number of arses");
	}

	for (; l>0; l--)
		php_printf("You're an arse!\n");

	return;
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
