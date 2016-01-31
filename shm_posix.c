#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

#define MEMLEN 1048576

int main(int argc, char **argv) {
    int sm = shm_open("/test.shm", O_CREAT | O_RDWR, 0666);
    perror("Errno after shm_open: ");
    
    ftruncate(sm, MEMLEN);
    perror("Errno after ftruncate: ");
    
    char *data = mmap(0, MEMLEN, PROT_READ | PROT_WRITE, MAP_SHARED,
        sm, 0);
    perror("Errno after mmap: ");
    
    for (int i = 0; i < MEMLEN; i++)
        data[i] = (char)13;
    perror("Errno after write: ");
    
    return 0;
}
