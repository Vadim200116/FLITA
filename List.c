#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
   struct sNode* next;
   int data;
}tNode;

void push(int data,tNode** head);
int pop(tNode** head);
void showall(tNode* head);


int main(void){
    tNode* head=NULL;
    int log=0;
    int a=0;
    int num=0;
    int ind;
    while(!log){
        printf("Press 1 to push a new number\n");
        printf("Press 2 to pop the last number\n");
        printf("Press any other symbol to quit\n");
        showall(head);
        printf(">");
        scanf("%d",&a);
        switch (a){
            case 1:
            printf("Enter one number\n");
            printf(">");
            scanf("%d",&num);
            push(num,&head);
            break;
        case 2:
            ind=pop(&head);
            if(!ind)
                printf("Failed to pop the last number\n");
            else
                printf("The last number: %d\n",ind);
            break;
        default:
        log=1;
        break;   
         }
    }
    return 0;
}



void showall(tNode* head){
    if(!head){
         printf("\t\tList is empty\n"); 
         return;
         }
    printf("\t\tThat's our list\n");   
    while(head){   
    printf("\t\t%d\n",head->data);
    head=head->next;
    }
}

void push(int data,tNode** head){
   tNode* temp=(tNode*)malloc(sizeof(tNode));
   temp->data=data;
   temp->next=(*head);
   (*head)=temp;
}

int pop(tNode** head){
     tNode* temp=*head;
     if (!(*head)){
         return 0;
     }
     *head=temp->next;
     int data=temp->data;
     free(temp);
     return data;
 }
