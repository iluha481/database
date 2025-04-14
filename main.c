#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGTH 40
#define CITY_LENGTH 30
#define ARR_LENGTH 10


/*
TODO:
добавить добавление всех структур, вывод и удаление
добавить возможность добавлять связи
взаимодействие с БД
вывод с сортировками
вынести функции в отдельный файл


*/

typedef struct {
    unsigned int sec;
    unsigned int min;
    unsigned int hour;
    unsigned int day;
}Date;

typedef struct {
    unsigned int snum;
    char sname[STR_LENGTH];
    char city[CITY_LENGTH];
    double comm;
}SalesMan;

typedef struct {
    unsigned int cnum;
	char cname[STR_LENGTH];
    char city[CITY_LENGTH];
    double rating;
    unsigned int snum;
    SalesMan* SalesMan;
}Customer;

typedef struct {
    unsigned int onum;
    Date date;
    unsigned int amount;
    unsigned int snum;
    SalesMan* SalesMan;
    unsigned int cnum;
    Customer* Customer;
}Order;
//
//
// структуры для хранения массивов
typedef struct {
    int len;
    SalesMan* SalesMan[ARR_LENGTH];

}SalesManArray;

typedef struct {
    int len;
    Customer* Customer[ARR_LENGTH];

}CustomerArray;

typedef struct {
    int len;
    Order* Order[ARR_LENGTH];

}OrderArray;

// структура хранилища
// содержит массивы данных
//
// TODO:
// добавить поле с указателем на базу данных
typedef struct {
    OrderArray* Order;
    CustomerArray* Customer;
    SalesManArray* SalesMan;
	//db *DB
}Storage;

// вспомогательная функция создания нового продавца
// возвращает указатель на SalesMan
SalesMan* New_SalesMan() {
    SalesMan* salesman = malloc(sizeof(SalesMan));
    return salesman;
}

// вспомогательная функция создания нового покупателя
// возвращает указатель на Customer
Customer* New_Customer() {
    Customer* customer = malloc(sizeof(Customer));
    customer->SalesMan = New_SalesMan();
    return customer;
}

// вспомогательная функция создания нового заказа
// возвращает указатель на Order
Order* New_Order(){
    Order* order = malloc(sizeof(Order));
    order->SalesMan = New_SalesMan();
    order->Customer = New_Customer();
    return order;
}

// вспомогательная функция создания массива
// выделяет память под массив и его элементов
// вовзращает указатель на SalesManArray
SalesManArray* New_SalesManArray() {
    SalesManArray* arr = malloc(sizeof(SalesManArray));
    arr->len = 0;
    for(int i = 0; i < ARR_LENGTH; i++){
        arr->SalesMan[i] = New_SalesMan();
    }
    return arr;
}

// вспомогательная функция создания массива
// выделяет память под массив и его элементов
// вовзращает указатель на CustomerArray
CustomerArray* New_CustomerArray() {
    CustomerArray* arr = malloc(sizeof(CustomerArray));
    arr->len = 0;
    for(int i = 0; i < ARR_LENGTH; i++){
        arr->Customer[i] = New_Customer();
    }
    return arr;
}

// вспомогательная функция создания массива
// выделяет память под массив и его элементов
// вовзращает указатель на OrderArray
OrderArray* New_OrderArray() {
    OrderArray* arr = malloc(sizeof(OrderArray));
    arr->len = 0;
    for(int i = 0; i < ARR_LENGTH; i++){
        arr->Order[i] = New_Order();
    }
    return arr;
}

// функция создания хранилища
// выделяет память под массивы данных и их элементов
// возвращает указатель на Storage
// перед завершением программы нужно вызвать функцию Free_Storage, передав в неё указатель на Storage
Storage* New_Storage() {
    Storage* storage = malloc(sizeof(Storage));
    storage->Customer = malloc(sizeof(CustomerArray));
    storage->SalesMan = malloc(sizeof(SalesManArray));
    storage->Order = malloc(sizeof(OrderArray));
    memcpy(storage->Customer, New_CustomerArray(), sizeof(CustomerArray));
    memcpy(storage->SalesMan, New_SalesManArray(),sizeof(SalesManArray));
    memcpy(storage->Order, New_OrderArray(), sizeof(OrderArray));
    return storage;
}


// функция очистки Storage
void Free_Storage(Storage* storage) {
	for(int i = 0; i < ARR_LENGTH; i++) {
		free(storage->SalesMan->SalesMan[i]);
		free(storage->Customer->Customer[i]);
		free(storage->Order->Order[i]);
	}
	free(storage->SalesMan);
	free(storage->Customer);
	free(storage->Order);
	free(storage);
}

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


// функция вывода продавцов в виде таблицы
void Print_all(Storage* storage){

	printf("\
                   SalesMan                                               Customer                                                Order                          \n\
+-------+--------------+--------------+-----------+ +-------+--------------+--------------+-----------+--------+ +-------+--------------+--------------+--------+\n\
|  id   |     name     |     city     | commision | |  id   |     name     |     city     |   rating  |  snum  | |  id   |    amount    |     cnum     |  snum  |\n\
+-------+--------------+--------------+-----------+ +-------+--------------+--------------+-----------+--------+ +-------+--------------+--------------+--------+\n");  
	int salesman_i = 0;
	int customer_i = 0;
	int order_i = 0;
	int max_i = storage->SalesMan->len;
	if(max_i < storage->Customer->len){
		max_i = storage->Customer->len;
	}
	if(max_i < storage->Order->len){
		max_i = storage->Order->len;
	}
	for(int i = 0; i < max_i; i++){
		if(salesman_i < storage->SalesMan->len && storage->SalesMan->SalesMan[salesman_i]->snum != 0){
		printf("|%-7u|%-14s|%-14s|%-11.2lf| ",storage->SalesMan->SalesMan[salesman_i]->snum, storage->SalesMan->SalesMan[salesman_i]->sname, storage->SalesMan->SalesMan[salesman_i]->city, storage->SalesMan->SalesMan[salesman_i]->comm); 
		}
		else{
			printf("|%-49s| ", "-");
		}
		if(customer_i < storage->Customer->len && storage->Customer->Customer[customer_i]->cnum != 0){
		printf("|%-7u|%-14s|%-14s|%-11.2lf|%-8u|",storage->Customer->Customer[customer_i]->cnum, storage->Customer->Customer[customer_i]->cname, storage->Customer->Customer[customer_i]->city, storage->Customer->Customer[customer_i]->rating, storage->Customer->Customer[customer_i]->snum);
		}else{
			printf("|%-58s| ", "-");
		}
		if(order_i < storage->Order->len && storage->Order->Order[order_i]->onum != 0){
			printf("|%-7u|%-14u|%-14u|%-8u|\n", storage->Order->Order[order_i]->onum, storage->Order->Order[order_i]->amount, storage->Order->Order[order_i]->cnum, storage->Order->Order[order_i]->snum);
		}else{
			printf("|%-46s| \n", "-");
		}

		printf("+-------+--------------+--------------+-----------+ +-------+--------------+--------------+-----------+--------+ +-------+--------------+--------------+--------+\n");  
		salesman_i++;
		customer_i++;
		order_i++;
	}
}



int main(){
    Storage* storage = New_Storage();
	Add_SalesMan(storage, 1,"asda", "asdadasdasda", 100);
	Print_all(storage);
	Free_Storage(storage);
    return 0;
}
