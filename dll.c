#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node_s{

   int data;
   struct node_s *next,*prev;

}node_t;

node_t *HEAD;

node_t *creat_new_node(int value){

   node_t *newnode=(node_t *)malloc(sizeof(node_t));
   newnode->data=value;
   newnode->next=NULL;
   newnode->prev=NULL;



    return newnode;
}

void insert_at_head(int value){

node_t *temp,*pos,*newnode=creat_new_node(value);

if(HEAD == NULL) {
		
		HEAD = newnode;
		return;
	}
	HEAD->prev = newnode;
	newnode->next = HEAD;
	HEAD = newnode;
}

void insert_at_tail(int value){

node_t *temp,*newnode=creat_new_node(value);
temp=HEAD;
while(temp->next!=NULL) temp=temp->next;

temp->next=newnode;
newnode->prev=temp;
newnode->next=NULL;

}

void find(int value){

   node_t* temp=HEAD;
 
   while(temp->next!=NULL){
     if(temp->data==value){

        printf("Ok Element Found\n");
        break;
     }
     else
     {
       temp=temp->next;
     }
  
  }
  if(temp->data!=value){
    printf("Element not Found\n");
  } 
}


void delete(int value){
  node_t* pre,*pos,*temp=HEAD;
  bool p=false;
    while(temp->next!=NULL){
     if(temp->data==value){
       p=true;
      // pos=temp->next;
     //  pre->next=temp->next;
     //  pre=pos->prev;
       printf("Ok Deleted %d \n",temp->data);
       break;
     }
     else
     {
       pre=temp;
       temp=temp->next;
     }
  
  }
  if(!p){
    printf("Element not Found\n");
  }else{
    free(temp);
  }
  
  }


void print(){
  int a=0;
  node_t* temp=HEAD;

  while(temp->next!=NULL){
     
   if(a!=0) printf("%d \n",temp->data); 

   temp=temp->next;

   a++;
  }
  
}

void print_revers(){

     node_t *temp=HEAD;
     while(temp->next!=NULL) temp=temp->next;

     while(temp->prev!=NULL){
     
      printf("%d \n",temp->data); 

      temp=temp->prev;

  }

}



int main(){
 
   HEAD=(node_t*)malloc(sizeof(node_t));
   HEAD->data=0;
   HEAD->next=NULL;
   HEAD->prev=NULL;

insert_at_head(21);
insert_at_head(32);
insert_at_head(46);
insert_at_head(47);
insert_at_head(51);
insert_at_head(20);
insert_at_head(54);


delete(51);
//find(47);
print_revers();
print();
    return 0;
}