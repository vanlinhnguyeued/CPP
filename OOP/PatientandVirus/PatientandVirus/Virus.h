#include <cstdlib>
#include <list>

#pragma once
using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(const Virus& other);
	virtual ~Virus();

	void setM_DNA(char *m_dna);
	char* getM_DAN();
	void setM_Resistance(int m_resistance);
	int getM_Resistance();

	void LoadADNInformation();
	void ReduceResistance(int medicie_resistance);

	virtual void DoBorn() = 0;
	virtual list<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;


};
