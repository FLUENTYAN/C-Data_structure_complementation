#include <iostream>
#include <memory>
#include "double_list.h"

int main(void) {
    // 初始化第一个节点为0
    auto list = new double_list(0);
    
    // 第二个位置插入两次
    list->insert_after(2);
    list->insert_after(1);
    std::cout << list->val_get() << " " 
              << list->next->val_get() << " " 
              << list->next->next->val_get() << std::endl;

    // 第三个位置插入已存在的数（在整个链表中已存在）
    // 数已存在，报错
    list->next->insert_after(2);

    // 第二个位置的值替换 
    list->replace_after(3);
    std::cout << list->val_get() << " " 
              << list->next->val_get() << " " 
              << list->next->next->val_get() << std::endl;
    // 第三个位置替换已存在的数
    // 数已存在，会报错
    list->next->replace_after(0);

    // 删除第二个位置的元素 
    list->erase_after();
    std::cout << list->val_get() << " "
              << list->next->val_get() << " "
              // 无此元素，会报错
              << list->next->next->val_get() << std::endl;

    return 0;
}