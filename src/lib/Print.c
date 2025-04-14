#include "constants.h"
#include "models/Customer.h"
#include "models/Date.h"
#include "models/SalesMan.h"
#include "models/Order.h"
#include "models/Storage.h"
#include <stdio.h>

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
