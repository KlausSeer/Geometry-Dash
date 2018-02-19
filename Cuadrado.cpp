#include "Cuadrado.h"



double Cuadrado::GetVo()
{
	return Vo;
}

double Cuadrado::Getangulo()
{
	return angulo;
}

void Cuadrado::SetVo(double Vo)
{
	this->Vo = Vo;
}

void Cuadrado::Setangulo(double angulo)
{
	this->angulo = angulo;
}

void Cuadrado::Mover()
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

void Cuadrado::Transformar()
{
	Transformado = true;
}

bool Cuadrado::Colision(Figura * a)
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
				//Tiled = false;
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

void Cuadrado::Salto(double tiempo)
{
	if (!OnColision)
	{
		if (!Impulsando)
		{
			if (x < 100)
				x = (Vo*cos(angulo)*tiempo);
			y = dy - GravMod*(1.7*Vo*sin(angulo)*tiempo - 0.5 * g * tiempo * tiempo);
			Rotation += 10;
			if (Rotation > 360)
				Rotation = 0;
			EnAire = true;
		}
	}
}

void Cuadrado::Impulso(double tiempo)
{
	if (!OnColision)
	{
		if (x < 100)
			x = (1.5*Vo*cos(angulo)*tiempo);
		y = dy - GravMod*(2 * Vo*sin(angulo)*tiempo - 0.5 * g * tiempo * tiempo);
		Rotation += 10;
		if (Rotation > 360)
			Rotation = 0;
		EnAire = true;
	}

}

void Cuadrado::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		if (!Tiled)
	{
		*T = 0;
		OnColision = true;
		Saltando = false;
		Impulsando = false;
	}
		dy = y;
		switch (a->GetTag())
		{
		case 1:
			Vivo = false;
			break;
		case 2: Gravity(); break;
		case 3: Gravity(); break;
		case 4: Tiled = true;
			OnColision = false; 
			EnAire = false;
			break;
		case 5: EnPortal = true; Transformar(); break;
		case 6: EnPortal = true; Transformar(); break;
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

void Cuadrado::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	array<Point>^ puntos = gcnew array<Point>(lado - 1);
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

Cuadrado::Cuadrado()
{
}

Cuadrado::Cuadrado(float px, float py, float pl)
{
	Transformado = false;
	lado = 4;
	Rotation = 0;
	Tag = 0;
	x = px;
	dy = y = py;
	l = pl;
	Vo = 35;
	angulo = 45;
	Lim = 300 + (GravMod * 200);
	t = 2 * (Vo*sin(angulo) / g);

}


Cuadrado::~Cuadrado()
{
}
