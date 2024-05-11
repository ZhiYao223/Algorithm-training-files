最常用的数据结构预算法:

- 数据结构：数组、链表、栈、队列、散列表、二叉树、堆、跳表、图、Tire树
- 算法： 递归、排序、二分查找、搜索、哈希算法、贪心算法、分治算法、回溯算法、动态规划、字符串匹配算法

# 线性表

|            |                            顺序表                            |                             链表                             |
| :--------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|  存储空间  |              预先分配，可能会导致空间闲置或溢出              |              动态分配，不会出现空间闲置或者溢出              |
|  存取元素  |           随机存取，按位置访问元素的时间复杂度O(1)           |         顺序存取，访问某位置的元素的时间复杂度为O(n)         |
| 插入、删除 | 插入和删除都要移动大量的元素。平均移动元素约为表的一半。时间复杂度O(n) | 不需要移动元素，只需要改变指针位置，继而改变结点之间的链接关系。时间复杂度O(1) |
|  适用情况  | 1.表长变化不大，或者事先就能确定变化的范围 2.很少进行插入和删除，需要下标访问元素 |             1.长度变化较大   2.频繁的插入和删除              |
|            |                 *这不就是vector的使用特点吗*                 |                  *这不就是list的使用特点吗*                  |

## ==顺序表==  

### 线性表的定义

- 每个数据元素所占空间一样大
- 线性表是具有==相同==数据类型的 $n(n>=0)$ 个数据元素的有限序列。
- 把顺序存储的方式实现线性表顺序存储。

### 顺序线性表的实现---------静态分配

- 当我们声明一个顺序表的时候，把length值置为0是很有必要的： **L.length = 0;**

#### 顺序表的定义

```cpp
#define MaxSize 10                        //定义最大长度
typedef struct{                           
	ElemType data[MaxSize];              //用静态的“数组”存放数据元素
	int length;                          //顺序表的当前长度
}SqList;                                 //顺序表的类型定义（静态分配方式）
```

#### 顺序表的初始化

```
bool InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE]; //在堆区开辟内存
    if(!L.elem)
    {
        cerr<<"error"<<endl;
        return false;
    }
    L.length = 0;//设定线性表长度为0
    return 1;
}
```

#### 顺序表的销毁

```cpp
void DestroyList(SqList &L)
{
    if(L.elem)
    {
        delete L.elem;
    }
}
```

#### 顺序表的清空

```cpp
void ClearList(SqList &L)
{
    L.length = 0;
}
```

#### 判断线性表是否为空

```cpp
bool IsEmpty(const SqList &L)
{
    return static_cast<bool>(L.length);
}
```

#### 线性表的取值

```cpp
bool GetElem(const SqList &L, const size_t i, ElemType &e)
{
    if(i<1 || i>MAXSIZE)
    {
        cerr<<"out of range"<<endl;
        return false;
    }
    e = L.elem[i-1];
    return true;
}
```

#### 线性表的查找

```cpp
int LocateList(const SqList &L, const ElemType &e)
{
    for(int i = 0; i < L.length; ++i)
    {
        if(L.elem[i] == e)
        {
            return i+1;	//查找成功，返回其查找元素的第一个下标值
        }
    }
    return 0;	//未能找到对应元素，返回0 
}
//算法时间复杂度：O(n)
```

#### 线性表的插入

```cpp
bool InsertList(SqList &L, const ElemType &e, const int &i)
{
    //判断线性表长度是否小于最大长度MAXSIZE
    if(L.length == MaxSize)
    {
        cerr << "can not insert!" <<endl;
        return false;
    }
    if(i<0 || i>L.length)
    {
        cerr << "wrong insert position!" <<endl;
        return false;
    }
    if(L.length > 0)
    {
        //将位于插入位置之后的元素一次向后挪动一位
        for(int k = L.length-1; k >= i; --k)
        {
            L.elem[p + 1] = L.elem[p];
        }
    }
    L.elem[i] = e;	//插入元素
    L.length += 1;	//线性表长度+1
    return true;    
    //算法时间复杂度：O(n)
}

```

