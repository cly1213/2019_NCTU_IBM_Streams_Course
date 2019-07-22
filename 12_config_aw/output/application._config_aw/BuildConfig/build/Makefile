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

SPL_TYPES = 
SPL_FUNCTIONS = 
SPL_OPERATORS = 
SPL_SO_BINS = 

SPL_ADL_FILE = application._config_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/12_config_aw/output/application._config_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._config_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

standalone: 
	@rm -f bin/standalone.exe
	@rm -f bin/application._config_aw
	@rm -f bin/sab
	@rm -f bin/standalone

sablink:

	@ln -sf ../application._config_aw.sab bin/sab

bundle: application._config_aw.sab

-include build/dep/application._config_aw.sab.d
application._config_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._config_aw.sab.d
	@echo ' [Bundle] application._config_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._config_aw.sab

