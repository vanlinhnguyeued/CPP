#include "Virus.h"
#include <string>
#pragma once
using namespace std;
class DengueVirus : public Virus
{
private:
	char* m_protein;
public:
	DengueVirus();
	~DengueVirus();
	void setM_Protein(char* m_protein);
	char* getM_Protein();
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();

};