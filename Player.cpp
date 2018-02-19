#include "Player.h"

//Metodos de Entrada

int Player::GetLim()
{
	return Lim;
}

double Player::GetDy()
{
	return dy;
}

bool Player::GetTransformado()
{
	return Transformado;
}

bool Player::GetSaltando()
{
	return Saltando;
}

bool Player::GetImpulsando()
{
	return Impulsando;
}

bool Player::GetEnAire()
{
	return EnAire;
}

double Player::Gett()
{
	return t;
}

double Player::GetRotation()
{
	return Rotation;
}

bool Player::GetEnPortal()
{
	return EnPortal;
}

bool Player::GetOnColision()
{
	return OnColision;
}

void Player::SetDy(double Dy)
{
	dy = Dy;
}

void Player::SetSaltando(bool Saltando)
{
	this->Saltando = Saltando;
}

void Player::SetImpulsando(bool Impulsando)
{
	this->Impulsando = Impulsando;
}

void Player::Sett(double t)
{
	this->t = t;
}

void Player::SetRotation(double Rotation)
{
	this->Rotation = Rotation;
}

void Player::SetOnAire(bool Aire)
{
	EnAire = Aire;
}


void Player::SetEnPortal(bool Portal)
{
	EnPortal = Portal;
}

void Player::SetTiled(bool Tile)
{
	this->Tiled = Tile;
}


bool Player::GetTiled()
{
	return Tiled;
}

bool Player::GetVivo()
{
	return Vivo;
}

void Player::Impulso(double tiempo)
{
}

bool Player::Colision(Figura * a)
{
	if (a->GetColide())
	{
		if (a->GetTag() == 4)
		{
			if (a->Getx() <= (x + l) && (a->Getx() + a->Getl()) >= x)

			{

				if (y + l >= a->Gety() && y <= a->Gety() + a->Getl())
				{

					if (y < a->Gety())
					{
						a->Colide(true);
						Lim = a->Gety();
						return true;
					}
					else
					{
						a->Colide(true);
						a->SetTag(1);
					}

				}
				else
				{
					Tiled = false;
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		else
		{
			float x1 = x + l / 2;
			float y1 = y + l / 2;
			float x2 = a->Getx() + a->Getl() / 2;
			float y2 = a->Gety() + a->Getl() / 2;

			float d = sqrt((pow((x2 - x1), 2) + (pow((y2 - y1), 2))));
			if (d < ((l + a->Getl()) / 2))
			{
				a->Colide(false);
				return true;
			}
		}
	}
}

Player::Player()
{
}


Player::~Player()
{
}
