
#include<stdio.h>
#define size 6
struct stack{
int top;
int array[size];
}st;
int top=-1;
void push(int item){
if(st.top>size-1){
printf("stack is overflow");
}
else{
st.top++;
st.array[st.top]=item;
}
}
int pop(){
int item;

if(st.top==-1){
printf("stack is underflow:\n");
}
else{

item=st.array[st.top];
st.top--;


}
return item;}
 int peek(){
int item;
 if(st.top==-1){
printf ("stack is overflow/n");
}
else{ 
return st.array[st.top];
} 
}
void display(){
if (st.top==-1){
printf("the stack is empty\n");}
else{
for (int i=0;i<st.top;i++){
printf("array element is %d:",st.array[i]);

}


}


}
int main(){
int choice=1;int value;
while(choice==1){
printf("\n STACK OPERATIONS\n");
printf("1 Push\n");
printf("2 pop\n");
printf("3 peek\n");
printf("4 display\n");
printf("enter your choice:");
scanf("%d", &choice);
switch(choice){
case 1:
printf(" enter  the data you want to push:");
scanf("%d",&value);
push(value);
break;
case 2:
value =pop();
if(value!=-1)
printf("The poped value is: %d\n ", value);

break;
case 3:
value=peek();
if(value!=-1)
printf ("the peekes element is% d\n",value);
break;
case 4:
display();
break;
default:
printf("wrong choice\n");
break;

}
printf("do you want to conitunue(1/0):");
scanf("%d",&choice);
}
}



