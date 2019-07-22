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

SPL_TYPES = build/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Beat.o \
                build/operator/MetricsSink_1.o 
SPL_SO_BINS = bin/Beat.so \
              bin/MetricsSink_1.so 

SPL_ADL_FILE = spiderman._metrics.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/03_metrics/output/spiderman._metrics')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone spiderman._metrics.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.o: \
	    src/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.h \
	    src/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int64 count,int64 item>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.cpp

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
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"spiderman._metrics.adl\" -c $(SPL_CXXFLAGS) src/operator/Beat.cpp

-include build/operator/MetricsSink_1.d
build/operator/MetricsSink_1.o: \
	    src/operator/MetricsSink_1.h \
	    src/operator/MetricsSink_1.cpp\
	    build/dep/operator/MetricsSink_1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MetricsSink_1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"spiderman._metrics.adl\" -c $(SPL_CXXFLAGS) src/operator/MetricsSink_1.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOBeat = \
	    build/operator/Beat.o \
	    build/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.o 

bin/Beat.so: \
	$(SOBeat) \
	build/dep/Beat.so \
	build/ldOptions
	@echo ' [LD-so] so Beat'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Beat.so -fPIC -shared $(SOBeat) $(SPL_LDFLAGS)

SOMetricsSink_1 = \
	    build/operator/MetricsSink_1.o \
	    build/type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.o 

bin/MetricsSink_1.so: \
	$(SOMetricsSink_1) \
	build/dep/MetricsSink_1.so \
	build/ldOptions
	@echo ' [LD-so] so MetricsSink_1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/MetricsSink_1.so -fPIC -shared $(SOMetricsSink_1) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/spiderman._metrics
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../spiderman._metrics.sab bin/sab

bundle: spiderman._metrics.sab

-include build/dep/spiderman._metrics.sab.d
spiderman._metrics.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/spiderman._metrics.sab.d bin/standalone.exe
	@echo ' [Bundle] spiderman._metrics.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) spiderman._metrics.sab

