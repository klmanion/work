## configure.ac

AC_PREREQ([2.69])
AC_INIT([work], [0.1.0], [klmanion@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CXX
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX([17], [noext], [mandatory])

AC_HEADER_STDC
AC_HEADER_ASSERT
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([locale.h])

AC_FUNC_MALLOC

## check for pkg-config
## must be installed to run autoreconf
## user installation not required, but supported
PKG_PREREQ
PKG_PROG_PKG_CONFIG([0.16])

AX_WITH_CURSES

AC_ARG_ENABLE([debug],
	      AS_HELP_STRING([--enable-debug],
			     [enable the DEBUG macro for the preprocessor]))
AM_CONDITIONAL([DEBUG], [test x"$enable_debug" = x"yes"])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
])

AC_OUTPUT

