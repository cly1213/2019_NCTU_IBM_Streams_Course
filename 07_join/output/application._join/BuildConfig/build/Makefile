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

SPL_TYPES = build/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.o \
            build/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.o \
            build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o \
            build/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.o \
            build/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.o \
            build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.o \
            build/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Employee.o \
                build/operator/Department.o \
                build/operator/Order.o \
                build/operator/Inventory.o \
                build/operator/InnerJoin1.o \
                build/operator/innerjoin.o \
                build/operator/InnerJoin2.o \
                build/operator/FileSink_8.o \
                build/operator/LeftOuter1.o \
                build/operator/leftouter1.o 
SPL_SO_BINS = bin/Employee.so \
              bin/Department.so \
              bin/Order.so \
              bin/Inventory.so \
              bin/InnerJoin1.so \
              bin/innerjoin.so \
              bin/InnerJoin2.so \
              bin/FileSink_8.so \
              bin/LeftOuter1.so \
              bin/leftouter1.so 

SPL_ADL_FILE = application._join.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/edu22/workspace/07_join/output/application._join')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application._join.sab

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.o: \
	    src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h \
	    src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{inner,outer,leftOuter,rightOuter}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.cpp

build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o: \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{csv,txt,bin,block,line}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp

build/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.o: \
	    src/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.h \
	    src/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 dept_id,rstring dep_name>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.cpp

build/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.o: \
	    src/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.h \
	    src/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 product_id,rstring productName,uint32 quantity,float32 price>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.cpp

build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o: \
	    src/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h \
	    src/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 id,rstring customer,rstring date,rstring product,uint32 quantity>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.cpp

build/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.o: \
	    src/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.h \
	    src/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,uint32 dept,uint32 dept_id,rstring dep_name>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.cpp

build/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.o: \
	    src/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.h \
	    src/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<uint32 id,rstring customer,rstring date,rstring pro...ce,uint32 quantity2>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.cpp

build/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.o: \
	    src/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.h \
	    src/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,uint32 dept>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Employee.d
build/operator/Employee.o: \
	    src/operator/Employee.h \
	    src/operator/Employee.cpp\
	    build/dep/operator/Employee.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Employee'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/Employee.cpp

-include build/operator/Department.d
build/operator/Department.o: \
	    src/operator/Department.h \
	    src/operator/Department.cpp\
	    build/dep/operator/Department.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Department'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/Department.cpp

-include build/operator/Order.d
build/operator/Order.o: \
	    src/operator/Order.h \
	    src/operator/Order.cpp\
	    build/dep/operator/Order.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Order'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/Order.cpp

-include build/operator/Inventory.d
build/operator/Inventory.o: \
	    src/operator/Inventory.h \
	    src/operator/Inventory.cpp\
	    build/dep/operator/Inventory.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Inventory'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/Inventory.cpp

-include build/operator/InnerJoin1.d
build/operator/InnerJoin1.o: \
	    src/operator/InnerJoin1.h \
	    src/operator/InnerJoin1.cpp\
	    build/dep/operator/InnerJoin1.dep \
	    src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] InnerJoin1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/InnerJoin1.cpp

-include build/operator/innerjoin.d
build/operator/innerjoin.o: \
	    src/operator/innerjoin.h \
	    src/operator/innerjoin.cpp\
	    build/dep/operator/innerjoin.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] innerjoin'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/innerjoin.cpp

-include build/operator/InnerJoin2.d
build/operator/InnerJoin2.o: \
	    src/operator/InnerJoin2.h \
	    src/operator/InnerJoin2.cpp\
	    build/dep/operator/InnerJoin2.dep \
	    src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] InnerJoin2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/InnerJoin2.cpp

-include build/operator/FileSink_8.d
build/operator/FileSink_8.o: \
	    src/operator/FileSink_8.h \
	    src/operator/FileSink_8.cpp\
	    build/dep/operator/FileSink_8.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FileSink_8'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/FileSink_8.cpp

-include build/operator/LeftOuter1.d
build/operator/LeftOuter1.o: \
	    src/operator/LeftOuter1.h \
	    src/operator/LeftOuter1.cpp\
	    build/dep/operator/LeftOuter1.dep \
	    src/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] LeftOuter1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/LeftOuter1.cpp

