#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define READ_END 0
#define WRITE_END 1
#define size_t unsigned

void writeFD(int fd[2], const char* str) {
    close(fd[READ_END]);          
    write(fd[WRITE_END], str, strlen(str));
    close(fd[WRITE_END]);          
}

void readFD(int fd[2], char* buf, size_t* readBytes) {
    close(fd[WRITE_END]);         
    
    while((*readBytes = read(fd[READ_END], buf, 1024)) > 0)
    {
        buf[*readBytes] = 0;
        printf("%s \n", buf);
    }
    
    close(fd[READ_END]); 
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix_expression>\n", argv[0]);
        return 1;
    }
    
    char str[] = "/ 6030 5";
    int parent_fd[2];
    int child_fd[2];
    
    if (pipe(parent_fd) == -1 || pipe(child_fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t cpid = fork();
    if (cpid == -1) {
        perror("fork");
        return 1;
    }

    if (cpid > 0) {  
        printf("write command in 1st pipe: %s\n", str);
        writeFD(parent_fd, str);
        
        wait(NULL);        
        
        printf("read result from 2nd pipe: ");
        char res[1024];
        size_t size;
        readFD(child_fd, res, &size);
    }
    else if (cpid == 0) {
        printf("read message from 1st pipe: ");
        char buf[1024];
        size_t size;
        readFD(parent_fd, buf, &size);
        printf("\n");
        
        //prefix expression evaluation
        int i = 0;
        char *p = strtok(buf, " ");
        char *str[3];
    
        while (p != NULL)
        {
            str[i++] = p;
            p = strtok (NULL, " ");
        }
        
        char op = str[0][0];
        int num1 = atoi(str[1]);
        int num2 = atoi(str[2]);
    
        int res;
	    switch(op)
	    {
	    	case '+': res=num1+num2;
	    	break;
	    	case '-': res=num1-num2;
	    	break;
	    	case '*': res=num1*num2;
	    	break;
	    	case '/': res=num1/num2;
	    	break;
	    }
        
        char ans[20];
        int n = log10(res)+1;
        while(res) {
            ans[n] = '0' + res%10;        
            res/=10;
            n--;
        }
        
        printf("write result in 2nd pipe: %s\n", ans);
        writeFD(child_fd, ans);
        
        //return 0;
    }
    
    return 0;
}