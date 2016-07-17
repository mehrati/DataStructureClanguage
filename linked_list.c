#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s{

int data;
struct node_s *next;

}node_t;

node_t *HEAD;

node_t* creat_new_node(int value){

  node_t *newnode;
  newnode=(node_t*)malloc(sizeof(node_t));
  newnode->data=value;
  newnode->next=NULL;

  return newnode;
}
void insert_at_head(int value){

  node_t* newnode=creat_new_node(value);
  
  newnode->next=HEAD->next;
  HEAD->next=newnode;

}
void insert_at_tail(int value){

  node_t* newnode=creat_new_node(value);
  node_t* temp=HEAD;
  while(temp->next!=NULL) temp=temp->next;
  temp->next=newnode;
  newnode->next=NULL;

}
void find(int val){
  node_t* temp=HEAD;
 
   while(temp->next!=NULL){
     if(temp->data==val){
        printf("Ok Element Found\n");
        break;
     }
     else
     {
       temp=temp->next;
     }
  
  }
  if(temp->data!=val){
    printf("Element not Found\n");
  } 
  

}
void delete(int val){
  node_t* pre,*temp=HEAD;
  while(temp->data!=val){ 
    pre=temp;
    temp=temp->next;
  
  }
  if(temp->data!=val){
    printf("Element not Found\n");
    return ;
  }
pre->next=temp->next;
free(temp);
}
void print(){
  int a=0;
  node_t* temp=HEAD;

  while(temp!=NULL){
     
   if(a!=0) printf("%d \n",temp->data); 

   temp=temp->next;
   a++;
  }
  
}

int main(){


HEAD=(node_t*)malloc(sizeof(node_t));
HEAD->next=NULL;
HEAD->data=0;

insert_at_tail(21);
insert_at_head(32);
insert_at_head(46);
insert_at_tail(47);
insert_at_head(51);
insert_at_tail(20);
insert_at_head(54);
delete(47);
print();
find(47);
  return 0;
}
