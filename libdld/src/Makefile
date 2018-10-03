object = manager.o task.o version.o
rootdir = /cygdrive/d/develop/dragon/libdld
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libsubdir = $(rootdir)/dragon
libname = dld
libsta = lib$(libname).a
libdyn = cyg$(libname).dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++17 -g3 $(CXXINC)

all: lib install

re: clean all

lib: $(object)
	$(AR) cru $(libsta) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(bindir) $(libdir)
	cp $(libsta) $(libdir)
	cp $(libdyn) $(bindir)

clean:
	rm -f *.o *.a *.dll
