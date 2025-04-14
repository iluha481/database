#pragma once
#include "Date.h"
#include "SalesMan.h"
#include "Customer.h"

typedef struct {
    unsigned int onum;
    Date date;
    unsigned int amount;
    unsigned int snum;
    SalesMan* SalesMan;
    unsigned int cnum;
    Customer* Customer;
}Order;