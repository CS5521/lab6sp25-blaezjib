#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
    printf(1, "fkc before two forks: %d\n", fkc());

    if(fork() == 0) { //fork once
        exit();
    }

    if(fork() == 0) { //fork twice
        exit();
    }

    wait(); // reap the child process
    wait(); //sold

     //fkc sys call
    printf(1, "fkc after two forks: %d\n", fkc());


    exit();
}