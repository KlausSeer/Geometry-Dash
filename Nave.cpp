#include "Nave.h"



void Nave::Transformar()
{
	Transformado = false;
}

Nave::Nave()
{
}

Nave::Nave(float px, float py, float pl)
{
	lado = 5;
	Rotation = 60;
	Tag = 0;
	x = px;
	dy = y = py;
	l = pl;
	Lim = 300 + (GravMod * 200);
	t = 3.4*0.35;
	Transformado = true;
}


Nave::~Nave()
{
}

void Nave::Mover()
{
	if (!Tiled)
	{
		if (!Saltando)
		y += g;
	}
}

void Nave::Salto(double tiempo)
{
	if (y -g*1.7 > 100)
	y -= g*1.7;
}

void Nave::Mostrar(Graphics ^ G, Bitmap^ img)
{
	int x1 = x;
	int y1 = y;
	Rectangle Cut(i*(img->Width / 4), j*img->Height / 2, img->Width / 4, img->Height / 2);

	G->DrawImage(img, x1, y1, Cut, GraphicsUnit::Pixel);

	j++;
	if (j > 1)
	{
		j = 0;
		i++;
	}
	if (i > 3)
		i = 0;
}

void Nave::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		if (!Tiled)
		{
			OnColision = true;
			Saltando = false;
			Impulsando = false;
		}
		dy = y;
		switch (a->GetTag())
		{
		case 1:
			break;
		case 4: 
			Tiled = true;
			OnColision = false;
			break;
		case 5: EnPortal = true; Transformar(); break;
		case 6: EnPortal = true; Transformar(); break;
		default: break;
		}
	}
	else
	{
		Lim = 300 + (GravMod * 200);
		OnColision = false;
	}
}
