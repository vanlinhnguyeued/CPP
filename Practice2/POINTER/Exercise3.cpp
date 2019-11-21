//câu 1: dùng delete để tránh lãng phí tài nguyên và tránh gây xung đột cho các lần tiếp theo
//câu 2: dùng delete sau khi chúng ta dừng làm việc với con trỏ, lệnh delete chỉ thực thiện khi con trỏ làm việc với vùng heap;
//câu 3: delete dùng cho 1 con trỏ, còn delete[] thì dùng để xóa mãng được trỏ bởi các con trỏ. cần phải tuân thủ để tránh hành vi không xác định


#include<iostream>
using namespace std;


int main(){
    int ptr_m = new int; // yêu cầu cấp phát bộ nhớ cho con trỏ
    int ptr_n = new int[5];
    *ptr_m = 123;
    
    delete ptr_m;
    ptr_m = NULL;

    cout<<ptr_m<<endl;
    cout<<&ptr_m<<endl;

    *ptr_n[5] = {1;2;3;4;5};
    for(int i = 0; i < 5; i++){
        cout<<ptr_n[i];
    }
    


    return 0;
}