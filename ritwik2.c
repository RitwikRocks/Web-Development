#include<stdio.h>
#include<stdlib.h>
struct dll{
  int data;
  struct dll *prev;
  struct dll *next;
};
struct dll *start=NULL;
void traverse()
{
    struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
    ptr=start->prev;
    printf("\n The Current list in Reverse order is : \n");
    while(ptr!=start)
    {

        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d ",ptr->data);
    printf("\n");
}
void traverse2()
{
    struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
    ptr=start;
    printf("\n The Current list  is : \n");
    while(ptr->next!=start)
    {

        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
    printf("\n");
}
void insertfirst()
{
    struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
    printf("\n Enter data to be inserted : ");
    int da=0;
    scanf("%d",&da);
    if(start==NULL)
    {
        ptr->data=da;
           start=ptr;
        ptr->next=start;
        ptr->prev=start;

    }
    else
    {
        ptr->data=da;
       start->prev->next=ptr;
       ptr->prev=start->prev;
       ptr->next=start;
       start->prev=ptr;
       start=ptr;
    }
}
void insertlast()
{
    struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
      struct dll *p=(struct dll *)malloc(sizeof(struct dll));
    printf("\n Enter data to be inserted : ");
    int da=0;
    scanf("%d",&da);
    if(start==NULL)
    {
        ptr->data=da;
           start=ptr;
        ptr->next=start;
        ptr->prev=start;
    }
    else
    {
        ptr->prev=start->prev;
       start->prev->next=ptr;
       ptr->next=start;
       start->prev=ptr;
    }
}
void insertindex()
{
     struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
      struct dll *p=(struct dll *)malloc(sizeof(struct dll));
    printf("\n Enter data and index to be inserted : ");
    int da=0,index=0;
    scanf("%d%d",&da,&index);
    int i=0;
    p=start;
    while(i<index-1)
      {
          p=p->next;
         i=i+1;
      }
      ptr->data=da;
      ptr->next=p->next;
      (p->next)->prev=ptr;
      ptr->prev=p;
      p->next=ptr;



}
void deletefirst()
{
    if(start==NULL)
        printf("\n No elements present.\n ");
    else{

         struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
         ptr=start;

         start=start->next;
         if(start->next=start)
         {
             ptr=start;
             start=NULL;
         }
         if(start!=NULL&&start->next!=start)
         {start->prev=ptr->prev;
           ptr->next=start;

         }
          printf("\n The deleted element is : %d \n",ptr->data);
         free(ptr);
    }
}
void deletelast()
{
    if(start==NULL)
        printf("\n No elements present.\n ");
    else{

         struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
         struct dll *p=(struct dll *)malloc(sizeof(struct dll));
         ptr=start->prev;
         p=ptr->prev;
         p->next=start;
         start->prev=p;
         p->prev=ptr->prev->prev;
         ptr->prev->prev->next=p;

         printf("\n The deleted element is : %d \n",ptr->data);
         free(ptr);
    }
}
void deleteindex()
{
    if(start==NULL)
        printf("\n No elements present.\n ");
    else{

    struct dll *ptr=(struct dll *)malloc(sizeof(struct dll));
    struct dll *p=(struct dll *)malloc(sizeof(struct dll));
    printf("\n Enter  index to be deleted : ");
    int index=0;
    scanf("%d",&index);
    int i=0;
    p=start;
    while(i<index-1)
      {
          p=p->next;
         i=i+1;
      }
    ptr=p->next;
    p->next=ptr->next;
    ptr->next->prev=p;
      printf("\n The deleted element is : %d \n",ptr->data);
         free(ptr);
    }
}
int main()
{
  printf("\n Doubly Linked List \n");
  int choice;
  do{
    printf("\t MENU \n");
    printf("1.Insertion at the beginning \n");
    printf("2.Insertion at the end \n");
    printf("3.Insertion at the index \n");
    printf("4.Deletion from the beginning\n");
    printf("5.Deletion from the end\n");
    printf("6.Deletion from the index\n");
    printf("7.Print list from beginning\n");
    printf("8.Print list from end");
    printf("\n Enter your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insertfirst();
               break;
        case 2:insertlast();
               break;
        case 3:insertindex();
               break;
        case 4:deletefirst();
                break;
        case 5:deletelast();
               break;
        case 6:deleteindex();
               break;
        case 7:traverse2();
               break;
        case 8:traverse();
               break;
        default:printf("\n Wrong choice entered\n");
    }

  }
  while(choice>=1&&choice<=8);
  return 0;
}
