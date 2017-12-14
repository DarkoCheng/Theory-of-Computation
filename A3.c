#include <stdio.h>

int A[100], B[100], C[100], atop=0, btop=0, ctop=0;
int n;
int num[20];
int config[22];
int total = 0;

void InitializeStacks(char * string);
int TestStack(int x[], int top, int n);
int Pop(int x[], int *top);
void Push(int x[], int *top, int v);
int Move(int m);
void RunAlgorithm(int * a);
void GenStartingConfig(int t);

int main()
{
	int a, b, c;
	int d[15] = {1, 3, 5, 3, 3, 5, 5, 2, 2, 1, 1, 1, 1, 1, 5};
    int i;
    n = 4;
    //n = 3;
    num[0] = 2;
    for (i = 1; i <= n; i++)
    {
        num[i] = 1;
    }
    GenStartingConfig(1);
    printf("Total configs = %d\n", total);
    //InitializeStacks("34506781029");
    printf("Printing A:\n");
    //RunAlgorithm(d);
    for (a = 0; a < atop; a++)
    {
        printf("%d\n", A[a]);
    }
    printf("Printing B:\n");
    for (b = 0; b < btop; b++)
    {
        printf("%d\n", B[b]);
    }
    printf("Printing C:\n");
    for (c = 0; c < ctop; c++)
    {
        printf("%d\n", C[c]);
    }

    return 0;
}

void RunAlgorithm(int * a)
{
	if (btop == 0 && ctop == 0)
	{
        Move(a[0]);
	}
	if (atop == 0 && ctop == 0)
	{
        Move(a[1]);
	}
	if (atop == 0 && btop == 0)
	{
        Move(a[2]);
	}
	if (atop == 0 && B[btop] < C[ctop])
	{
        Move(a[3]);
	}
	if (atop == 0 && C[ctop] < B[btop])
	{
        Move(a[4]);
	}
	if (btop == 0 && A[atop] < C[ctop])
	{
		Move(a[5]);
	}
	if (btop == 0 && C[ctop] < A[atop])
	{
		Move(a[6]);
	}
	if (ctop == 0 && A[atop] < B[btop])
	{
		Move(a[7]);
	}
	if (ctop == 0 && B[btop] < A[atop])
	{
		Move(a[8]);
	}
	if (A[atop] < B[btop] && B[btop] < C[ctop])
	{
		Move(a[9]);
	}
	if (A[atop] < C[ctop] && C[ctop] < B[btop])
	{
		Move(a[10]);
	}
	if (B[btop] < A[atop] && A[atop] < C[ctop])
	{
		Move(a[11]);
	}
	if (B[btop] < C[ctop] && C[ctop] < A[atop])
	{
		Move(a[12]);
	}
	if (C[ctop] < A[atop] && A[atop] < B[btop])
	{
		Move(a[13]);
	}
	if (C[ctop] < B[btop] && B[btop] < A[atop])
	{
		Move(a[14]);
	}

	return;
}

void InitializeStacks(char * string)
{
	int a, b, c, d;
	a = 0; 
	b = 0; 
	c = 0; 
	d = 0;
    while(1)
    {
        if (string[a] == '0' || string[a] == '\0')
        {
            break;
        }
        else
        {
        	A[b] = string[a] - '0'; // convert char to int and insort to top of stack
        	b++;
        	atop++;
        }
        a++;
    }
    a++; // to the next stack
    while(1)
    {
        if (string[a] == '0' || string[a] == '\0')
        {
            break;
        }
        else
        {
        	B[c] = string[a] - '0'; // convert char to int and insort to top of stack
        	c++;
        	btop++;
        }
        a++;
    }
    a++; // to the next stack
    while(1)
    {
        if (string[a] == '0' || string[a] == '\0')
        {
            break;
        }
        else
        {
        	C[d] = string[a] - '0'; // convert char to int and insort to top of stack
        	d++;
        	ctop++;
        }
        a++;
    }

    return;
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

void GenStartingConfig(int t)
{
	int i;

	if (t > n+2)
	{
		for (i = 1; i <= n+2; i++)
		{
			//printf("%d", config[i]);
		}
		printf("\n");
		total++;
		char str[22];
		int e;
		for (e = 0; e <= i; e++)
		{
			if (e + 1 > i)
			{
                break;
			}
            str[e] = config[e+1];
        }
		str[e+1] = '\0';
		//printf("string:%s", str);
		InitializeStacks(str);
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			if (num[i] > 0)
			{
				num[i]--;
				config[t] = i;
				GenStartingConfig(t+1);
				num[i]++;
			}
		}
	}
}
