//#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int  global_counter=0;
void alarmWakeup(int sig_num);
int main(int argc, char *argv[]){
    unsigned int j;
    
    signal(SIGALRM, alarmWakeup);
    ualarm(50000, 50000);
    printf(" start infinit loop: ");
    while(1) {         
        for(j=0; j<8000000; j++);//do something
        printf(".");
        for(j=0; j<8000000; j++);//do something
        printf(".");
        for(j=0; j<8000000; j++);//do something
        printf(":");
        for(j=0; j<8000000; j++);//do something
        printf(".");
        for(j=0; j<8000000; j++);//do something
        printf(".");
    }
    printf(" infinit loop end. ");
    return 0;
}//int main(int argc, char *argv[])

void alarmWakeup(int sig_num){
    //unsigned int i;
    if(sig_num == SIGALRM){
        global_counter++;
        printf(" | ");
        if(global_counter % 50 == 0){
            printf("\n counter = %d  ==> ",global_counter);
        }        
    }
}