# Fortran Compiler (GNU)
FC=gfortran

# Compilation flags
FFLAGS=-fopenmp

saxpy_omp.exe: saxpy_omp.o
	$(FC) ${FFLAGS} -o $@ $^

saxpy_omp.o: saxpy_omp.f90
	$(FC) ${FFLAGS} -c $<

clean:
	rm -r *.o *.exe