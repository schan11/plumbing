// Serena Chan
// Systems Level Programming
// 12/23/2020
// Work 16: Plumbing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    
    int input, output; // user will enter input, and will return the square of said input (output)
    
    mkfifo("pipe", 0644); // makes special named pipe
    
    int fd1 = open("pipe", O_RDONLY);
    int fd2 = open("pipe", O_WRONLY);
    
    while(1){
        read(fd1, &input, sizeof(input));
        close(fd1);
        
        printf("square of %d\n", input);
        output = (input * input);
        
        write(fd2, &output, sizeof(output));
        close(fd2);
        
    }
    return 0;
}
