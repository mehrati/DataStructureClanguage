#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

void enqueue();
void dequeue();


int queue_array[MAX_SIZE];
int rear = -1;
int front = -1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.add element to queue \n"
               "2.delete element from queue \n"
               "3.Quit \n"
               "Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            exit(1);
            break;
            default:
            printf("Wrong choice \n");
            
        } 
    } 
    return 0;
}
//**************************************************************************
void enqueue()
{
    int add_item;
    if (front == MAX_SIZE)
    {
    printf("Queue Overflow \n");
    }
    else
    {
        printf("Enter number element in queue : ");
        scanf("%d", &add_item);
        front++;
        queue_array[front] = add_item;
       
    }


}
//************************************************************************** 
void dequeue()
{

    if (front > rear )
    {
        
        rear++;
        printf("deleted %d Element from queue\n", queue_array[rear]);
        queue_array[rear]=0;
        
    }
    else{
        printf("Queue is empty!!! \n");
    }
} 
//************************************************************************


