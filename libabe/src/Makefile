object = attribute.o database.o file.o relation.o translator.o version.o
rootdir = /cygdrive/d/develop/libabe
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop/gitlib
libdir = $(rootdir)/lib
libsubdir = $(rootdir)/dragon
libname = abe
vermajor = 1
libsta = lib$(libname).a
libimp = lib$(libname).dll.a
libdyn = cyg$(libname)-$(vermajor).dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++2a -O2 -g3 $(CXXINC)

all: lib install

re: clean all

lib: $(object)
	$(AR) cru $(libsta) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn) \
		-Wl,--enable-auto-image-base -Xlinker --out-implib -Xlinker $(libimp)

$(object): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(bindir) $(libdir)
	cp $(libsta) $(libimp) $(libdir)
	cp $(libdyn) $(bindir)

clean:
	rm -f *.o *.a *.dll
