#include "GameManager.h"



Player * GameManager::GetPlayer()
{
	return Jugador;
}

void GameManager::CheckColisions()
{
	for (unsigned int i = 0; i < Vec.size(); i++)
	{
		Jugador->CheckColision(Vec[i], &TiempoReal);
	}
}

double GameManager::GetTemp()
{
	return TiempoReal;
}

void GameManager::Temp(double t)
{
	TiempoReal += t;
}

void GameManager::SetTemp(double t)
{
	TiempoReal = t;
}

void GameManager::MostrarObjetos(Graphics ^ G)
{
	Jugador->Mostrar(G);
	for (unsigned int i = 0; i < Vec.size(); i++)
	{
		Vec[i]->Mostrar(G);
	}
}

void GameManager::MoverObjetos()
{
	for (unsigned int i = 0; i < Vec.size(); i++)
	{
		Vec[i]->Mover();
	}
}

void GameManager::Agregar(Figura * Nuevo)
{
	Vec.push_back(Nuevo);
}

void GameManager::Update(Graphics ^ G)
{
	if (Jugador->GetImpulsando())
	{
		if (TiempoReal  < 2 * Jugador->Gett())
			Jugador->Impulso(TiempoReal);
		else
		{
			Jugador->SetImpulsando(false);
			Jugador->SetRotation(45);
		}

	}

	else if (Jugador->GetSaltando())
	{
		if (TiempoReal < 1.7*Jugador->Gett())
			Jugador->Salto(TiempoReal);
		else
		{
			Jugador->SetSaltando(false);
			Jugador->SetRotation(45);
		}
	}


	/*else if (Jugador->Getx() > 90)
	Jugador->Setx(Jugador->Getx() - 5);
	*/
	else
	{
		Jugador->SetDy(Jugador->GetLim());
		Jugador->Mover();

	}

	
	MoverObjetos();
	TiempoReal += 0.35;
}

GameManager::GameManager()
{
	TiempoReal = 0;
	Jugador = new Player(90, 400, 30);
}


GameManager::~GameManager()
{
}
