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

SPL_TYPES = build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/REC.o \
                build/operator/SortByName.o \
                build/operator/NAME.o \
                build/operator/SortById.o \
                build/operator/ID.o \
                build/operator/SortByTitle.o 
SPL_SO_BINS = bin/REC.so \
              bin/SortByName.so \
              bin/NAME.so \
              bin/SortById.so \
              bin/ID.so \
              bin/SortByTitle.so 

SPL_ADL_FILE = application._sort.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/13_sort/output/application._sort')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._sort.sab

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

build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o: \
	    src/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.h \
	    src/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,uint32 id,rstring title,float32 salary>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/REC.d
build/operator/REC.o: \
	    src/operator/REC.h \
	    src/operator/REC.cpp\
	    build/dep/operator/REC.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] REC'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/REC.cpp

-include build/operator/SortByName.d
build/operator/SortByName.o: \
	    src/operator/SortByName.h \
	    src/operator/SortByName.cpp\
	    build/dep/operator/SortByName.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SortByName'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/SortByName.cpp

-include build/operator/NAME.d
build/operator/NAME.o: \
	    src/operator/NAME.h \
	    src/operator/NAME.cpp\
	    build/dep/operator/NAME.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] NAME'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/NAME.cpp

-include build/operator/SortById.d
build/operator/SortById.o: \
	    src/operator/SortById.h \
	    src/operator/SortById.cpp\
	    build/dep/operator/SortById.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SortById'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/SortById.cpp

-include build/operator/ID.d
build/operator/ID.o: \
	    src/operator/ID.h \
	    src/operator/ID.cpp\
	    build/dep/operator/ID.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] ID'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/ID.cpp

-include build/operator/SortByTitle.d
build/operator/SortByTitle.o: \
	    src/operator/SortByTitle.h \
	    src/operator/SortByTitle.cpp\
	    build/dep/operator/SortByTitle.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SortByTitle'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._sort.adl\" -c $(SPL_CXXFLAGS) src/operator/SortByTitle.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOREC = \
	    build/operator/REC.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/REC.so: \
	$(SOREC) \
	build/dep/REC.so \
	build/ldOptions
	@echo ' [LD-so] so REC'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/REC.so -fPIC -shared $(SOREC) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOSortByName = \
	    build/operator/SortByName.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/SortByName.so: \
	$(SOSortByName) \
	build/dep/SortByName.so \
	build/ldOptions
	@echo ' [LD-so] so SortByName'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SortByName.so -fPIC -shared $(SOSortByName) $(SPL_LDFLAGS)

SONAME = \
	    build/operator/NAME.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/NAME.so: \
	$(SONAME) \
	build/dep/NAME.so \
	build/ldOptions
	@echo ' [LD-so] so NAME'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/NAME.so -fPIC -shared $(SONAME) $(SPL_LDFLAGS)

SOSortById = \
	    build/operator/SortById.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/SortById.so: \
	$(SOSortById) \
	build/dep/SortById.so \
	build/ldOptions
	@echo ' [LD-so] so SortById'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SortById.so -fPIC -shared $(SOSortById) $(SPL_LDFLAGS)

SOID = \
	    build/operator/ID.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/ID.so: \
	$(SOID) \
	build/dep/ID.so \
	build/ldOptions
	@echo ' [LD-so] so ID'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/ID.so -fPIC -shared $(SOID) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOSortByTitle = \
	    build/operator/SortByTitle.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/SortByTitle.so: \
	$(SOSortByTitle) \
	build/dep/SortByTitle.so \
	build/ldOptions
	@echo ' [LD-so] so SortByTitle'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SortByTitle.so -fPIC -shared $(SOSortByTitle) $(SPL_LDFLAGS)

SOTitle = \
	    build/operator/ID.o \
	    build/type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.o 

bin/Title.so: \
	$(SOTitle) \
	build/dep/Title.so \
	build/ldOptions
	@echo ' [LD-so] so Title'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Title.so -fPIC -shared $(SOTitle) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._sort
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._sort.sab bin/sab

bundle: application._sort.sab

-include build/dep/application._sort.sab.d
application._sort.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._sort.sab.d bin/standalone.exe
	@echo ' [Bundle] application._sort.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._sort.sab

