# ifndef VEHICLE_H
# define VEHICLE_H





extern const int MAX_READ_SIZE;
extern Vehicle* Garage[MAX_VEHICLE_ROW][MAX_VEHICLE_COL];

Vehicle* allocVehicle(char* model, char* plate, VType type, double curFuel, double maxFuel);



int deallocVehicle(Vehicle* v);

void printVehicle(Vehicle* v);


void printAllVehicles();

double calcFuel(Vehicle* v);
int refuelVehicle(Vehicle* v, double fuelAmount);

int importFromFile(char* file);






#endif
