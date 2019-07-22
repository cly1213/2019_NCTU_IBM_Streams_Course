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

SPL_TYPES = build/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 
SPL_FUNCTIONS = build/function/application/division.o \
                build/function/application/multiplication.o \
                build/function/application/subtraction.o \
                build/function/application/addition.o 
SPL_OPERATORS = build/operator/Aop.o \
                build/operator/writter.o 
SPL_SO_BINS = bin/Aop.so \
              bin/writter.so 

SPL_ADL_FILE = application._splfunction_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/15_splfunction_aw/output/application._splfunction_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._splfunction_aw.sab

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

build/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.o: \
	    src/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.h \
	    src/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring op,uint32 op1,uint32 op2,uint32 result>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Aop.d
build/operator/Aop.o: \
	    src/operator/Aop.h \
	    src/operator/Aop.cpp\
	    build/dep/operator/Aop.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Aop'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Aop.cpp

-include build/operator/writter.d
build/operator/writter.o: \
	    src/operator/writter.h \
	    src/operator/writter.cpp\
	    build/dep/operator/writter.dep \
	    src/function/application/subtraction.h \
	    src/function/application/addition.h \
	    src/function/application/multiplication.h \
	    src/function/application/division.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] writter'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/writter.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

-include build/function/application/division.d
build/function/application/division.o: \
	    src/function/application/division.h \
	    src/function/application/division.cpp\
	    build/dep/function/application/division.dep \
	    build/cppOptions \
	    | build/function/application
	@echo ' [CXX-function] application::division'
	@$(CXX) -o $@ -c -MD -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" $(SPL_CXXFLAGS) src/function/application/division.cpp

-include build/function/application/multiplication.d
build/function/application/multiplication.o: \
	    src/function/application/multiplication.h \
	    src/function/application/multiplication.cpp\
	    build/dep/function/application/multiplication.dep \
	    build/cppOptions \
	    | build/function/application
	@echo ' [CXX-function] application::multiplication'
	@$(CXX) -o $@ -c -MD -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" $(SPL_CXXFLAGS) src/function/application/multiplication.cpp

-include build/function/application/subtraction.d
build/function/application/subtraction.o: \
	    src/function/application/subtraction.h \
	    src/function/application/subtraction.cpp\
	    build/dep/function/application/subtraction.dep \
	    build/cppOptions \
	    | build/function/application
	@echo ' [CXX-function] application::subtraction'
	@$(CXX) -o $@ -c -MD -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" $(SPL_CXXFLAGS) src/function/application/subtraction.cpp

-include build/function/application/addition.d
build/function/application/addition.o: \
	    src/function/application/addition.h \
	    src/function/application/addition.cpp\
	    build/dep/function/application/addition.dep \
	    build/cppOptions \
	    | build/function/application
	@echo ' [CXX-function] application::addition'
	@$(CXX) -o $@ -c -MD -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._splfunction_aw.adl\" $(SPL_CXXFLAGS) src/function/application/addition.cpp

build/function/application:
	-@mkdir -m 755 -p build/function/application

sos: $(SPL_SO_BINS)

SOAop = \
	    build/operator/Aop.o \
	    build/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 

bin/Aop.so: \
	$(SOAop) \
	build/dep/Aop.so \
	build/ldOptions
	@echo ' [LD-so] so Aop'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Aop.so -fPIC -shared $(SOAop) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOwritter = \
	    build/operator/writter.o \
	    build/function/application/addition.o \
	    build/function/application/division.o \
	    build/function/application/multiplication.o \
	    build/function/application/subtraction.o \
	    build/type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.o 

bin/writter.so: \
	$(SOwritter) \
	build/dep/writter.so \
	build/ldOptions
	@echo ' [LD-so] so writter'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/writter.so -fPIC -shared $(SOwritter) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._splfunction_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._splfunction_aw.sab bin/sab

bundle: application._splfunction_aw.sab

-include build/dep/application._splfunction_aw.sab.d
application._splfunction_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._splfunction_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._splfunction_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._splfunction_aw.sab

