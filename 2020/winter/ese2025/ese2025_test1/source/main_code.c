/*
 * main_code.c
 *
 *  Created on: Apr. 15, 2020
 *      Author: takis
 *      Author: you too!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_db.h"
#include "dyn_arr.h"

/*****************************************************
 * PRIVATE FUNCTIONS
 *****************************************************/
stuRec_t fillStudentRecord(const char *fam_name, const char *giv_name,
		const float grade)
{
	stuRec_t ret;
	strcpy(ret.fName, fam_name); // set family name
	strcpy(ret.gName, giv_name); // set given name
	ret.grade = grade;	// set the grade

	return ret;
}

/*****************************************************
 * MAIN FUNCTION
 *****************************************************/
int main(int argc, char *argv[])
{
	stuLL_t *pHead = NULL; // pointer to student data structure
	size_t student_count = 0; // count of students
	char fam_name[STRSIZE] = ""; // variable to hold a last name
	char giv_name[STRSIZE] = ""; // variable to hold a given name
	float grade = 0.0; // variable to hold a student grade
	stuRec_t stdata;

	// read data from standard input
	printf("Command %s %s detected...\n", argv[1], argv[2]);
	printf("Reading data ... \n \n");
	_Bool readExitFlag = 0;
	while (!readExitFlag)
	{
		scanf("%s %s %f\n", fam_name, giv_name, &grade);
		printf("%s %s %f\n", fam_name, giv_name, grade);

		if (strcmp(fam_name, EOFSTR)) // if the strings are EQUAL, strcmp() will return 0, i.e., false
		{
			// data is valid
			printf("... creating student record ...\n");
			stdata = fillStudentRecord(fam_name, giv_name, grade);
			printf("... done... adding student record to linked list...\n");
			pHead = addNodeLinkedList(pHead, stdata);
			printf("... done... accessing next student data... \n");
			++student_count;
		}
		else
		{
			// we have reached the end of the data
			readExitFlag = 1;
		}
		printf("\n\n");
	}

	// process request
	char *commandStr = argv[1];
	if (!strcmp(commandStr, "find"))
	{
		char *targetFamilyName = argv[2];
		printf("find command executing... ");
		printf("looking for family name: %s\n\n", targetFamilyName);
		stuLL_t *pNode = findLinkedList(pHead, targetFamilyName);
		printf("displaying discovered node: \n");
		displayNodeLinkedList(pNode);
	}
	else if (!strcmp(commandStr, "sort"))
	{
		printf("sort command executing... \n");
		stuDA_t *pHeadArr = formDynamicArray(pHead, student_count);
		char *arg2 = argv[2];
		printf("	printing contents of dynamic array: \n");
		displayDynamicArray(pHeadArr, student_count);
		printf("\n\n");
		if (!strcmp(arg2, "family"))
		{
			// sort by family name
			printf("	sorting by family name... printing... \n");
			pHeadArr = sortDynamicArray(pHeadArr, fNamesort, student_count);
		}
		else if (!strcmp(arg2, "given"))
		{
			// sort by given name
			printf("	sorting by given name... printing... \n");
			pHeadArr = sortDynamicArray(pHeadArr, gNamesort, student_count);
		}
		else
		{
			// sort by grade (by default)
			printf("	sorting by grades... printing... \n");
			pHeadArr = sortDynamicArray(pHeadArr, gradesort, student_count);
		}
		displayDynamicArray(pHeadArr, student_count);
		printf("\n\n");
	}

	// exit normally
	return 0;
}

