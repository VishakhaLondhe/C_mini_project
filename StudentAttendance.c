#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char name[20][30];
int presentattendance[20]={0};
int absentatt[20]={0};
int indexnumber=0;

void checkattendance()
{
	int i;
	printf("\nTotal present || Total absent\n");
	for(i=0;i<indexnumber;i++)
	{
		
		printf("%s",name[i]);
		printf("%d %d",presentattendance[i] ,absentatt[i]);
	}
}



void addstude()
{
	int i,add,num=0;
	if(indexnumber==0)
	{
		printf("Enter number student you want to add...");
		scanf("%d",&num);
		
		for(i=0;i<num;i++);
		{
		printf("\nEnter %d student name to add in attendance ragister:",i);
			gets(name[i]);
			indexnumber++;
		}
		
	}
	else
	{
		printf("Enter number student you want to add...");
		scanf("%d",&num);
		add =indexnumber+num;
		for(i=indexnumber;i<add;i++)
		{
		printf("\nEnter %d student name to add in attendance ragister:",i+1);
			gets(name[i]);
			indexnumber++ ;
			
		}
		
	}
}





void removestudent()
{
	char sname[30]; 
	int i,j;
	
	printf("Enter name to remove:");
	gets(sname);
	for(i=0;i<indexnumber;i++)
	{
		if(strcmp(sname,name[i])==0)
		{
		
		for(j=i;j<indexnumber;j++)
		{
			strcpy(name[j],name[j+1]);
			presentattendance[i]=presentattendance[i+1];
			absentatt[i]=absentatt[i+1];
			

			
		}
		indexnumber--;
		printf("student removed..%s",sname);
		break;
	}
	else if(i==indexnumber-1){
		printf("the student does not exits");	
		
	}
		
	}
}


void takeattendance()
{
	int i;
	char ch;
	printf("\n Enter y for present N for absent");
	for(i=0;i<indexnumber;i++)
	{
		repeate:
		printf(" %d %s is present",i+1,name[i]);
		scanf("%c",&ch);
		if(ch =='y'||ch=='Y')
		{
			presentattendance[i]+=1;	
		}
		else if(ch =='n'||ch=='N')
		{
			absentatt[i]+=1;
		}
		else
		{
			printf("Invalid choice");
			goto repeate;
		}
		
	}
}


void main()
{
	int choose;
	do
	{
		printf("\n*************Main menu********************");
		printf("\n enter 1 for add student");
		printf("\n enter 2 for add attendance");
		printf("\n enter 3 for check attendance");
		printf("\n enter 4 for remove student");
		printf("\n enter 5 for exit");
		scanf("%d",&choose);
		
		
		switch(choose)
		{
			case 1:
				addstude();
				break;
			
			case 2:
				takeattendance();
				break;
			case 3:
				checkattendance();
				break;
			case 4:
				removestudent();
				break;
			case 5:
				exit(0);
				break;
			
		}
		
	
		
	}while(choose!=5);
}
