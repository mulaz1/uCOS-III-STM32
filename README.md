## STM32 PORTING uCOS-III

#### How to correctly handle the project import

- To correctly import the project, clone the repository anywhere with the **git clone** command
- Now, open STM32CubeIDE, choose the workspace you want to associate the project to
- Click on **File** -> **Open project from filesystem** -> **Directory** and then select the folder of the cloned repository

Now the work is done and you can build the project without errors.

In order to use ```COM_port_serial_print()``` function, you need to use PuTTY (or another serial terminal emulator) and open a serial connection 115200 8E1 on the right COM port that you can see on Device Manager (if you are on Windows) in the section Ports (COM & LPT).

##### OSTimeDlyHMSM flow

The function when called insert the current task in a list of task waiting for time to expire through the **OS_TickListInsertDly** method. Every time a tick interrupt is raised then the **OS_CPU_SysTickHandler** handler is called and in the handler the **OSTimeTick** function is called. (OSTimeTick function is used to signal to the kernel the occurrence of a system tick). OSTimeTick then update the tick using OS_TickUpdate(1u) function which calls the OS_TickListUpdate function which, if the task is ready to execute (i.e. the delay has expired) then the function puts it in the Ready List using the **OS_RdyListInsert** function.