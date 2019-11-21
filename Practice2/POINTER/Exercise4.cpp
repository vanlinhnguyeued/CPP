#include <iostream>
using namespace std;

int main(){
    int iVar = 10;
    int *p1 = &iVar;
    int **p2 = &p1;
    cout<<*p1<<endl; //giá trị của ô nhớ mà p1 trỏ tới
    cout<<*p2<<endl; //== địa chỉ của iVar;
    cout<<*(*p2)<<endl;//==*p1==*(&iVar) == với giá trị của iVar 
}