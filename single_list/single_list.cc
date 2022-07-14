#include <iostream>                         // std::cerr std::endl
#include "single_list.h"

// static���ݳ�Ա��Ҫ����ĺ���ʵ��cpp�ļ���ȫ�ֶ��壬�Ҳ��ܼ�static�ؼ���
single_list* single_list::head = new single_list();

// ��ýڵ��Ԫ��ֵֵ
int single_list::val_get() const {
    // ��ǰ�ڵ㲻����ʱ���������Ϣ������-1
    if (this == nullptr) {
        std::cerr << "node not exist! -1 will be returned." << std::endl;
        return -1;
    } else {
        return this->val;
    }
}

// ��ĳ�ڵ�����ڵ�
void single_list::insert_after(int num) {
    // ��Ҫnode���ڣ�Ҫ�����ֵnum������
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

// ɾ��ĳ�ڵ��Ľڵ�
void single_list::erase_after(void) {
    // ��Ҫnode��node->next����
    if (this != nullptr && this->next != nullptr) {
        single_list* temp = this-next;
        this->next = this->next->next;
        delete(temp);
    } else {
        std::cerr << "Erasing failed!" << std::endl;
    }
    return;
}

// �ı�ĳ�ڵ����һ���ڵ��ֵ
void single_list::replace_after(int num) {
    // ��Ҫnode �� node->next�����ڣ�Ҫ�����ֵnum������
    if (this != nullptr && this->next != nullptr && !exist_num(num)) {
        this->next->val = num;
    } else {
        std::cerr << "Replacing failed!" << std::endl;
    }
    return;
}

// �жϸýڵ��ֵ�Ƿ���ڵĺ���
bool single_list::exist_num(int num) {
    // ��������num�Ƿ����
    for (auto i = head->next; i != nullptr; i = i->next) { 
        if (i->val == num)
            return true;
    }
    return false;
}