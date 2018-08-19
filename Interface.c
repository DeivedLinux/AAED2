#include "Interface.h"		
#include "Depedent.h"
#include "Employee.h"
#include "Exception.h"									
#include <stdio.h>


GtkWidget* myWindow;
private FILE* EmployeeFile;
private FILE* DepedentFile;



void InterfaceInit(void)
{
	
}



void __attribute__((destructor))Exit(void)
{
	FileClose(EmployeeFile);
	FileClose(DepedentFile);
}