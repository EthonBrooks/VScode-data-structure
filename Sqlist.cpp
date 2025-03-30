#include <bits/stdc++.h>
using namespace std;
# define MAX_SIZE 100

typedef struct
{
    int* date;
    int length; // ˳���ĳ���
} Sqlist;

// ˳���ĳ�ʼ��
void Initlist(Sqlist& L)
{
    L.date = new int[MAX_SIZE];
    L.length = 0; // ˳����ʼ����Ϊ0
}
// ˳��������
void destroy(Sqlist &L)
{
    delete[]L.date;
    L.date = nullptr;
    L.length = 0;
}
// �ж�˳����Ƿ�Ϊ��
bool IsEmpty(Sqlist L)
{
    return L.length == 0;
}

// ��ȡ˳���ĳ���
int length(Sqlist L)
{
    return L.length;
}

// ���˳���
void clear_Sqlist(Sqlist& L)
{
    L.length = 0;
}


// ˳���Ĳ���
int insert(Sqlist& L, int i, int x)
{
    if (i < 1 || i > L.length + 1) // ����λ�ò��Ϸ�
        return 0;
    if (L.length >= MAX_SIZE) // ˳������������ɲ���
        return 0;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.date[j + 1] = L.date[j]; // ��λ��i��i���Ԫ�ض�����ƶ�һλ���±��λ����1
    L.date[i - 1] = x; // �±��λ����1
    L.length++;
    return 1;
}

// ˳����ȡֵ
int get_elem(Sqlist L, int i)
{
    int x = 0;
    if (i < 1 && i > L.length)
        return 0;
    x = L.date[i - 1];
    return x;
}

// ˳���Ĳ���(λ��)�����ص���Ԫ����˳����е�һ�γ��ֵ�λ��
int locate(Sqlist L, int x)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.date[i] == x)
            return i + 1;
    }
    return 0;
}

// ˳����ɾ��
int del(Sqlist& L, int i)
{
    if (i < 1 || i > L.length - 1) // ɾ��λ�ò��Ϸ�
        return 0;
    for (int j = i; j < L.length; j++) // ��λ��Ϊi��i���Ԫ�ض���ǰ�ƶ�һλ���±��λ����1
        L.date[j-1] = L.date[j];
    L.length--;
    return 1;
}

// ˳���ı���
void printl(Sqlist L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.date[i] << " ";
    cout << endl;
}

int main()
{
    // ����ṹ�����
    Sqlist mylist;
    // ������ʼ��
    Initlist(mylist);
    if (IsEmpty(mylist))
        cout << "Empty List" << endl; // �пղ���
    int x;
    int i = 1;
    while (cin >> x && x != -1)
    {
        if (insert(mylist, i, x) == 0)
            cout << "error" << endl;
        i++;
    } // ͨ���������룬������
    printl(mylist); // �����������
    cout << "��Ϊ��" << length(mylist) << endl;
    cout << "ɾ���ڼ���";
    cin >> i;
    del(mylist, i); // ����ɾ������
    printl(mylist);
    cout << "�ڼ���λ�ò���";
    cin >> i;
    cout << "�����Ԫ��" ;
    cin >> x;
    insert(mylist, i, x);
    printl(mylist);
    cout << "��ȡ�ڼ���";
    cin >> i;
    cout << get_elem(mylist, i) << endl;
    cout << "���ҵڼ���";
    cin >> x;
    i = locate(mylist, x);
    if (i != 0)
        cout << "λ��Ϊ" << i << endl;
    else
        cout << "error" << endl;
    clear_Sqlist(mylist);
    cout << "��պ󣬱�Ϊ" << length(mylist) << endl;
    destroy(mylist);
    return 0;
}
