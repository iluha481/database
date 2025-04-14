#pragma once
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
