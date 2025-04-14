
#include "constants.h"
#include "models/Customer.h"
#include "models/Date.h"
#include "models/SalesMan.h"
#include "models/Order.h"
#include "models/Storage.h"
#include <stdlib.h>
#include <string.h>
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