#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sigroutine(int dunno)

{ /* 信号处理例程，其中dunno将会得到信号的值 */
    switch(dunno) {
        case 1:
            printf("Get a signal -- SIGHUP ");
            break;
        case 2:
            printf("Get a signal --SIGINT");
            break;
        case 3:
            printf("Get a signal --SIGQUIT");
            break;
    }
    return;
}

int main() {

    printf("waiting for signal SIGINT or SIGQUIT ... \n"); 
//    printf("process id is %d ", getpid());
    signal(SIGHUP, sigroutine);
    signal(SIGINT, sigroutine);
    signal(SIGQUIT, sigroutine); 

    
    while(1)
    {

        printf("Hello world!\n");
        sleep(1);
    }
    return 0;
}
