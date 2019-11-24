#include "stdafx.h"
#include "Virus.h"
#include<list>
#include <fstream>
#include<string>

using namespace std;

Virus::Virus()
{

}


Virus::~Virus()
{

}
void Virus::setM_DNA(char*m_dna){
	this->m_dna = m_dna;
}
char* Virus::getM_DNA(){
	return m_dna;
}
void Virus::setM_Resistance(int m_resistance){
	this->m_resistance = m_resistance;
}
int Virus::getM_Resistance(){
	return m_resistance;
}
void Virus::LoadADNInformation() {
	ifstream inputFile("../ATGX.bin");
	string contentFile;
	getline(inputFile, contentFile);
	m_dna = new char[contentFile.size() + 1];
	copy(contentFile.begin(), contentFile.end(), m_dna);
	m_dna[contentFile.size()] = '\0';

}
int Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance = m_resistance - medicine_resistance;
	if (m_resistance <= 0)
		return 1;
	else
		return 0;
}
list<Virus*> Virus::DoClone()
{
	list<Virus*> listVR;
	return listVR;
}
