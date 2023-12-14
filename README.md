## STM32 PORTING uCOS-III

#### How to correctly handle the project import

- To correctly import the project, clone the repository anywhere with the **git clone** command
- Now, open STM32CubeIDE, choose the workspace you want to associate the project to
- Click on **File** -> **Open project from filesystem** -> **Directory** and then select the folder of the cloned repository
- Now right click on the project in **Project Explorer** and go to **Properties** (the last entry of the menu)
- Now open **C/C++ General** submenu, and click on **Paths and Symbols**
- Now under **Includes** section, remove the **C:\<something>** entry and click on **Add** -> **File System** and choose the **software** folder from the cloned repository
- Now do the same thing under Assembly section

Now the work is done and you can build the project without errors.
