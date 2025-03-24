# makefile for scheduling program
#

# make fcfs - for FCFS scheduling


CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf sjf
	rm -rf fcfs

sjf: src/driver.o src/list.o src/CPU.o src/schedule_sjf.o
	$(CC) $(CFLAGS) -o sjf src/driver.o src/schedule_sjf.o src/list.o src/CPU.o

fcfs: src/driver.o src/list.o src/CPU.o src/schedule_fcfs.o
	$(CC) $(CFLAGS) -o fcfs src/driver.o src/schedule_fcfs.o src/list.o src/CPU.o


schedule_sjf.o: src/schedule_sjf.c
	$(CC) $(CFLAGS) -c src/schedule_sjf.c

schedule_fcfs.o: src/schedule_fcfs.c
	$(CC) $(CFLAGS) -c src/schedule_fcfs.c

driver.o: src/driver.c
	$(CC) $(CFLAGS) -c src/driver.c

list.o: src/list.c headers/list.h
	$(CC) $(CFLAGS) -c src/list.c

CPU.o: src/CPU.c headers/cpu.h
	$(CC) $(CFLAGS) -c src/CPU.c
