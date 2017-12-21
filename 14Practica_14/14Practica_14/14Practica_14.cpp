// 14Practica_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include "Jpg.h"
#include "Png.h"

void PrintImageInfo(const CImagen &oImagen);
void DeletePngAlphaChannel(CImagen* imagesTable[255]);

int _tmain(int argc, _TCHAR* argv[])
{
	// Práctica Imagen
	CPng *oPng1 = new CPng();
	CPng *oPng2 = new CPng();
	CJpg *oJpg1 = new CJpg();
	CJpg *oJpg2 = new CJpg();

	oPng1->SetPngFile("Fichero.png");
	oPng2->SetPngFile("Fichero.png");
	oJpg1->SetJpgFile("Fichero.jpg");
	oJpg2->SetJpgFile("Fichero.jpg");

	/*PrintImageInfo(oPng1);
	PrintImageInfo(oJpg2);*/

	CImagen* imagesTable[255] = { oPng1, oJpg1, oPng2, oJpg2 };

	DeletePngAlphaChannel(imagesTable);

	getchar();

	return 0;
}

// ***************************************************
//
// ***************************************************
void PrintImageInfo(const CImagen &oImagen)
{
	printf("NumPixes: %d \nSize: %d\n", oImagen.GetNumPixels(), oImagen.GetUncompressedSize());
}

void DeletePngAlphaChannel(CImagen* imagesTable[255]) {
	for each (CImagen* img in imagesTable)
	{
		if (img) {
			if (img->GetType() == PNG) {
				CPng* pngImg = static_cast<CPng*>(img);
				if (pngImg) {
					pngImg->DeleteAlphaChannel();
				}
				delete(pngImg);
			}
		}
		
	}

}