#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    
    int input, output;
    
    printf("Calculate the square of any number: ");
    mkfifo("pipe", 0644);
    
    int fd1 = open("pipe", O_WRONLY);
    int fd2 = open("pipe", O_RDONLY);
    
    while(1){
        scanf("%d",&input);
        write(fd1, &input, sizeof(input));
        close(fd1);
        
        read(fd2, &output, sizeof(output));
        close(fd2);
        
        printf("SQUARE: %d\n", output);
    }
    return 0;
}
