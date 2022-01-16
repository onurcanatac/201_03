//Onurcan Ataç, 22002194
#include <iostream>
#include "Flower.h"

Flower::Flower()
{
	size = 0;
	flowerName = "";
	head = NULL;
}

Flower::Flower(string flowerName)
{
	size = 0;
	this->flowerName = flowerName;
	head = NULL;
}

Flower::Flower(const Flower& aFlower)
{
	if (aFlower.head == NULL)
	{
		this->head = NULL;
	}
	else
	{
		this->head = new FeatureNode;
		(this->head)->feature = (aFlower.head)->feature;

		FeatureNode* newPointer = this->head;

		for (FeatureNode* originalPointer = (aFlower.head)->next; originalPointer != NULL; originalPointer = originalPointer->next)
		{
			newPointer->next = new FeatureNode;
			newPointer = newPointer->next;
			newPointer->feature = originalPointer->feature;
		}
		newPointer->next = NULL;
	}
	this->flowerName = aFlower.flowerName;
	this->size = aFlower.size;
}

Flower::~Flower()
{
	//delete linked list if there is one
	
	if (this->head != NULL)
	{
		FeatureNode* current;
		current = this->head;

		while (current->next != NULL)
		{
			//döngüye sok
			FeatureNode* next = NULL;

			next = current->next;
			delete current;
			current = next;
		}
		delete current;
	}
}

//methods

bool Flower::isEmpty() const
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Flower::getLength() const
{
	return this->size;
}

bool Flower::add(string feature)
{
	//if added return 1, not added return 0

	//check if that feature exists

	FeatureNode* current;
	current = this->head;

	while (current != NULL)
	{
		if (current->feature == feature)
		{
			std::cout << feature + " already exists in " + this->flowerName << std::endl;
			return 0;
		}
		else
		{
			current = current->next;
		}
	}

	//insert new node

	FeatureNode* temp;
	FeatureNode* newPointer = new FeatureNode;
	
	(newPointer->feature) = feature;
	newPointer->next = NULL;

	string key = feature;
	if ((this->head) == NULL || key < (this->head)->feature)
	{
		newPointer->next = this->head;
		this->head = newPointer;
		
		size += 1;

		std::cout << feature + " is added into " + this->flowerName << std::endl;
		
		return 1;
	}
	else
	{
		temp = this->head;
		while (temp->next != NULL && temp->next->feature < key)
		{
			temp = temp->next;
		}
		newPointer->next = temp->next;
		temp->next = newPointer;

		size += 1;

		std::cout << feature + " is added into " + this->flowerName << std::endl;

		return 1;
	}
}

bool Flower::remove(string feature)
{
	FeatureNode* current;
	current = this->head;

	FeatureNode* trail = NULL;

	if ((this->head) == NULL)
	{
		std::cout << feature + " doesn't exist in " + this->flowerName << std::endl;
		return 0;
	}
	else if (feature == (this->head)->feature)
	{
		this->head = this->head->next;
		delete current;

		std::cout << feature + " is removed from " + this->flowerName << std::endl;

		size -= 1;

		return 1;
	}
	else
	{
		while (current!= NULL)
		{
			if ((current)->feature == feature)
			{
				//remove feature
				FeatureNode* temp = current;
				
				trail->next = current->next;

				delete temp;

				std::cout << feature + " is removed from " + this->flowerName << std::endl;

				size -= 1;

				return 1;
			}
			else
			{
				trail = current;
				current = current->next;
			}
		}		
		std::cout << feature + " doesn't exist in " + this->flowerName << std::endl;
		return 0;

	}

}

string Flower::printFlower() const
{
	string descriptionString = (this->flowerName) + ": ";

	if (this->head == NULL)
	{
		descriptionString += "No feature";
	}
	else
	{
		FeatureNode* current;
		current = this->head;

		while (current != NULL)
		{
			descriptionString += current->feature;
			if (current->next != NULL)
			{
				descriptionString += ", ";
			}
			current = current->next;
		}
	}
	return descriptionString;
}

string Flower::getFlowerName()
{
	return this->flowerName;
}

void Flower::setFlowerName(string flowerName)
{
	this->flowerName = flowerName;
}

bool Flower::checkFeatures(string feature) const
{
	FeatureNode* current = this->head;

	while (current != NULL)
	{
		if (feature == current->feature)
		{
			return 1;
		}
		current = current->next;
	}
	
	return 0;
}