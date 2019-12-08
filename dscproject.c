#include <stdio.h>
#define MAXSIZE 100

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

void push(int);
int  pop(void);
void display(void);
void Ap(int);
int factorial(int);
void trace(void);
void main ()
{
  s.top=-1;
  int n=100,m=13;
  push(s.top);
  push(n);
  push(m);
  printf("local variables of main function s.top,n,m got pushed into stack\n");
  display();
  printf("function Ap is about to get executed\n");
  Ap(n);
  printf("function factorial is about to get executed\n");
  printf("the factorial is %d \n",factorial(m));
  printf("function trace is about to get executed\n");
  trace();
  printf("the local variables of main function got popped\n");
  pop();
  pop();
  pop();
  display();
  printf("program came to an end\n");
}
/*  Function to add an element to the stack */
void push(int num)
{
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf ("poped element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}
void Ap(int n)
{
  push(n);
  printf("the parameter of function Ap n got pushed into the stack\n");
  display();
  int s=(n*(n+1))/2;
  push(s);
  printf("local variable s of function Ap got pushed into the stack\n");
  display();
  printf("the sum is %d\n",s);
  printf("function execution completed\n");
  pop();
  pop();
  printf("the local variables of function Ap got popped\n");
  display();
}
int factorial(int m)
{
  int k=0;
  push(k);
  push(m);
  printf("the parameter m and k of function factorial got pushed into the stack\n");
  display;
  if (m==1)
  {
    printf("recusion reached its base case\n");
    pop();
    pop();
    printf("local variables of last recursion call function got popped\n");
    display();
    return 1;
  }
  else
    k= m*factorial(m-1);
    printf("local variables of recursion functions are being popped in reverse\n");
    pop();
    pop();
    return k;

}
void trace()
{
  int a[3][3],j,i,order,trace=0;
  printf("enter the order of the square matrix: ");
  scanf("%d",&order);
  push(order);
  printf("the local variable order of function trace got pushed into the stack\n");
  display();
  printf("enter the elements of the stack\n");
  for(i=0;i<order;i++)
  {
    for(j=0;j<order;j++)
    {
      scanf("%d",&a[i][j]);
      push(a[i][j]);
    }
  }
  printf("the elements of the matrix got pushed into the stack\n");
  display();
  for(i=0;i<order;i++)
  {
    trace=trace+a[i][i];
  }
  push(trace);
  printf("the trace variable of function trace got pushed into the stack\n");
  display();
  printf("the trace is : %d\n",trace);
  printf("the trace function came to an end\n");
  pop();
  for(i=0;i<order*order+1;i++)
  {
    pop();
  }
  printf("all local variables of function trace got popped\n");
  display();
}
