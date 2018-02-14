#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

//Metodos de Entrada

int Player::GetLim()
{
	return Lim;
}

double Player::GetDx()
{
	return dx;
}

double Player::GetDy()
{
	return dy;
}

double Player::GetVo()
{
	return Vo;
}

double Player::Getangulo()
{
	return angulo;
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

bool Player::GetTiled()
{
	return Tiled;
}

bool Player::GetOnColision()
{
	return OnColision;
}

void Player::Mover()

{
	if (Tiled)
	{
		EnAire = false;
		if (GravMod == 1)
		{
			Rotation = 135;
		}


		if (GravMod == -1)
		{
			Rotation = 315;
		}
	}
	
	if (!Tiled)
	{

		Lim = 300 + (GravMod * 200);
		if (GravMod == 1)
		{
			if (y <= Lim)
			{
				EnAire = true;
				y += g*1.3;
				Rotation += 10;
				if (Rotation > 360)
					Rotation = 0;
			}
			if (y >= Lim)
			{
				EnAire = false;
				Rotation = 135;
			}

		}

		else if (GravMod == -1)
		{
			if (y >= Lim)
			{
				EnAire = true;
				y -= g*1.3;
				Rotation += 10;
				if (Rotation > 360)
					Rotation = 0;
			}

			if (y <= Lim)
			{
				EnAire = false;
				Rotation = 315;
			}
		}
	}
}

void Player::SetDx(double Dx)
{
	dx = Dx;
}

void Player::SetDy(double Dy)
{
	dy = Dy;
}

void Player::SetVo(double Vo)
{
	this->Vo = Vo;
}

void Player::Setangulo(double angulo)
{
	this->angulo = angulo;
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

void Player::Tranformar()
{
		Transformado = true;
}

void Player::SetEnPortal(bool Portal)
{
	EnPortal = Portal;
}

void Player::SetTiled(bool Tile)
{
	Tiled = Tile;
}

//Movimiento

void Player::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		OnColision = true;
		if(!Tiled)
		*T = 0;
		Saltando = false;
		Impulsando = false;
		dx = x;
		dy = y;
		switch (a->GetTag())
		{
		case 1:
			break;
		case 2: Gravity(); break;
		case 3: Gravity(); break;
		case 4: Tiled = true;
			OnColision = false;  break;
		case 5: EnPortal = true; Tranformar(); break;
		case 6: EnPortal = true; Tranformar(); break;
		case 7: SetImpulsando(true); break;		
		default: break;
		}
	}
	else
	{
		Lim = 300 + (GravMod * 200);
		OnColision = false;
	}
		
}

void Player::Impulso(double tiempo)
{
	if (!OnColision)
	{
		if (x < 100)
		x = dx + (1.5*Vo*cos(angulo)*tiempo);
		y = dy - GravMod*(2*Vo*sin(angulo)*tiempo - 0.5 * g * tiempo * tiempo);
		Rotation += 10;
		if (Rotation > 360)
			Rotation = 0;
		EnAire = true;
	}
}

void Player::Mostrar(Graphics ^ G, Bitmap^ img)
{
	array<Point>^ puntos = gcnew array<Point>(lado-1);
	float x1, y1;
	float ang = Rotation + 90;
	x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
	y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
	puntos[0] = Point(x1, y1);

	ang = Rotation + 180;
	x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
	y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
	puntos[1] = Point(x1, y1);

	ang = Rotation;
	x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
	y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
	puntos[2] = Point(x1, y1);

	G->DrawImage(img, puntos);
}


void Player::Salto(double tiempo)
{
	
	if (!OnColision)
	{
		if (!Impulsando)
		{
			if (x < 100)
			x = dx + (Vo*cos(angulo)*tiempo);
			y = dy - GravMod*(1.7*Vo*sin(angulo)*tiempo - 0.5 * g * tiempo * tiempo);
			Rotation += 10;
			if (Rotation > 360)
				Rotation = 0;
			EnAire = true;
		}
	}
}

Player::Player(float px, float py, float pl)
{
	Transformado = false;
	lado = 4;
	Rotation = 0;
	Tag = 0;
	dx = x = px;
	dy = y = py;
	l = pl;
	Vo = 35;
	angulo = 45;
	Lim = 300 + (GravMod * 200);
	t = 2 * (Vo*sin(angulo) / g);
}

bool Player::Colision(Figura* a)
{
	if (a->GetColide())
	{
		if (a->GetTag() == 4)
		{
			if (y + l >= a->Gety() && y <= a->Gety() + a->Getl())
			{

				if (a->Getx() <= (x + l) && (a->Getx() + a->Getl()) >= x + l)
				{
					
					if ((y + l) - 1 < a->Gety())
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

void Player::Tiling(Figura * a)
{
	if (OnColision)
		Tiled = true;
	else
		Tiled = false;
}
