#include "Participante.h"

string Participante::GetNombre()
{
	return Nombre;
}
int Participante::GetSaltos()
{
	return Saltos;
}
int Participante::GetIntentos()
{
	return Intentos;
}
int Participante::GetPorcentaje()
{
	return Porcentaje;
}
bool Participante::GetCompleto()
{
	return Completo;
}

Participante::Participante()
{
}


Participante::~Participante()
{
}

void Participante::SetNombre(string Nombre)
{
	this->Nombre = Nombre;
}
void Participante::SetSaltos(int Saltos)
{
	this->Saltos = Saltos;
}
void Participante::SetIntentos(int Intentos)
{
	this->Intentos = Intentos;
}
void Participante::SetPorcentaje(int Porcentaje)
{
	this->Porcentaje = Porcentaje;
}
void Participante::SetCompleto(bool Completo)
{
	this->Completo = Completo;
}