// 单向不循环链表，只支持int数据类型，每个元素的int值需要不同

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

class single_list {
public:
    // 构造函数
    single_list(int num) :
        val(num), next(nullptr) { head->next = this; }
    // 获得节点的元素值值
    int val_get() const;
    // 在某节点后插入节点
    void insert_after(int);
    // 删除某节点后的节点
    void erase_after(void);
    // 改变某节点的下一个节点的值
    void replace_after(int);

public:
    // 指向下一个节点的指针
    single_list* next;
    // 一直指向第一个节点的指针（头指针）
    static single_list* head;
private:
    // 仅在new时使用
    single_list() = default;
    int val;

    // 判断该节点的值是否存在的函数
    bool exist_num(int);
};

#endif