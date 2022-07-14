#include <iostream>                         // std::cerr std::endl
#include "single_list.h"

// static数据成员需要在类的函数实现cpp文件中全局定义，且不能加static关键字
single_list* single_list::head = new single_list();

// 获得节点的元素值值
int single_list::val_get() const {
    // 当前节点不存在时输出错误信息并返回-1
    if (this == nullptr) {
        std::cerr << "node not exist! -1 will be returned." << std::endl;
        return -1;
    } else {
        return this->val;
    }
}

// 在某节点后插入节点
void single_list::insert_after(int num) {
    // 需要node存在，要插入的值num不存在
    if (this != nullptr && !exist_num(num)) {
        single_list* temp = new single_list();
        temp->next = this->next;
        this->next = temp;
        this->next->val = num;
    } else {
        std::cerr << "Inserting failed!" << std::endl;
    }
    return;
}

// 删除某节点后的节点
void single_list::erase_after(void) {
    // 需要node和node->next存在
    if (this != nullptr && this->next != nullptr) {
        single_list* temp = this-next;
        this->next = this->next->next;
        delete(temp);
    } else {
        std::cerr << "Erasing failed!" << std::endl;
    }
    return;
}

// 改变某节点的下一个节点的值
void single_list::replace_after(int num) {
    // 需要node 和 node->next都存在，要插入的值num不存在
    if (this != nullptr && this->next != nullptr && !exist_num(num)) {
        this->next->val = num;
    } else {
        std::cerr << "Replacing failed!" << std::endl;
    }
    return;
}

// 判断该节点的值是否存在的函数
bool single_list::exist_num(int num) {
    // 遍历查找num是否存在
    for (auto i = head->next; i != nullptr; i = i->next) { 
        if (i->val == num)
            return true;
    }
    return false;
}