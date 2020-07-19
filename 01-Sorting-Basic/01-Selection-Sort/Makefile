#BUILDMAKE edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m), x86_64)
CC=gcc
CXX=g++
CXXFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC \
  -std=c++11
CXXFLAGS_EXTRA=
CFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=-I../deps/
DEP_INCPATH=

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#BUILDMAKE UUID
BUILDMAKE_MD5=301ac547fccf3fc532db68d7eb646147  BUILDMAKE


.PHONY:all
all:buildmake_makefile_check 01-Selection-Sort 
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mall[0m']"
	@echo "make all done"

.PHONY:buildmake_makefile_check
buildmake_makefile_check:
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mbuildmake_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'buildmake'
	@echo "$(BUILDMAKE_MD5)" > buildmake.md5
	@md5sum -c --status buildmake.md5
	@rm -f buildmake.md5

.PHONY:ccpClean
ccpclean:
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpClean
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mclean[0m']"
	rm -rf 01-Selection-Sort
	rm -rf ./output/bin/01-Selection-Sort
	rm -rf 01-Selection-Sort_main.o

.PHONY:dist
dist:
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40mlove[0m']"
	@echo "make love done"

01-Selection-Sort:01-Selection-Sort_main.o
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40m01-Selection-Sort[0m']"
	$(CXX) 01-Selection-Sort_main.o -Xlinker "-("   -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o 01-Selection-Sort
	mkdir -p ./output/bin
	cp -f --link 01-Selection-Sort ./output/bin

01-Selection-Sort_main.o:main.cpp
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40m01-Selection-Sort_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o 01-Selection-Sort_main.o main.cpp

endif #ifeq ($(shell uname -m), x86_64)


