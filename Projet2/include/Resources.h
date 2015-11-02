#pragma once
#include "ConfigXml.h"
#include "Img.h"
class Resources
{
public:
	Resources();
	~Resources();

	ConfigXml * getConfigXML();
	Img * getImg();
private : 
	ConfigXml * xmldata;
	Img * img;
};

