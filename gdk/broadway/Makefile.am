## Process this file with automake to produce Makefile.in
include $(top_srcdir)/Makefile.decl

libgdkincludedir = $(includedir)/gtk-3.0/gdk

INCLUDES =			\
	-DG_LOG_DOMAIN=\"Gdk\"	\
	-DGDK_COMPILATION	\
	-I$(top_srcdir)		\
	-I$(top_srcdir)/gdk	\
	-I$(top_builddir)/gdk	\
	$(GTK_DEBUG_FLAGS)	\
	$(GDK_DEP_CFLAGS)

LDADDS = $(GDK_DEP_LIBS)

noinst_LTLIBRARIES = libbroadway.la libgdk-broadway.la

libbroadway_la_SOURCES =		\
	broadway.h			\
	broadway.c

clienthtml.h: client.html
	$(PERL) ./toarray.pl client.html client_html > $@

broadwayjs.h: broadway.js
	$(PERL) ./toarray.pl broadway.js broadway_js > $@

# built headers that don't get installed
broadway_built_private_headers =	\
	clienthtml.h			\
	broadwayjs.h

broadway_built_sources =		\
	${broadway_built_private_headers}

libgdk_broadway_la_SOURCES =		\
	${broadway_built_private_headers}\
	gdkbroadwaydisplaymanager.h	\
	gdkcursor-broadway.c	\
	gdkdevice-broadway.h	\
	gdkdevice-broadway.c	\
	gdkdevicemanager-broadway.h \
	gdkdevicemanager-broadway.c \
	gdkdisplay-broadway.c	\
	gdkdisplay-broadway.h	\
	gdkdisplaymanager-broadway.c	\
	gdkdnd-broadway.c	\
	gdkeventsource.c	\
	gdkeventsource.h	\
	gdkglobals-broadway.c	\
	gdkim-broadway.c	\
	gdkkeys-broadway.c	\
	gdkmain-broadway.c	\
	gdkproperty-broadway.c	\
	gdkscreen-broadway.c	\
	gdkscreen-broadway.h	\
	gdkselection-broadway.c	\
	gdktestutils-broadway.c	\
	gdkvisual-broadway.c	\
	gdkwindow-broadway.c	\
	gdkwindow-broadway.h	\
	gdkprivate-broadway.h

libgdk_broadway_la_LIBADD = libbroadway.la

MAINTAINERCLEANFILES = $(broadway_built_sources)
EXTRA_DIST += $(broadway_built_sources)

BUILT_SOURCES = $(broadway_built_sources)

noinst_PROGRAMS = broadway-demo
broadway_demo_LDADD = -lz -lcairo libbroadway.la -lglib-2.0

-include $(top_srcdir)/git.mk
