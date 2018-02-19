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

	struct ParticipantesCompare {

		bool operator() (const Participante *a, const Participante *b) {

			if (a->Porcentaje < b->Porcentaje)
				return true;
			else if (a->Porcentaje > b->Porcentaje)
				return false;

			if (a->Intentos < b->Intentos)
				return true;
			else if (a->Intentos < b->Intentos)
				return false;

			if (a->Saltos < b->Saltos)
				return true;
			
			return false;
				/*(a->Porcentaje < b->Porcentaje) ||
				((a->Porcentaje == b->Porcentaje) && (a->Intentos < b->Intentos)) ||
				((a->Porcentaje == b->Porcentaje) && (a->Intentos == b->Intentos) && (a->Saltos< b->Saltos));*/
		}

	};

};

