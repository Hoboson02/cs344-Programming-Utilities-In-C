/* Filename: yell.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  /* Check number of files inputted */
    char buf[2048];
    char chr;   
    int fd;
    int count;
    while ((count = read(fd, buf, sizeof buf)) > 0) {
          fd = open(argv[0], O_RDONLY);
          for (int x = 0; x < sizeof buf; x++)
            buf[x] = toupper(buf[x]);
          write(1, buf, count);
          close(fd);
    }
    for (int i = 1; i < argc; ++i) {
        fd = open(argv[i], O_RDONLY);
        count = read(fd, buf, sizeof buf - 1);
        for (int x = 0; x < sizeof buf; x++)
          buf[x] = toupper(buf[x]);
        write(1, buf, count); 
        close(fd);
    }
    
}
