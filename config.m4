dnl $Id$
dnl config.m4 for extension light

PHP_ARG_ENABLE(light, whether to enable light support, [  --enable-light           Enable light support])

if test "$PHP_LIGHT" != "no"; then
	PHP_NEW_EXTENSION(light, php_light.c \
		classes/classes.c \
		classes/application/application.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1,, yes)
	PHP_ADD_BUILD_DIR($ext_builddir/classes)
	PHP_ADD_BUILD_DIR($ext_builddir/classes/application)
fi