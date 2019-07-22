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

SPL_TYPES = build/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Web.o \
                build/operator/Custom_2.o 
SPL_SO_BINS = bin/Web.so \
              bin/Custom_2.so 

SPL_ADL_FILE = application._inetsource_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/19_inetsource_aw/output/application._inetsource_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._inetsource_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.o: \
	    src/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.h \
	    src/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring web_rec>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Web.d
build/operator/Web.o: \
	    src/operator/Web.h \
	    src/operator/Web.cpp\
	    build/dep/operator/Web.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Web'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/com.ibm.streamsx.inet/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/com.ibm.streamsx.inet/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._inetsource_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Web.cpp

-include build/operator/Custom_2.d
build/operator/Custom_2.o: \
	    src/operator/Custom_2.h \
	    src/operator/Custom_2.cpp\
	    build/dep/operator/Custom_2.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Custom_2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._inetsource_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Custom_2.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOWeb = \
	    build/operator/Web.o \
	    build/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.o 

bin/Web.so: \
	$(SOWeb) \
	build/dep/Web.so \
	build/ldOptions
	@echo ' [LD-so] so Web'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Web.so -fPIC -shared $(SOWeb) -lcurl $(SPL_LDFLAGS)

SOCustom_2 = \
	    build/operator/Custom_2.o \
	    build/type/BeJwrMSw2L09Nii9KTQYAGDwEAn.o 

bin/Custom_2.so: \
	$(SOCustom_2) \
	build/dep/Custom_2.so \
	build/ldOptions
	@echo ' [LD-so] so Custom_2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Custom_2.so -fPIC -shared $(SOCustom_2) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._inetsource_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._inetsource_aw.sab bin/sab

bundle: application._inetsource_aw.sab

-include build/dep/application._inetsource_aw.sab.d
application._inetsource_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._inetsource_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._inetsource_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._inetsource_aw.sab

