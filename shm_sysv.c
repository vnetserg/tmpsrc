#include <sys/shm.h>

int main(int argc, char** argv) {
    key_t key = ftok("/tmp/mem.temp", 0);
    perror("Errno after ftok: ");
    int shm = shmget(key, 1048576, IPC_CREAT | 0666);
    perror("Errno after shmget: ");
    
    char* data = shmat(shm, (void*)0, 0);
    perror("Errno after shmgat: ");
    
    for (int i = 0; i < 1048576; i++)
        data[i] = (char)42;
    perror("Errno after writing: ");
    
    return 0;
}
