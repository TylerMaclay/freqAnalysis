CC = g++
CFLAGS = -I inc -std=c++11 -Wall -Wextra -pedantic
SRCDIR = ./src
INCDIR = ./inc

freqAnalysis : main.o fileReader.o wordCounter.o output.o cmdargs.o
	$(CC) $(CFLAGS) -o ./bin/freqAnalysis main.o fileReader.o wordCounter.o output.o cmdargs.o

cmdargs.o : $(INCDIR)/cmdargs.h $(SRCDIR)/cmdargs.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)/cmdargs.cpp

output.o : $(INCDIR)/output.h $(SRCDIR)/output.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)/output.cpp

fileReader.o : $(INCDIR)/fileReader.h $(SRCDIR)/fileReader.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)/fileReader.cpp

wordCounter.o : $(INCDIR)/wordCounter.h $(SRCDIR)/wordCounter.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)/wordCounter.cpp

main.o : $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.cpp

.PHONY :

clean :
	rm -r *.o ./bin/freqAnalysis
