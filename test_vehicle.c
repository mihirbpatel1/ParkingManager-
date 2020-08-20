#include <assert.h>     // for assert()
#include <stdio.h>      // for printf(), etc.
#include <stdlib.h>     // for EXIT_SUCCESS, abs(), etc.
#include <string.h>     // for strcpy(), strlen(), etc.

// local headers
#include "reports.h"   	// for the reports data structure and functions
#include "vehicle.h" 	// for the vehicle functions





const int MAX_READ_SIZE = 2000;

int assignStall(Vehicle* v, int r, int c);


void printRefuelReport();


void printGarageMap();

Vehicle* allocVehicle(char* model, char* plate, VType type, double curFuel, double maxFuel);



int deallocVehicle(Vehicle* v);

void printVehicle(Vehicle* v);


void printAllVehicles();

double calcFuel(Vehicle* v);
int refuelVehicle(Vehicle* v, double fuelAmount);

int importFromFile(char* file);


int main() {


	for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {

                // Found the vehicle's position
                Garage[r][c] = NULL;
                // Allow loop to continue on the off-chance the vehicle is
                // listed in the garage multiple times

        }
    }

    // Test Vehicle allocation
    char v1_model[] = "1982 Ford F-150";
    char v1_plate[] = "ABC 123";
    Vehicle *v1 = allocVehicle(v1_model, v1_plate, TRUCK, 93.24, 100);
    char v2_model[] = "1994 Ford Taurus";
    char v2_plate[] = "CMP 214";
    Vehicle *v2 = allocVehicle(v2_model, v2_plate, CAR, 4.54, 45);
    char v3_model[] = "2005 Chevrolet Trailblazer";
    char v3_plate[] = "DOW 039";
    Vehicle *v3 = allocVehicle(v3_model, v3_plate, SUV, 18, 80);

    // Check vehicle v1 was correctly initialized
    assert(NULL != v1);
    assert(NULL != v2);
    assert(NULL != v3);
    assert(NULL != v1->model);
    assert(NULL != v1->plate);
    assert(strcmp(v1->model,v1_model) == 0);
    assert(strcmp(v1->plate,v1_plate) == 0);
    assert(TRUCK == v1->type);
    assert(93.24 == v1->curFuel);
    assert(100 == v1->maxFuel);

    // Check invalid case behaves appropriately
    assert(NULL == allocVehicle(NULL, NULL, TRUCK, 100, 100));

    // Test deallocation - not many tests to do

    // Try a valid deallocation
    assert(deallocVehicle(v3) == 0);
    // Try an invalid deallocation
    assert(deallocVehicle(NULL) == -1);

    // reallocate v3 for use in future tests
    v3 = allocVehicle(v3_model, v3_plate, SUV, 18, 80);

    // Testing assignStall function
    assert(0 == assignStall(v1, 5, 5));
    // Checking every space of array to ensure it is correct
    for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {
            if (r == 5 && c == 5) {
                assert(Garage[r][c] == v1);
            } else {
                assert(Garage[r][c] == NULL);
            }
        }
    }
    assert(0 == assignStall(v2, 2, 8));
    assert(0 == assignStall(v3, 0, 9));

    // Move a vehicle to a new location
    assert(0 == assignStall(v3, 9, 0));

    // Some invalid placements
    assert(-1 == assignStall(v2, -1, 8)); // out of range
    assert(-1 == assignStall(v2, MAX_VEHICLE_ROW, MAX_VEHICLE_COL)); // out of range
    assert(-1 == assignStall(v3, 5, 5)); // already occupied
    assert(-1 == assignStall(NULL, 3, 5)); // invalid pointer

     // Testing print functions
    printf("==========printVehicle() tests==========\n");

    printf("Test: nothing should print between the two lines below\n");
    printf("=====\n");

    // Invalid pointer
    printVehicle(NULL);

    printf("=====\n");

    printVehicle(v1);
    printVehicle(v2);

    printf("==========End printVehicle() tests==========\n\n");

    printf("==========printAllVehicles() tests - with vehicles==========\n");

    printAllVehicles();

    printf("==========End printAllVehicles() test - with vehicles==========\n");



    // Clean up

    deallocVehicle(v1);
    deallocVehicle(v2);
    deallocVehicle(v3);

    printf("==========printAllVehicles() tests - without vehicles==========\n");

    printAllVehicles();

    printf("==========End printAllVehicles() test - without vehicles==========\n");



    char filename[] = "test_file.txt";

        // Test of importFromFile, test_file.txt must be in pwd and correctly formatted
    assert(10 == importFromFile("test_file.txt"));
    printAllVehicles();

     //#endif // TESTING

    return EXIT_SUCCESS;
}
