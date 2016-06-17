/* $Id$ */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <php.h>

void light_register_Application_class(void);

extern zend_class_entry *Application_ce_ptr;

PHP_METHOD(Application, __construct);
PHP_METHOD(Application, run);
PHP_METHOD(Application, bind);

#endif // #ifndef APPLICATION_H