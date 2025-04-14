#pragma once
#include "SalesMan.h"
typedef struct {
    unsigned int cnum;
	char cname[STR_LENGTH];
    char city[CITY_LENGTH];
    double rating;
    unsigned int snum;
    SalesMan* SalesMan;
}Customer;