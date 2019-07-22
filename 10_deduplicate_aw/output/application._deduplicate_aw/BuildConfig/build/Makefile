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

SPL_TYPES = build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/EBook.o \
                build/operator/BookREC.o \
                build/operator/DBookREC.o \
                build/operator/vBook.o \
                build/operator/FileSink_5.o 
SPL_SO_BINS = bin/EBook.so \
              bin/BookREC.so \
              bin/DBookREC.so \
              bin/vBook.so \
              bin/FileSink_5.so 

SPL_ADL_FILE = application._deduplicate_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/10_deduplicate_aw/output/application._deduplicate_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._deduplicate_aw.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o: \
	    src/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.h \
	    src/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring title,rstring isbn,rstring author,rstring publisher,float32 price>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/EBook.d
build/operator/EBook.o: \
	    src/operator/EBook.h \
	    src/operator/EBook.cpp\
	    build/dep/operator/EBook.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] EBook'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._deduplicate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/EBook.cpp

-include build/operator/BookREC.d
build/operator/BookREC.o: \
	    src/operator/BookREC.h \
	    src/operator/BookREC.cpp\
	    build/dep/operator/BookREC.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] BookREC'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._deduplicate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/BookREC.cpp

-include build/operator/DBookREC.d
build/operator/DBookREC.o: \
	    src/operator/DBookREC.h \
	    src/operator/DBookREC.cpp\
	    build/dep/operator/DBookREC.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DBookREC'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._deduplicate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/DBookREC.cpp

-include build/operator/vBook.d
build/operator/vBook.o: \
	    src/operator/vBook.h \
	    src/operator/vBook.cpp\
	    build/dep/operator/vBook.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] vBook'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._deduplicate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/vBook.cpp

-include build/operator/FileSink_5.d
build/operator/FileSink_5.o: \
	    src/operator/FileSink_5.h \
	    src/operator/FileSink_5.cpp\
	    build/dep/operator/FileSink_5.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FileSink_5'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._deduplicate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/FileSink_5.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOEBook = \
	    build/operator/EBook.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/EBook.so: \
	$(SOEBook) \
	build/dep/EBook.so \
	build/ldOptions
	@echo ' [LD-so] so EBook'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/EBook.so -fPIC -shared $(SOEBook) $(SPL_LDFLAGS)

SOBookREC = \
	    build/operator/BookREC.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/BookREC.so: \
	$(SOBookREC) \
	build/dep/BookREC.so \
	build/ldOptions
	@echo ' [LD-so] so BookREC'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/BookREC.so -fPIC -shared $(SOBookREC) $(SPL_LDFLAGS)

SODBookREC = \
	    build/operator/DBookREC.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/DBookREC.so: \
	$(SODBookREC) \
	build/dep/DBookREC.so \
	build/ldOptions
	@echo ' [LD-so] so DBookREC'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DBookREC.so -fPIC -shared $(SODBookREC) $(SPL_LDFLAGS)

SOvBook = \
	    build/operator/vBook.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/vBook.so: \
	$(SOvBook) \
	build/dep/vBook.so \
	build/ldOptions
	@echo ' [LD-so] so vBook'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/vBook.so -fPIC -shared $(SOvBook) $(SPL_LDFLAGS)

SOFileSink_5 = \
	    build/operator/FileSink_5.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/FileSink_5.so: \
	$(SOFileSink_5) \
	build/dep/FileSink_5.so \
	build/ldOptions
	@echo ' [LD-so] so FileSink_5'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FileSink_5.so -fPIC -shared $(SOFileSink_5) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOFileSink_6 = \
	    build/operator/FileSink_5.o \
	    build/type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.o 

bin/FileSink_6.so: \
	$(SOFileSink_6) \
	build/dep/FileSink_6.so \
	build/ldOptions
	@echo ' [LD-so] so FileSink_6'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FileSink_6.so -fPIC -shared $(SOFileSink_6) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._deduplicate_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._deduplicate_aw.sab bin/sab

bundle: application._deduplicate_aw.sab

-include build/dep/application._deduplicate_aw.sab.d
application._deduplicate_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._deduplicate_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._deduplicate_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._deduplicate_aw.sab

