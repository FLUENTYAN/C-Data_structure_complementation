#include <iostream>
#include <memory>
#include "single_list.h"

int main(void) {
    // ��ʼ����һ���ڵ�Ϊ0
    auto list = new single_list(0);
    
    // �ڶ���λ�ò�������
    list->insert_after(2);
    list->insert_after(1);
    std::cout << list->val_get() << " " 
              << list->next->val_get() << " " 
              << list->next->next->val_get() << std::endl;

    // ������λ�ò����Ѵ��ڵ������������������Ѵ��ڣ�
    // ���Ѵ��ڣ�����
    list->next->insert_after(2);

    // �ڶ���λ�õ�ֵ�滻 
    list->replace_after(3);
    std::cout << list->val_get() << " " 
              << list->next->val_get() << " " 
              << list->next->next->val_get() << std::endl;
    // ������λ���滻�Ѵ��ڵ���
    // ���Ѵ��ڣ��ᱨ��
    list->next->replace_after(0);

    // ɾ���ڶ���λ�õ�Ԫ�� 
    list->erase_after();
    std::cout << list->val_get() << " "
              << list->next->val_get() << " "
              // �޴�Ԫ�أ��ᱨ��
              << list->next->next->val_get() << std::endl;

    return 0;
}