#pragma once
#include "Participante.h"
#include "Espina.h"
#include "Trampolin.h"
#include "Gravedad.h"
#include "Portal.h"
#include "Tile.h"
#include "Nave.h"
#include "Cuadrado.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class GameManager
{
	string file_nameH;
	string file_name;
	double TiempoReal;
	Player* Jugador;
	vector<Figura*> Vec;
	float Progreso;
	int N_Saltos;
	int N_Intentos;
	bool Complete;
	vector<Participante*> Participantes;
public:
	GameManager();
	~GameManager();



	//Metodos de Acceso
	Player* GetPlayer();
	double GetTemp();
	int GetN_Saltos();
	void Temp(double t);
	void SetTemp(double t);

	void LeerHighscores();
	void RegistrarPuntuacion();
	void AumentarSalto();
	void Inicializar();
	void CheckColisions();
	void MostrarObjetos(Graphics^ G, Bitmap^ imgNave, Bitmap^ imgJugador, Bitmap^ imgTile, Bitmap^ imgPortal1, Bitmap^ imgPortal2, Bitmap^imgEspina, Bitmap^ imgTrampolin);
	void MoverObjetos();
	void Update(Graphics^ G);
	void Transformar();
};

