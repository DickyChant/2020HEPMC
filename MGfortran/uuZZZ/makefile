FFLAGS = -g -fno-automatic -ffixed-line-length-none  
FC=gfortran

LIB     =       -L/user/lib\
                -lpawlib -lgraflib \
                -lgrafX11 -lpdflib804\
                -lmathlib -lpacklib -lkernlib\
                -lLHAPDF \
                -L/home/qliphy/Desktop/common/lhapdf6/lib

OBJECTS =  main.o \
           m2.o \
           monaco8.o \
           couplings.o \
           hist.o \
           psnew.o \

lq:  $(OBJECTS)
	$(FC) -o lq $(FFLAGS) $(OBJECTS) /home/qliphy/Desktop/common/libdhelas3.a $(LIB)

f.o:  $(FC) -c -o $*.o  $(FFLAGS) $*.f
