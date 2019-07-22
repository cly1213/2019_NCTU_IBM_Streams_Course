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

SPL_TYPES = build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o \
            build/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Beat.o \
                build/operator/SRO.o \
                build/operator/PSR.o \
                build/operator/Custom_4.o 
SPL_SO_BINS = bin/Beat.so \
              bin/SRO.so \
              bin/PSR.so \
              bin/Custom_4.so 

SPL_ADL_FILE = application._punctor.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/06_punctor/output/application._punctor')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._punctor.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.o: \
	    src/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.h \
	    src/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{before,after}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.cpp

build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o: \
	    src/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.h \
	    src/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,int32 id,int32 rank,rstring major>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.cpp

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
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._punctor.adl\" -c $(SPL_CXXFLAGS) src/operator/Beat.cpp

-include build/operator/SRO.d
build/operator/SRO.o: \
	    src/operator/SRO.h \
	    src/operator/SRO.cpp\
	    build/dep/operator/SRO.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SRO'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._punctor.adl\" -c $(SPL_CXXFLAGS) src/operator/SRO.cpp

-include build/operator/PSR.d
build/operator/PSR.o: \
	    src/operator/PSR.h \
	    src/operator/PSR.cpp\
	    build/dep/operator/PSR.dep \
	    src/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] PSR'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._punctor.adl\" -c $(SPL_CXXFLAGS) src/operator/PSR.cpp

-include build/operator/Custom_4.d
build/operator/Custom_4.o: \
	    src/operator/Custom_4.h \
	    src/operator/Custom_4.cpp\
	    build/dep/operator/Custom_4.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Custom_4'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._punctor.adl\" -c $(SPL_CXXFLAGS) src/operator/Custom_4.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOBeat = \
	    build/operator/Beat.o \
	    build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o 

bin/Beat.so: \
	$(SOBeat) \
	build/dep/Beat.so \
	build/ldOptions
	@echo ' [LD-so] so Beat'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Beat.so -fPIC -shared $(SOBeat) $(SPL_LDFLAGS)

SOSRO = \
	    build/operator/SRO.o \
	    build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o 

bin/SRO.so: \
	$(SOSRO) \
	build/dep/SRO.so \
	build/ldOptions
	@echo ' [LD-so] so SRO'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SRO.so -fPIC -shared $(SOSRO) $(SPL_LDFLAGS)

SOPSR = \
	    build/operator/PSR.o \
	    build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o \
	    build/type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.o 

bin/PSR.so: \
	$(SOPSR) \
	build/dep/PSR.so \
	build/ldOptions
	@echo ' [LD-so] so PSR'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/PSR.so -fPIC -shared $(SOPSR) $(SPL_LDFLAGS)

SOCustom_4 = \
	    build/operator/Custom_4.o \
	    build/type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.o 

bin/Custom_4.so: \
	$(SOCustom_4) \
	build/dep/Custom_4.so \
	build/ldOptions
	@echo ' [LD-so] so Custom_4'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Custom_4.so -fPIC -shared $(SOCustom_4) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._punctor
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._punctor.sab bin/sab

bundle: application._punctor.sab

-include build/dep/application._punctor.sab.d
application._punctor.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._punctor.sab.d bin/standalone.exe
	@echo ' [Bundle] application._punctor.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._punctor.sab

