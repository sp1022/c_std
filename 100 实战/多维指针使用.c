#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};

void insertAtHead1(struct Node *head,int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void insertAtHead(struct Node **head,int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node=node->next;
    }
    printf("NULL\n");
}
int main()
{
  struct  Node *node=NULL;
  //insertAtHead1(node,100);
  //insertAtHead1(node,200);
  /*
  insertAtHead 函数接收的是 struct Node *head，即链表头指针的值的副本。
  在函数内部，虽然 head 被修改了，但它只是在 insertAtHead 的作用域内修改，
  并没有改变 main 函数中的 head 变量。因此，链表插入操作没有生效
  */
  //insertAtHead1(node,300);
  //printList(node); //预计输出为300->200->100->Null，但是实际输出为Null

  insertAtHead(&node,100);
  insertAtHead(&node,200);
  insertAtHead(&node,300);
  printList(node);
}