#### 线性表的删除

```cpp
bool EraseList(SqList &L, const int &i)
{
    //异常判断
    if(i<0 || i>L.length)
    {
        cerr << "wrong erase position!" << endl;
        return false;
    }
    if(L.length == 0)
    {
        cerr << "List has no length" << endl;
        return false;
    }
    //将位于删除位置之后的元素依次向前挪动一位
    for (int k = i + 1; k < L.length; ++k)
    {
        L.elem[k - 1] = L.elem[k];
    }
    //线性表长度-1
    L.length -= 1;
    return true;
    //算法时间复杂度：O(n)
}
```



```cpp
/*不初始化数据元素，内存不刷0*/
#include <stdio.h>
#define MaxSize 10		        //定义最大长度

/*线性表的定义*/
typedef struct
{
    ElemType data[MaxSize];		//用静态的“数组”存放数据元素
    int length;				   //顺序表的当前长度
}SqList;					  //顺序表的类型定义(静态分配方式)

/*初始化一个顺序表*/
bool InitList(SqList &L)
{
    L.elem = new ElemType[MaxSize];	//在堆区开辟内存
    if(!L.elem)
    {
        cerr << "error" <<endl;     //cerr是标准错误流，用于向标准错误输出错误信息，摆布程序员发现处理问题。
        return false; 
    }
    L.length = 0;				   //设定线性表长度为0
    return 1;
}

int main()
{
    SqList L;					  //声明一个顺序表
    InitList(L);				  //初始化顺序表
    //......
    return 0;
}
```

### 顺序表的实现---------动态分配

​	顺序表是一种线性表的存储结构，可以在连续的内存空间中存储元素。动态分配顺序表是指在需要时，根据实际情况动态增加或释放存储空间。

以下是实现动态分配顺序表的基本步骤：

1. **定义结构体或类**：首先，需要定义一个结构体或类来表示顺序表，可以包含如下成员：

   - 数据区域的指针，用于存储元素的数组。

   - 当前顺序表的大小（元素个数）。

   - 当前分配的存储空间大小。

   - 其他辅助变量或信息。

2. **创建动态顺序表**：在内存中分配一定大小的空间作为动态顺序表的初始存储空间，并初始化顺序表的各个成员。可以使用动态内存分配函数（如malloc）来分配空间。

3. **插入元素**：当需要插入新元素时，按照顺序表的逻辑顺序找到插入位置。如果当前存储空间不足以容纳新元素，则需要进行动态扩容，重新分配更大的存储空间，并将原有的元素复制到新的空间中。

4. **删除元素**：当需要删除元素时，将待删除元素后面的元素向前移动，填补删除位置，并更新顺序表的大小。如果删除元素后，剩余存储空间占比过低，可以考虑进行动态缩容，释放多余的存储空间。

5. **销毁顺序表**：当顺序表不再使用时，需要释放占用的内存空间，即使用动态内存释放函数（如free）释放动态顺序表的存储空间。

#### 顺序表的定义

```cpp
#define InitSize 10		//顺序表的初始长度
typedef struct
{
    ElemType *data;		//指示动态分配数组的指针
    int MaxSize;		//顺序表的最大容量
    int length;			//顺序表的当前长度
}SeqList;			    //顺序表的类型定义(动态分配方式)

//Key： 动态申请和释放内存空间   
//C---- malloc、free函数
		L.data = (Elem Type*) malloc(sizeof(ElemType), *InitSize);
//C++---new、delete关键字
```

- malloc函数申请的是一整片连续的存储空间，malloc 函数返回一个指针，需要强制转换型为你定义的数据元素类型指针。
- malloc函数的参数，指明要分配多大的连续内存空间。

