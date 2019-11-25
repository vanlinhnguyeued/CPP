#include "stdafx.h"
#include "Virus.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
Virus::Virus()
{
	m_dna = nullptr;
}
Virus::Virus(const Virus& otherVR) {
	this->m_dna = otherVR.m_dna;
	this->m_resistance = otherVR.m_resistance;
}

Virus::~Virus()
{
	if (m_dna)
	{
		delete[] m_dna;
		m_dna = NULL;
	}
}
void Virus::setM_DNA(char* m_dna) {
	this->m_dna = m_dna;
}
char* Virus::getM_DAN() {
	return m_dna;
}
void Virus::setM_Resistance(int m_resistance) {
	this->m_resistance = m_resistance;

}
int Virus::getM_Resistance() {
	return m_resistance;
}

void Virus::LoadADNInformation()
{
	ifstream inputFile("../ATGX.bin");
	string contentFile;

	getline(inputFile, contentFile);

	this->m_dna = new char[contentFile.size() + 1];
	for (int i = 0; i < contentFile.size(); i++)
		this->m_dna[i] = contentFile[i];
	this->m_dna[contentFile.size()] = '\0';
}

int Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance = m_resistance - medicine_resistance;
	if (m_resistance <= 0)
		return 1;
	else
		return 0;
}
