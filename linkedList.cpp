#include <stdio.h>
#include <malloc.h>
#include <conio.h>

struct n {
    int data;
    n *next;
};
typedef n node;

void printList(node *r){
    while (r != NULL)
    {
        printf("\n%d", r->data);
        r = r->next;
    }
}

void add(node *r,int value){
    while (r->next != NULL)
    {
        r=r->next;
    }
    r->next = (node *)malloc(sizeof(node));
    r=r->next;
    r->data = value;
    r->next = NULL;
}

node *insert(node *r,int value,int index){
    node *temp;
    //1
    if(index == 0){
        temp = (node *)malloc(sizeof(node));
        temp->data = value;
        temp->next = r;

        return temp;
    }


    temp = r;
    --index;
    while(index != 0 && r->next != NULL){
        r=r->next;
        --index;
    }

    //2. Girilen indeks eleman sayısından daha büyük durumu
    if(r->next == NULL && index != 0){
        printf("Girilen indexks eleman sayisindan daha fazla");
        return temp;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = r->next;
    r->next = newNode;         
    return temp;
}   

node *remove(node *r, int value){
    node *temp;
    //Silinecek veri 0. indekste olma durumu 
    if(r->next != NULL && r->data == value){
        temp = r;
        r=r->next; 
        free(temp);
        return r;
    }

    temp = r;
    while (r->next != NULL && r->next->data != value)
    {
       r=r->next;
    }

    //Girilen değerin bulunamaması durumu
    if(r->next == NULL){
        printf("\nGirilen deger(%d) listede bulunamadi", value);
        return temp;
    }

    node *deletedNode = r->next;
    r->next = deletedNode->next;

    free(deletedNode);
    return temp;
}

node *removeAt(node *r, int index){
    node *temp;

    if(index == 0){
        temp = r;
        r=r->next;
        free(temp);
        return r;
    }

    temp = r;
    --index;
    while (r->next != NULL && index != 0)
    {
        r=r->next;
        --index;
    }

    if(r->next == NULL){
        printf("\nGiriline indeks(%d) fonksiyondan daha uzun",index);
        return temp;
    }
    
    node *deleteNode = r->next;
    r->next = deleteNode->next;
    free(deleteNode);

    return temp;
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    head->data = 10;
    head->next = (node *)malloc(sizeof(node));
    head->next->data = 20;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->data = 30;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->data = 40;
    head->next->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->next->data = 50;
    head->next->next->next->next->next = NULL;

    add(head, 60);
    add(head, 70);

    head = insert(head, 999, 70);
    head = insert(head, 80, 7); //son indekse ekleme örneği
    head = insert(head, 35, 3); //ortalara ekleme örneği
    head = insert(head, 1, 0);//ilk satıra ekleme örneği

    head = remove(head, 35);
    head = remove(head, 0);
    head = remove(head, 80);
    head = remove(head, 1);


    head = removeAt(head, 3);


    printList(head);
    getch();
}