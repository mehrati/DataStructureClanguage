#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int count=-1;
int data[SIZE];
void push(int val);
void pop();

int main(){
    
while(1){

int select;

if(count==-1)

    printf("if push Enter 1 and if End Enter 3 : ");
      
else if(count==100)

    printf("if pop Enter 2 and if End Enter 3 : ");
      
else
    
    printf("if push Enter 1 and if pop Enter 2 and if End Enter 3 : ");

scanf("%d",&select);

if(select==1){
    
int val;

printf("Enter Value : ");

scanf("%d",&val);

push(val);

}
else if(select==2)

      pop();

else if(select==3)

       break;

}


return 0;

}

//***********************************************
void push(int val){
    
    if(count==100){

       printf("stack is full");
    }
    else{
    
       count++;

       data[count]=val;
    }
}

//***********************************************
void pop(){
    
    if(count==-1){
    
       printf("no data in stack!!! \n");
       
    }
     else{

       int val=data[count];

       data[count]=0;

       count--;

       printf("Vlaue is : %d\n",val);
     }
}
