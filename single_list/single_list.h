// ����ѭ������ֻ֧��int�������ͣ�ÿ��Ԫ�ص�intֵ��Ҫ��ͬ

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

class single_list {
public:
    // ���캯��
    single_list(int num) :
        val(num), next(nullptr) { head->next = this; }
    // ��ýڵ��Ԫ��ֵֵ
    int val_get() const;
    // ��ĳ�ڵ�����ڵ�
    void insert_after(int);
    // ɾ��ĳ�ڵ��Ľڵ�
    void erase_after(void);
    // �ı�ĳ�ڵ����һ���ڵ��ֵ
    void replace_after(int);

public:
    // ָ����һ���ڵ��ָ��
    single_list* next;
    // һֱָ���һ���ڵ��ָ�루ͷָ�룩
    static single_list* head;
private:
    // ����newʱʹ��
    single_list() = default;
    int val;

    // �жϸýڵ��ֵ�Ƿ���ڵĺ���
    bool exist_num(int);
};

#endif