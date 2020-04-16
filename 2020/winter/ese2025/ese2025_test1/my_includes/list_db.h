#ifndef MY_INCLUDES_LIST_DB_H_
#define MY_INCLUDES_LIST_DB_H_

/*
 * list_db.h
 *
 *  Created on: Apr. 15, 2020
 *      Author: takis
 */

/*
 * IMPORTANT DEFINITIONS
 */
#define	STRSIZE 30
#define	EOFSTR	"NULL_NAME"

/*****************************************************
 * TYPEDEFs
 *****************************************************/
struct stuRecStruct
{
	char fName[STRSIZE];
	char gName[STRSIZE];
	float grade;
};
typedef struct stuRecStruct stuRec_t;

struct stuLLStruct
{
	stuRec_t data;
	struct stuStruct *pNext;
};
typedef struct stuLLStruct stuLL_t;

/*****************************************************
 * PUBLIC FUNCTION PROTOTYPES
 *****************************************************/
stuLL_t* addNodeLinkedList(stuLL_t*, stuRec_t);

stuLL_t* findLinkedList(stuLL_t*, char*);

void displayNodeLinkedList(stuLL_t*);

#endif /* MY_INCLUDES_LIST_DB_H_ */
