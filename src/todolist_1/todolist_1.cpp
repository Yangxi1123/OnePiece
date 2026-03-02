// todolist_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<string>
using namespace std;

//函数的声明：函数的返回值、函数的传参、函数的作用
void printMenu();//输出主菜单
void addTask(std::vector<std::string>& tasks);//添加
void viewTasks(const std::vector<std::string>& tasks);//查看
void deleteTask(std::vector<std::string>& tasks);//删除任务

int main() {
    //数据容器类型，数据结构
    std::vector<std::string> tasks; // 存储任务的向量，全局变量
    int choice = 0;

    std::cout << "=== 简易待办事项列表 ===" << std::endl;

    do {
        printMenu();
        std::cin >> choice;

        // 清除输入缓冲区，防止后续getline读取到换行符
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            std::cout << "感谢使用待办事项列表，再见！" << std::endl;
            break;
        default:
            std::cout << "无效选择，请重试。" << std::endl;
        }
    } while (choice != 4);

    return 0;
}

//打印主菜单
void printMenu() {
    std::cout << "\n--- 主菜单 ---" << std::endl;
    std::cout << "1. 添加任务" << std::endl;
    std::cout << "2. 查看所有任务" << std::endl;
    std::cout << "3. 删除任务" << std::endl;
    std::cout << "4. 退出程序" << std::endl;
    std::cout << "请选择操作 (1-4): ";
}

void addTask(std::vector<std::string>& tasks) {
    std::string task;
    std::cout << "请输入新任务: ";
    std::getline(std::cin, task);//getline(cin,task)向task中存储一行字符串，如果用cin>>task,则只能存储进空格之前的内容

    if (!task.empty()) { //如果task不为空，则添加进tasks列表中
        tasks.push_back(task);//用于将元素添加到 std::vector 容器的末尾。
        std::cout << "任务添加成功！" << std::endl;
    }
    else {
        std::cout << "任务内容不能为空！" << std::endl;
    }
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "当前没有待办任务。" << std::endl;
        return;
    }

    std::cout << "\n--- 当前待办事项 ---" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
    std::cout << "总计: " << tasks.size() << " 个任务" << std::endl;
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "当前没有可删除的任务。" << std::endl;
        return;
    }

    viewTasks(tasks); // 先显示所有任务

    int taskNumber;
    std::cout << "请输入要删除的任务编号: ";
    std::cin >> taskNumber;

    // 检查输入是否为数字且有效
    if (std::cin.fail()) {//检查输入是否失败，是的话就执行以下
        std::cin.clear(); // 清除错误状态
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区
        std::cout << "请输入有效的数字！" << std::endl;
        return;// 退出当前函数
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        std::string removedTask = tasks[taskNumber - 1];
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "任务 \"" << removedTask << "\" 已删除！" << std::endl;
    }
    else {
        std::cout << "无效的任务编号！" << std::endl;
    }
}