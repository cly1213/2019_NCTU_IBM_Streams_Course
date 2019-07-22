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

SPL_TYPES = build/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.o \
            build/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/CityREC.o \
                build/operator/A_Result.o \
                build/operator/Custom_3.o \
                build/operator/B_Result.o \
                build/operator/Custom_4.o 
SPL_SO_BINS = bin/CityREC.so \
              bin/A_Result.so \
              bin/Custom_3.so \
              bin/B_Result.so \
              bin/Custom_4.so 

SPL_ADL_FILE = application._aggregate_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/14_aggregate_aw/output/application._aggregate_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._aggregate_aw.sab

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

build/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.o: \
	    src/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h \
	    src/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring city,rstring country,uint32 population,uint...ge,uint32 pEducated>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.cpp

build/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.o: \
	    src/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.h \
	    src/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 maxPopulation,uint32 maxMAge,uint32 minMAge,uint32 minpEducated>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.cpp

build/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.o: \
	    src/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.h \
	    src/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 maxPopulation,uint32 maxMAge,uint32 minMAge,...ity,rstring country>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/CityREC.d
build/operator/CityREC.o: \
	    src/operator/CityREC.h \
	    src/operator/CityREC.cpp\
	    build/dep/operator/CityREC.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] CityREC'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._aggregate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/CityREC.cpp

-include build/operator/A_Result.d
build/operator/A_Result.o: \
	    src/operator/A_Result.h \
	    src/operator/A_Result.cpp\
	    build/dep/operator/A_Result.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] A_Result'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._aggregate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/A_Result.cpp

-include build/operator/Custom_3.d
build/operator/Custom_3.o: \
	    src/operator/Custom_3.h \
	    src/operator/Custom_3.cpp\
	    build/dep/operator/Custom_3.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Custom_3'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._aggregate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Custom_3.cpp

-include build/operator/B_Result.d
build/operator/B_Result.o: \
	    src/operator/B_Result.h \
	    src/operator/B_Result.cpp\
	    build/dep/operator/B_Result.dep \
	    src/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] B_Result'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._aggregate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/B_Result.cpp

-include build/operator/Custom_4.d
build/operator/Custom_4.o: \
	    src/operator/Custom_4.h \
	    src/operator/Custom_4.cpp\
	    build/dep/operator/Custom_4.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Custom_4'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._aggregate_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Custom_4.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOCityREC = \
	    build/operator/CityREC.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.o 

bin/CityREC.so: \
	$(SOCityREC) \
	build/dep/CityREC.so \
	build/ldOptions
	@echo ' [LD-so] so CityREC'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/CityREC.so -fPIC -shared $(SOCityREC) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOA_Result = \
	    build/operator/A_Result.o \
	    build/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.o \
	    build/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.o 

bin/A_Result.so: \
	$(SOA_Result) \
	build/dep/A_Result.so \
	build/ldOptions
	@echo ' [LD-so] so A_Result'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/A_Result.so -fPIC -shared $(SOA_Result) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOCustom_3 = \
	    build/operator/Custom_3.o \
	    build/type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.o 

bin/Custom_3.so: \
	$(SOCustom_3) \
	build/dep/Custom_3.so \
	build/ldOptions
	@echo ' [LD-so] so Custom_3'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Custom_3.so -fPIC -shared $(SOCustom_3) $(SPL_LDFLAGS)

SOB_Result = \
	    build/operator/B_Result.o \
	    build/type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.o \
	    build/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.o 

bin/B_Result.so: \
	$(SOB_Result) \
	build/dep/B_Result.so \
	build/ldOptions
	@echo ' [LD-so] so B_Result'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/B_Result.so -fPIC -shared $(SOB_Result) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOCustom_4 = \
	    build/operator/Custom_4.o \
	    build/type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.o 

bin/Custom_4.so: \
	$(SOCustom_4) \
	build/dep/Custom_4.so \
	build/ldOptions
	@echo ' [LD-so] so Custom_4'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Custom_4.so -fPIC -shared $(SOCustom_4) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._aggregate_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._aggregate_aw.sab bin/sab

bundle: application._aggregate_aw.sab

-include build/dep/application._aggregate_aw.sab.d
application._aggregate_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._aggregate_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._aggregate_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._aggregate_aw.sab

