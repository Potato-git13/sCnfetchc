CFLAGS=-g -Wall -Wextra -pedantic -Wformat=2 -Wextra

# Compiles and makes bin if needed
c: src/main.c src/whoami.c src/getdistro.c src/getshell.c src/gethost.c
	mkdir -p bin
	$(CC) -o bin/scnfetchc src/main.c src/whoami.c src/getdistro.c src/getshell.c src/gethost.c -lm $(CFLAGS)

# run
r:
	bin/scnfetchc

# compile and run
cr: c r

# run with a debugger
rd: c
	gdb bin/scnfetchc

# compile and run with a debugger
crd: c rd

clear:
	rm bin/scnfetchc
	rmdir bin

# Tell makefile that those arguments aren't files
.PHONY: c r cr rd crd

