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

double Player::GetVo()
{
	return Vo;
}

double Player::Getangulo()
{
	return angulo;
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

void Player::Mover()

{
	Lim = 300 + (GravMod * 200);
	if (GravMod == 1)
	{
		if (y <= Lim)
		{
			EnAire = true;
			y += g*1.3;
			Rotation += 5;
			if (Rotation > 360)
				Rotation = 0;
		}
		if (y >= Lim)
		{
			EnAire = false;
			Rotation = 45;
		}

	}

	else if (GravMod == -1)
	{
		if (y >= Lim)
		{
			EnAire = true;
			y -= g*1.3;
			Rotation += 5;
			if (Rotation > 360)
				Rotation = 0;
		}

		if (y <= Lim)
		{
			EnAire = false;
			Rotation = 45;
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

//Movimiento

void Player::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		OnColision = true;
		*T = 0;
		Saltando = false;
		Impulsando = false;
		dx = x;
		dy = y;
		switch (a->GetTag())
		{
		case 1: Gravity();  break;
		case 2: Gravity(); break;
		case 3: SetImpulsando(true); break;
			//case 4: Tiling(a); break;
		default: break;
		}
	}
	else
	{
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
		Rotation += 5;
		if (Rotation > 360)
			Rotation = 0;
		EnAire = true;
	}
}

void Player::Mostrar(Graphics ^ G)
{
	array<Point>^ puntos = gcnew array<Point>(lado);
	float x1, y1;
	for (int i = 0; i < lado; i++)
	{
		float ang = Rotation + (360 / lado)*i;
		x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
		y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
		puntos[i] = Point(x1, y1);
	}
	SolidBrush ^ B = gcnew SolidBrush(Color::LawnGreen);
	G->FillPolygon(B, puntos);
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
			Rotation += 5;
			if (Rotation > 360)
				Rotation = 0;
			EnAire = true;
		}
	}
}

Player::Player(float px, float py, float pl)
{
	lado = 4;
	Rotation = 45;
	Tag = 0;
	l = 4;
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
		float x1 = x + l / 2;
		float y1 = y + l / 2;
		float x2 = a->Getx() + a->Getl() / 2;
		float y2 = a->Gety() + a->Getl() / 2;

		float d = sqrt((pow((x2 - x1), 2) + (pow((y2 - y1), 2))));
		if (d < ((l + a->Getl())/2))
		{
			a->Colide(false);
			return true;
		}
	}

}
