compiler = gcc -g
cflags = -std=c99 -lm -llapacke -llapack -lblas

headers = $(wildcard *.h)
sources = $(wildcard *.c)
objects = $(sources:.c=.o)

executables: gmres

%.o: %.c $(headers)
	$(compiler) -c -o $@ $< $(cflags)

arnoldi: $(objects)
	$(compiler) -o $@ $^ $(cflags)

gmres: $(objects)
	$(compiler) -o $@ $^ $(cflags)
clean:
	rm -f gmres arnoldi *.o
