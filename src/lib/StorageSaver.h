#pragma once


#include "models/Customer.h"
#include "models/Date.h"
#include "models/SalesMan.h"
#include "models/Order.h"
#include "models/Storage.h"



void Add_SalesMan
(
    Storage* storage,
    unsigned int id,
    char sname[],
    char city[],
    int comm
) ;