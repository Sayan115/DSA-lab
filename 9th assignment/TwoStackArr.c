#include <stdio.h>

void peek(int t, int *arr)
{
	printf("Element is %d ", arr[t]);
}

int fpush(int *arr, int t1, int t2)
{
	int val;
	if (t1 == t2 - 1)
	{
		printf("Overflow ");
		return t1;
	}
	printf("Enter the value ");
	scanf("%d", &val);
	t1 = t1 + 1;
	arr[t1] = val;
	return t1;
}
int rpush(int *arr, int t1, int t2)
{
	int val;
	if (t2 == t1 + 1)
	{
		printf("Overflow ");
		return t2;
	}
	printf("Enter the value ");
	scanf("%d", &val);
	t2 = t2 - 1;
	arr[t2] = val;
	return t2;
}

int fpop(int *arr, int t1)
{
	if (t1 == -1)
	{
		printf("Underflow ");
		return t1;
	}
	peek(t1, arr);
	t1 = t1 - 1;
	return t1;
}

int rpop(int *arr, int t2, int length)
{
	if (t2 == length)
	{
		printf("Underflow ");
		return t2;
	}
	peek(t2, arr);
	t2 = t2 + 1;
	return t2;
}

void show(int *arr, int t1, int t2, int length)
{
	printf("\nFirst stack is ");
	for (int i = 0; i <= t1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nSecond stack is ");
	for (int i = length - 1; i >= t2; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10];
	int length = sizeof(arr) / sizeof(arr[0]);
	int t1 = -1, ch, op1, op2;
	int t2 = length;
	do
	{
		printf("1.Push\n2.Pop\n3.Show ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			printf("1.Front\n2.Rear ");
			scanf("%d", &op1);
			if (op1 == 1)
			{
				t1 = fpush(arr, t1, t2);
				show(arr, t1, t2, length);
			}
			else if (op1 == 2)
			{
				t2 = rpush(arr, t1, t2);
				show(arr, t1, t2, length);
			}
		}
		else if (ch == 2)
		{
			printf("1.Front\n2.Rear ");
			scanf("%d", &op2);
			if (op2 == 1)
			{
				t1 = fpop(arr, t1);
				show(arr, t1, t2, length);
			}
			else if (op2 == 2)
			{
				t2 = rpop(arr, t2, length);
				show(arr, t1, t2, length);
			}
		}
	} while ((ch == 1 || ch == 2) && (op1 == 1 || op2 == 2 || op1 == 2 || op2 == 2));
}
