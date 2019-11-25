#include "stdafx.h"
#include "DengueVirus.h"
#include<string>

using namespace std;
DengueVirus::DengueVirus()
{
	InitResistance();
	DoBorn();
}

DengueVirus::DengueVirus(const DengueVirus& otherVR) {
	this->m_protein = otherVR.m_protein;

}
DengueVirus::~DengueVirus()
{
	DoDie();
}
void DengueVirus::setM_Protein(char* m_protein) {
	this->m_protein = m_protein;
}
char* DengueVirus::getM_Protein() {
	return m_protein;
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	int rannum = 1 + (rand() % (int)(3 - 1 + 1));
	if (rannum == 1)
	{
		char str[4] = "NS3";
		char* protein = new char[strlen(str) + 1];
		strcpy_s(protein, sizeof(str), str);
		this->setM_Protein(protein);

	}
	if (rannum == 2)
	{
		char str[4]="NS5"; 
		char* protein = new char[strlen(str)+1];
		strcpy_s(protein, sizeof(str), str);
		this->setM_Protein(protein);
	}
	if (rannum == 3)
	{
		char str[4] = "E";
		char* protein = new char[strlen(str) + 1];
		strcpy_s(protein, sizeof(str), str);
		this->setM_Protein(protein);
	}
}

std::list<Virus*> DengueVirus::DoClone()
{
	DengueVirus *otherVR1 = new DengueVirus(*this);
	DengueVirus *otherVR2 = new DengueVirus(*this);
	list<Virus*> listVR;


	listVR.push_back(otherVR1);
	listVR.push_back(otherVR2);


	return listVR;
}

void DengueVirus::DoDie()
{
	this->setM_Resistance(NULL);
}

void DengueVirus::InitResistance()
{
	if (this->getM_Protein() == "NS3")
	{
		this->setM_Resistance(1 + (rand() % (int)(10 - 1 + 1)));
	}
	if (this->getM_Protein() == "NS5")
	{
		this->setM_Resistance (11 + (rand() % (int)(20 - 11 + 1)));
	}
	if (this->getM_Protein() == "E")
	{
		this->setM_Resistance(21 + (rand() % (int)(30 - 21 + 1)));
	}
}