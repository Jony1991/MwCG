#include "stdafx.h"
#include "MwGLElement.h"

IMPLEMENT_SERIAL(MwGLElement, MwGLObject, 1);

MwGLElement::MwGLElement(void)
{
}


MwGLElement::~MwGLElement(void)
{
}

void MwGLElement::Serialize(CArchive& ar)
{
	MwGLObject::Serialize(ar);

	if (ar.IsStoring())
	{	
		// storing code
		ar<<&color_;
	}
	else
	{	
		// loading code
		MwColor* pColor;
		ar>>pColor;
		color_.set(*pColor);
		delete pColor;
	}
}