#include "Nave.h"



void Nave::Tranformar()
{
	Transformado = false;
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
	//array<Point>^ puntos = gcnew array<Point>(lado);
	//float x1, y1;
	//for (int i = 0; i < lado; i++)
	//{
	//	float ang = Rotation + (360 / lado)*i;
	//	x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
	//	y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
	//	puntos[i] = Point(x1, y1);
	//}
	//SolidBrush ^ B = gcnew SolidBrush(Color::BurlyWood);
	//G->FillPolygon(B, puntos);
	Rectangle Cut(i*(img->Width / 4), j*img->Height / 2, img->Width / 4, img->Height/2);

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

Nave::Nave()
{
}

Nave::Nave(float px, float py, float pl)
{
	lado = 5;
	Rotation = 60;
	Tag = 0;
	dx = x = px;
	dy = y = py;
	l = pl;
	Lim = 300 + (GravMod * 200);
	t = 0.35;
	Transformado = true;
}


Nave::~Nave()
{
}
