
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_arse2.h"

/* True global resources - no need for thread safety here */
static int le_arse2;

/* {{{ arse2_module_entry
 */
zend_module_entry arse2_module_entry = {
	STANDARD_MODULE_HEADER,
	"arse2",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(arse2),
	"0.1", /* Replace with version number for your extension */
	NULL,
	NULL,
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};
/* }}} */

#ifdef COMPILE_DL_ARSE2
ZEND_GET_MODULE(arse2)
#endif

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(arse2)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "arse2 support", "enabled");
	php_info_print_table_end();
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_arse2_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_arse2_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "arse2", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */

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

/* {{{ php_arse_class_methods */
static zend_function_entry php_arse_class_methods[] = {
	PHP_ME(arse2, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
