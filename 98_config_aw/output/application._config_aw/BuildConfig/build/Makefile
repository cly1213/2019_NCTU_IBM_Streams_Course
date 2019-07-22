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

SPL_TYPES = build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/C_ticker.o \
                build/operator/Ticker.o \
                build/operator/GM_Ticker.o \
                build/operator/Ticker_1.o 
SPL_SO_BINS = bin/C_ticker.so \
              bin/Ticker.so \
              bin/GM_Ticker.so \
              bin/Ticker_1.so 

SPL_ADL_FILE = application._config_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/98_config_aw/output/application._config_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._config_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o: \
	    src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.h \
	    src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,float32 price,uint32 quantity,rstring tradetype>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.cpp

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
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._config_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/C_ticker.cpp

-include build/operator/Ticker.d
build/operator/Ticker.o: \
	    src/operator/Ticker.h \
	    src/operator/Ticker.cpp\
	    build/dep/operator/Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._config_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker.cpp

-include build/operator/GM_Ticker.d
build/operator/GM_Ticker.o: \
	    src/operator/GM_Ticker.h \
	    src/operator/GM_Ticker.cpp\
	    build/dep/operator/GM_Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] GM_Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._config_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/GM_Ticker.cpp

-include build/operator/Ticker_1.d
build/operator/Ticker_1.o: \
	    src/operator/Ticker_1.h \
	    src/operator/Ticker_1.cpp\
	    build/dep/operator/Ticker_1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker_1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._config_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker_1.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOC_ticker = \
	    build/operator/C_ticker.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/C_ticker.so: \
	$(SOC_ticker) \
	build/dep/C_ticker.so \
	build/ldOptions
	@echo ' [LD-so] so C_ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/C_ticker.so -fPIC -shared $(SOC_ticker) $(SPL_LDFLAGS)

SOTicker = \
	    build/operator/Ticker.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker.so: \
	$(SOTicker) \
	build/dep/Ticker.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker.so -fPIC -shared $(SOTicker) $(SPL_LDFLAGS)

SOGM_Ticker = \
	    build/operator/GM_Ticker.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/GM_Ticker.so: \
	$(SOGM_Ticker) \
	build/dep/GM_Ticker.so \
	build/ldOptions
	@echo ' [LD-so] so GM_Ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/GM_Ticker.so -fPIC -shared $(SOGM_Ticker) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOTicker_1 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_1.so: \
	$(SOTicker_1) \
	build/dep/Ticker_1.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_1.so -fPIC -shared $(SOTicker_1) $(SPL_LDFLAGS)

SOTicker_2 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_2.so: \
	$(SOTicker_2) \
	build/dep/Ticker_2.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_2.so -fPIC -shared $(SOTicker_2) $(SPL_LDFLAGS)

SOTicker_3 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_3.so: \
	$(SOTicker_3) \
	build/dep/Ticker_3.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_3'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_3.so -fPIC -shared $(SOTicker_3) $(SPL_LDFLAGS)

SOTicker_4 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_4.so: \
	$(SOTicker_4) \
	build/dep/Ticker_4.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_4'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_4.so -fPIC -shared $(SOTicker_4) $(SPL_LDFLAGS)

SOTicker_5 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_5.so: \
	$(SOTicker_5) \
	build/dep/Ticker_5.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_5'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_5.so -fPIC -shared $(SOTicker_5) $(SPL_LDFLAGS)

SOTicker_6 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_6.so: \
	$(SOTicker_6) \
	build/dep/Ticker_6.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_6'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_6.so -fPIC -shared $(SOTicker_6) $(SPL_LDFLAGS)

SOTicker_7 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_7.so: \
	$(SOTicker_7) \
	build/dep/Ticker_7.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_7'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_7.so -fPIC -shared $(SOTicker_7) $(SPL_LDFLAGS)

SOTicker_8 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_8.so: \
	$(SOTicker_8) \
	build/dep/Ticker_8.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_8'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_8.so -fPIC -shared $(SOTicker_8) $(SPL_LDFLAGS)

SOTicker_9 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_9.so: \
	$(SOTicker_9) \
	build/dep/Ticker_9.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_9'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_9.so -fPIC -shared $(SOTicker_9) $(SPL_LDFLAGS)

SOTicker_10 = \
	    build/operator/Ticker_1.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

bin/Ticker_10.so: \
	$(SOTicker_10) \
	build/dep/Ticker_10.so \
	build/ldOptions
	@echo ' [LD-so] so Ticker_10'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Ticker_10.so -fPIC -shared $(SOTicker_10) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._config_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._config_aw.sab bin/sab

bundle: application._config_aw.sab

-include build/dep/application._config_aw.sab.d
application._config_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._config_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._config_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._config_aw.sab

