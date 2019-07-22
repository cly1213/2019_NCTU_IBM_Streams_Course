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

SPL_TYPES = build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.o \
            build/type/BeJwrMSw1TUzOTk0BAA_12ANI.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Ticker_T.o \
                build/operator/R_Ticker.o \
                build/operator/Ticker1.o 
SPL_SO_BINS = bin/Ticker_T.so \
              bin/R_Ticker.so \
              bin/Ticker1.so 

SPL_ADL_FILE = application._gate_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/09_gate_aw/output/application._gate_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._gate_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.o: \
	    src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.h \
	    src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,float32 price,uint32 quantity,rstring tradeType>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.cpp

build/type/BeJwrMSw1TUzOTk0BAA_12ANI.o: \
	    src/type/BeJwrMSw1TUzOTk0BAA_12ANI.h \
	    src/type/BeJwrMSw1TUzOTk0BAA_12ANI.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 acked>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw1TUzOTk0BAA_12ANI.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Ticker_T.d
build/operator/Ticker_T.o: \
	    src/operator/Ticker_T.h \
	    src/operator/Ticker_T.cpp\
	    build/dep/operator/Ticker_T.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker_T'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._gate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker_T.cpp

-include build/operator/R_Ticker.d
build/operator/R_Ticker.o: \
	    src/operator/R_Ticker.h \
	    src/operator/R_Ticker.cpp\
	    build/dep/operator/R_Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] R_Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._gate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/R_Ticker.cpp

-include build/operator/Ticker1.d
build/operator/Ticker1.o: \
	    src/operator/Ticker1.h \
	    src/operator/Ticker1.cpp\
	    build/dep/operator/Ticker1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._gate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker1.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOTicker_T = \
	    build/operator/Ticker_T.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.o 

bin/Ticker_T.so: \
	$(SOTicker_T) \
	build/dep/Ticker_T.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_T'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_T.so -fPIC -shared $(SOTicker_T) $(SPL_LDFLAGS)

SOR_Ticker = \
	    build/operator/R_Ticker.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.o \
	    build/type/BeJwrMSw1TUzOTk0BAA_12ANI.o 

bin/R_Ticker.so: \
	$(SOR_Ticker) \
	build/dep/R_Ticker.so \
	build/ldOptions
	@echo ' [LD-so] so R_Ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/R_Ticker.so -fPIC -shared $(SOR_Ticker) $(SPL_LDFLAGS)

SOTicker1 = \
	    build/operator/Ticker1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.o \
	    build/type/BeJwrMSw1TUzOTk0BAA_12ANI.o 

bin/Ticker1.so: \
	$(SOTicker1) \
	build/dep/Ticker1.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker1.so -fPIC -shared $(SOTicker1) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._gate_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._gate_aw.sab bin/sab

bundle: application._gate_aw.sab

-include build/dep/application._gate_aw.sab.d
application._gate_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._gate_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._gate_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._gate_aw.sab

