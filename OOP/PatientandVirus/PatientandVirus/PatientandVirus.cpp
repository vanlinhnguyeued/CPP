// PatientAndVirus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patient.h"
#include <stdio.h>
#include <cstdlib>
#include<iostream>

int main()
{
	Patient p;
	char t = 0;
	while (p.GetState() == 1)
	{
		cout<< "Take Medicine (0 = NO, 1 = YES)";
		cin >> t;
		if (t == '1')
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(medicine_resistance);
		}
	}
	return 0;
}
