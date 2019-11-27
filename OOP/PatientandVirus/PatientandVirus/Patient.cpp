#include "stdafx.h"
#include "Patient.h"
#include "Fluvirus.h"
#include "DengueVirus.h"
#include <algorithm>
#include<iostream>
#include<vld.h>
using namespace std;
Patient::Patient()
{
	InitResistance();
	DoStart();
}

Patient::~Patient()
{
	DoDie();
}

void Patient::setState(int m_state) {
	this->m_state = m_state;
}
int Patient::GetState()
{
	return m_state;
}
void Patient::InitResistance()
{
	this->m_resistance = 1000 + (rand() % (int)(9000 - 1000 + 1));
}

void Patient::DoStart()
{
	this->m_state = 1;
	int numvirus = rand() % 20 + 10;
	cout << "Number virus: " << numvirus << endl;
	int demDE = 0, demFLU = 0;
	for (int i = 0; i < numvirus; i++)
	{
		int k = 0;
		if (k % 2 == 0)
		{
			demDE++;
			Virus *deng = new DengueVirus;
			this->m_virusList.push_back(deng);
			deng = NULL;
		}
		else
		{
			demFLU++;
			Virus *flu = new Fluvirus;
			this->m_virusList.push_back(flu);
			flu = NULL;
		}
	}
	cout << "Vius DE: " << demDE<<endl;
	cout << "virus FLU: " << demFLU << endl;
}

void Patient::TakeMedicine(int medicine_resistance)
{	
	
	cout << "Medicine resistance: " <<medicine_resistance<< endl;
	for (list<Virus*>::iterator it = m_virusList.begin(); it != m_virusList.end();)
	{
		int res = (*it)->ReduceResistance(medicine_resistance);
		if (res <= 0)
		{
			Virus *v = *it;
			it = m_virusList.erase(it);
			delete v;
		}
		else
		{
			
			list<Virus*> tempLst = (*it)->DoClone();
			list<Virus*>::iterator it2;
			for (it2 = tempLst.begin(); it2 != tempLst.end(); it2++) {
				this->m_virusList.push_back(*it2);
				*it2 = NULL;
			}

			it++;
		}
	}
	



	cout << "Number Virus after taking the pill: " << m_virusList.size()<<endl;
	if (m_virusList.size() == 0) {
		cout << "The patient has healed!" << endl;
	}
	
}

void Patient::DoDie()
{
	m_state = 0;
	list<Virus*>::iterator it = m_virusList.begin();
	while (it != m_virusList.end()) {
		delete *it;
		it++;         
	}
}

