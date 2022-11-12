#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define STRING_PATTERN  "%s\n"
#define NUMERIC_PATTERN "%d\n"

int main(int argc, char** argv)
{
    const int count = argc-1;
	if (count <= 0)
	{
        printf("%s", "Number count cannot be non-positive.");
        return 2;
	}

    pid_t pid = fork();
    if (pid < 0)
    {
        printf(STRING_PATTERN, "Unable to fork.");
        return 1;
    }

    if (pid == 0)
    {
        double arr[count];
	    for (int i = 1; i < count+1; i++)
	    {
	    	arr[i-1] = atoi(argv[i]);
	    }

	    double sum = 0.0;
	    for (int i = 0; i < count; i++)
	    {
	    	sum += arr[i];
	    }

	    printf("\n%s %lf\n", "Your average is:", sum / count);
        return 0;
    }


    wait(NULL);

    return 1;
}