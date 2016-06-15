#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_light.h"
#include "ext/standard/info.h"

ZEND_DECLARE_MODULE_GLOBALS(light)

static int le_light;

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("light.int", "42", PHP_INI_ALL, OnUpdateLong, global_int, zend_light_globals, light_globals)
    STD_PHP_INI_ENTRY("light.str", "string", PHP_INI_ALL, OnUpdateString, global_str, zend_light_globals, light_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_light_init_globals
 */
static void php_light_init_globals(zend_light_globals *light_globals)
{
	light_globals->global_int = 42;
	light_globals->global_str = "string";
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(light)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(light)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(light)
{
#if defined(COMPILE_DL_LIGHT) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(light)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(light)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "light support", "enabled");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ light_functions[]
 */
const zend_function_entry light_functions[] = {
	PHP_FE_END
};
/* }}} */

/* {{{ light_module_entry
 */
zend_module_entry light_module_entry = {
	STANDARD_MODULE_HEADER,
	"light",
	light_functions,
	PHP_MINIT(light),
	PHP_MSHUTDOWN(light),
	PHP_RINIT(light),
	PHP_RSHUTDOWN(light),
	PHP_MINFO(light),
	PHP_LIGHT_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LIGHT
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(light)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */