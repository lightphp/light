/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <zend_API.h>
#include <zend.h>
#include <php.h>
#include "main/php_ini.h"
#include "application.h"

zend_class_entry *Application_ce_ptr = NULL;

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(application_0_args, 0, 0, 0)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(application_0_args_string, 0, 0, IS_STRING, "Application", IS_FALSE)
ZEND_END_ARG_INFO()
/* }}} */

zend_function_entry Application_class_functions[] = { /* {{{ */
	PHP_ME(Application, __construct, application_0_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Application, run, application_0_args_string, ZEND_ACC_PUBLIC)
	PHP_ME(Application, bind, application_0_args_string, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
/* }}} */

void light_register_Application_class(void) /* {{{ */
{
	zend_class_entry ce;

	INIT_NS_CLASS_ENTRY(ce, "Light", "Application", Application_class_functions);
	ce.create_object = NULL;
	Application_ce_ptr = zend_register_internal_class(&ce);

	if (!Application_ce_ptr) {
		zend_error(E_ERROR, "Failed to register Application class.");
		return;
	}
}
/* }}} */

PHP_METHOD(Application, __construct) /* {{{ */
{
	return_value = getThis();
}
/* }}} */

PHP_METHOD(Application, run) /* {{{ */
{
	char *str = "run method called";
	zend_string *result = zend_string_init(str, strlen(str), 0);
	RETURN_NEW_STR(result);
}
/* }}} */

PHP_METHOD(Application, bind) /* {{{ */
{
	char *str = "bind method called";
	zend_string *result = zend_string_init(str, strlen(str), 0);
	RETURN_NEW_STR(result);
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