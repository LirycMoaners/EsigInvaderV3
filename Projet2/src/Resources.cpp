#include "..\include\Resources.h"



Resources::Resources()
{
	xmldata = new ConfigXml();
	img = new Img();

}
ConfigXml * Resources::getConfigXML() {
	return xmldata;
}

Img * Resources::getImg() {
	return img;
}


Resources::~Resources()
{
}
