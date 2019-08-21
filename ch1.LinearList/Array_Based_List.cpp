#include <iostream>
using namespace std;
#define ARRAYSIZE 7//why 8 is wrong
struct List
{
    int a[ARRAYSIZE];
    int Length;
};
int get(List *L,int Position,int *e);
int find(List *L,int e);
int deleteEle(List *L,int Position,int *e);
int insertEle(List *L,int Position,int e);
void showList(List *L);
int main(){
    List *L;
    //List *L=(List*)malloc(sizeof(List));
    for (int i=0;i<3;i++)
    {
        L->a[i]=i*2;
        L->Length=i+1;
    }
    for (int ii=0;ii<10;ii++)
    {
        cout<<ii<<endl;
    }
    showList(L);
    int a;
    get(L,3,&a);
    cout<<"find 3th, a="<<a<<endl;
    cout<<"find ele=4, position="<<find(L,4)<<endl;
    deleteEle(L,2,&a);
    cout<<"delete 5th, a="<<a<<endl;
    showList(L);
    insertEle(L,3,80);
    showList(L);
}
void showList(List *L)
{
    for (int i=0;i<L->Length;i++)
    { cout<<L->a[i]<<endl;}
    return;

}
int get(List *L,int Position,int *e)
{
    if(Position>L->Length || Position<1)
        return 1;
    *e=L->a[Position-1];
    return 0;
}
int find(List *L,int e)
{
    for (int i=0; i<L->Length;i++)
    {
        if(e==L->a[i])
            return i+1;
    }
    return 0;
}
int deleteEle(List *L,int Position,int *e)
{
    if(Position>L->Length||Position<1)
        return 1;

    *e=L->a[Position-1];
    for(int i=Position-1;i<L->Length-1;i++)
    {
        L->a[i]=L->a[i+1];
    }
    L->Length--;
    return 0;
}
int insertEle(List *L,int Position,int e)
{
    if(Position<1||L->Length>=ARRAYSIZE||Position>L->Length+1)
        return 1;
    for (int i=L->Length;i>Position;i--)
        L->a[i]=L->a[i-1];
    L->a[Position-1]=e;
    L->Length++;
    return 0;
}