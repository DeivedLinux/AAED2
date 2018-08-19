#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Defs.h"

#ifndef MAX_NAME_EMPLOYEE
#define MAX_NAME_EMPLOYEE	20UL
#endif

typedef struct Employee
{
	unsigned char name[MAX_NAME_EMPLOYEE];
	unsigned short age;
	float salary;
	unsigned int codeOfTheEmployee;
	Integer next;
}*Employee;





#endif	