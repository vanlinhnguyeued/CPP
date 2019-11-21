#include <iostream>
using namespace std;
void main()
{
int a[4] = {1, 2, 3, 4};
int *p = &a;
int *p2 = new int;
delete p;
// delete[] a; k cần phải xóa vì k phải con trỏ
delete p2;
p = NULL; //sau khi giải phóng vùng nhớ chúng ta nên gán null tránh sữ dụng tiếp vùng nhớ đã được giải phóng mà p vẫn còn trỏ tới.
p2 = NULL;
}