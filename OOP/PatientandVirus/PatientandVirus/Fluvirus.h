#pragma once
#include "Virus.h"
#include <list>
using namespace std;

class Fluvirus : public Virus
{
private:
	int m_color;
public:
	Fluvirus();
	~Fluvirus();
	Fluvirus(const Fluvirus& otherVR);
	void setColor(int m_color);
	int getColor();

	void DoBorn();
	list<Virus*> Fluvirus::DoClone();
	void DoDie();
	void InitResistance();


};