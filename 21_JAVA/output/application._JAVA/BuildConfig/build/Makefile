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

SPL_TYPES = build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/C_ticker.o \
                build/operator/Ticker.o \
                build/operator/Ticker_T.o \
                build/operator/OnConsole.o 
SPL_SO_BINS = bin/C_ticker.so \
              bin/Ticker.so \
              bin/Ticker_T.so \
              bin/OnConsole.so 

SPL_ADL_FILE = application._JAVA.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/21_JAVA/output/application._JAVA')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._JAVA.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o: \
	    src/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.h \
	    src/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,float32 price,uint32 quantity,rstrin...pe,rstring datetime>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/C_ticker.d
build/operator/C_ticker.o: \
	    src/operator/C_ticker.h \
	    src/operator/C_ticker.cpp\
	    build/dep/operator/C_ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] C_ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._JAVA.adl\" -c $(SPL_CXXFLAGS) src/operator/C_ticker.cpp

-include build/operator/Ticker.d
build/operator/Ticker.o: \
	    src/operator/Ticker.h \
	    src/operator/Ticker.cpp\
	    build/dep/operator/Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._JAVA.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker.cpp

-include build/operator/Ticker_T.d
build/operator/Ticker_T.o: \
	    src/operator/Ticker_T.h \
	    src/operator/Ticker_T.cpp\
	    build/dep/operator/Ticker_T.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker_T'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/java/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._JAVA.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker_T.cpp

-include build/operator/OnConsole.d
build/operator/OnConsole.o: \
	    src/operator/OnConsole.h \
	    src/operator/OnConsole.cpp\
	    build/dep/operator/OnConsole.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] OnConsole'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._JAVA.adl\" -c $(SPL_CXXFLAGS) src/operator/OnConsole.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOC_ticker = \
	    build/operator/C_ticker.o \
	    build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o 

bin/C_ticker.so: \
	$(SOC_ticker) \
	build/dep/C_ticker.so \
	build/ldOptions
	@echo ' [LD-so] so C_ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/C_ticker.so -fPIC -shared $(SOC_ticker) $(SPL_LDFLAGS)

SOTicker = \
	    build/operator/Ticker.o \
	    build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o 

bin/Ticker.so: \
	$(SOTicker) \
	build/dep/Ticker.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker.so -fPIC -shared $(SOTicker) $(SPL_LDFLAGS)

SOTicker_T = \
	    build/operator/Ticker_T.o \
	    build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o 

bin/Ticker_T.so: \
	$(SOTicker_T) \
	build/dep/Ticker_T.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_T'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_T.so -fPIC -shared $(SOTicker_T) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.3.0.3/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.3/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOOnConsole = \
	    build/operator/OnConsole.o \
	    build/type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.o 

bin/OnConsole.so: \
	$(SOOnConsole) \
	build/dep/OnConsole.so \
	build/ldOptions
	@echo ' [LD-so] so OnConsole'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/OnConsole.so -fPIC -shared $(SOOnConsole) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._JAVA
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._JAVA.sab bin/sab

bundle: application._JAVA.sab

-include build/dep/application._JAVA.sab.d
application._JAVA.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._JAVA.sab.d bin/standalone.exe
	@echo ' [Bundle] application._JAVA.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._JAVA.sab

