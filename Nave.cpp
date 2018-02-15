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
	t = 0.35;
	Transformado = true;
}


Nave::~Nave()
{
}

void Nave::Mover()
{
	if (!Saltando)
		y += g*1.5;
	if (Rotation < 180)
		Rotation += 5;
}

void Nave::Salto(double tiempo)
{
	y -= g*1.7;
	if (Rotation > 0)
		Rotation -= 5;
}

void Nave::Mostrar(Graphics ^ G, Bitmap^ img)
{
	int x1 = x;
	int y1 = y;
	Rectangle Cut(i*(img->Width / 4), j*img->Height / 2, img->Width / 4, img->Height / 2);

	G->DrawImage(img, x1, y1, Cut, GraphicsUnit::Pixel);

	i++;
	if (i > 3)
	{
		i = 0;
		j++;
	}
	if (i > 1)
		j = 0;
}

void Nave::CheckColision(Figura * a, double *T)
{
	if (Colision(a))
	{
		OnColision = true;
		Saltando = false;
		Impulsando = false;
		dy = y;
		switch (a->GetTag())
		{
		case 1:
			break;
		case 5: EnPortal = true; Transformar(); break;
		case 6: EnPortal = true; Transformar(); break;
		default: break;
		}
	}

}
