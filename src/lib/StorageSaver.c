#include "constants.h"
#include "models/Customer.h"
#include "models/Date.h"
#include "models/SalesMan.h"
#include "models/Order.h"
#include "models/Storage.h"

#include "lib/Storage.h"

#include <stdlib.h>
#include <string.h>

// функция добавления нового продавца
// TODO:
// добавить сохранения в БД
void Add_SalesMan
(
    Storage* storage,
    unsigned int id,
    char sname[],
    char city[],
    int comm
) {
    SalesMan* salesman = New_SalesMan();
    salesman->snum = id;
    salesman->comm = comm;
    memcpy(salesman->sname, sname, sizeof(char) * STR_LENGTH);
    memcpy(salesman->city,city, sizeof(char) * CITY_LENGTH);
	
    memcpy(storage->SalesMan->SalesMan[storage->SalesMan->len], salesman, sizeof(SalesMan));
	storage->SalesMan->len++;
}

