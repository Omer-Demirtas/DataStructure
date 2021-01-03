#include <stdio.h>
#include <stdlib.h>


struct s
{
    int id;
    char name[20];
    char surName[20];
};
typedef s seat;

struct n
{
    n *next;
    seat *seats;
};
typedef n node;

int carNumber = 0;
int seatNumber = 0;
int maxSeatCount = 10;

node *head = NULL;

void pop(node **head){

    node *temp = *head;

    if(temp == NULL)
    {
        printf("\nSilinecek Bir vagon yok");
    }
    else if(temp->next == NULL) 
    {
        free(head);
        *head = NULL;
        carNumber = 0;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;   
        }
        
        free(temp->next);
        temp->next = NULL;
        carNumber--;
    }
}

void push(node **head){

    node *temp = *head;

    if(temp == NULL)
    {
        printf("\nhead is null");
        temp = (node *)malloc(sizeof(node));
        
        temp->next = NULL;
        temp->seats = (seat *)malloc(sizeof(seat) * maxSeatCount);

        *head = temp;
    }
    else
    {
        printf("\nhead is not null");

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = (node *)malloc(sizeof(node));
        
        temp->next->next = NULL;
        temp->next->seats = (seat *)malloc(sizeof(seat) * maxSeatCount);

        carNumber++;
    }

}

void pushSeat(node **head, seat s){

    node *temp = *head;

    if(temp == NULL){
        push(head);
        pushSeat(head, s);
    }
    else
    {
        int i = 0;

        while (i != carNumber)
        {
            temp = temp->next;
            i++;
        }
        
        int index = (seatNumber++) - (carNumber * maxSeatCount);

        temp->seats[index] = s;

        if(seatNumber % maxSeatCount == 0 && seatNumber != 0)
        {
            push(head);
        }
    }
}

seat popSeat(node **head){

    node *temp = *head;
    seat s1;
    
    if(seatNumber % maxSeatCount == 0 && seatNumber != 0)
    {
        printf(" \nvagon silinecek");
        pop(head);
    }    

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    int index = seatNumber-- -1 - (carNumber * maxSeatCount);

    s1 = temp->seats[index];


    seat *seats = (seat *)malloc(sizeof(seat) * maxSeatCount);

    for (int i = 0; i < index; i++)
    {
        seats[i] = temp->seats[i];
    }

    temp->seats = seats;

    return s1;
}


void printTrain(node *head){
    printf("\n-------------Train-------------");
    printf("\ncar nmber %d", carNumber);
    int c = 0;
    while (head != NULL)
    {
        printf("\n------------%d.vagon------------",c);
        for (int i = 0; i < maxSeatCount; i++)
        {
            if(head->seats[i].id == NULL)
            {
                printf("\n %d : BOŞ KOLTUK", i);
            }
            else
            {
                seat s = head->seats[i];
                printf("\n %d : %d  %s  %s ", i, s.id, s.name, s.surName);
            }
            
        }
        c++;
        head = head->next;
    }
}

int main(){

    for (int i = 1; i < 21; i++)
    {
        seat s1 = seat{ i , "Ömer", "Demirtaş"};
        pushSeat(&head, s1);    
    }
    
    for (int i = 1; i < 21; i++)
    {
        seat s = popSeat(&head);
        printf("\nsilinen kişi: %d %s %s", s.id, s.name, s.surName);  
    }

    seat s1 = seat{ 1 , "Ömer", "Demirtaş"};

    pushSeat(&head, s1);
    pushSeat(&head, s1);
    pushSeat(&head, s1);
    pushSeat(&head, s1);


    printTrain(head);


    printf("\n\n\n\n\n");
}