#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>

#define QUEUE_NAME "/red_poruka"
#define MAX_SIZE 2048
#define MSG_STOP "izlaz"

int main() {
    mqd_t red_poruka;
    struct mq_attr atributi;
    char bafer[MAX_SIZE + 1];
    int stop = 0;


    atributi.mq_flags = 0;
    atributi.mq_maxmsg = 10;
    atributi.mq_msgsize = MAX_SIZE;
    atributi.mq_curmsgs = 0;


    red_poruka = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &atributi);
    if (red_poruka == (mqd_t)-1) {
        perror("Greska prilikom otvaranja reda sa porukama");
        exit(1);
    }

    do {
        ssize_t procitano;

        procitano = mq_receive(red_poruka, bafer, MAX_SIZE, NULL);
        if (procitano >= 0) {
            bafer[procitano] = '\0';
            if (strcmp(bafer, MSG_STOP) == 0) {
               stop = 1;
            } else {
                printf("Primljeno: %s\n", bafer);
            }
        } else {
            perror("mq_receive");
            exit(1);
        }
    } while (!stop);

    mq_close(red_poruka);
    mq_unlink(QUEUE_NAME);

    return 0;
}

	

