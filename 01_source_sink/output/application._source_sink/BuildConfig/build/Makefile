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

SPL_TYPES = build/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/FileSource_1_out0.o \
                build/operator/FileSink_2.o 
SPL_SO_BINS = bin/FileSource_1_out0.so \
              bin/FileSink_2.so 

SPL_ADL_FILE = application._source_sink.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/01_source_sink/output/application._source_sink')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._source_sink.sab

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

build/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.o: \
	    src/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.h \
	    src/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,rstring title,rstring department,float64 salary>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/FileSource_1_out0.d
build/operator/FileSource_1_out0.o: \
	    src/operator/FileSource_1_out0.h \
	    src/operator/FileSource_1_out0.cpp\
	    build/dep/operator/FileSource_1_out0.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FileSource_1_out0'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._source_sink.adl\" -c $(SPL_CXXFLAGS) src/operator/FileSource_1_out0.cpp

-include build/operator/FileSink_2.d
build/operator/FileSink_2.o: \
	    src/operator/FileSink_2.h \
	    src/operator/FileSink_2.cpp\
	    build/dep/operator/FileSink_2.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FileSink_2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._source_sink.adl\" -c $(SPL_CXXFLAGS) src/operator/FileSink_2.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOFileSource_1_out0 = \
	    build/operator/FileSource_1_out0.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.o 

bin/FileSource_1_out0.so: \
	$(SOFileSource_1_out0) \
	build/dep/FileSource_1_out0.so \
	build/ldOptions
	@echo ' [LD-so] so FileSource_1_out0'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FileSource_1_out0.so -fPIC -shared $(SOFileSource_1_out0) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOFileSink_2 = \
	    build/operator/FileSink_2.o \
	    build/type/BeJwrMSk2yUvMTS02LcksyUktNjRISS1ILCrJTc0rcTMrTsxJLKoEAPpZA3L.o 

bin/FileSink_2.so: \
	$(SOFileSink_2) \
	build/dep/FileSink_2.so \
	build/ldOptions
	@echo ' [LD-so] so FileSink_2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FileSink_2.so -fPIC -shared $(SOFileSink_2) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._source_sink
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._source_sink.sab bin/sab

bundle: application._source_sink.sab

-include build/dep/application._source_sink.sab.d
application._source_sink.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._source_sink.sab.d bin/standalone.exe
	@echo ' [Bundle] application._source_sink.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._source_sink.sab

