#ifndef DEPEDENT_H_
#define DEPEDENT_H_ 


#ifndef MAX_NAME_DEPEDENT
#define MAX_NAME_DEPEDENT 20UL
#endif

typedef struct Depedent
{
	unsigned int code;
	unsigned int whoAmIDepedentOn;
	unsigned char name[MAX_NAME_DEPEDENT];
}*Depedent;



#endif