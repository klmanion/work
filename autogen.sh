#!/bin/sh -

if [ -e Makefile ]; then
	make distclean
fi

autoreconf --verbose --force --install || exit 0;

env CXX=clang++ CPPFLAGS="-Wall -pedantic" ./configure "$@"
exit $?;
