#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define IN_FIFO "/home/box/in.fifo"
#define OUT_FIFO "/home/box/out.fifo"
//#define IN_FIFO "/root/in.fifo"
//#define OUT_FIFO "/root/out.fifo"
#define BUFLEN 2048

int main(int argc, char **argv)
{
    mkfifo(IN_FIFO, 0666);
    mkfifo(OUT_FIFO, 0666);

    int in = open(IN_FIFO, O_RDONLY);
    perror("Error after in open: ");
    
    int out = open(OUT_FIFO, O_WRONLY);
    perror("Error after out open: ");
    
    char buffer[BUFLEN];
    while (1) {
        ssize_t nbytes = read(in, buffer, BUFLEN);
        perror("Error after read: ");
        write(out, buffer, nbytes);
        perror("Error after write: ");
    }
    close(in);
    close(out);

    unlink(IN_FIFO);
    unlink(OUT_FIFO);

    return 0;
}
