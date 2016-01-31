#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    key_t key = ftok("/tmp/sem.temp", 0);
    int sems = semget(key, 16, IPC_CREAT);
    perror("Errno after semcreation: ");
    
    struct sembuf sops[16];
    for (int i = 0; i < 16; i++) {
        sops[i].sem_num = (unsigned short)i;
        sops[i].sem_op = (short)i;
        sops[i].sem_flg = (short)0;
    }
    semop(sems, sops, (size_t)16);
    perror("Errno after semop: ");
	
    pause();
	
    return 0;
}
