#include<stdio.h>
#include<conio.h>
#include<malloc.h>  
#include<stdlib.h>
#include<string.h>

int MAXSIZE = 8;       
char stack[80];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

char peek() {
   return stack[top];
}

char pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

char push(char data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

bool chack(char* str){
    int len = strlen(str);

    if(len == 0){
        return true;
    }

    for (int i = 0; i < len; i++){

        char c = str[i];
        if (c == '{' || c == '(' || c == '[')
        {
            push(c);
        }   

        if (c == '}' || c == ')' || c == ']')
            {
                if (isempty()){
                    return false;
                }

                char last = peek();
                if (c == '}' && last == '{' || c == ')' && last == '(' || c == ']' && last == '[')
                    pop();
                else{
                    return false;
                }
            }

        }
        return isempty();

    }

int main() {
    char *str = "(2*1) + ((2x+1) * 12 )";



    printf(chack(str) ? "\ntrue" : "\nfalse");
    getch();
}

