#pragma once

#include "models/Customer.h"
#include "models/Date.h"
#include "models/SalesMan.h"
#include "models/Order.h"
#include "models/Storage.h"

SalesMan* New_SalesMan();

Customer* New_Customer();

Order* New_Order();

SalesManArray* New_SalesManArray();

CustomerArray* New_CustomerArray() ;

OrderArray* New_OrderArray();

Storage* New_Storage();

void Free_Storage(Storage* storage);