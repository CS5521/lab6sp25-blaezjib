#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
    // fkc(0); // sets to 0 for tests

    printf(1, "number of forks when program starts: %d\n", fkc(2));
    if(fork() == 0) { // fork once
        exit();
    }

    if(fork() == 0) { // fork twice
        exit();
    }

    printf(1, "number of forks after two more forks: %d\n", fkc(1));


    wait(); // reap the child process
    wait(); // got the second one

     //fkc sys call
    printf(1, "number of forks after fork count cleared: %d\n", fkc(0));

    if(fork() == 0) { // fork once
        exit();
    }

    if(fork() == 0) { // fork twice
        exit();
    }

    if(fork() == 0) { // fork thrice
        exit();
    }

    wait(); 
    wait(); 
    wait(); // get all of them outa here

    printf(1, "number of forks after three more forks: %d\n", fkc(1));


    exit();
}