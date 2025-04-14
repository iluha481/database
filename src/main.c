
#include "constants.h"

#include "models/SalesMan.h"
#include "models/Customer.h"
#include "models/Order.h"
#include "models/Date.h"
#include "models/Storage.h"

#include "lib/Storage.h"
#include "lib/Print.h"
#include "lib/StorageSaver.h"

/*
TODO:
добавить добавление всех структур, вывод и удаление
добавить возможность добавлять связи
взаимодействие с БД
вывод с сортировками
вынести функции в отдельный файл
*/
int main(){
    Storage* storage = New_Storage();
	Add_SalesMan(storage, 1,"asda", "asdadasdasda", 100);
	Print_all(storage);
	Free_Storage(storage);
    return 0;
}
