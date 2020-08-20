CC=gcc
CFLAGS = -Wall -Wextra

.PHONY: all tests clean

all: parkingManager tests

parkingManager_OBJ = vehicle.o reports.o parkingManager.o

parkingManager: $(parkingManager_OBJ)
	gcc $(parkingManager_OBJ) -o parkingManager

tests: test_vehicle test_reports

TESTREPORTS_OBJ = vehicle.o  reports.o test_reports.o

test_reports: $(TESTREPORTS_OBJ)
	gcc $(TESTREPORTS_OBJ) -o test_reports

TESTVEHICLE_OBJ = vehicle.o reports.o test_vehicle.o

test_vehicle: $(TESTVEHICLE_OBJ)
	gcc $(TESTVEHICLE_OBJ) -o test_vehicle

reports.o: reports.c reports.h vehicle.h
	gcc $(CFLAGS) -c reports.c

vehicle.o: vehicle.c vehicle.h reports.h
	gcc $(CFLAGS) -c vehicle.c

parkingManager.o: parkingManager.c reports.h vehicle.h
	gcc $(CFLAGS) -c parkingManager.c

test_reports.o: test_reports.c reports.h vehicle.h
	gcc $(CFLAGS) -c test_reports.c

test_vehicle.o: test_vehicle.c vehicle.h reports.h
	gcc $(CFLAGS) -c test_vehicle.c

clean:
	rm -f vehicle.o reports.o test_vehicle.o test_reports.o parkingManager.o
	rm -f parkingManager test_vehicle test_reports
