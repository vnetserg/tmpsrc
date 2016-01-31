#include <sys/msg.h>
#include <stdio.h>

struct message {
	long mtype;
	char mtext[80];
};

void write_file(const char *filename, const char *text) {
	FILE *f = fopen(filename, "w");
	fprintf(f, text);
	fclose(f);
}

int main(int argc, char** argv) {
	struct message my_msg;
	key_t key = ftok("/tmp/msg.temp", 0);
	int msqid = msgget(key, 0666 | IPC_CREAT);
	while (1) {
		msgrcv(msqid, &my_msg, sizeof(my_msg.mtext), 0, 0);
		write_file("/home/box/message.txt", my_msg.mtext);
	}
	return 0;
}