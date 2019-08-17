header = manager.h task.h version.h
libheader = libdnl.h
rootdir = /cygdrive/d/develop/dragon/libdnl
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libname = dnl
libsubdir = $(rootdir)/$(libname)
vermajor = 0
libsta = lib$(libname).a
libimp = lib$(libname).dll.a
libdyn = cyg$(libname)-$(vermajor).dll

destdir = /usr/local
destincdir = $(destdir)/include

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++2a -O2 -g3 $(CXXINC)

all:

redo: clean all

install:
	mkdir -p $(destincdir)/$(libname)
	cp $(libheader) $(destincdir)
	cp $(header) $(destincdir)/$(libname)

clean:
