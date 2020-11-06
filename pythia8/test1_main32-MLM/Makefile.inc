# PYTHIA configuration file.
# Generated on Fri Sep 25 03:35:31 PM UTC 2020 with the user supplied options:
# --prefix=/usr
# --prefix-bin=/usr/bin
# --prefix-include=/usr/include
# --prefix-lib=/usr/lib
# --prefix-share=/usr/share/pythia8
# --cxx=/usr/bin/g++
# --cxx-common=-march=x86-64 -mtune=generic -O2 -pipe -fno-plt -fPIC
# --cxx-shared=-shared -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now -ldl
# --with-fastjet3
# --with-fastjet3-include=/usr/include
# --with-fastjet3-lib=/usr/lib
# --with-gzip
# --with-gzip-include=/usr/include
# --with-gzip-lib=/usr/lib
# --with-hepmc2
# --with-hepmc2-include=/usr/include
# --with-hepmc2-lib=/usr/lib
# --with-hepmc3
# --with-hepmc3-include=/usr/include
# --with-hepmc3-lib=/usr/lib
# --with-lhapdf5
# --with-lhapdf5-include=/usr/include
# --with-lhapdf5-lib=/usr/lib
# --with-lhapdf6
# --with-lhapdf6-include=/usr/include
# --with-lhapdf6-lib=/usr/lib
# --with-python
# --with-python-include=/usr/include/python3.8
# --with-python-lib=/usr/lib/python3.8
# --with-root
# --with-root-include=/usr/include/root
# --with-root-lib=/usr/lib/root
# --with-openmp
# --with-openmp-include=/usr/include
# --with-openmp-lib=/usr/lib

# Install directory prefixes.
PREFIX_BIN=/usr/bin
PREFIX_INCLUDE=/usr/include
PREFIX_LIB=/usr/lib
PREFIX_SHARE=/usr/share/pythia8

# Compilation flags (see ./configure --help for further documentation).
CXX=/usr/bin/g++
CXX_COMMON=-march=x86-64 -mtune=generic -O2 -pipe -fno-plt -fPIC -DGZIP -I/usr/include -fopenmp -DOPENMP -I/usr/include 
CXX_SHARED=-shared -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now -ldl
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so
OBJ_COMMON=

EVTGEN_USE=false
EVTGEN_CONFIG=
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

FASTJET3_USE=true
FASTJET3_CONFIG=fastjet-config
FASTJET3_BIN=
FASTJET3_INCLUDE=-I/usr/include
FASTJET3_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lfastjet

HEPMC2_USE=true
HEPMC2_CONFIG=
HEPMC2_BIN=
HEPMC2_INCLUDE=-I/usr/include
HEPMC2_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lHepMC

HEPMC3_USE=true
HEPMC3_CONFIG=HepMC3-config
HEPMC3_BIN=
HEPMC3_INCLUDE=-I/usr/include
HEPMC3_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lHepMC3

LHAPDF5_USE=true
LHAPDF5_CONFIG=lhapdf-config
LHAPDF5_BIN=
LHAPDF5_INCLUDE=-I/usr/include
LHAPDF5_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lLHAPDF

LHAPDF6_USE=true
LHAPDF6_CONFIG=lhapdf-config
LHAPDF6_BIN=
LHAPDF6_INCLUDE=-I/usr/include
LHAPDF6_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lLHAPDF

POWHEG_USE=false
POWHEG_CONFIG=lhapdf-config
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

RIVET_USE=false
RIVET_CONFIG=lhapdf-config
RIVET_BIN=
RIVET_INCLUDE=
RIVET_LIB=

ROOT_USE=true
ROOT_CONFIG=root-config
ROOT_BIN=/usr/bin/
ROOT_INCLUDE=-I/usr/include/root
ROOT_LIB=-L/usr/lib/root -Wl,-rpath,/usr/lib/root -lCore

YODA_USE=false
YODA_CONFIG=root-config
YODA_BIN=
YODA_INCLUDE=
YODA_LIB=

GZIP_USE=true
GZIP_CONFIG=
GZIP_BIN=
GZIP_INCLUDE=-I/usr/include
GZIP_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lz

PYTHON_USE=true
PYTHON_CONFIG=python-config
PYTHON_BIN=
PYTHON_INCLUDE=-I/usr/include/python3.8
PYTHON_LIB=-L/usr/lib/python3.8 -Wl,-rpath,/usr/lib/python3.8

MG5MES_USE=false
MG5MES_CONFIG=python-config
MG5MES_BIN=
MG5MES_INCLUDE=
MG5MES_LIB=

OPENMP_USE=true
OPENMP_CONFIG=
OPENMP_BIN=
OPENMP_INCLUDE=-I/usr/include
OPENMP_LIB=-L/usr/lib -Wl,-rpath,/usr/lib -lgomp
