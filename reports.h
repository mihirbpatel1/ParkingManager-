# ifndef REPORTS_H
# define REPORTS_H




#define MAX_VEHICLE_ROW 10
#define MAX_VEHICLE_COL 10
typedef enum {CAR, TRUCK, SUV} VType;
// Data type to represent a single vehicle
typedef struct {
    char* model;               // string with the make and model of the vehicle
    char* plate;               // licence plate of the vehicle as a string
    VType type;          // either CAR, TRUCK OR SUV
    double curFuel;          // current fuel level, in litres
    double maxFuel;       // maximum fuel level, in litres
} Vehicle;

extern Vehicle* Garage[MAX_VEHICLE_ROW][MAX_VEHICLE_COL];

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

#endif
