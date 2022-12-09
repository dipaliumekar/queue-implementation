/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define max 10
int queue[max];
int front=-1,rear =-1;
void enqueue();
void dequeue();
void display();
int main()
{
    int ch,d,y;
   
    do{
       printf("\n Enter choice :");
       printf("\n 1.Insert \n 2.Delete \n 3.Display \n");
        scanf("%d",&ch);
        switch(ch)
       {
           case 1:/* printf("\n Enter data :");
                   scanf("%d",&d);*/
                   enqueue();
                   break;
           case 2:  dequeue();
                   /*printf("\n data deleted is %d",d);*/
                   break;
           case 3 : display();
                    break;
       }
       printf("\n Do you want to continue ?(0/1)");
       scanf("%d",&y);
       
    }
    while(y==1);
   
}
 void enqueue()
 {
     int element;
     printf("\n Enter the element :");   //to check queue is full or not
     scanf("%d",&element);
     if(((rear+1)%max==front) || ((rear== max-1 ) && (front == 0)))
     {
         printf("\nQueue is full");
         return;
     }
     else if (rear==-1)  // to check queue is empty
     {
         front = rear=0;
         queue[rear]=element;
     }
     else             //for other condition
     {
       rear = (rear+1)%max;
       queue[rear]=element;
     }
 }
void dequeue()
 {
     if(front==-1)
     {
         printf("\n underflow");
         return;
         
     }
     else if (front==rear)
     {
         front=rear=-1;
     }
     else  
     {
        printf("\nElement deleted from queue is :%d ",queue[front]);
       front = (front+1)%max;

     }
   
 }
 void display()
 {
     if(rear >front)
     {
         for(int i=front; i<=rear ;i++)
         {
             printf(" %d ",queue[i]);
         }
     }
         else
         {
             for(int i=front;i<max ;i++)
             {
             printf(" %d ",queue[i]);
             }
             for(int i=0 ; i<=rear ;i++)
             {
             printf(" %d ",queue[i]);
             }
         }
     
 }