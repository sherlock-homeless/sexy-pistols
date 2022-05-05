#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

 static void CopyToNode(Item item,Node*pn);
 static void CopyToItem(Node*pn,Item*pi);
 
 void InitializeQueue(Queue*pq){
 	pq->front=pq->rear=NULL;
 	pq->items=0;
 }
 bool QueueIsFull(const Queue*pq){
 	return pq->items==MAXQUEUE;
 }
  bool QueueIsEmpty(const Queue*pq){
 	return pq->items==0;
 }
 int QueueItemCount(const Queue*pq){
 	return pq->items;
 }
 bool EnQueue(Item item,Queue*pq){
 	Node*pnew;
 	pnew=(Node*)(malloc(sizeof(Node)));
 	if(pnew==NULL){
 		printf("problem memory allocating");
 		exit(1);
 		 }
 	pnew->next=NULL;
	CopyToNode(item,pnew); 
	if(QueueIsEmpty( pq)){
		pq->front=pnew;
	} 
	else{
		pq->rear=pnew;
	}
	pq->rear->next=pnew;
	pq->items++;
	return true; 
 }
 bool DeQueue(Item*pitem,Queue*pq){
 	Node*pt;
 	if(QueueIsEmpty( pq))
 	{
 		return false;
	 }
	 CopyToItem(pq->front,pitem);
	 pt=pq->front;
	 free(pt);
	 pq->front=pq->front->next;
	 pq->items--;
	 if(pq->items==0){
	 	pq->rear=NULL;
	 }
 	return true;
 }
 void EmptyTheQueue(Queue*pq){
 	Node*temp; 
 	while(pq->items!=0){
 		temp=pq->front;
 		free(temp);
 		pq->front=pq->front->next;
 		pq->items--;
	 }
 	
 }
 static void CopyToItem(Node*pn,Item*pi){
 	*pi=pn->item;
 }
 static void CopyToNode(Item item,Node*pn){
 	pn->item=item;
 }
