#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>

#define SPY_INFO_SYSCALL 452 //syscall number in the syscall table

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <app_name>\n", argv[0]);
        return 1;
    }

    char *app_name = argv[1];
    int pid,uid,cpu;

    long result = syscall(SPY_INFO_SYSCALL, app_name, &pid, &uid, &cpu);

    if(result == 0)
    {
        printf("Process Name: %s\n", app_name);
        printf("Process PID: %d, UID: %d, Running on CPU: %d\n", pid, uid, cpu);
    } else {
        printf("Process '%s' not found.\n" , app_name);
    }

    return 0;
}