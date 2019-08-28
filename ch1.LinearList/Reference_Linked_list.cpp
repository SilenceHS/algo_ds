#include <iostream>
using namespace std;
struct LinkList{
    int data;
    LinkList * next;
};
void show(LinkList* L);
void delete2thNode(LinkList* &L);
int main(){
    LinkList* L= (LinkList*)malloc(sizeof(LinkList));
    LinkList* pre=L;
    for(int i=0;i<4;i++)
    {
        LinkList* node= (LinkList*)malloc(sizeof(LinkList));
        node->next=NULL;
        node->data=i*2;
        pre->next=node;
        pre=pre->next;
    }
    cout<<L<<endl;
    cout<<L->next<<endl;
    show(L);
    
    delete2thNode(L->next);
    show(L);
}
void show(LinkList* L)
{
    LinkList * node=L->next;
    while(node)
    {
        cout<<node->data<<endl;
        node=node->next;
    }
    cout<<"......"<<endl;
}
void delete2thNode(LinkList* &L)
{
    cout<<"**"<<L<<endl;
    cout<<L->data<<endl<<endl;
    L=L->next;
}
