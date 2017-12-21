#include "stdafx.h"
#include "Png.h"
#include <string>
// **************************************************************
//
// **************************************************************
int CPng::SetPngFile(const char *pszPngFile)
{
	printf("Lectura del fichero comprimido Png\n");
	m_type = PNG;
	UncompressImage();
	return 0;
}

// **************************************************************
//
// **************************************************************
int CPng::UncompressImage()
{
	printf("Descompresión de Imagen Png\n");
	m_uResX				= 480;
	m_uResY				= 320;
	m_uColorBytes	= 4;
	m_uSize				= m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer			= new unsigned char[m_uSize];
	strcpy(reinterpret_cast<char *>(m_pBuffer), "Bytes del buffer descomprimido desde Png");
	return 0;
}


void CPng::DeleteAlphaChannel()
{
	printf("Eliminacion del canal alpha de Imagen Png\n");
	m_uColorBytes = 3;
	m_uSize = m_uResX * m_uResY * m_uColorBytes;
	m_pBuffer = new unsigned char[m_uSize];
	strcpy(reinterpret_cast<char *>(m_pBuffer), "Bytes del buffer sin el canal alpha");
}