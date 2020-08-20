#include <assert.h>     // for assert()
#include <stdio.h>      // for printf(), etc.
#include <stdlib.h>     // for EXIT_SUCCESS, abs(), etc.
#include <string.h>     // for strcpy(), strlen(), etc.

// local headers
#include "reports.h"   	// for the reports data structure and functions
#include "vehicle.h" 	// for the vehicle functions


int assignStall(Vehicle* v, int r, int c) {
    
    // Invalid pointer passed in
    if (NULL == v) {
        return -1; // error
    }
    
    // Stall already occupied
    if (NULL != Garage[r][c]) {
        return -1; // error
    }
    
    // New position out of bounds
    if ((r < 0) || (c < 0) || (r >= MAX_VEHICLE_ROW) || (c >= MAX_VEHICLE_COL)) {
        return -1; // error
    }
    
    // Clear vehicle's current position, if it has one
    for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {
            if (Garage[r][c] == v) {
                // Found the vehicle's position
                Garage[r][c] = NULL;
                // Allow loop to continue on the off-chance the vehicle is
                // listed in the garage multiple times
            }
        }
    }
    
    Garage[r][c] = v;
    
    return 0; // success
}
void printRefuelReport() {
    int numVehicles = 0;
    
    printf("The following vehicles have less than 50%% fuel:\n");
    for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {
            if ((NULL != Garage[r][c]) && (calcFuel(Garage[r][c]) < 50)) {
                // Found a vehicle matching criteria
                printf("-----\n");
                printVehicle(Garage[r][c]);
                printf("-----\n");
            }
        }
    }
    printf("Total number of vehicles on report: %d\n", numVehicles);
}

// printGarageMap:
//   Prints out a graphical diagram of the parking lot in a user-friendly format
// In:
//   n/a
// Out:
//   diagram is printed to standard output
//   on error, function halts where it left off printing
void printGarageMap() {
    
    printf("Printing graphical representation of parking lot:\n");
    for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {
            if (NULL != Garage[r][c]) {
                // Found a vehicle
                switch(Garage[r][c]->type) {
                   case CAR:
                      printf("C ");
                      break;
                   case TRUCK:
                      printf("T ");
                      break;
                   case SUV:
                      printf("S ");
                      break;
                   default :
                      return; // error
                }
            } else {
                // Represent a blank stall
                printf(". ");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}