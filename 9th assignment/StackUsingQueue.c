#include <stdio.h>
int q1[20], q2[20];
int f1 = -1, f2 = -1, r1 = -1, r2 = -1;

void transfer1()
{
	while (f1 != -1)
	{
		if ((f1 == r1) && (f2 == -1 && r2 == -1))
		{
			f2 = 0;
			r2 = 0;
			q2[f2] = q1[f1];
			f1 = -1;
			r1 = -1;
		}
		else if (f1 == r1)
		{
			r2 = r2 + 1;
			q2[r2] = q1[f1];
			f1 = -1;
			r1 = -1;
		}
		else if (f2 == -1 && r2 == -1)
		{
			f2 = 0;
			r2 = 0;
			q2[f2] = q1[f1];
			f1 = f1 + 1;
		}
		else
		{
			r2 = r2 + 1;
			q2[r2] = q1[f1];
			f1 = f1 + 1;
		}
	}
}

void transfer2()
{
	while (f2 != -1)
	{
		if (f2 == r2)
		{
			r1 = r1 + 1;
			q1[r1] = q2[f2];
			f2 = -1;
			r2 = -1;
		}
		else
		{
			r1 = r1 + 1;
			q1[r1] = q2[f2];
			f2 = f2 + 1;
		}
	}
}

void enqueue1(int val)
{
	if (f1 == -1 && r1 == -1)
	{
		f1 = 0;
		r1 = 0;
		q1[f1] = val;
	}
	else
	{
		r1 = r1 + 1;
		q1[r1] = val;
	}
}

void push(int val)
{
	if (r1 == 20)
	{
		printf("Overflow ");
		return;
	}
	if (f1 == -1 && r1 == -1)
	{
		enqueue1(val);
	}
	else
	{
		transfer1();
		enqueue1(val);
		transfer2();
	}
}
void pik(int x)
{
	printf("Pikked value is %d ", q1[x]);
}

void pop()
{
	if (f1 == r1)
	{
		pik(f1);
		f1 = -1;
		r1 = -1;
	}
	else
	{
		pik(f1);
		f1 = f1 + 1;
	}
}

void show()
{
	printf("The stack is ");
	for (int i = r1; i >= f1; i--)
	{
		printf("%d ", q1[i]);
	}
	printf("\n");
}

int main()
{
	int ch, val;
	do
	{
		printf("1.Push\n2.Pop ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			printf("Enter the val ");
			scanf("%d", &val);
			push(val);
			show();
		}
		else if (ch == 2)
		{
			pop();
		}
	} while (ch == 1 || ch == 2);
}
