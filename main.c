#include <stdio.h>

int A[100], B[100], C[100];
int atop=0, btop=0, ctop=0;

int TestStack(int x[], int top, int n);
int Pop(int x[], int *top);
void Push(int x[], int *top, int v);
int Move(int m);

int main()
{
	/*Pop(A, &atop);
	Push(A, &atop, 5);
	Push(A, &atop, 4);
	Push(A, &atop, 1);
	Pop(A, &atop);
	Push(A, &atop, 3);
	Push(A, &atop, 2);
	Push(A, &atop, 1);*/
    Push(A, &atop, 1);
    Push(B, &btop, 1);
    Push(C, &ctop, 1);
    Push(A, &atop, 2);
    Push(B, &btop, 2);
    Push(C, &ctop, 2);
    Push(A, &atop, 3);
    Move(1);
    Move(2);
    Move(3);
    Move(4);
    Move(5);
    Move(6);
	if (TestStack(B, btop, 5))
	{
        printf("The stack is sotred!\n");
	}

	return 0;
}

int Move(int m)
{
    int a;
    if (m == 1)
    {
        a = Pop(A, &atop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(B, &btop, a);
        }
    }
    else if (m == 2)
    {
        a = Pop(A, &atop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(C, &ctop, a);
        }
    }
    else if (m == 3)
    {
        a = Pop(B, &btop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(A, &atop, a);
        }
    }
    else if (m == 4)
    {
        a = Pop(B, &btop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(C, &ctop, a);
        }
    }
    else if (m == 5)
    {
        a = Pop(C, &ctop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(A, &atop, a);
        }
    }
    else if (m == 6)
    {
        a = Pop(C, &ctop);
        if (a == 0)
        {
            printf("Empty Stack.\n");
            return 0;
        }
        else
        {
            Push(B, &btop, a);
        }
    }
    return 1;
}

int TestStack(int x[], int top, int n)
{
	int i;
	int a;
    for (a = 0; a < top; a++)
	{
        printf("%d\n", B[a]);
	}
    if (top == 0)
    {
    	return 0;
    }
    else
    {
    	for (i = 0; i <= top; i++)
    	{
            if (x[i]-1 != x[i+1] && x[i] != 0)
            {            	
            	return 0;
            }
            if (x[i] == 0)
            {
                return 1;
            }
    	}
    	return 1;
    }
}

int Pop(int x[], int *top)
{
     int a;
     a = *top;
     if (a == 0)
     {
     	return 0;
     }
     else
     {
     	*top = *top-1;
     	return a;
     }
}

void Push(int x[], int *top, int v)
{
    x[*top] = v;
    *top = *top+1;
}
