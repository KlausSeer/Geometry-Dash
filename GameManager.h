#pragma once
#include "Espina.h"
#include "Player.h"
#include "Gravedad.h"
#include "Trampolin.h"
#include "Tile.h"
#include <vector>
#include <iostream>

using namespace std;
class GameManager
{
	double TiempoReal;
	Player* Jugador;
	vector<Figura*> Vec;
public:
	Player* GetPlayer();
	void CheckColisions();
	double GetTemp();
	void Temp(double t);
	void SetTemp(double t);
	void MostrarObjetos(Graphics^G);
	void MoverObjetos();
	void Agregar(Figura*Nuevo);
	void Update(Graphics^ G);
	GameManager();
	~GameManager();
};

