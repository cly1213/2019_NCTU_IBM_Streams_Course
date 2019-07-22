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

SPL_TYPES = build/type/BeJwrMco0zMw0zAIADBwCCu.o \
            build/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Beat.o \
                build/operator/Functor_stream.o \
                build/operator/Custom_3.o 
SPL_SO_BINS = bin/Beat.so \
              bin/Functor_stream.so \
              bin/Custom_3.so 

SPL_ADL_FILE = _compile_time.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/04_compile_time/output/_compile_time')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone _compile_time.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMco0zMw0zAIADBwCCu.o: \
	    src/type/BeJwrMco0zMw0zAIADBwCCu.h \
	    src/type/BeJwrMco0zMw0zAIADBwCCu.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 i,int32 j>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMco0zMw0zAIADBwCCu.cpp

build/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.o: \
	    src/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.h \
	    src/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 i,int32 j,rstring str1,rstring str2,rstring s...g str6,rstring str7>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Beat.d
build/operator/Beat.o: \
	    src/operator/Beat.h \
	    src/operator/Beat.cpp\
	    build/dep/operator/Beat.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Beat'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"_compile_time.adl\" -c $(SPL_CXXFLAGS) src/operator/Beat.cpp

-include build/operator/Functor_stream.d
build/operator/Functor_stream.o: \
	    src/operator/Functor_stream.h \
	    src/operator/Functor_stream.cpp\
	    build/dep/operator/Functor_stream.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Functor_stream'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"_compile_time.adl\" -c $(SPL_CXXFLAGS) src/operator/Functor_stream.cpp

-include build/operator/Custom_3.d
build/operator/Custom_3.o: \
	    src/operator/Custom_3.h \
	    src/operator/Custom_3.cpp\
	    build/dep/operator/Custom_3.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Custom_3'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"_compile_time.adl\" -c $(SPL_CXXFLAGS) src/operator/Custom_3.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOBeat = \
	    build/operator/Beat.o \
	    build/type/BeJwrMco0zMw0zAIADBwCCu.o 

bin/Beat.so: \
	$(SOBeat) \
	build/dep/Beat.so \
	build/ldOptions
	@echo ' [LD-so] so Beat'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Beat.so -fPIC -shared $(SOBeat) $(SPL_LDFLAGS)

SOFunctor_stream = \
	    build/operator/Functor_stream.o \
	    build/type/BeJwrMco0zMw0zAIADBwCCu.o \
	    build/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.o 

bin/Functor_stream.so: \
	$(SOFunctor_stream) \
	build/dep/Functor_stream.so \
	build/ldOptions
	@echo ' [LD-so] so Functor_stream'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Functor_stream.so -fPIC -shared $(SOFunctor_stream) $(SPL_LDFLAGS)

SOCustom_3 = \
	    build/operator/Custom_3.o \
	    build/type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.o 

bin/Custom_3.so: \
	$(SOCustom_3) \
	build/dep/Custom_3.so \
	build/ldOptions
	@echo ' [LD-so] so Custom_3'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Custom_3.so -fPIC -shared $(SOCustom_3) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/_compile_time
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../_compile_time.sab bin/sab

bundle: _compile_time.sab

-include build/dep/_compile_time.sab.d
_compile_time.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/_compile_time.sab.d bin/standalone.exe
	@echo ' [Bundle] _compile_time.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) _compile_time.sab

