/* Filename: readfile.c */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char buf[2048];

    if (fd == -1) {
        perror("Error occurred when attempting to open file");
    }
    else {
        int count = read(fd, buf, sizeof buf);

        write(1, buf, count);
    }
    close(fd);
}
