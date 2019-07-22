# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

SHELL=/bin/bash
ifeq ($(CXX),)
  CXX=g++
endif
ifeq ($(CXX_LN),)
  CXX_LN=g++
endif
PKGCONFIG := /opt/ibm/InfoSphere_Streams/4.3.0.3/bin/dst-pe-pkg-config-alternative.sh
SPL_BUNDLE_BUILDER := /opt/ibm/InfoSphere_Streams/4.3.0.3/system/impl/bin/spl-bundle-builder
SO_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
SO_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
SO_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(SO_INCLUDE) -O3 -DNDEBUG  -std=gnu++98 
SPL_LDFLAGS = $(SO_LIB)

SPL_TYPES = build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o \
            build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Flight_gate.o \
                build/operator/TCPSink_2.o 
SPL_SO_BINS = bin/Flight_gate.so \
              bin/TCPSink_2.so 

SPL_ADL_FILE = application.Receiver.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/17_TCP_aw/output/application.Receiver')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application.Receiver.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o: \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{server,client}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.cpp

build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o: \
	    src/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h \
	    src/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring fly_num,rstring depDate,rstring origin,rstring dest,rstring gate>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Flight_gate.d
build/operator/Flight_gate.o: \
	    src/operator/Flight_gate.h \
	    src/operator/Flight_gate.cpp\
	    build/dep/operator/Flight_gate.dep \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h \
	    src/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Flight_gate'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.Receiver.adl\" -c $(SPL_CXXFLAGS) src/operator/Flight_gate.cpp

-include build/operator/TCPSink_2.d
build/operator/TCPSink_2.o: \
	    src/operator/TCPSink_2.h \
	    src/operator/TCPSink_2.cpp\
	    build/dep/operator/TCPSink_2.dep \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h \
	    src/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TCPSink_2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.Receiver.adl\" -c $(SPL_CXXFLAGS) src/operator/TCPSink_2.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOFlight_gate = \
	    build/operator/Flight_gate.o \
	    build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o \
	    build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o 

bin/Flight_gate.so: \
	$(SOFlight_gate) \
	build/dep/Flight_gate.so \
	build/ldOptions
	@echo ' [LD-so] so Flight_gate'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Flight_gate.so -fPIC -shared $(SOFlight_gate) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_system $(SPL_LDFLAGS)

SOTCPSink_2 = \
	    build/operator/TCPSink_2.o \
	    build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o \
	    build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o 

bin/TCPSink_2.so: \
	$(SOTCPSink_2) \
	build/dep/TCPSink_2.so \
	build/ldOptions
	@echo ' [LD-so] so TCPSink_2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TCPSink_2.so -fPIC -shared $(SOTCPSink_2) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_system $(SPL_LDFLAGS)

standalone: bin/standalone.exe

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone.exe: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/standalone.exe build/standalone/standalone.o $(SO_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/application.Receiver
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application.Receiver.sab bin/sab

bundle: application.Receiver.sab

-include build/dep/application.Receiver.sab.d
application.Receiver.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application.Receiver.sab.d bin/standalone.exe
	@echo ' [Bundle] application.Receiver.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application.Receiver.sab

