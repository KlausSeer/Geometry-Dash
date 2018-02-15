#pragma once
#include <string>
#include <iostream>

using namespace std;
class Participante
{
	string Nombre;
	int Saltos;
	int Intentos;
	int Porcentaje;
	bool Completo;
public:
	Participante();
	~Participante();

	string GetNombre();
	int GetSaltos();
	int GetIntentos();
	int GetPorcentaje();
	bool GetCompleto();

	void SetNombre(string Nombre);
	void SetSaltos(int Saltos);
	void SetIntentos(int Intentos);
	void SetPorcentaje(int Porcentaje);
	void SetCompleto(bool Completo);
};

