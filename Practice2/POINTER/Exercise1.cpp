#include <iostream>
using namespace std;

typedef int *IntPtrType; //Định nghĩa cho *IntPtrType thành kiểu dữ liệu: int

int  main(){
	IntPtrType ptr_a, ptr_b, *ptr_c; //Khai báo  con trỏ ptr_a, ptr_b và con trỏ trỏ tới con trỏ ptr_c

	ptr_a = new int;//Cấp phát ô nhớ cho ptr_a
	*ptr_a = 3; //Gán 3 cho ô nhớ mà ptr_a đang trỏ tới
	ptr_b = ptr_a; //Gán địa chỉ ô nhớ của con trỏ ptr_a đang trỏ tới chocon trỏ ptr_b
	cout << *ptr_a << " " << *ptr_b << "\n"; //In ra giá trị mà con trỏ ptr_a và ptr_b đang trỏ tới
											// Vì ptr_a và ptr_b cùng trỏ tới 1 địa chỉ nên giá trị bằng nhau và bằng 3 
	ptr_b = new int; //Cấp phát ô nhớ mới cho ptr_b
	*ptr_b = 9; //Gán 9 cho ô nhớ ptr_b vừa mới cấp phát
	cout << *ptr_a << " " << *ptr_b << "\n"; //Vì ptr_a đang trỏ tới ô nhớ cũ nên giá trị của nó vẫn bằng 3 nên in ra 3
											//Còn ptr_b vừa trỏ tới ô nhớ có giá trị 9 nên in ra 9	

	*ptr_b = *ptr_a; //Gán giá trị của ô nhớ mà ptr_a đang trỏ cho ôn nhớ của ptr_b đang trỏ tới và bằng 3
	cout << *ptr_a << " " << *ptr_b << "\n"; //In ra giá trị hai ô nhớ mà hai con trỏ đang trỏ tới

	delete ptr_a; //Giải phóng con trỏ ptr_a khỏi ô nhớ được cấp phát trước đó
	ptr_a = ptr_b; //Con trỏ ptr_a trỏ tới ô nhớ mà con trỏ ptr_b đang trỏ
	cout << *ptr_a << " " << *ptr_b << "\n"; //ô nhớ mà hai con trỏ đang trỏ tới có giá trị bằng 3 nên in ra 3  

	ptr_c = &ptr_a; //Con trỏ ptr_c trỏ tới con trỏ ptr_a nên giá trị ô nhớ của ptr_c là địa chỉ ô nhớ mà ptr_a đang trỏ tới
	cout << *ptr_c << " " << **ptr_c << "\n"; //in ra giá trị ô nhớ của ptr_c và giá trị ô nhớ mà sau khi trỏ tới giá trị ô nhớ ptr_c tức là giá trị ô nhó mà ptr_a đang trỏ tới 
	delete ptr_a; //giải phóng ptr_a ra khỏi ô nhớ được cấp trước đó
	ptr_a = NULL; //
	system("pause");//
	return 0;
}