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

SPL_TYPES = build/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/C_ticker.o \
                build/operator/Ticker.o \
                build/operator/AddKey.o \
                build/operator/M_Ticker.o \
                build/operator/OnConsole.o 
SPL_SO_BINS = bin/C_ticker.so \
              bin/Ticker.so \
              bin/AddKey.so \
              bin/M_Ticker.so \
              bin/OnConsole.so 

SPL_ADL_FILE = application._dynamic_filter_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/11_dynamic_filter_aw/output/application._dynamic_filter_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._dynamic_filter_aw.sab

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

build/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.o: \
	    src/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.h \
	    src/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,rstring tradetype>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.cpp

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
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._dynamic_filter_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/C_ticker.cpp

-include build/operator/Ticker.d
build/operator/Ticker.o: \
	    src/operator/Ticker.h \
	    src/operator/Ticker.cpp\
	    build/dep/operator/Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._dynamic_filter_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Ticker.cpp

-include build/operator/AddKey.d
build/operator/AddKey.o: \
	    src/operator/AddKey.h \
	    src/operator/AddKey.cpp\
	    build/dep/operator/AddKey.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] AddKey'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._dynamic_filter_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/AddKey.cpp

-include build/operator/M_Ticker.d
build/operator/M_Ticker.o: \
	    src/operator/M_Ticker.h \
	    src/operator/M_Ticker.cpp\
	    build/dep/operator/M_Ticker.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] M_Ticker'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._dynamic_filter_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/M_Ticker.cpp

-include build/operator/OnConsole.d
build/operator/OnConsole.o: \
	    src/operator/OnConsole.h \
	    src/operator/OnConsole.cpp\
	    build/dep/operator/OnConsole.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] OnConsole'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._dynamic_filter_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/OnConsole.cpp

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

SOAddKey = \
	    build/operator/AddKey.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.o 

bin/AddKey.so: \
	$(SOAddKey) \
	build/dep/AddKey.so \
	build/ldOptions
	@echo ' [LD-so] so AddKey'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/AddKey.so -fPIC -shared $(SOAddKey) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SORemoveKey = \
	    build/operator/AddKey.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.o 

bin/RemoveKey.so: \
	$(SORemoveKey) \
	build/dep/RemoveKey.so \
	build/ldOptions
	@echo ' [LD-so] so RemoveKey'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/RemoveKey.so -fPIC -shared $(SORemoveKey) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOM_Ticker = \
	    build/operator/M_Ticker.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o \
	    build/type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.o 

bin/M_Ticker.so: \
	$(SOM_Ticker) \
	build/dep/M_Ticker.so \
	build/ldOptions
	@echo ' [LD-so] so M_Ticker'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/M_Ticker.so -fPIC -shared $(SOM_Ticker) $(SPL_LDFLAGS)

SOOnConsole = \
	    build/operator/OnConsole.o \
	    build/type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.o 

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
	@ln -sf standalone bin/application._dynamic_filter_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._dynamic_filter_aw.sab bin/sab

bundle: application._dynamic_filter_aw.sab

-include build/dep/application._dynamic_filter_aw.sab.d
application._dynamic_filter_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._dynamic_filter_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._dynamic_filter_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._dynamic_filter_aw.sab

