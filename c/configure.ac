#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([leetcode],[0.1],[lilinj2000@163.com])
#AC_CONFIG_SRCDIR([String.cpp])
#AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_STRERROR_R
AC_CHECK_FUNCS([select strdup strtol])

AC_CONFIG_FILES([Makefile
		src/Makefile
		unittest/Makefile])

AC_OUTPUT
