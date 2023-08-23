#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int QElemType;
typedef int Status;

//����һ�����н��
typedef struct QNode{
	QElemType data;//������ 
	struct QNode *next;//ָ���� 
}QNode,*QueuePtr; 

//��������ָ�룬�������ӷ���Ŀ���������� 
typedef struct LinkQueue{
	QueuePtr front;//��ͷָ�룬ֻ�ܴ���ָ��Ľ����ӣ�����ͷָ�� 
	QueuePtr rear;//��βָ�� ��ֻ�ܴ�������� 
}LinkQueue;

//���ӵĳ�ʼ�� 
Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front -> next = NULL;
	return OK;
}

//���ӵ�����
Status DestroyQueue(LinkQueue &Q){
	//QueuePtr p;//����һ��ָ�������ʱָ��
	while(Q.front){
		Q.rear = Q.front -> next;
		delete Q.front;//free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
} 

//���ӵ����
Status EnQueue(LinkQueue &Q,QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p -> data = e;
	p -> next = NULL;
	Q.rear -> next = p;
	Q.rear = p;
} 

//���ӵĳ���
Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front == Q.rear)return ERROR;
	QueuePtr p;
	p = Q.front ->next;
	e = p -> data;
	Q.front -> next = p -> next;
	if(Q.rear == p) Q.rear = Q.front;//������Ӻ��Ϊ�� 
	free(p);
} 

//ȡ��ͷԪ�ظ�ֵ��e
Status GetHead(LinkQueue Q,QElemType &e){
	if(Q.front == Q.rear)return ERROR;
	e = Q.front -> next ->data;
	return OK;
} 

int main(){
	LinkQueue Q;
	InitQueue(Q);
	int n; 
	//���1��2��3��4��5
	for(int i = 1;i <= 5;i++){
		EnQueue(Q,i);
	} 
	//����2��
	for(int i = 0;i < 2;i++){
		int n = 0;
		DeQueue(Q,n);
		printf("%d\n",n);
	}
	//��ʱ��ͷԪ��Ϊ
	
	GetHead(Q,n);
	printf("��ʱ��ͷԪ��Ϊ%d",n);
	return 0;
}
