object = manager.o task.o version.o
rootdir = /cygdrive/d/develop/libdld
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libsubdir = $(rootdir)/dragon
libname = dld
vermajor = 1
libsta = lib$(libname).a
libimp = lib$(libname).dll.a
libdyn = cyg$(libname)-$(vermajor).dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++2a -g3 $(CXXINC)

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
