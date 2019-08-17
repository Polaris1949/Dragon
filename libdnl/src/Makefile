object = manager.o task.o version.o
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
destbindir = $(destdir)/bin
destlibdir = $(destdir)/lib

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++2a -O2 $(CXXINC)

all: lib install

re: clean all

lib: $(object)
	$(AR) cru $(libsta) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn) -Wl,--enable-auto-image-base -Xlinker --out-implib -Xlinker $(libimp)

$(object): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(destbindir) $(destlibdir)
	cp $(libsta) $(libimp) $(destlibdir)
	cp $(libdyn) $(destbindir)

clean:
	rm -f *.o *.a *.dll
