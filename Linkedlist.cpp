#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node *next; //指向下一个节点的指针
}node, *nodeptr;

//单链表初始化
void init (nodeptr &L)
{
    L = new node; //生成新节点作为头节点，用头指针L指向头节点
    L->next = nullptr; //头节点的next置空
}

//前插法创建单链表
void createList_H(nodeptr &L, int n)
{
    L = new node; //生成新节点作为头节点
    L->next = nullptr; //头节点的next置空
    for (int i = 0; i < n; i++)
    {
        nodeptr s = new node; //生成新节点s
        cin >> s->data; //输入数据
        s->next = L->next; //将新节点s的next指向头节点的next
        L->next = s; //将头节点的next指向新节点s
    }
}

//后插法创建单链表
void createList_R(nodeptr &L, int n)
{
    L = new node; //生成新节点作为头节点
    L->next = nullptr; //头节点的next置空
    nodeptr r = L; //创建一个尾指针r，指向头节点
    for (int i = 0; i < n; i++)
    {
        nodeptr s = new node; //生成新节点s
        cin >> s->data; //输入数据
        s->next = nullptr; //新节点s的next置空
        r->next = s; //将尾指针r的next指向新节点s
        r = s; //将尾指针r指向新节点
    }
}

//单链表的销毁
void destroy (nodeptr &L)
{
    nodeptr p;
    while (L != nullptr) //当链表不为空时
    {
        p = L; //将p指向当前头节点
        L = L->next; //将头指针L指向下一个节点
        delete p; //删除当前节点
    }
}

//单链表的插入
int insert (nodeptr &L, int i, int x)
{
    nodeptr p = L; //将p指向头节点
    int j = 0;
    while (p && j < i - 1) //遍历单链表，找到第i-1个节点
    {
        p = p->next; //将p指向下一个节点
        j++;
    }
    if (!p || j > i - 1) //如果p为空或j大于i-1，表示插入位置不合法
        return 0;
    nodeptr s = new node; //生成新节点s
    s->data = x; //将数据x赋值给新节点s
    s->next = p->next; //将新节点s的next指向p的next
    p->next = s; //将p的next指向新节点s
    return 1; //插入成功
}

//单链表的删除
int del (nodeptr &L, int i)
{
    nodeptr p = L; //将p指向头节点
    int j = 0;
    while (p->next && j < i - 1) //遍历单链表，找到第i-1个节点
    {
        p = p->next; //将p指向下一个节点
        j++;
    }
    if (!p->next || j > i -1) //如果p的next为空或j大于i-1，表示删除位置不合法
        return 0;
    nodeptr q = p->next; //将q指向要删除的节点
    p->next = q->next; //将p的next指向q的next
    delete q; //删除节点q
    return 1; //删除成功
}

//单链表的查找
nodeptr locate (nodeptr L, int x)
{
    nodeptr p = L->next; //将p指向首元节点
    while (p && p->data != x) //遍历单链表，查找数据x
    {
        p = p->next; //将p指向下一个节点
    }
    return p; //查找成功返回值为e的节点地址，查找失败p为NULL
}

//单链表的取值
int getelem (nodeptr L, int i)
{
    nodeptr p = L->next; //将p指向首元节点
    int j = 1;
    while (p && j < i ) //遍历单链表，找到第i个节点
    {
        p = p->next; //将p指向下一个节点
        j++;
    }
    if (!p || j > i) //如果p为空或j大于i，表示取值位置不合法
        return 0;
    return p->data; //返回第i个节点的数据
}

//单链表的尾部追加
int append (nodeptr &L, int x)
{
    nodeptr p = L; //将p指向头节点
    while (p->next)
    {
        p = p->next; //遍历单链表，找到最后一个节点
    }
    nodeptr s = new node; //生成新节点s
    s->data = x; //将数据x赋值给新节点s
    s->next = NULL; //将新节点s的next置空
    p->next = s; //将最后一个节点的next指向新节点s
    return 1; //插入成功
}

//单链表的长度
int length (nodeptr L)
{
    nodeptr p = L->next; //将p指向首元节点
    int len = 0; //初始化长度为0
    while (p)
    {
        len++; //长度加1
        p = p->next; //将p指向下一个节点
    }
    return len; //返回长度
}

//单链表的遍历
void printl (nodeptr L)
{
    nodeptr p = L->next; //将p指向首元节点
    while (p)
    {
        cout << p->data << " "; //输出节点数据
        p = p->next; //将p指向下一个节点
    }
    
}

int main()
{
    nodeptr L; //定义单链表头指针L
    init(L); //初始化单链表L
    int x;
    while (cin >> x && x != -1) //输入数据，-1表示结束
    {
        append(L, x); //将数据x追加到单链表L的尾部
    }
    printl(L); //遍历输出单链表L
    cout << endl; //换行
    cout << "Length: " << length(L) << endl; //输出单链表L的长度
    cout << "Enter position to insert: ";//提示输入插入位置
    int i;
    cin >> i; //输入插入位置
    cout << "Enter value to insert: "; //提示输入插入值
    cin >> x; //输入插入值
    if (insert(L, i, x)) //插入成功
        cout << "Insert success!" << endl; //提示插入成功
    else //插入失败
        cout << "Insert failed!" << endl; //提示插入失败
    printl(L); //遍历输出单链表L
    cout << endl; //换行
    cout << "Enter position to delete: "; //提示输入删除位置
    cin >> i; //输入删除位置
    if (del(L, i)) //删除指定位置的节点
        cout << "Delete success!" << endl; //提示删除成功
    else //删除失败
        cout << "Delete failed!" << endl; //提示删除失败
    printl(L); //遍历输出单链表L
    cout << endl; //换行
    cout << "Enter value to locate: "; //提示输入查找值
    cin >> x; //输入查找值
    nodeptr p = locate(L, x); //查找值为x的节点
    cout << "Locate result: "; //提示查找结果
    cout << p << endl; //输出查找结果
    cout << "Enter position to get value: "; //提示输入获取值的位置
    cin >> i; //输入获取值的位置
    int value = getelem(L, i); //获取第i个节点的值
    cout << "Get value: "; //提示获取值
    cout << value << endl; //输出获取值
    return 0;
}