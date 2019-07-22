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

SPL_TYPES = build/type/BeJwrMSw1TSnNza0EABB4AN8.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/TestJAVA.o \
                build/operator/ConsoleWritter.o 
SPL_SO_BINS = bin/TestJAVA.so \
              bin/ConsoleWritter.so 

SPL_ADL_FILE = application._java_nf_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/16_java_nf_aw/output/application._java_nf_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._java_nf_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMSw1TSnNza0EABB4AN8.o: \
	    src/type/BeJwrMSw1TSnNza0EABB4AN8.h \
	    src/type/BeJwrMSw1TSnNza0EABB4AN8.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 dummy>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw1TSnNza0EABB4AN8.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/TestJAVA.d
build/operator/TestJAVA.o: \
	    src/operator/TestJAVA.h \
	    src/operator/TestJAVA.cpp\
	    build/dep/operator/TestJAVA.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TestJAVA'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._java_nf_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/TestJAVA.cpp

-include build/operator/ConsoleWritter.d
build/operator/ConsoleWritter.o: \
	    src/operator/ConsoleWritter.h \
	    src/operator/ConsoleWritter.cpp\
	    build/dep/operator/ConsoleWritter.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] ConsoleWritter'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I ../../.././com.nctu.myutilx/native.function/. -I /opt/ibm/InfoSphere_Streams/4.3.0.3/java/include -I ../../.././com.nctu.myutils/native.function/. -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._java_nf_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/ConsoleWritter.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOTestJAVA = \
	    build/operator/TestJAVA.o \
	    build/type/BeJwrMSw1TSnNza0EABB4AN8.o 

bin/TestJAVA.so: \
	$(SOTestJAVA) \
	build/dep/TestJAVA.so \
	build/ldOptions
	@echo ' [LD-so] so TestJAVA'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TestJAVA.so -fPIC -shared $(SOTestJAVA) $(SPL_LDFLAGS)

SOConsoleWritter = \
	    build/operator/ConsoleWritter.o \
	    build/type/BeJwrMSw1TSnNza0EABB4AN8.o 

bin/ConsoleWritter.so: \
	$(SOConsoleWritter) \
	build/dep/ConsoleWritter.so \
	build/ldOptions
	@echo ' [LD-so] so ConsoleWritter'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/ConsoleWritter.so -fPIC -shared $(SOConsoleWritter) -lstreams-stdtk-javaop -lstreams-stdtk-runtime -L /opt/ibm/InfoSphere_Streams/4.3.0.3/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.3/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-javaop -lstreams-stdtk-runtime -lpthread -ldl -lstreams-stdtk-javaop -lstreams-stdtk-runtime -lpthread -ldl $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._java_nf_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._java_nf_aw.sab bin/sab

bundle: application._java_nf_aw.sab

-include build/dep/application._java_nf_aw.sab.d
application._java_nf_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._java_nf_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._java_nf_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._java_nf_aw.sab

