#pragma once
#include "Espina.h"
#include "Player.h"
#include "Gravedad.h"
#include "Trampolin.h"
#include "Tile.h"
#include "Nave.h"
#include "Portal.h"
#include <vector>
#include <iostream>

using namespace std;
class GameManager
{
	double TiempoReal;
	Player* Jugador;
	vector<Figura*> Vec;
	float Progreso;
	int N_Saltos;
	int N_Intentos;
	bool Complete;
public:
	//Constructores
	GameManager();
	~GameManager();

	//Metodos de Acceso
	Player* GetPlayer();
	double GetTemp();
	int GetN_Saltos();
	void Temp(double t);
	void SetTemp(double t);

	//Metodos Objetos
	void CheckColisions();
	void MostrarObjetos(Graphics^ G, Bitmap^ imgNave, Bitmap^ imgJugador, Bitmap^ imgTile, Bitmap^ imgPortal1, Bitmap^ imgPortal2, Bitmap^imgEspina, Bitmap^ imgTrampolin);
	void MoverObjetos();
	void Agregar(Figura*Nuevo);
	void Update(Graphics^ G);
	void AumentarSalto();
	//void Reset();
	//void CalcularPuntaje();
	//void Ranking();

	void Transformar();
};

