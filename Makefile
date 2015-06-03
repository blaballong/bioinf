OBJS = $(BUILDDIR)/algorithm.o $(BUILDDIR)/dna.o $(BUILDDIR)/helper.o $(BUILDDIR)/spectrum.o $(BUILDDIR)/main.o
CC = g++
DEBUG =
LIBS = 
CFLAGS = -Wall -std=c++0x -c $(DEBUG) $(LIBS) -Iinclude -o $@
LFLAGS = -Wall $(DEBUG) $(LIBS) -Iinclude
MKDIR = mkdir -p

SRCDIR = src
INCDIR = include
BUILDDIR = bin

all : ${BUILDDIR} $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

$(BUILDDIR)/main.o : $(SRCDIR)/main.cpp $(INCDIR)/algorithm.h
	$(CC) $(SRCDIR)/main.cpp $(CFLAGS)

$(BUILDDIR)/algorithm.o : $(INCDIR)/algorithm.h $(INCDIR)/dna.h $(INCDIR)/helper.h $(INCDIR)/spectrum.h
	$(CC) $(SRCDIR)/algorithm.cpp $(CFLAGS)

$(BUILDDIR)/dna.o : $(INCDIR)/dna.h
	$(CC) $(SRCDIR)/dna.cpp $(CFLAGS)

$(BUILDDIR)/helper.o : $(INCDIR)/helper.h
	$(CC) $(SRCDIR)/helper.cpp $(CFLAGS)

$(BUILDDIR)/spectrum.o : $(INCDIR)/spectrum.h
	$(CC) $(SRCDIR)/spectrum.cpp $(CFLAGS)

${BUILDDIR} :
	${MKDIR} ${BUILDDIR}

clean :
	rm -f $(BUILDDIR)/*