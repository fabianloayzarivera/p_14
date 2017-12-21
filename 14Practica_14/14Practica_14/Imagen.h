#pragma once

#include "stdafx.h"
#include <string>

enum ImageType {
	JPG,
	PNG
};

class CImagen
{
public:
	~CImagen();

	int								SetImageFile(const char *pszFile);
	unsigned int					GetNumPixels() const;
	unsigned int					GetUncompressedSize() const;
	const unsigned char *			GetBuffer() const;
	int							    Draw() const;
	int								InvertImage();
	const unsigned char				GetType() const;

protected:
	unsigned int		m_uResX;
	unsigned int		m_uResY;
	unsigned int		m_uColorBytes;
	unsigned char *	    m_pBuffer;
	unsigned int		m_uSize;
	unsigned char		m_type;
};