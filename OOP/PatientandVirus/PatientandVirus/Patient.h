#include <list>
#include "Virus.h"
#include <cstdlib>
#pragma once
using namespace std;
class Patient
{
private:
	int m_resistance;
	int m_state;
	list<Virus*> m_virusList;

public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
	void setState(int m_state);
	int GetState();

};