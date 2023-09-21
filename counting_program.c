#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *arg[]) {
    struct sched_param param;
    param.sched_priority = 0;

    int policy;
    if (strcmp(argv[1], "SCHED_OTHER") == 0) {
        policy = SCHED_OTHER;
    } else if (strcmp(argv[1], "SCHED_RR") == 0) {
        policy = SCHED_RR;
    } else if (strcmp(argv[1], "SCHED_FIFO") == 0) {
        policy = SCHED_FIFO;
    } else {
        fprintf(stderr, "Invalid scheduling policy: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    

    if (sched_setscheduler(0, policy, &param) == -1) {
        perror("sched_setscheduler");
        return EXIT_FAILURE;
    }

    int i=0;
    while(i< 2**32){
        i++;
    }
    return 0;

}
