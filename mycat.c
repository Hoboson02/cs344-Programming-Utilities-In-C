/* Filename: mycat.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
  /* Check number of files inputted */
    char buf[2048];   
    int fd;
    int count;
    while ((count = read(fd, buf, sizeof buf)) > 0) {
          fd = open(argv[0], O_RDONLY);
          write(1, buf, count);
          close(fd);
    }
    for (int i = 1; i < argc; ++i) {
        fd = open(argv[i], O_RDONLY);
        count = read(fd, buf, sizeof buf - 1);
        write(1, buf, count); 
      
    }
    
}
