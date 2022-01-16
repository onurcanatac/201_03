//Onurcan Ataç, 22002194
#include <iostream>

#include "FlowerLibrary.h"

FlowerLibrary::FlowerLibrary()
{
	flowers;
}

FlowerLibrary::~FlowerLibrary()
{
	//flowers are removed by FlowerList destructor.
}

void FlowerLibrary::addFlower(string name)
{
	//turn name into full lowercase

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = std::tolower(name[i]);
	}
	
	//add flower

	this->flowers.add(name);
}

void FlowerLibrary::removeFlower(string name)
{
	//turn name into full lowercase

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = std::tolower(name[i]);
	}

	//remove flower 

	this->flowers.remove(name);
}

void FlowerLibrary::listFlowers() const
{
	std::cout << this->flowers.printFlowerList() << std::endl;
}

void FlowerLibrary::listFeatures(string name) const
{
	//turn name into full lowercase

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = std::tolower(name[i]);
	}

	Flower* a = NULL;
	bool isRetrieved = (this->flowers.retrieve(name,a));
	
	if (isRetrieved)
	{

		std::cout << (*a).printFlower() << std::endl;
	}
}

void FlowerLibrary::addFeature(string name, string feature)
{
	//turn name into full lowercase

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = std::tolower(name[i]);
	}

	//turn feature into full lowercase

	for (int i = 0; i < feature.length(); i++)
	{
		feature[i] = std::tolower(feature[i]);
	}

	Flower* a = NULL;
	bool isRetrieved = this->flowers.retrieve(name, a);
	
	if (isRetrieved)
	{
		(*a).add(feature);
	}
}

void FlowerLibrary::removeFeature(string name, string feature)
{

	//turn name into full lowercase

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = std::tolower(name[i]);
	}

	//turn feature into full lowercase

	for (int i = 0; i < feature.length(); i++)
	{
		feature[i] = std::tolower(feature[i]);
	}

	Flower* a = NULL;
	bool isRetrieved = this->flowers.retrieve(name, a);

	if (isRetrieved)
	{
		(* a).remove(feature);
	}
	else
	{
		std::cout << name + " isn't found in the library" << std::endl;
	}
}

void FlowerLibrary::findFlowers(string feature) const
{
	(this->flowers).findFlowers(feature);
	std::cout << "" << std::endl;
}