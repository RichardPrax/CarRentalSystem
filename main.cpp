//if include <json/value.h> line fails (latest kernels), try also:
//  #include <jsoncpp/json/json.h>
#include "json/json.h"
#include <fstream>
#include <iostream>


std::ifstream car_file("cars.json", std::ifstream::binary);
Json::Value car;
std::ifstream car_file >> car;

std::cout<<people; //This will print the entire json object.

//The following lines will let you access the indexed objects.
cout<<people["Anna"]; //Prints the value for "Anna"
cout<<people["ben"]; //Prints the value for "Ben"
cout<<people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

cout<<people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.