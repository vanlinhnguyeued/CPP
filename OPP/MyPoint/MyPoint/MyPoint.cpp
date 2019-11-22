// MyPoint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include"MyPoint.h"

using namespace std;
int main()
{	
	MyPoint* myPoint = new MyPoint();
	MyPoint* p = new MyPoint(20, 20);
	myPoint->SetX(10);
	myPoint->SetY(10);myPoint->Display();
	cout << "Distance between current point and p: " << myPoint->Distance(*p)<<endl;
	system("pause");
    return 0;
}



MyPoint::MyPoint() {};
MyPoint::MyPoint(int X, int Y) {
	this->mPosX = X;
	this->mPosY = Y;
}
void MyPoint::Display() {
	cout << "Point: (" << this->mPosX << "; " << this->mPosY << ")"<<endl;
}
void MyPoint::SetX(int mPosX) {
	this->mPosX = mPosX;
}
int MyPoint::GetX() {
	return mPosX;
}
void MyPoint::SetY(int mPosY) {
	this->mPosY = mPosY;
}
int MyPoint::GetY() {
	return mPosY;
}
float MyPoint::Distance(MyPoint p) {
	float distance;
	distance = sqrt(pow((p.GetX() - this->GetX()), 2) + pow((p.GetY() - this->GetY()), 2));
	return distance;
}
MyPoint::~MyPoint() {};
