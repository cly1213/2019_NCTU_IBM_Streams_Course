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

SPL_TYPES = build/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.o \
            build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o \
            build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Flight.o \
                build/operator/FlightGate.o \
                build/operator/TCPSink_3.o 
SPL_SO_BINS = bin/Flight.so \
              bin/FlightGate.so \
              bin/TCPSink_3.so 

SPL_ADL_FILE = application.Sender.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/17_TCP_aw/output/application.Sender')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application.Sender.sab

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

build/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.o: \
	    src/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.h \
	    src/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring fly_num,rstring depDate,rstring origin,rstring dest>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.cpp

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

-include build/operator/Flight.d
build/operator/Flight.o: \
	    src/operator/Flight.h \
	    src/operator/Flight.cpp\
	    build/dep/operator/Flight.dep \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Flight'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.Sender.adl\" -c $(SPL_CXXFLAGS) src/operator/Flight.cpp

-include build/operator/FlightGate.d
build/operator/FlightGate.o: \
	    src/operator/FlightGate.h \
	    src/operator/FlightGate.cpp\
	    build/dep/operator/FlightGate.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FlightGate'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.Sender.adl\" -c $(SPL_CXXFLAGS) src/operator/FlightGate.cpp

-include build/operator/TCPSink_3.d
build/operator/TCPSink_3.o: \
	    src/operator/TCPSink_3.h \
	    src/operator/TCPSink_3.cpp\
	    build/dep/operator/TCPSink_3.dep \
	    src/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TCPSink_3'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.Sender.adl\" -c $(SPL_CXXFLAGS) src/operator/TCPSink_3.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOFlight = \
	    build/operator/Flight.o \
	    build/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.o \
	    build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o 

bin/Flight.so: \
	$(SOFlight) \
	build/dep/Flight.so \
	build/ldOptions
	@echo ' [LD-so] so Flight'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Flight.so -fPIC -shared $(SOFlight) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_system $(SPL_LDFLAGS)

SOFlightGate = \
	    build/operator/FlightGate.o \
	    build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o \
	    build/type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.o 

bin/FlightGate.so: \
	$(SOFlightGate) \
	build/dep/FlightGate.so \
	build/ldOptions
	@echo ' [LD-so] so FlightGate'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FlightGate.so -fPIC -shared $(SOFlightGate) $(SPL_LDFLAGS)

SOTCPSink_3 = \
	    build/operator/TCPSink_3.o \
	    build/type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.o \
	    build/type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.o 

bin/TCPSink_3.so: \
	$(SOTCPSink_3) \
	build/dep/TCPSink_3.so \
	build/ldOptions
	@echo ' [LD-so] so TCPSink_3'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TCPSink_3.so -fPIC -shared $(SOTCPSink_3) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application.Sender
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application.Sender.sab bin/sab

bundle: application.Sender.sab

-include build/dep/application.Sender.sab.d
application.Sender.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application.Sender.sab.d bin/standalone.exe
	@echo ' [Bundle] application.Sender.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application.Sender.sab

