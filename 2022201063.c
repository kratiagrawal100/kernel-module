#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/kernel.h>

void procs_info_print(void){
struct task_struct* task_list;
size_t p_c=0,i_c=0,ui_c=0;
for_each_process(task_list) {
		if(task_list->state == TASK_RUNNING) p_c++;
		else if(task_list->state == TASK_INTERRUPTIBLE) i_c++;
		else if(task_list->state == TASK_UNINTERRUPTIBLE) ui_c++;
	}

printk(KERN_INFO "Count == %zu\n",p_c);
printk(KERN_INFO "Interrupt Count == %zu\n",i_c);
printk(KERN_INFO "Uninterrupt Count == %zu\n",ui_c);
}

int ques_init(void)
{
printk(KERN_INFO "Module Initialsed....\n");
procs_info_print();
return 0;
}

void ques_exit(void){
printk(KERN_INFO "Byee!!\n");
}

module_init(ques_init);
module_exit(ques_exit);
