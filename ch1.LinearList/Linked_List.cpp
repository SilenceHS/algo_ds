#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void show(Node * Head);
int get(Node * Head,int position,int *e);
int insert(Node * Head,int position, int e);
int deleteNode(Node * Head,int position);
int main()
{
    Node * Head=(Node*)malloc(sizeof(Node));
    Head->data=0;
    Node * pre=Head;
    for (int i=0;i<10;i++)
    {
        Node * node=(Node*)malloc(sizeof(Node));
        node->next=NULL;
        node->data=i*2;
        pre->next=node;
        pre=node;
        Head->data++;
    }
    // int *e=(int *)malloc(sizeof(int));
    // get(Head,3,e);
    // cout<<*e<<endl;
    insert(Head,3,50);
    deleteNode(Head,5);
    show(Head);
}
void show(Node * Head){
    Node * node=Head->next;
    for (int i=0;i<Head->data;i++){
        cout<<node->data<<endl;
        node=node->next;
    }
}
int get(Node * Head,int position,int *e)
{
    if(position<1||position>Head->data)
        return 1;
    Node * node =Head;
    for (int i=0;i<position;i++)
        node=node->next;
    *e=node->data;
    return 0;
}
int insert(Node * Head,int position, int e)
{
    if(position<1||position>Head->data+1)
        return 1;
    Node * node=(Node *)malloc(sizeof(Node));
    node->data=e;
    Node * pre=Head;
    for(int i=1;i<position;i++)
        pre=pre->next;
    node->next=pre->next;
    pre->next=node;
    Head->data++;
    return 0;
}
int deleteNode(Node * Head,int position)
{
    if(position<1||position>Head->data)
        return 1;
    Node * pre =Head;
    for(int i=1;i<position;i++)
        pre=pre->next;
    Node * freeNode=pre->next;
    pre->next=pre->next->next;
    free(freeNode);
    Head->data--;
    return 0;
}