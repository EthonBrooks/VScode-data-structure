#include <bits/stdc++.h>
using namespace std;
# define MAX_SIZE 100

typedef struct
{
    int* date;
    int length; // 顺序表的长度
} Sqlist;

// 顺序表的初始化
void Initlist(Sqlist& L)
{
    L.date = new int[MAX_SIZE];
    L.length = 0; // 顺序表初始长度为0
}
// 顺序表的销毁
void destroy(Sqlist &L)
{
    delete[]L.date;
    L.date = nullptr;
    L.length = 0;
}
// 判断顺序表是否为空
bool IsEmpty(Sqlist L)
{
    return L.length == 0;
}

// 获取顺序表的长度
int length(Sqlist L)
{
    return L.length;
}

// 清除顺序表
void clear_Sqlist(Sqlist& L)
{
    L.length = 0;
}


// 顺序表的插入
int insert(Sqlist& L, int i, int x)
{
    if (i < 1 || i > L.length + 1) // 插入位置不合法
        return 0;
    if (L.length >= MAX_SIZE) // 顺序表已满，不可插入
        return 0;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.date[j + 1] = L.date[j]; // 把位置i和i后的元素都向后移动一位，下标比位置少1
    L.date[i - 1] = x; // 下标比位置少1
    L.length++;
    return 1;
}

// 顺序表的取值
int get_elem(Sqlist L, int i)
{
    int x = 0;
    if (i < 1 && i > L.length)
        return 0;
    x = L.date[i - 1];
    return x;
}

// 顺序表的查找(位置)，返回的是元素在顺序表中第一次出现的位序
int locate(Sqlist L, int x)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.date[i] == x)
            return i + 1;
    }
    return 0;
}

// 顺序表的删除
int del(Sqlist& L, int i)
{
    if (i < 1 || i > L.length - 1) // 删除位置不合法
        return 0;
    for (int j = i; j < L.length; j++) // 把位置为i和i后的元素都向前移动一位，下标比位置少1
        L.date[j-1] = L.date[j];
    L.length--;
    return 1;
}

// 顺序表的遍历
void printl(Sqlist L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.date[i] << " ";
    cout << endl;
}

int main()
{
    // 定义结构体变量
    Sqlist mylist;
    // 变量初始化
    Initlist(mylist);
    if (IsEmpty(mylist))
        cout << "Empty List" << endl; // 判空操作
    int x;
    int i = 1;
    while (cin >> x && x != -1)
    {
        if (insert(mylist, i, x) == 0)
            cout << "error" << endl;
        i++;
    } // 通过反腐插入，创建表
    printl(mylist); // 测试输出数据
    cout << "表长为：" << length(mylist) << endl;
    cout << "删除第几个";
    cin >> i;
    del(mylist, i); // 测试删除数据
    printl(mylist);
    cout << "第几个位置插入";
    cin >> i;
    cout << "插入的元素" ;
    cin >> x;
    insert(mylist, i, x);
    printl(mylist);
    cout << "读取第几个";
    cin >> i;
    cout << get_elem(mylist, i) << endl;
    cout << "查找第几个";
    cin >> x;
    i = locate(mylist, x);
    if (i != 0)
        cout << "位序为" << i << endl;
    else
        cout << "error" << endl;
    clear_Sqlist(mylist);
    cout << "清空后，表长为" << length(mylist) << endl;
    destroy(mylist);
    return 0;
}
