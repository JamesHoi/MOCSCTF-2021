#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <signal.h>
 
void sig_handler(int num)
{
    printf("hello\n");
    exit(0);
}
void set_up(){
        signal(SIGALRM, sig_handler);
        alarm(3);
}
void backdoor(){
    system("echo MOCSCTF{YOU_GET_THE_FLAG_WHAT_AN_EZ_PWN!!!}");
}
void task(){
    char s[0x20];
    printf("This GIFT will help you: %p\n",&s);
    memset(s,0,0x20);
    puts("Use your magic word now:");
    read(0,s,0x30);
    return;
}
int main(){
    setbuf(stdout,0);
    setbuf(stderr,0);
    setbuf(stdin,0);
    //set_up();
    puts("welcome to MOCSCTF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    task();
    return 0;
}
