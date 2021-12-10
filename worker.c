#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    int in = open("input", O_RDONLY);
    int out = open("output", O_WRONLY);

    char line[200];

    while (1) {       
            
        read(in, line, sizeof(line) );
        line[strlen(line) - 1] = '\0';
        int len = strlen(line);
        int i;
        for (i = 0; i < len; i++) {
            if ((line[i] >= 'a' && line[i] <= 'z')) {
                line[i] = line[i] - 32;
            }
        }
        write(out, line, sizeof(line));
    
    }

    return 0;
}
