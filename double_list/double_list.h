// 双向不循环链表，只支持int数据类型，每个元素的int值需要不同

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

class double_list {
public:
	// 初始化头节点
	double_list(int num) :
        val(num), pre(nullptr), next(nullptr) { head->next = this; }
	// 获得节点的元素值
    int val_get() const;
    // 在某节点后插入节点
    void insert_after(int);
    // 删除某节点后的节点
    void erase_after(void);
    // 改变某节点的下一个节点的值
    void replace_after(int);

public:
	// 一直指向第一个节点的指针
	static double_list* head;
	// 指向下一个节点的指针
	double_list* next = nullptr;

private:
	// 仅在new时使用
    double_list() = default;
	// 数据
	int val = 0;
	// 指向前一个节点的指针
	double_list* pre = nullptr;

	// 判断节点的值是否存在的函数
    bool exist_num(int);
};

#endif