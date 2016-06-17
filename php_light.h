#ifndef PHP_LIGHT_H
#define PHP_LIGHT_H

#include <php.h>

extern zend_module_entry light_module_entry;
#define phpext_light_ptr &light_module_entry

#define LIGHT_NAME				"Light"
#define LIGHT_VERSION			"0.1.0-dev"
#define LIGHT_AUTHOR			"loss"
#define LIGHT_URL				"https://lightphp.com"
#define LIGHT_COPYRIGHT			"Copyright (c) 2015-2016 by loss"
#define LIGHT_COPYRIGHT_SHORT	"Copyright (c) 2015-2016"

#ifdef PHP_WIN32
#	define PHP_LIGHT_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_LIGHT_API __attribute__ ((visibility("default")))
#else
#	define PHP_LIGHT_API ZEND_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(light)
	zend_long global_int;
	char *global_str;
ZEND_END_MODULE_GLOBALS(light)

#define LIGHT_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(light, v)

#if defined(ZTS) && defined(COMPILE_DL_LIGHT)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_LIGHT_H */