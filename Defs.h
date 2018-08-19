#ifndef DEFS_H_
#define DEFS_H_


#include <stdio.h>


#define MAX_NAME_EMPLOYEE 20UL
#define private static 


typedef union
{
	int* spointer;
	unsigned int* upointer;
	int sword;
	unsigned int uword;
	unsigned short uHalf[2];
	short half[2];
}Integer;


#endif