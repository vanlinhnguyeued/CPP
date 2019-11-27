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
Fluvirus::Fluvirus(const Fluvirus& otherVR) : Virus(otherVR)
{
	this->m_color = otherVR.m_color;
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
	
	Fluvirus *otherVR = new Fluvirus(*this);
	list<Virus*> listVR;
	listVR.push_back(otherVR);
	//delete otherVR;
	otherVR = NULL;
	return listVR;
}

void Fluvirus::DoDie()
{
	this->setColor(0);
}

void Fluvirus::InitResistance()
{
	
	if (this->getColor()==1)
	{
		this->setM_Resistance(rand() % 20 + 10);
	}
	else
	{
		this->setM_Resistance(rand() % 15 + 10);
	}
}