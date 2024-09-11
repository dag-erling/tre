## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS = agrep

check_PROGRAMS = retest randtest test-str-source
EXTRA_PROGRAMS = bench
LDADD = $(LTLIBINTL)

retest_SOURCES = retest.c
retest_LDADD = ../lib/libtre.la $(LDADD)
if TRE_MULTIBYTE
check_PROGRAMS += wretest
wretest_SOURCES = retest.c
wretest_CPPFLAGS = -DWRETEST $(AM_CPPFLAGS)
wretest_LDADD = ../lib/libtre.la $(LDADD)
endif TRE_MULTIBYTE

randtest_SOURCES = randtest.c
randtest_LDADD = ../lib/libtre.la $(LDADD)

bench_SOURCES = bench.c
bench_LDADD = ../lib/libtre.la $(LDADD) -lm

test_str_source_SOURCES = test-str-source.c
test_str_source_LDADD = ../lib/libtre.la $(LDADD)

AM_CPPFLAGS = -I$(top_srcdir)/lib

EXTRA_DIST = build-tests.sh

TESTS = test-str-source retest
if TRE_MULTIBYTE
TESTS += wretest
endif TRE_MULTIBYTE
