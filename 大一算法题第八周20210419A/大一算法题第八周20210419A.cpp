#define _CRT_SECURE_NO_WARNINGS
/*
#include <stdio.h>
int arr[1001];

int Find(int a, int b)
{

	for (int i = 1; i <=a; i++)
	{
		if (arr[i] > b)
		{
			return i;
		}
	}

	return NULL;
}
int main()
{

	int N;
	int Temp, temp;

	int X = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 1 && Find(i,1))
		{
			Temp = Find(i, 1);

			temp = arr[Temp];
			arr[Temp] = arr[i];
			arr[i] = temp;
			X++;
		}
	}
		
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 2 && Find(i, 2))
		{
			Temp = Find(i, 2);

			temp = arr[Temp];
			arr[Temp] = arr[i];
			arr[i] = temp;
			X++;
		}
	}

	printf("%d", X);

	

	return 0;
}
*/

#include<stdio.h>
#include<string.h>
int main()
{
	int arr[1005];
	int Num[4] = { 0 };
	int i, j, N, X = 0, temp;

    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
		Num[arr[i]]++;
    }
	
    for (i = 1; i <= Num[1]; i++)
    {
        if (arr[i] == 2) {
	        X++;
			for (j = Num[1] + 1; j <= Num[1] + Num[2]; j++)
			{
				if (arr[j] == 1)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}

		}
        if (arr[i] == 3)
        {
			int count = 0;
			X++;
            for (j = Num[1] + Num[2] + 1; j <= Num[1] + Num[2] + Num[3]; j++)
            {
                if (arr[j] == 1)
                {
					temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                else
                    count++;
                if (count == Num[3])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i--;
                }
            }
        }

    }
     for (i = Num[1] + 1; i <= Num[1] + Num[2]; i++)
     {
         if (arr[i] == 3)
         {
			X++;
            for (j = Num[1] + Num[2] + 1; j <= Num[1] + Num[2] + Num[3]; j++)
            {
                if (arr[j] == 2)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
         }
     }
	 printf("%d\n", X);
	 return 0;
}
