#include "stdafx.h"
#include "DengueVirus.h"
#include<string>


using namespace std;
DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
	
}

DengueVirus::DengueVirus(const DengueVirus& otherVR) : Virus(otherVR) {
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
	int rannum = rand() % 3 + 1;
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
	
	if (strcmp(m_protein, "NS3")==0)
	{
		this->setM_Resistance(rand()%10 +1);
	}
	if (strcmp(m_protein, "NS5") == 0)
	{
		this->setM_Resistance (rand()%20 + 11);
	}
	if (strcmp(m_protein, "E") == 0)
	{
		this->setM_Resistance(rand()%30 + 21);
	}
}