#include <stdio.h>
#include <stlib.h>/*for transfering from char to int or double with atof*/
#include <ctype.h>/* for isdigit function*/

#define MAXOP 100 /* max size of operand or operator */
#define MAXVAL 100 /* maximum depth of val stack */
#define NUMBER '0' /* Signal that a number was found */


int getop(char[]);
void push(double);
double pop(void);
void ungetchh(int);/* double hh because we dont want a colution betwen function 			ungetch with only one h at the end*/

int getchh(void);/* double hh because we dont want a colution betwen function 				getch with only one h at the end*/

/*until here all that you see above going to be in header file*/


/*reversc Polish calculator*/
void main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type=getop(s))!=EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2=pop()
				push(pop()-op2);
				break;
			case '/':
				op2=pop()
				if(op2)
					push(pop()/op2);
				else
					printf("error:zero divisuin./n");
				break;

			case '\n':
				printf("\t%.4f\n",pop());
				break;
			default:
				printf("error : unknown command %c\n",type)
				break;
		}
	}
}
 
/* golabal varibale */


int sp = 0; /* pointer of the location in the stack*/
double val[MAXVAL]; /* value of the stack*/

void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;/* put f value in the next free place in the stack 					if there is free space*/
	else
		printf("error: stack full, cant push %.4f./n",f);
}

/* pop:pop and return top value from stack*/
double pop(void)
{
	if (sp>0)
		return val[--sp];
	else{
		printf("error:stack is empty\n");
	return 0.0;
	}
}

/* getop:get the next character or numeric operand*/
int getop(char s[])
{
inr i = 0,c;
while((c=getchh())==''||c=='\t')
;
if(!isdigit(c)&&c!='.')
	return c;/* means not a number*/
s[i++]=c;
if(isdigit(c))/* collect integer part*/
	while(isdigit(s[i++]=c=getchh()))
	;
if(c=='.')/* collect fractional part*/
	while(isdigit(s[i++]=c=getchh()))
		;
s[i--]='\0';
if(c!=''&&c!='\t')
	ungetchh(c);
return NUMBER;
}

/* global var */

enum {EMPTY,FULL};
int flag = EMPTY,buf;



/*new function*/

int getchh(void)/* get a possibly pushed back character*/
{
if(flag==FULL){
	flag=EMPTY;
	return buf;
}

else
	return getchar();
}

void ungetchh(int c) /* push character back on input*/
{
if(flag==EMPTY){
	buf=c;
	flag = FULL;
}
else
	printf("Buffer is full can not enter more information");
}










































