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

SPL_TYPES = build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/SR.o \
                build/operator/SROutput1.o \
                build/operator/sink1.o 
SPL_SO_BINS = bin/SR.so \
              bin/SROutput1.so \
              bin/sink1.so 

SPL_ADL_FILE = application._split.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/05_split_mm/output/application._split')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._split.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o: \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{csv,txt,bin,block,line}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp

build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o: \
	    src/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.h \
	    src/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,rstring datetime,float64 price,uint32 vol>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/SR.d
build/operator/SR.o: \
	    src/operator/SR.h \
	    src/operator/SR.cpp\
	    build/dep/operator/SR.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SR'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._split.adl\" -c $(SPL_CXXFLAGS) src/operator/SR.cpp

-include build/operator/SROutput1.d
build/operator/SROutput1.o: \
	    src/operator/SROutput1.h \
	    src/operator/SROutput1.cpp\
	    build/dep/operator/SROutput1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SROutput1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._split.adl\" -c $(SPL_CXXFLAGS) src/operator/SROutput1.cpp

-include build/operator/sink1.d
build/operator/sink1.o: \
	    src/operator/sink1.h \
	    src/operator/sink1.cpp\
	    build/dep/operator/sink1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] sink1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._split.adl\" -c $(SPL_CXXFLAGS) src/operator/sink1.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOSR = \
	    build/operator/SR.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/SR.so: \
	$(SOSR) \
	build/dep/SR.so \
	build/ldOptions
	@echo ' [LD-so] so SR'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SR.so -fPIC -shared $(SOSR) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOSROutput1 = \
	    build/operator/SROutput1.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/SROutput1.so: \
	$(SOSROutput1) \
	build/dep/SROutput1.so \
	build/ldOptions
	@echo ' [LD-so] so SROutput1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SROutput1.so -fPIC -shared $(SOSROutput1) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOsink1 = \
	    build/operator/sink1.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/sink1.so: \
	$(SOsink1) \
	build/dep/sink1.so \
	build/ldOptions
	@echo ' [LD-so] so sink1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/sink1.so -fPIC -shared $(SOsink1) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOsink6 = \
	    build/operator/sink1.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/sink6.so: \
	$(SOsink6) \
	build/dep/sink6.so \
	build/ldOptions
	@echo ' [LD-so] so sink6'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/sink6.so -fPIC -shared $(SOsink6) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOsink15 = \
	    build/operator/sink1.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/sink15.so: \
	$(SOsink15) \
	build/dep/sink15.so \
	build/ldOptions
	@echo ' [LD-so] so sink15'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/sink15.so -fPIC -shared $(SOsink15) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOsink24 = \
	    build/operator/sink1.o \
	    build/type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.o 

bin/sink24.so: \
	$(SOsink24) \
	build/dep/sink24.so \
	build/ldOptions
	@echo ' [LD-so] so sink24'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/sink24.so -fPIC -shared $(SOsink24) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._split
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._split.sab bin/sab

bundle: application._split.sab

-include build/dep/application._split.sab.d
application._split.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._split.sab.d bin/standalone.exe
	@echo ' [Bundle] application._split.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._split.sab

