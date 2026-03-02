#include <iostream>
#include "TodoManager.h"

int main() {
    try {
        TodoManager manager;//创建类对象
        manager.run();//启动

        //或者如下指针方式创建类对象并启动
        //TodoManager* pmanager = new TodoManager;
        //pmanager->run();
        
    }
    catch (const std::exception& e) {
        std::cerr << "程序发生异常: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}