```cpp
#include<stdlib.h>            //malloc、free函数的头文件
#define InitSize 10          //默认的最大长度
typedef struct{
	int *data;               //指示动态分配数组的指针		
	int MaxSize;             //顺序表的最大容量
	int length;              //顺序表的当前长度
}SeqList;

void InitList(SeqList &L){
	//用malloc函数申请一片连续的存储空间，如下图所示
	//调用malloc函数，申请一整片连续存储空间，其大小能存的下10个int类型数据。
	//malloc会返回一个指针类型，将其转换成和int *data;同类型的指针类型(int *)，然后将返回值赋值给data
	L.data = (int *)malloc(InitSize*sizeof(int));
	//malloc返回的是开辟的一整片存储空间的起始地址->data[0]
	L.length = 0;
	L.MaxSize = InitSize; //将顺序表最大容量设置为初始值
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len){
	int *p = L.data;      //将顺序表data指针的值赋给指针p，即p指针和data指向同一个位置
	//调用malloc函数，申请的另一块内存空间能够存得下当前所有数据元素，再多存5个新的数据元素，
	//再乘以每个数据元素的大小
	L.data = (int *)malloc((L.MaxSize + len)*sizeof(int));
	for(int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];     //将数据复制到新区域（时间开销大）
	}
	L.MaxSize = L.MaxSize + len;  //顺序表最大长度增加len
	//free会将p指针所指向的一整片(原空间)释放掉，归还给系统，这样就实现了内存的扩展。  
	free(p);                //释放原来的内存空间
	//由于*p是局部变量，在该函数执行完后，*p所在内存空间会被系统自动释放
}

int main()
{
	SeqList L;           //声明一个顺序表，计算机会开辟一小块存储空间用来存储SeqList顺序表
	InitList(L);         //初始化顺序表
	//......往顺序表中插入几个元素.......
	IncreaseSize(L, 5);
	return 0;
}

//realloc函数也可以实现，但建议初学者使用malloc和free更能理解背后的过程。

```

![在这里插入图片描述](assets/486805e02eeb4ebf91323cdcc5e2248b.png)

![在这里插入图片描述](assets/a2ee08e0bec44673b2e65959ca1ac8d5.png)

------



## ==单链表==

### 单链表的特性

​	单链表的特点是每个节点只有一个指针，指向下一个节点，而最后一个节点的指针指向空(null)。这意味着可以从链表的头节点开始，逐个访问每个节点，直到到达链表的末尾。

> 头指针 -> 节点1 -> 节点2 -> 节点3 -> … -> 最后一个节点 -> nullptr

- 链表(链式存储)
  - 单链表(两种实现)
    - 带头结点
    - 不带头结点
  - 双链表
  - 循环链表
  - 静态链表

