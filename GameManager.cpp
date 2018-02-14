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

int GameManager::GetN_Saltos()
{
	return N_Saltos;
}

void GameManager::Temp(double t)
{
	TiempoReal += t;
}

void GameManager::SetTemp(double t)
{
	TiempoReal = t;
}

void GameManager::MostrarObjetos(Graphics ^ G, Bitmap^ imgNave, Bitmap^ imgJugador, Bitmap^ imgTile, Bitmap^ imgPortal1, Bitmap^ imgPortal2, Bitmap^imgEspina, Bitmap^ imgTrampolin)
{
	if(Jugador->GetTransformado())
		Jugador->Mostrar(G, imgNave);
	else
		Jugador->Mostrar(G, imgJugador);
	for (unsigned int i = 0; i < Vec.size(); i++)
	{
		switch (Vec[i]->GetTag())
		{
		case 1: Vec[i]->Mostrar(G, imgEspina); break;
		case 2:	Vec[i]->Mostrar(G, imgPortal1); break;
		case 3:	Vec[i]->Mostrar(G, imgPortal2); break;
		case 4:	Vec[i]->Mostrar(G, imgTile); break;
		case 5:	Vec[i]->Mostrar(G, imgPortal1); break;
		case 6:	Vec[i]->Mostrar(G, imgPortal2); break;
		case 7:	Vec[i]->Mostrar(G, imgTrampolin); break;
		default:
			break;
		}
		
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
		}

	}

	else if (Jugador->GetSaltando())
	{
		if (TiempoReal < 1.7*Jugador->Gett())
			Jugador->Salto(TiempoReal);
		else
		{
			Jugador->SetSaltando(false);
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
	
	/*if (!Jugador->GetOnColision())
		Jugador->SetTiled(false);
	*/
	MoverObjetos();
	TiempoReal += 0.35;
}

void GameManager::AumentarSalto()
{
	N_Saltos++;
}

void GameManager::Inicializar()
{
	int _tag;
	int _x;
	int _y;
	int _l;
	bool Prim;
	ifstream fs(file_name);
	string cadena;
	while (!fs.eof())
	{
		getline(fs, cadena);
		if (cadena.length() > 0) {
			Figura* Nueva;
			_tag = (atoi(cadena.c_str()));
			getline(fs, cadena);
			_x = (atoi(cadena.c_str()));
			getline(fs, cadena);
			_y = (atoi(cadena.c_str()));
			getline(fs, cadena);
			_l = (atoi(cadena.c_str()));
			if (_tag == 2 || _tag == 3 || _tag == 5 || _tag == 6)
			{
				getline(fs, cadena);
				string Id = (cadena.c_str());
				if (strcmp(&*Id.begin(), "Si"))
					Prim = false;
				else
					Prim = true;
			}
			switch (_tag)
			{
			case 1: Nueva = new Espina(_x, _y, _l); break;
			case 2:	Nueva = new Gravedad(_x, _y, _l,Prim); break;
			case 3:	Nueva = new Gravedad(_x, _y, _l, Prim); break;
			case 4:	Nueva = new Tile(_x, _y, _l); break;
			case 5:	Nueva = new Portal(_x, _y, _l, Prim); break;
			case 6:	Nueva = new Portal(_x, _y, _l, Prim); break;
			case 7:	Nueva = new Trampolin(_x, _y, _l); break;
			default:
				break;
			}

			Vec.push_back(Nueva);
		}
	}
	fs.close();
}

void GameManager::Transformar()
{
	if (Jugador->GetTransformado())
		Jugador = new Nave(Jugador->Getx(), Jugador->Gety(), Jugador->Getl());
	else 
		Jugador = new Player(Jugador->Getx(), Jugador->Gety(), Jugador->Getl());
	Jugador->SetEnPortal(false);
}

GameManager::GameManager()
{
	file_name = "Editor.txt";
	N_Saltos = 0;
	TiempoReal = 0;
	Jugador = new Player(90, 400, 30);
	Inicializar();
}


GameManager::~GameManager()
{
}
