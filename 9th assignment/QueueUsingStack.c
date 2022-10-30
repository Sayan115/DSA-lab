#include <stdio.h>
int s1[10], s2[10];
int t1 = -1, t2 = -1;

void transfer1()
{
	while (t1 != -1)
	{
		t2 = t2 + 1;
		s2[t2] = s1[t1];
		t1 = t1 - 1;
	}
}

void transfer2()
{
	while (t2 != -1)
	{
		t1 = t1 + 1;
		s1[t1] = s2[t2];
		t2 = t2 - 1;
		//		printf(" %d ",t1);
	}
}

void push1(int val)
{
	t1 = t1 + 1;
	s1[t1] = val;
}

void enqueue(int val)
{
	if (t1 == 9)
	{
		printf("Overflow ");
		return;
	}
	if (t1 == -1)
	{
		push1(val);
	}
	else
	{
		transfer1();
		push1(val);
		transfer2();
	}
}

void dequeue()
{
	if (t1 == -1)
	{
		printf("underflow ");
		return;
	}
	printf("Pikked element is %d \n", s1[t1]);
	t1 = t1 - 1;
}

void show()
{
	printf("The queue is ");
	for (int i = 0; i <= t1; i++)
	{
		printf("%d ", s1[i]);
	}
	printf("\n");
}

int main()
{
	int ch, val;
	do
	{
		printf("1.Enqueue\n2.Dequeue ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			printf("Enter the value ");
			scanf("%d", &val);
			enqueue(val);
			show();
		}
		else if (ch == 2)
		{
			dequeue();
		}
	} while (ch == 1 || ch == 2);
}
