dnl $Id$
dnl config.m4 for extension light

PHP_ARG_ENABLE(light, whether to enable light support, [  --enable-light           Enable light support])

if test "$PHP_LIGHT" != "no"; then
	PHP_NEW_EXTENSION(light, php_light.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi