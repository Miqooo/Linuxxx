#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("%s", "Incorrect amount of arguments is provided.");
		return 1;
	}

	const int count = atoi(argv[1]);
	if (count <= 0)
	{
		printf("%s", "Number count cannot be non-positive.");
		return 2;
	}

	int arr[count];
	for (int i = 0; i < count; i++)
	{
		printf("%s %d: ", "Enter the number", i+1);
		scanf("%d", &arr[i]);
	}

    for (int i = 0; i < count; ++i) 
    {
        for (int j = i + 1; j < count; ++j) 
        {
            if (arr[i] < arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

	printf("%s", "Sorted array: ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}