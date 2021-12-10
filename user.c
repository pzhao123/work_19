#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {

    mkfifo("input", 0644);
    mkfifo("output", 0644);
    int in = open("input", O_WRONLY);
    int out = open("output", O_RDONLY);

    char line[200];

    while (1) {       
        
        printf("Input: ");
        fgets(line, sizeof(line), stdin);
        write(in, line, sizeof(line));
        read(out, line, sizeof(line));
        printf("OUTPUT: %s\n", line);
        }

    return 0;
}
