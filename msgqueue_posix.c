#include <mqueue.h>
#include <stdio.h>

void write_file(const char *filename, const char *text) {
	FILE *f = fopen(filename, "w");
	fprintf(f, "%s\n", text);
	fclose(f);
}

int main(int argc, char **argv) {
    char msg[1024];
    mqd_t mq = mq_open("/test.mq", O_CREAT, 0666, NULL);
    while (1) {
        mq_receive(mq, msg, sizeof(msg), NULL);
        write_file("/home/box/message.txt", msg);
    }
}
