#pragma once
#include<list>

using namespace std;
class Virus
{
private: 
	char* m_dna;
	int m_resistance;
public:
	Virus();
	~Virus();

	void setM_DNA(char*);
	char* getM_DNA();
	void setM_Resistance(int);
	int getM_Resistance();

	void LoadADNInformation();
	int ReduceResistance(int);

	virtual void DoBorn()=0;
	virtual list<Virus*> DoClone()=0;
	virtual void DoDie()=0;
	virtual void InitResistane()=0;

};