单链表是一种常见的[数据结构](https://so.csdn.net/so/search?q=数据结构&spm=1001.2101.3001.7020)，用于存储元素的序列。它由一系列节点组成，每个节点包含一个数据元素和一个指向下一个节点的引用（指针）。单链表中的节点之间通过指针连接起来，形成一个线性结构。每个结点只能指向下一个结点，而最后一个结点指向一个空指针nullptr。

|      | 顺序表(顺序存储)                 | 单链表(链式存储)                     |
| ---- | -------------------------------- | ------------------------------------ |
| 优点 | 可随机存取，存储密度高           | 不要求大片连续空间，改变容量方便     |
| 缺点 | 要求大片连续空间，改变容量不方便 | 不可随机存取，要耗费一定空间存放指针 |

一个单链表包含一个头节点和一些后续的节点。头节点是链表的起点，它不存储任何实际的数据，只是用来标识链表的开始。头节点的指针指向链表中的第一个实际节点，而每个节点的指针则指向下一个节点。

通过这种指针链接，可以在链表中插入、删除和查找元素。插入元素时，只需要修改相应节点的指针，将新的节点插入到链表中的合适位置。删除元素时，需要修改前一个节点的指针，使其指向删除节点的下一个节点，然后将删除节点的内存空间释放。查找元素时，可以从头节点开始沿着指针依次访问链表，直到找到目标元素或到达链表的末尾。

单链表在某些场景下的操作效率较高，例如插入和删除操作，因为只需要修改指针而不需移动大量元素。然而，单链表的缺点是访问特定位置的元素较慢，需要从头节点开始遍历整个链表。此外，单链表不支持直接反向遍历，因为只有每个节点的下一个节点的指针，没有指向前一个节点的指针。

#### 定义单链表

```cpp
/*写法一(推荐)*/
typedef struct LNode{		//定义单链表结点类型
    ElemType data;			//每个结点存放下一个数据元素
    LNode *next;		    //指针指向下一个结点
}LNode, *LinkList;

/*写法二*/
struct LNode{			 //定义单链表结点类型
    ElemType data;		 //每个结点存放下一个数据元素
    LNode *next;	     //指针指向下一个结点
}
typedef LNode *LinkList;

/*要表示一个单链表时，只需声明一个头指针L,指向单链表的第一个结点
LNode *L;		//声明一个指向单链表第一个结点的指针(强调结点) 或
LinkList L;		//声明一个指向单链表第一个结点的指针(可读性更强，强调单链表)
*/

//增加一个新的结点：在内存中申请一个结点所需空间，并用指针p指向这个结点
struct LNode *p = (struct LNode*) malloc(sizeof(struct LNode));

typedef 关键字 ---数据类型重命名
typedef struct LNode LNode;     //将struct LNode 重命名为 LNode
LNode *p = (LNode*) malloc(sizeof(LNode)); //增加一个该类型的新结点
```

#### 链表的初始化

```cpp
bool InitList(LinkList &L)    
{
    L = new LNode;			//在堆区创建一个头结点，数据类型为LNode
    L->next = nullptr;       //空表、暂时没有任何结点，头结点指针指向空	
	return true;
}
```

### **头结点**

**单链表的带头结点和不带头结点的区别在于是否在链表的开头添加一个额外的头结点。**

- 不带头结点的单链表：

> 不带头结点的单链表直接将第一个节点作为链表的头节点。
> 特点是第一个节点存储数据，并且没有指向前一个节点的指针。
> 删除头节点时需要特殊处理，需要更新头指针。

- 带头结点的单链表：

> 带头结点的单链表在链表开头添加一个额外的头结点，头结点的数据域可以不存储实际数据。
> 头结点的作用是使得链表的第一个节点与其他节点的操作一致，简化链表操作。
> 头结点的指针域指向链表的第一个节点，方便遍历和插入。
> 删除头节点时可以直接将头指针指向下一个节点。

> 带头结点的单链表更常用，它使得链表的操作更加简单一致，避免了一些边界情况的特殊处理，更加方便处理链表的插入、删除等操作。同时，带头结点的单链表还可以避免链表为空的特殊情况的处理。

### 带头结点的单链表

```cpp
/*定义一个单链表*/
typedef struct LNode{		//定义单链表结点类型
    ElemType data;			//每个结点存放下一个数据元素
    struct LNode *next;		 //指针指向下一个结点
}LNode, *LinkList;

/*初始化一个单链表(带头结点)*/
bool InitList(LinkList &L)
{
    L = (LNode *) malloc(sizeof(LNode));	//分配一个头结点
    if(L==NULL)		
        return false;		//内存不足，分配失败
    L->next = NULL;
    return true;
}
```

#### 不带头结点的单链

```cpp
/*定义一个单链表*/
typedef struct LNode{		//定义单链表结点类型
    ElemType data;			//每个结点存放下一个数据元素
    struct LNode *next;		 //指针指向下一个结点
}LNode, *LinkList;

/*初始化一个空的单链表*/
bool InitList(LinkList &L)
{
    L = NULL;		//空表，暂时还没有任何结点(防止脏数据污染)
    return true;
}
/*判断单链表是否为空*/
bool Empty(LinkList L)
{
	return (L==NULL);
}
```

#### 头插法创建单向链表

```cpp
void CreatListHead(LinkList &L, const size_t n)
{
    for(int i = 0; i < n; ++i)
    {
        LNode *p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
```

#### 尾插法创建单向链表

```c++
void CreatListTail(LinkList &L, const size_t n)
{
    LNode *r = L;
    for(int i = 0; i < n; ++i)
    {
        LNode *p = new Lnode;
        cin >> p->data;
        p->next = r->next;
        r->next = p;
        r = r->next;
    }
}
```

#### 判断链表是否为空

```cpp
bool IsEmpty(const LinkList &L)
{
    return (L==NULL);
}
```

#### 销毁链表

```cpp
bool DestoryList(LinkList &L)
{
    if(IsEmpty(L))
    {
        cerr << "empty List！" << endl;
        return false;
    }
    while(L)                         //链表还未到达尾端
    {
        auto temp = L->next;		//头指针指向下一个结点
        delete L;                    //从头结点开始逐个释放结点空间
        L = temp;				   //更新头借点
    }
    return true;
}
```

#### 计算链表长度

```cpp
size_t GetLength(const LinkList &L)
{
    LNode *p;				//声明一个指向LNode结构体类型的指针变量，用来遍历链表
    p = L->next;			//将指针p指向链表的第一个实际数据结点(L->next)
    size_t count = 0;			
    while(p)                 //判断指向的有效性(指向非空)
    {
        ++count;			//计数
        p = p->next;		//更新，使p指向下一个结点，直到到达链表末尾(p=nullptr)
    }
    return count;
}
//时间复杂度O(n)
```

#### 获取第 i 个元素的值

```cpp
bool GetElem(const LinkList &L, const int &i, ElemType &e)
{
    if(i < 0)
    {
        cerr << "out of range" << endl;
        return false;
    }
    LNode *p = L->next;            //创建一个链表指针，指向 L 的下一个结点
    for(int j = 1; j < i+1; ++j)
    {
        if(!p)                
        {
            cerr << "out of range" << endl;
            return false;		//若p指向结点为空，表示已遍历到链表尾部，停止遍历
        }			
    }
    e = p->next;		    //更新指针p，指向下一个结点
    return true;
}
```

#### 按值查找元素

```cpp
/*按值查找元素(返回第几个位置)*/
size_t LocateElem(LinkList &L, ElemType &e)
{
    //声明一个LNode类型的指针变量p，并指向链表的第一个实际数据结点(L->next)。
    LNode *p = L->next; 	
    size_t count = 1;          //从第一个位置开始找
    while(p)			
    {
        if(p->data == e)   return count;    
        ++count;
        p = p->next;	       //更新p结点指向下一个位置
    }
    cerr << "not found" << endl; 
    return 0;
}
```

#### 在链表中插入元素

[传送门：单链表的插入删除](https://blog.csdn.net/AII_IIA/article/details/134065689)

```cpp
/*在单链表 L 的第 i 个位置插入元素 e*/
bool InsertList(LinkList &L, const int &i, const Elem ElemType &e)
{
    LNode *p = L;
    int j = 0;            
    while(p && j < i-1)    //判断插入位置合理性, 检查单链表前i个位置是否有效
    {
        p = p->next;	  //将p指向链表的第一个结点
        ++j;		
    }
    if(!p || i < 0)        //异常情况报错
    {
        cerr << "out of range" << endl;
        return false;
    }
    LinkList insert = new Lnode;   //创建一个链表结点
    insert->data = e; 			  //将待插入元素放入结点数据域
    insert->next = p->next;		  //将插入元素next指针指向第i+1个元素
    p->next = insert;		      //将插入元素前一个结点指向该插入元素，形成链表
    return true;
}
//时间复杂度为O(n)
```

##### 按位序插入(带头结点)

```cpp
//在第i个位置插入元素e（带头结点）
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool ListInsert(LinkList &L, int i, ElemType e){
	if(i < 1)
		return false;
	LNode *p;	//指针p指向当前扫描到的结点
	int j = 0;	//当前p指向的是第几个结点
	p = L;		//L指向头结点，头结点是第0个结点(不存数据)
	while (p != NULL && j < i-1){
	//循环找到第i-1个结点
	p = p->next;   //p结点向后移动一位
	j++;           
	}
	if(p==NULL)		//i值不合法
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;    //将数据元素e存入s数据域中
	s->next = p->next;  //令s指向p结点的后继结点。即使s结点连上p的后一个结点。
	p->next = s;      //将结点s连到p之后
	return true;      //插入成功
}
```

##### 按位序插入(不带头结点)

```cpp
//删除第i个元素(带头结点)
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool ListDelete(LinkList &L, int i, ElemType &e)
{
	if (i < 1)
		return false;
	LNode *p;       //指针p指向当前扫描到的结点
	int j = 0;      //当前p指向的是第几个结点
	p = L;          //L指向头结点，头结点是第0个结点(不存数据)
	while(p != NULL && j < i-1)    //循环找到第  i - 1 个结点 
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	if (p->next == NULL)     //第i-1个结点之后已经无其他结点
		return false;
	LNode *q = p->next;      //令q指向被删除结点
	e = q->data;			//用e返回元素的值
	p->next = q->next;		//将*q结点从链中“断开”
	free(q);				//释放结点的存储空间
	return true;			//删除成功
}
```



#### 删除链表的某个结点

- 注意，此函数没有处理删除头节点的特殊情况，即当`i == 0`时，直接从头开始删除节点的情况需要单独考虑。

``` cpp
bool EraseList(LinkList &L, const int &i)
{
    LNode *p = L;      		   //声明一个指向LNode类型的指针，初始化为指针L(链表头结点)
    int j = 0;
    //p->next确保p不是尾节点且未越界，j < i-1确保遍历到正确的位置。
    while(p->next && j < i-1)   //判断插入位置合理性, 检查单链表前i个位置是否有效
    {
        p = p->next;		   //使指针p向前移动
        ++j;
    }
    if(!(p->next) || i < 0)    //!(p->next)意味着已经到达链表末尾但还未找到第i个位置。
    {
        cerr << "out of range" <<endl;
        return false;
    }
    LNode *q = p->next; //声明新指针q，指向当前p所指向节点的下一个节点(即将被删除的节点)。
    p->next = p->next->next; 	//执行删除操作
    delete q;				   //释放掉不再链表中的节点q所占用的内存，防止内存泄漏。
    return true; 
}
```



#### 两个有序列表的合并

```cpp
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    Lnode *pa = La->next;    //声明指针pa，指向链表La的第一个实际数据结点
    Lnode *pb = Lb->next;	 //声明指针pb，指向链表Lb的第一个实际数据结点
    Lc = La;                 //先将La复制到新链表Lc中
    Lnode *pc = Lc;          //声明指针pc，指向Lc链表
    while (pa && pb)
    {
        if (pa->data <= pb->data) //尾插法，插入元素
        {
            //pc的指针域指向小元素的地址
            pc->next = pa;
            //移动pc指针，使得pc永远都指向最后链表Lc的最后一个元素
            pc = pc->next;
            //pa的元素使用过后，要向后移动pa
            pa = pa->next;
        }
        else
        {
            //pc的指针域指向小元素的地址
            pc->next = pb;
            //移动pc指针，使得pc永远都指向最后链表Lc的最后一个元素
            pc = pc->next;
            //pb的元素使用过后，要向后移动pa
            pb = pb->next;
        }
    }
    //上面的while循环执行完毕后，较长的链表还会余留一段元素，这段元素的起始地址就是pa（或pb
    pc->next = (pa ? pa : pb);
    //链表合并完毕，释放Lb的头结点
    delete Lb;
}
```

#### 完整C++单链表案例

```cpp
#include <iostream>

// 定义链表节点结构体
struct Node {
    int data;       // 存储节点的数据
    Node* next;     // 指向下一个节点的指针
};

// 定义链表类
class LinkedList {
private:
    Node* head;     // 头节点指针

public:
    // 构造函数，初始化链表为空
    LinkedList() : head(nullptr) {}

    // 在链表末尾插入新节点
    void insert(int value) {
        // 创建新节点
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        
        // 如果链表为空，将新节点作为头节点
        if (head == nullptr) {
            head = newNode;
        } else {
            // 找到链表末尾的节点
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // 将新节点插入到末尾
            current->next = newNode;
        }
    }

    // 在指定位置插入新节点
    void insertAt(int value, int position) {
        // 创建新节点
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        // 如果插入位置是头部
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } 
        // 如果插入位置不是头部
        else {
            int count = 0;
            Node* current = head;
            Node* prev = nullptr;

            // 找到插入位置的节点
            while (current != nullptr && count < position) {
                prev = current;
                current = current->next;
                count++;
            }

            // 在插入位置插入新节点
            prev->next = newNode;
            newNode->next = current;
        }
    }

    // 删除指定节点
    void remove(int value) {
        // 如果链表为空，直接返回
        if (head == nullptr) {
            return;
        }

        // 如果要删除的节点是头节点
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // 查找要删除节点的前驱节点
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        // 如果找到要删除的节点
        if (current != nullptr) {
            prev->next = current->next;
            delete current;
        }
    }

    // 遍历链表并打印节点数据
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // 创建链表对象
    LinkedList list;

    // 在链表末尾插入节点
    list.insert(1);
    list.insert(2);
    list.insert(3);

    // 打印链表
    std::cout << "链表: ";
    list.printList();

    // 在指定位置插入节点
    list.insertAt(4, 2);

    // 打印链表
    std::cout << "链表: ";
    list.printList();

    // 删除节点
    list.remove(2);

    // 打印链表
    std::cout << "链表: ";
    list.printList();

    return 0;
}

```



## 循环链表

[传送门：循环链表(单循环、双循环)](https://blog.csdn.net/AII_IIA/article/details/134215172)

#### 循环链表的定义

```cpp
typedef struct CLNode
{
    ElemType data; 
    CLNode *next;
}*CircList;
```

#### 循环链表的初始化

```cpp
void InitList(CircList &L)
{
    L = new CLNode;   //在堆区创建一个初始结点
    L->next = L;      //将该结点指向自身
}
```

循环链表的基本操作和单链表基本上相同，唯一不同的是，由于循环链表的最后一个结点的next不再是空指针，而是指向头结点，因此，循环中的结束条件要发生变化。

### 循环单链表

单链表：

![在这里插入图片描述](https://img-blog.csdnimg.cn/9b77848111c64c9594df905a7866dd59.png)

循环单链表：

![在这里插入图片描述](https://img-blog.csdnimg.cn/b0f5d86fd176493a855922c863282f16.png)

- 循环单链表与普通单链表的主要区别在于，循环单链表的尾节点的指针不是指向 nullptr，而是指向头节点，形成一个闭环。这意味着，在循环单链表中，可以通过尾节点的指针重新回到头节点。

循环单链表可以具有以下特点和优势：

1. 尾节点的指针指向头节点，使得在遍历链表时不需要特别处理尾节点，方便实现循环遍历。
2. 可以更容易地进行环形操作，如判断链表是否形成环、寻找环的起始点等。
3. 循环单链表的插入和删除操作相对简单，因为不需要特别处理头部和尾部情况。
4. 在使用循环单链表时，我们需要额外关注以下几点：
5. 在插入和删除节点时，要确保更新指针的正确性，以避免死循环或链表中断。
6. 在循环单链表中遍历时要设置终止条件，防止进入无限循环。

#### 初始化一个循环单链表

```cpp
typedef struct LNode   		//定义单链表结合类型
{
	ElemType data;			//每个结点存放一个一个数据元素
	struct LNode *next; 	//指针指向下一个结点
}LNode, *LinkList;

//初始化一个循环单链表
bool InitList(LinkList &L)
{
	L =(LNode *) malloc(sizeof(LNode));	 //分配一个头结点
	if(L == NULL)  		//内存不足、分配失败
		return false;
	L->next = L;		//头结点next指向头结点
	return true;
}
```

#### 判断单链表是否为空

```cpp
//判断循环单链表是否为空, 检查头结点指针是否指向它自己就行,如下图所示
bool Empty(LinkList L)
{
	if(L->next == L)  //检查头结点指针是否指向它自己
		return true;
	else 
		return false;
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/918255adcfe647eeaef0aae2f29d8255.png)



### 循环双链表

> 循环双链表（Circular Doubly Linked List）是一种特殊类型的双向链表，其中最后一个节点的下一个指针指向头节点，头节点的前一个指针指向最后一个节点，形成一个循环。

> 循环双链表与普通双链表的主要区别在于，循环双链表既具有双向链表的前驱和后继关系，也具有循环遍历的能力。

双链表：表头结点的prior指向NULL; 表尾结点的next指向NULL。

![在这里插入图片描述](https://img-blog.csdnimg.cn/2b0245850a8d42b9ae51f5bb202d7a05.png)

循环双链表：表头结点的prior指向表尾结点； 表尾结点的next指向头结点。

![在这里插入图片描述](https://img-blog.csdnimg.cn/1edef12eb32c4c1bbe94fcc2b29fa2bf.png)

#### 循环双链表的特点和优势

1. 可以通过任意节点的前驱和后继指针方便地在双链表中进行插入和删除操作。
2. 最后一个节点的下一个指针指向头节点，使得在遍历链表时不需要特别处理尾节点，可以很方便地实现循环遍历。
3. 可以更容易地进行环形操作，如判断链表是否形成环、寻找环的起始点等。
4. 循环双链表的插入和删除操作相对简单，不需要特别处理头部和尾部情况。

#### 循环双链表的初始化

> 当我们在初始化一个双链表时，需要让头结点的前指针和后指针都指向头结点自己（而普通的双链表指向NULL），如下图所示：

![在这里插入图片描述](https://img-blog.csdnimg.cn/cb4d399eafc343a8ad1c6b9464fcaa04.png)

```c
//初始化空的循环双链表
bool InitDLinkList(DlinkList &L)
{
	L = (DNode*) malloc(sizeof(DNode));	//分配一个头结点
	if(L ==　NULL)		//内存不足，分配失败
		return false;
	L->prior = L;    //头结点的prior指向头结点
	L->next = L;   	//头结点的next指向头结点
	return true;	//初始化成功
}
12345678910
```

#### 判断循环链表是否为空

```c
typedef struct DNode     //创建循环双链表
{
	ElemType data;
	struct DNode *prior,*next;
}DNode, *DLinkList;

void testDLinkList()
{
	//初始化循环双链表
	DLinkList L;
	InitDLinkList(L);
	//.......后续代码.......
}
//判断循环链表是否为空
bool Empty(DLinkList L)
{
	if(L->next == L)
		return true;
	else
		return false;
}
```

#### 判断结点p是否为循环双链表的表尾结点

```c
bool isTail(DLinkList L, DNode  *p)
{
	if(p->next == L)
		return true;
	else
		return false;
}
```

#### 双链表的插入

```c
//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
	s->next = p->next;	//将结点*s插入到结点*p之后
	p->next->prior = s;   //如果
	s->prior = p;
	p->next = s;
}
12345678
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/a6f465b95f6245b0969f3be41976df88.png)

#### 双链表的删除

```c
//删除p的后继结点q
p->next = q->next;
q->next->prior = p;  //如果p没有后继结点，普通循环链表会出问题
free(q);
1234
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/301a1c869401465b84534beddb91700c.png)







