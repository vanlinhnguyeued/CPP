#include <iostream>
using namespace std;

int main(){
    int iVar = 10;
    int *p1 = &iVar;
    int **p2 = &p1;
    cout<<*p1<<endl; //==10 giá trị của ô nhớ mà p1 trỏ tới 
    cout<<*p2<<endl; //== 0x100 địa chỉ của iVar;
    cout<<*(*p2)<<endl;//==10==*p1==*(&iVar) == với giá trị của iVar 
}