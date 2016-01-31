#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
	key_t key = ftok("/tmp/sem.temp", 0);
	int sems = semget(key, 16, IPC_CREAT);
	perror("Errno after semcreation: ");
	for (int i = 0; i < 16; i++) {
	    unsigned short semval = i;
	    semctl(sems, i, SETVAL, semval);
	}
	perror("Errno after semctl: ");
	pause();
	return 0;
}
