/*
 * dyn_arr.c
 *
 *  Created on: Apr. 15, 2020
 *      Author: takis
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_db.h"
#include "dyn_arr.h"

/*****************************************************
 * FUNCTION DECLARATIONS
 *****************************************************/

/*
 * (private) function provides comparison between two array elements for qsort(), based on fName
 *
 */
int comparo_fName(const void *pA, const void *pB)
{

	// PROBLEM #3: complete the code for this function
	//	       NOTE: PLEASE COMMIT CHANGES ONCE YOUR DONE THIS FUNCTION
}

/*
 * (private) function provides comparison between two array elements for qsort(), based on gName
 *
 */
int comparo_gName(const void *pA, const void *pB)
{
	// extract student records
	stuDA_t student_A = *((stuDA_t*) pA);
	stuDA_t student_B = *((stuDA_t*) pB);

	// get student given names
	char *gName_A = student_A.data.gName;
	char *gName_B = student_B.data.gName;

	return strcmp(gName_A, gName_B);
}

/*
 * (private) function provides comparison between two array elements for qsort(), based on grade
 *
 */
int comparo_grade(const void *pA, const void *pB)
{
	// PROBLEM #4: complete the code for this function
	//	       NOTE: PLEASE COMMIT CHANGES ONCE YOUR DONE THIS FUNCTION
}

/*
 * function forms a dynamically allocated array based on the linked list
 */
stuDA_t* formDynamicArray(stuLL_t *pHEAD_LL, size_t student_count)
{
	/* create an array with enough elements */
	stuDA_t *pHEAD_DA = (stuDA_t*) malloc(student_count * sizeof(stuRec_t));

	/* now transfer the data from record to the array */
	stuLL_t *pW_LL = pHEAD_LL; // if pHEAD_LL is NULL, we will return NULL
	size_t i = 0;
	while (pW_LL != NULL)
	{
		strcpy(pHEAD_DA[i].data.fName, pW_LL->data.fName); // assign fName
		strcpy(pHEAD_DA[i].data.gName, pW_LL->data.gName); // assign gName
		pHEAD_DA[i].data.grade = pW_LL->data.grade; // assign grade
		pW_LL = pW_LL->pNext; // go to next linked-list element
		++i; // increment to next array index
	}

	return pHEAD_DA;
}

/*
 * function uses std qsort() function to sort the dynamic array
 */
stuDA_t* sortDynamicArray(stuDA_t *pHEAD, const sort_t sort_type,
		const size_t array_size)
{
	// PROBLEM #5: complete the code for this function
	//	       NOTE: PLEASE COMMIT CHANGES ONCE YOUR DONE THIS FUNCTION

	switch (sort_type)
	{
	case fNamesort:
		qsort(pHEAD, array_size, sizeof(stuRec_t), comparo_fName);
		break;
	case gNamesort:
		// fill the code here for Part a)
	case gradesort:
		// fill the code here for Part b)
	}
	return pHEAD;
}

/*
 * function sends the dynamic array data to stdout
 */
void displayDynamicArray(stuDA_t *pHEAD, const size_t array_size)
{
	size_t i;
	printf("%-12s %-12s %-5s\n", "FAMILY NAME", "GIVEN NAME", "GRADE");
	for (i = 0; i != array_size; ++i)
	{
		printf("%-12s %-12s %2.3f\n", pHEAD[i].data.fName, pHEAD[i].data.gName,
				pHEAD[i].data.grade);
	}
}

