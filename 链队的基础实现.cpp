#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int QElemType;
typedef int Status;

//定义一个队列结点
typedef struct QNode{
	QElemType data;//数据域 
	struct QNode *next;//指针域 
}QNode,*QueuePtr; 

//定义两个指针，用来更加方便的控制这个队列 
typedef struct LinkQueue{
	QueuePtr front;//队头指针，只能从它指向的结点出队，又作头指针 
	QueuePtr rear;//队尾指针 ，只能从这里入队 
}LinkQueue;

//链队的初始化 
Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front -> next = NULL;
	return OK;
}

//链队的销毁
Status DestroyQueue(LinkQueue &Q){
	//QueuePtr p;//定义一个指向结点的临时指针
	while(Q.front){
		Q.rear = Q.front -> next;
		delete Q.front;//free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
} 

//链队的入队
Status EnQueue(LinkQueue &Q,QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p -> data = e;
	p -> next = NULL;
	Q.rear -> next = p;
	Q.rear = p;
} 

//链队的出队
Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front == Q.rear)return ERROR;
	QueuePtr p;
	p = Q.front ->next;
	e = p -> data;
	Q.front -> next = p -> next;
	if(Q.rear == p) Q.rear = Q.front;//如果出队后队为空 
	free(p);
} 

//取队头元素赋值给e
Status GetHead(LinkQueue Q,QElemType &e){
	if(Q.front == Q.rear)return ERROR;
	e = Q.front -> next ->data;
	return OK;
} 

int main(){
	LinkQueue Q;
	InitQueue(Q);
	int n; 
	//入队1，2，3，4，5
	for(int i = 1;i <= 5;i++){
		EnQueue(Q,i);
	} 
	//出队2次
	for(int i = 0;i < 2;i++){
		int n = 0;
		DeQueue(Q,n);
		printf("%d\n",n);
	}
	//此时队头元素为
	
	GetHead(Q,n);
	printf("此时队头元素为%d",n);
	return 0;
}
