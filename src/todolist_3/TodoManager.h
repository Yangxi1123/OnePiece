#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include "TodoList.h"
#include <memory>

class TodoManager {//TodoManager类承接的是用户交互功能。

public://公有函数
    TodoManager();
    void run();

private://私有函数，面向用户交互的接口
    

    void printMainMenu() const;//打印主菜单
    void printFileMenu() const;//打印文件操作菜单
    void handleMainMenu();//
    void handleFileMenu();//
    void handleAddTask();//响应任务添加
    void handleDeleteTask();//响应任务删除
    void handleSaveToFile();//
    void handleLoadFromFile();//
    void handleViewFileContent() const;

private://私有成员
    std::unique_ptr<TodoList> todoList;//unique_ptr：智能指针
};//TodoList类是数据存储功能。

#endif // TODOMANAGER_H