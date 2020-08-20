#include <assert.h>     // for assert()
#include <stdio.h>      // for printf(), etc.
#include <stdlib.h>     // for EXIT_SUCCESS, abs(), etc.
#include <string.h>     // for strcpy(), strlen(), etc.

// local headers
#include "reports.h"   	// for the reports data structure and functions
#include "vehicle.h" 	// for the vehicle functions




const int MAX_READ_SIZE = 2000;

int main(){
  	Vehicle* Garage[MAX_VEHICLE_ROW][MAX_VEHICLE_COL];
	for (int r = 0; r < MAX_VEHICLE_ROW; r++) {
        for (int c = 0; c < MAX_VEHICLE_COL; c++) {
            
                Garage[r][c] = NULL;
                // Allow loop to continue on the off-chance the vehicle is
                // listed in the garage multiple times
            
        }
    }

  	
  	
  	
  	
  	char v1_model[] = "1982 Ford F-150";
  	char v1_plate[] = "ABC 123";
  	Vehicle *v1 = allocVehicle(v1_model, v1_plate, TRUCK, 93.24, 100);
  	char v2_model[] = "1994 Ford Taurus";
  	char v2_plate[] = "CMP 214";
 	 Vehicle *v2 = allocVehicle(v2_model, v2_plate, CAR, 4.54, 45);

 
 
 	assert(calcFuel(NULL) == -1);
    
    // Testing refuelVehicle function
    assert(refuelVehicle(v2, 10) == 0);
    assert(v2->curFuel == 14.54);
    
    assert(refuelVehicle(v1, 105834) == 0);
    assert(v1->curFuel == 100);
    
    // Invalid cases
    assert(refuelVehicle(v1, -1) == -1);
    assert(refuelVehicle(NULL, 10) == -1);
    
    
    printf("==========printRefuelReport() test - without vehicles==========\n");
    
    printRefuelReport();
    
    printf("==========End printRefuelReport() test - without vehicles==========\n");
    
    printf("==========printGarageMap() test - without vehicles==========\n");
    
    printGarageMap();
    
    printf("==========End printGarageMap() test - without vehicles==========\n");
    
    
      //  #endif // TESTING

    return EXIT_SUCCESS;
}
