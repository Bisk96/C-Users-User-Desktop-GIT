## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = admin

admin_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
    	greeting.c greeting.h \
	verifier.c verifier.h \
	seance.c seance.h \
	functions.c function.h\
	finals.c finals.h \
	fonctions.c fonctions.h

admin_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

