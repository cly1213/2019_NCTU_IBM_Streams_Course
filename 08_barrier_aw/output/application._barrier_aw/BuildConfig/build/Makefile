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

SPL_TYPES = build/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.o \
            build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.o \
            build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o \
            build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Tx_Data.o \
                build/operator/DepR.o \
                build/operator/DebR.o \
                build/operator/DepRes.o \
                build/operator/DebRes.o \
                build/operator/F_Dep.o \
                build/operator/F_Deb.o \
                build/operator/Deposit.o 
SPL_SO_BINS = bin/Tx_Data.so \
              bin/DepR.so \
              bin/DebR.so \
              bin/DepRes.so \
              bin/DebRes.so \
              bin/F_Dep.so \
              bin/F_Deb.so \
              bin/Deposit.so 

SPL_ADL_FILE = application._barrier_aw.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/08_barrier_aw/output/application._barrier_aw')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._barrier_aw.sab

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

build/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.o: \
	    src/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.h \
	    src/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 a_num,rstring tx_type,float64 c_bal,float64 tx_amount>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.cpp

build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.o: \
	    src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.h \
	    src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 a_num,float64 c_bal,float64 dep_amount>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.cpp

build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.o: \
	    src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.h \
	    src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 a_num,float64 c_bal,float64 deb_amount>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.cpp

build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o: \
	    src/type/BeJwrMXQzz0stj09KzAEAFqIDD7.h \
	    src/type/BeJwrMXQzz0stj09KzAEAFqIDD7.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<float64 new_bal>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMXQzz0stj09KzAEAFqIDD7.cpp

build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o: \
	    src/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.h \
	    src/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 a_num,float64 c_bal>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Tx_Data.d
build/operator/Tx_Data.o: \
	    src/operator/Tx_Data.h \
	    src/operator/Tx_Data.cpp\
	    build/dep/operator/Tx_Data.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Tx_Data'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Tx_Data.cpp

-include build/operator/DepR.d
build/operator/DepR.o: \
	    src/operator/DepR.h \
	    src/operator/DepR.cpp\
	    build/dep/operator/DepR.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DepR'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/DepR.cpp

-include build/operator/DebR.d
build/operator/DebR.o: \
	    src/operator/DebR.h \
	    src/operator/DebR.cpp\
	    build/dep/operator/DebR.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DebR'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/DebR.cpp

-include build/operator/DepRes.d
build/operator/DepRes.o: \
	    src/operator/DepRes.h \
	    src/operator/DepRes.cpp\
	    build/dep/operator/DepRes.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DepRes'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/DepRes.cpp

-include build/operator/DebRes.d
build/operator/DebRes.o: \
	    src/operator/DebRes.h \
	    src/operator/DebRes.cpp\
	    build/dep/operator/DebRes.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DebRes'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/DebRes.cpp

-include build/operator/F_Dep.d
build/operator/F_Dep.o: \
	    src/operator/F_Dep.h \
	    src/operator/F_Dep.cpp\
	    build/dep/operator/F_Dep.dep \
	    src/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.h \
	    src/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] F_Dep'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/F_Dep.cpp

-include build/operator/F_Deb.d
build/operator/F_Deb.o: \
	    src/operator/F_Deb.h \
	    src/operator/F_Deb.cpp\
	    build/dep/operator/F_Deb.dep \
	    src/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] F_Deb'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/F_Deb.cpp

-include build/operator/Deposit.d
build/operator/Deposit.o: \
	    src/operator/Deposit.h \
	    src/operator/Deposit.cpp\
	    build/dep/operator/Deposit.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Deposit'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._barrier_aw.adl\" -c $(SPL_CXXFLAGS) src/operator/Deposit.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOTx_Data = \
	    build/operator/Tx_Data.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.o 

bin/Tx_Data.so: \
	$(SOTx_Data) \
	build/dep/Tx_Data.so \
	build/ldOptions
	@echo ' [LD-so] so Tx_Data'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Tx_Data.so -fPIC -shared $(SOTx_Data) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SODepR = \
	    build/operator/DepR.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.o \
	    build/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.o 

bin/DepR.so: \
	$(SODepR) \
	build/dep/DepR.so \
	build/ldOptions
	@echo ' [LD-so] so DepR'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DepR.so -fPIC -shared $(SODepR) $(SPL_LDFLAGS)

SODebR = \
	    build/operator/DebR.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.o \
	    build/type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.o 

bin/DebR.so: \
	$(SODebR) \
	build/dep/DebR.so \
	build/ldOptions
	@echo ' [LD-so] so DebR'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DebR.so -fPIC -shared $(SODebR) $(SPL_LDFLAGS)

SODepRes = \
	    build/operator/DepRes.o \
	    build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.o 

bin/DepRes.so: \
	$(SODepRes) \
	build/dep/DepRes.so \
	build/ldOptions
	@echo ' [LD-so] so DepRes'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DepRes.so -fPIC -shared $(SODepRes) $(SPL_LDFLAGS)

SODebRes = \
	    build/operator/DebRes.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.o \
	    build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o 

bin/DebRes.so: \
	$(SODebRes) \
	build/dep/DebRes.so \
	build/ldOptions
	@echo ' [LD-so] so DebRes'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DebRes.so -fPIC -shared $(SODebRes) $(SPL_LDFLAGS)

SOF_Dep = \
	    build/operator/F_Dep.o \
	    build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o \
	    build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.o 

bin/F_Dep.so: \
	$(SOF_Dep) \
	build/dep/F_Dep.so \
	build/ldOptions
	@echo ' [LD-so] so F_Dep'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/F_Dep.so -fPIC -shared $(SOF_Dep) $(SPL_LDFLAGS)

SOF_Deb = \
	    build/operator/F_Deb.o \
	    build/type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.o \
	    build/type/BeJwrMXQzz0stj09KzAEAFqIDD7.o \
	    build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o 

bin/F_Deb.so: \
	$(SOF_Deb) \
	build/dep/F_Deb.so \
	build/ldOptions
	@echo ' [LD-so] so F_Deb'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/F_Deb.so -fPIC -shared $(SOF_Deb) $(SPL_LDFLAGS)

SODeposit = \
	    build/operator/Deposit.o \
	    build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o 

bin/Deposit.so: \
	$(SODeposit) \
	build/dep/Deposit.so \
	build/ldOptions
	@echo ' [LD-so] so Deposit'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Deposit.so -fPIC -shared $(SODeposit) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOWithdraw = \
	    build/operator/Deposit.o \
	    build/type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.o 

bin/Withdraw.so: \
	$(SOWithdraw) \
	build/dep/Withdraw.so \
	build/ldOptions
	@echo ' [LD-so] so Withdraw'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Withdraw.so -fPIC -shared $(SOWithdraw) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._barrier_aw
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._barrier_aw.sab bin/sab

bundle: application._barrier_aw.sab

-include build/dep/application._barrier_aw.sab.d
application._barrier_aw.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._barrier_aw.sab.d bin/standalone.exe
	@echo ' [Bundle] application._barrier_aw.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._barrier_aw.sab

