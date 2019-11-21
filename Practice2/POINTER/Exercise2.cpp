#include <iostream>
using namespace std;
void main()
{
int a[4] = {1, 2, 3, 4};
int *p = a;
int *p2 = new int;
delete p;
delete[] a; // Xóa mảng thì thêm []
delete p2;
p = NULL; //sau khi giải phóng vùng nhớ chúng ta nên gán null tránh sữ dụng tiếp vùng nhớ đã được giải phóng mà p vẫn còn trỏ tới.
p2 = NULL;
// để giải phóng mảng a[] sau khi xóa thì có thể gán các phần từ bằng null
for(int i = 0; i <4; i++){
    a[i]=NULL;
}
}