###########################################################
#
# Makefile of Error Injector (Bin Wang B.Wang@qub.ac.uk)
#
########################################################

CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = sample.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sample: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o
