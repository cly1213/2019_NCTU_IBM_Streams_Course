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

SPL_TYPES = build/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.o \
            build/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Order.o \
                build/operator/Result.o \
                build/operator/ODBCAppend_3.o 
SPL_SO_BINS = bin/Order.so \
              bin/Result.so \
              bin/ODBCAppend_3.so 

SPL_ADL_FILE = application._ODBC_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/20_ODBC_aw/output/application._ODBC_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._ODBC_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.o: \
	    src/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.h \
	    src/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 OrderId,rstring CustomerName,int32 CustomerId...uctId,rstring Price>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.cpp

build/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.o: \
	    src/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.h \
	    src/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 OrderId,rstring CustomerName,int32 CustomerId...string ShippingDate>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Order.d
build/operator/Order.o: \
	    src/operator/Order.h \
	    src/operator/Order.cpp\
	    build/dep/operator/Order.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Order'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/com.ibm.streams.db/impl/nl/include -I /opt/ibm/db2/V10.5/include/ -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._ODBC_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Order.cpp

-include build/operator/Result.d
build/operator/Result.o: \
	    src/operator/Result.h \
	    src/operator/Result.cpp\
	    build/dep/operator/Result.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Result'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._ODBC_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Result.cpp

-include build/operator/ODBCAppend_3.d
build/operator/ODBCAppend_3.o: \
	    src/operator/ODBCAppend_3.h \
	    src/operator/ODBCAppend_3.cpp\
	    build/dep/operator/ODBCAppend_3.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] ODBCAppend_3'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/com.ibm.streams.db/impl/nl/include -I /opt/ibm/db2/V10.5/include/ -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._ODBC_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/ODBCAppend_3.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOOrder = \
	    build/operator/Order.o \
	    build/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.o 

bin/Order.so: \
	$(SOOrder) \
	build/dep/Order.so \
	build/ldOptions
	@echo ' [LD-so] so Order'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Order.so -fPIC -shared $(SOOrder) -L /opt/ibm/db2/V10.5/lib64/ -Wl,-rpath -Wl,/opt/ibm/db2/V10.5/lib64 -ldb2 $(SPL_LDFLAGS)

SOResult = \
	    build/operator/Result.o \
	    build/type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.o \
	    build/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.o 

bin/Result.so: \
	$(SOResult) \
	build/dep/Result.so \
	build/ldOptions
	@echo ' [LD-so] so Result'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Result.so -fPIC -shared $(SOResult) $(SPL_LDFLAGS)

SOODBCAppend_3 = \
	    build/operator/ODBCAppend_3.o \
	    build/type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.o 

bin/ODBCAppend_3.so: \
	$(SOODBCAppend_3) \
	build/dep/ODBCAppend_3.so \
	build/ldOptions
	@echo ' [LD-so] so ODBCAppend_3'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/ODBCAppend_3.so -fPIC -shared $(SOODBCAppend_3) -L /opt/ibm/db2/V10.5/lib64/ -Wl,-rpath -Wl,/opt/ibm/db2/V10.5/lib64 -ldb2 $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._ODBC_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._ODBC_aw.sab bin/sab

bundle: application._ODBC_aw.sab

-include build/dep/application._ODBC_aw.sab.d
application._ODBC_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._ODBC_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._ODBC_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._ODBC_aw.sab

