/*
 * dyn_arr.h
 *
 *  Created on: Apr. 15, 2020
 *      Author: takis
 */

#ifndef MY_INCLUDES_DYN_ARR_H_
#define MY_INCLUDES_DYN_ARR_H_

#include <stdlib.h>
#include "list_db.h"

/*****************************************************
 * TYPEDEFS
 *****************************************************/

// define an element-type for our dynamic array
struct stuDAStruct
{
	stuRec_t data;
};
typedef struct stuDAStruct stuDA_t;

enum sortenum
{
	fNamesort, gNamesort, gradesort
};
typedef enum sortenum sort_t;

/*****************************************************
 * PUBLIC FUNCTION PROTOTYPES
 *****************************************************/

stuDA_t* formDynamicArray(stuLL_t*, size_t);

stuDA_t* sortDynamicArray(stuDA_t*, const sort_t, const size_t);

void displayDynamicArray(stuDA_t*, const size_t);

#endif /* MY_INCLUDES_DYN_ARR_H_ */
