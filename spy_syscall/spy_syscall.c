#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/string.h>


SYSCALL_DEFINE4 (spy_info, char __user *, app_name, int __user *, pid, int __user *, uid, int __ser* , cpu)
{
    struct task_struct *task;
    char k_app_name[TASK_COMM_LEN];

    if(copy_from_user(k_app_name, app_name, TASK_COMM_LEN))
        return -EFAULT;

    k_app_name[TASK_COMM_LEN - 1] = '\0'; // null termination

    for_each_process(task)
    {
        if(strcmp(task->comm, k_app_name) == 0)
        {
            int _pid = task->pid;
            int _uid = __kuid_val(task->real_cred->uid);
            int _cpu = task_cpu(task);

            if(copy_to_user(pid, &_pid, sizeof(int)) ||
               copy_to_user(uid, &_uid, sizeof(int)) ||
               copy_to_user(cpu, &_cpu, sizeof(int)))
               return -EFAULT;

            return 0;
        }
    }

    return -ESRCH; // No matching process found
}