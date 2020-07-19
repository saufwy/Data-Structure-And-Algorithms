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
BUILDMAKE_MD5=90a1e47b4d99607898151f1dd9a3653d  BUILDMAKE


.PHONY:all
all:buildmake_makefile_check 02-Insertiong-Sort 
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
	rm -rf 02-Insertiong-Sort
	rm -rf ./output/bin/02-Insertiong-Sort
	rm -rf 02-Insertiong-Sort_main.o

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

02-Insertiong-Sort:02-Insertiong-Sort_main.o
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40m02-Insertiong-Sort[0m']"
	$(CXX) 02-Insertiong-Sort_main.o -Xlinker "-("   -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o 02-Insertiong-Sort
	mkdir -p ./output/bin
	cp -f --link 02-Insertiong-Sort ./output/bin

02-Insertiong-Sort_main.o:main.cpp
	@echo "[[1;32;40mBUILDMAKE:BUILD[0m][Target:'[1;31;40m02-Insertiong-Sort_main.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o 02-Insertiong-Sort_main.o main.cpp

endif #ifeq ($(shell uname -m), x86_64)