-include build/operator/leftouter1.d
build/operator/leftouter1.o: \
	    src/operator/leftouter1.h \
	    src/operator/leftouter1.cpp\
	    build/dep/operator/leftouter1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] leftouter1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.3/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application._join.adl\" -c $(SPL_CXXFLAGS) src/operator/leftouter1.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOEmployee = \
	    build/operator/Employee.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.o 

bin/Employee.so: \
	$(SOEmployee) \
	build/dep/Employee.so \
	build/ldOptions
	@echo ' [LD-so] so Employee'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Employee.so -fPIC -shared $(SOEmployee) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SODepartment = \
	    build/operator/Department.o \
	    build/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 

bin/Department.so: \
	$(SODepartment) \
	build/dep/Department.so \
	build/ldOptions
	@echo ' [LD-so] so Department'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Department.so -fPIC -shared $(SODepartment) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOOrder = \
	    build/operator/Order.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
	    build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o 

bin/Order.so: \
	$(SOOrder) \
	build/dep/Order.so \
	build/ldOptions
	@echo ' [LD-so] so Order'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Order.so -fPIC -shared $(SOOrder) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOInventory = \
	    build/operator/Inventory.o \
	    build/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 

bin/Inventory.so: \
	$(SOInventory) \
	build/dep/Inventory.so \
	build/ldOptions
	@echo ' [LD-so] so Inventory'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Inventory.so -fPIC -shared $(SOInventory) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOInnerJoin1 = \
	    build/operator/InnerJoin1.o \
	    build/type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.o \
	    build/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.o \
	    build/type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.o \
	    build/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.o 

bin/InnerJoin1.so: \
	$(SOInnerJoin1) \
	build/dep/InnerJoin1.so \
	build/ldOptions
	@echo ' [LD-so] so InnerJoin1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/InnerJoin1.so -fPIC -shared $(SOInnerJoin1) $(SPL_LDFLAGS)

SOinnerjoin = \
	    build/operator/innerjoin.o \
	    build/type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.o 

bin/innerjoin.so: \
	$(SOinnerjoin) \
	build/dep/innerjoin.so \
	build/ldOptions
	@echo ' [LD-so] so innerjoin'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/innerjoin.so -fPIC -shared $(SOinnerjoin) $(SPL_LDFLAGS)

SOInnerJoin2 = \
	    build/operator/InnerJoin2.o \
	    build/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.o \
	    build/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.o \
	    build/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.o \
	    build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o 

bin/InnerJoin2.so: \
	$(SOInnerJoin2) \
	build/dep/InnerJoin2.so \
	build/ldOptions
	@echo ' [LD-so] so InnerJoin2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/InnerJoin2.so -fPIC -shared $(SOInnerJoin2) $(SPL_LDFLAGS)

SOFileSink_8 = \
	    build/operator/FileSink_8.o \
	    build/type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.o 

bin/FileSink_8.so: \
	$(SOFileSink_8) \
	build/dep/FileSink_8.so \
	build/ldOptions
	@echo ' [LD-so] so FileSink_8'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/FileSink_8.so -fPIC -shared $(SOFileSink_8) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOLeftOuter1 = \
	    build/operator/LeftOuter1.o \
	    build/type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.o \
	    build/type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.o \
	    build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o 

bin/LeftOuter1.so: \
	$(SOLeftOuter1) \
	build/dep/LeftOuter1.so \
	build/ldOptions
	@echo ' [LD-so] so LeftOuter1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/LeftOuter1.so -fPIC -shared $(SOLeftOuter1) $(SPL_LDFLAGS)

SOleftouter1 = \
	    build/operator/leftouter1.o \
	    build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o 

bin/leftouter1.so: \
	$(SOleftouter1) \
	build/dep/leftouter1.so \
	build/ldOptions
	@echo ' [LD-so] so leftouter1'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/leftouter1.so -fPIC -shared $(SOleftouter1) $(SPL_LDFLAGS)

SOleftouter2 = \
	    build/operator/leftouter1.o \
	    build/type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.o 

bin/leftouter2.so: \
	$(SOleftouter2) \
	build/dep/leftouter2.so \
	build/ldOptions
	@echo ' [LD-so] so leftouter2'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/leftouter2.so -fPIC -shared $(SOleftouter2) $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/application._join
build/standalone:
	-@mkdir -m 755 build/standalone

sablink:

	@ln -sf ../application._join.sab bin/sab

bundle: application._join.sab

-include build/dep/application._join.sab.d
application._join.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application._join.sab.d bin/standalone.exe
	@echo ' [Bundle] application._join.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application._join.sab

