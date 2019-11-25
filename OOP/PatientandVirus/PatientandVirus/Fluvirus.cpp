#include "stdafx.h"
#include "Fluvirus.h"

using namespace std;

Fluvirus::Fluvirus()
{
	this->DoBorn();
	this->InitResistance();
}

Fluvirus::~Fluvirus()
{
	this->DoDie();
}
void Fluvirus::setColor(int m_color) {
	this->m_color = m_color;
}
int Fluvirus::getColor() {
	return m_color;
}

void Fluvirus::DoBorn()
{
	LoadADNInformation();
	if (rand() % 2 == 0)
		this->setColor(1);
	else
		this->setColor(2);
}

list<Virus*> Fluvirus::DoClone()
{
	Fluvirus *otherVR = new Fluvirus;
	list<Virus*> listVR;

	otherVR->setColor(this->getColor());
	otherVR->setM_DNA(this->getM_DAN());
	otherVR->setM_Resistance(this->getM_Resistance());

	listVR.push_back(otherVR);

	return listVR;
}

void Fluvirus::DoDie()
{
	this->setColor(0);
	this->setM_Resistance(0);
}

void Fluvirus::InitResistance()
{
	if (this->getColor()==1)
	{
		this->setM_Resistance(10 + (rand() % (int)(20 - 10 + 1)));
	}
	else
	{
		this->setM_Resistance(10 + (rand() % (int)(15 - 10 + 1)));
	}
}