#include "stdafx.h"
#include "Patient.h"
#include "Fluvirus.h"
#include "DengueVirus.h"
#include <algorithm>

using namespace std;
Patient::Patient()
{
	InitResistance();
	DoStart();
}

Patient::~Patient()
{
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

	int numvirus = 10 + (rand() % (int)(20 - 10 + 1));
	for (int i = 0; i < numvirus; i++)
	{
		if (i % 2 == 0)
		{
			Virus *deng = new DengueVirus;
			this->m_virusList.push_back(deng);
		}
		else
		{
			Virus *flu = new Fluvirus;
			this->m_virusList.push_back(flu);
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	list<Virus*> toAdded;
	for (list<Virus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		if ((*it)->getM_Resistance() <= 0)
		{
			Virus* virus = *it;
			*it = nullptr;

			delete virus;
			virus = nullptr;
		}
		else
		{
			list<Virus*> tempLst = (*it)->DoClone();
			for (auto it2 : tempLst)
			{
				toAdded.push_back(it2);
			}
		}
	}

	m_virusList.remove(nullptr);

	for (auto it : toAdded)
	{
		m_virusList.push_back(it);
	}
}

void Patient::DoDie()
{
	m_state = 0;
	this->m_virusList.clear();
}

