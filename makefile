CFLAGS=-Wall -Wextra -Wpedantic
CC=gcc

FILES=src/*.c
OUTDIR=bin
OUTNAME=$(OUTDIR)/scnfetchc

clean:
	rm $(OUTNAME)
	rmdir $(OUTDIR)

compile:
	mkdir -p $(OUTDIR)
	$(CC) -o $(OUTNAME) $(FILES) -lm $(CFLAGS)

compile-debug: CFLAGS += -g
compile-debug: compile

run:
	$(OUTNAME)

install:
	sudo cp -p $(OUTNAME) /bin/scnfetchc

uninstall:
	sudo rm /bin/scnfetchc