#include <iostream>                         // std::cerr std::endl
#include "double_list.h"

// static数据成员需要在类的函数实现cpp文件中全局定义，且不能加static关键字
double_list* double_list::head = new double_list();

// 获得节点的元素值
int double_list::val_get() const {
    // 当前节点不存在时输出错误信息并返回-1
    if (this == nullptr) {
        std::cerr << "node not exist! -1 will be returned." << std::endl;
        return -1;
    } else {
        return this->val;
    }
}

// 在某节点后插入节点
void double_list::insert_after(int num) {
    // 插入位置后面有节点, 要插入的值在链表中没有
    if (this != nullptr && this->next != nullptr && !exist_num(num)) {
        double_list* temp = new double_list();
        this->next->pre = temp;
        temp->next = this->next;
        temp->pre = this;
        this->next = temp;
        temp->val = num;
    }
    // 插入位置后面没有节点, 要插入的值在链表中没有
    else if (this != nullptr && this->next == nullptr && !exist_num(num)) {
        double_list* temp = new double_list();
        temp->next = nullptr;
        temp->pre = this;
        this->next = temp;
        temp->val = num;
    } else {
        std::cerr << "Insert failed!" << std::endl;
    }
}

// 删除某节点后的节点
void double_list::erase_after(void) {
    // 要删除的节点后面有节点
    if (this != nullptr && this->next != nullptr) {
        double_list* temp = this->next;
        this->next = this->next->next;
        this->next->pre = this;
        delete(temp);
    }
    // 要删除的节点后面为空
    else if (this != nullptr && this->next == nullptr) {
        double_list* temp = this->next;
        this->next = nullptr;
        delete(temp);
    } else {
        std::cerr << "Erasing failed!" << std::endl;
    }
    return;
}

// 改变某节点的下一个节点的值
void double_list::replace_after(int num) {
    // 需要改变的节点存在，num在链表中不存在
    if (this != nullptr && this->next != nullptr && !exist_num(num)) {
        this->next->val = num;
    } else {
        std::cerr << "Replacing failed!" << std::endl;
    }
    return;
}

// 判断该节点的值是否存在的函数
bool double_list::exist_num(int num) {
    // 遍历查找num是否存在
    for (auto i = head->next; i != nullptr; i = i->next) { 
        if (i->val == num)
            return true;
    }
    return false;
}