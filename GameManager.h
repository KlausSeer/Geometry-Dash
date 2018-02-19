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
#include <algorithm>

using namespace std;

class GameManager
{
	int Fin;
	string file_nameH;
	string file_name;
	double TiempoReal;
	Player* Jugador;
	vector<Figura*> Vec;
	float Progreso;
	int N_Saltos;
	int N_Intentos;
	bool Complete;
	Participante*Actual;
	vector<Participante*> Participantes;
public:
	GameManager();
	GameManager(int pProgreso,int pIntentos, int pSaltos);
	~GameManager();
	
	//Metodos de Acceso
	Player* GetPlayer();
	double GetTemp();
	int GetN_Saltos();
	int GetN_Intentos();
	int GetN_Progreso();
	void Temp(double t);
	void SetTemp(double t);

	void SetIntentos(int In);
	void LeerHighscores();
	void RegistrarPuntuacion(string Nombre);
	void AumentarSalto();
	void Inicializar();
	void CheckColisions();
	void MostrarObjetos(Graphics^ G, Bitmap^ imgNave, Bitmap^ imgJugador, Bitmap^ imgTile, Bitmap^ imgPortal1, Bitmap^ imgPortal2, Bitmap^imgEspina, Bitmap^ imgTrampolin);
	void MoverObjetos();
	void Update(Graphics^ G);
	void Transformar();
	void ParActual();
	void CalcularProgreso();
	void ShowRanking(System::Drawing::Graphics ^gr);
};

