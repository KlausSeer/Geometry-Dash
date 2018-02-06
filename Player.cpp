#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		*T = 0;
		dx = x;
		dy = y;
		switch (a->GetTag())
		{
		case 1: Gravity();  break;
		case 2: Gravity(); break;
		case 3: Impulsar(true); break;
		case 4: Tiling(a); break;
		default: break;
		}
	}
}

void Player::Impulso(double tiempo)
{
	a = (1.5*Vo*cos(angulo)*tiempo);
	b = GravMod*(2.5*Vo*sin( angulo)*tiempo - 0.5 * g * tiempo * tiempo);
	//x = dx + a;
	y = dy - b;
}


void Player::MoverP(double tiempo)
{
	a = (Vo*cos(angulo)*tiempo);
	b = GravMod*(Vo*sin(angulo)*tiempo - 0.5 * g * tiempo * tiempo);
	x = a;
	y = dy - b;

}

void Player::Mover()
{
	if (!Tiled)
	{
		Lim = 300 + (GravMod * 200);
	}
	

	if (GravMod == 1)
	{
		if (y  <= Lim)
			y += g*1.3;
	}

	else if (GravMod == -1)
	{
		if (y >= Lim)
			y -= g*1.3;
	}

	//x += 6;
}

void Player::Mostrar(Graphics ^ G)
{
	Pen^ P = gcnew Pen(Color::LawnGreen);
	G->DrawRectangle(P, x, y, l, l);
	Brush^ B = gcnew SolidBrush(Color::LawnGreen);
	G->FillRectangle(B, x, y, l, l);
}

Player::Player(float px, float py, float pl)
{
	Tag = 0;
	dx = x = px;
	dy = y = py;
	l = pl;
	Vo = 35;
	angulo = 45;
	Lim = 300 + (GravMod * 200);
	t = 2 * (Vo*sin(angulo) / g);
	a = b = 0;
}

bool Player::JumpState()
{
	return Salto;
}

bool Player::ImpulseState()
{
	return OnImpulse;
}

bool Player::Colision(Figura* a)
{
	if (a->GetColide())
	{
		float d = sqrt((pow((x - a->Getx()), 2) + (pow((y - a->Gety()), 2))));
		if (d <= (l + a->Getl()))
		{
			a->Colide(false);
			return true;
		}
	}

}

bool Player::Dentro(Figura * a)
{
	return (x+l >= a->Getx() && x + l <= a->Getx() + a->Getl() && y + l >= a->Gety() && y + l <= a->Gety() + a->Getl());
}

void Player::SetDx(double pdx)
{
	dx = pdx;
}

void Player::SetDy(double pdy)
{
	dy = pdy;
}

void Player::Saltar(bool B)
{
	Salto = B;
}

void Player::Tiling(Figura * a)
{
		if ((y + l) -1  < a->Gety())
		{
				Tiled = true;
				Lim = a->Gety();
		}

		else
		{
			a->SetTag(1);
			a->Colide(true);
		}
			
}

double Player::GetTiempo()
{
	return t;
}

int Player::GetLim()
{
	return Lim;
}

double Player::GetTiempoReal()
{
	return TiempoReal;
}

void Player::SetTiempo(double t)
{
	TiempoReal = t;
}

void Player::Impulsar(bool b)
{
	OnImpulse = b;
}

