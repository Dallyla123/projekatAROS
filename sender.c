#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>

#define QUEUE_NAME "/red_poruka"
#define MAX_SIZE 2048

int main() {
    mqd_t red_poruka; 
    char bafer[MAX_SIZE];

    red_poruka = mq_open(QUEUE_NAME, O_WRONLY);
    if (red_poruka == (mqd_t)-1) {
        perror("Greska prilikom otvaranja reda");
        exit(1);
    }

    printf("Unesite poruku i pritisnite ENTER ili otkucajte 'izlaz' za zaustavljanje programa:\n");

    do {
        printf("-- ");
        fflush(stdout);

        memset(bafer, 0, MAX_SIZE);
        fgets(bafer, MAX_SIZE, stdin);
        
        bafer[strcspn(bafer, "\n")] = '\0';
        if (mq_send(red_poruka, bafer, strlen(bafer), 0) == -1) {
            perror("Greska prilikom slanja poruke");
            exit(1);
        }
    } while (strncmp(bafer, "izlaz", strlen("izlaz")));


    mq_close(red_poruka);

    return 0;
}


	

