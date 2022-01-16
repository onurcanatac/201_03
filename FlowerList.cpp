//Onurcan Ataç, 22002194
#include <iostream>
#include "FlowerList.h"

FlowerList::FlowerList()
{
	size = 0;
	head = NULL;
}

FlowerList::FlowerList(const FlowerList& aList)
{
	if (aList.head == NULL)
	{
		this->head = NULL;
	}
	else
	{
		this->head = new FlowerNode;
		(this->head)->f = (aList.head)->f;

		FlowerNode* newPointer = this->head;

		for (FlowerNode* originalPointer = (aList.head)->next; originalPointer != NULL; originalPointer = originalPointer->next)
		{
			newPointer->next = new FlowerNode;
			newPointer = newPointer->next;
			newPointer->f = originalPointer->f;
		}
		newPointer->next = NULL;
	}
	this->size = aList.size;
}

FlowerList::~FlowerList()
{
	//delete linked list if there is one

	if (this->head != NULL)
	{
		FlowerNode* current;
		current = this->head;

		while (current->next != NULL)
		{
			//döngüye sok
			FlowerNode* next = NULL;

			next = current->next;
			delete current;
			current = next;
		}
		delete current;
	}
}

bool FlowerList::isEmpty() const
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

int FlowerList::getLength() const
{
	return this->size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const
{
	FlowerNode* current;
	current = this->head;

	//FlowerNode* trail = NULL;

	if ((this->head) == NULL)
	{
		std::cout << flowerName + " isn't found in the library" << std::endl;
		return 0;
	}
	else if (flowerName == (this->head)->f.getFlowerName())
	{
		flower = current->f;

		return 1;
	}
	else
	{
		while (current != NULL)
		{
			if ((current)->f.getFlowerName() == flowerName)
			{
				//remove feature
				FlowerNode* temp = current;

				//trail->next = current->next;

				flower = (temp)->f;

				return 1;
			}
			else
			{
				//trail = current;
				current = current->next;
			}
		}
		
		std::cout << flowerName + " isn't found in the library" << std::endl;
		return 0;

	}
}

bool FlowerList::retrieve(string flowerName, Flower*& flower) const
{
	FlowerNode* current;
	current = this->head;

	//FlowerNode* trail = NULL;

	if ((this->head) == NULL)
	{
		std::cout << flowerName + " isn't found in the library" << std::endl;
		return 0;
	}
	else if (flowerName == (this->head)->f.getFlowerName())
	{
		flower = &(current->f);

		return 1;
	}
	else
	{
		while (current != NULL)
		{
			if ((current)->f.getFlowerName() == flowerName)
			{
				//remove feature
				FlowerNode* temp = current;

				//trail->next = current->next;

				flower = &((temp)->f);

				return 1;
			}
			else
			{
				//trail = current;
				current = current->next;
			}
		}

		std::cout << flowerName + " isn't found in the library" << std::endl;
		return 0;

	}
}

bool FlowerList::add(string flowerName)
{
	//if added return 1, not added return 0

	//check if that flower exists

	FlowerNode* current;
	current = this->head;

	while (current != NULL)
	{
		if (current->f.getFlowerName() == flowerName)
		{
			std::cout << flowerName + " cannot be added into the library because it already exists." << std::endl;
			return 0;
		}
		else
		{
			current = current->next;
		}
	}

	//insert new node

	FlowerNode* temp;
	FlowerNode* newPointer = new FlowerNode;
	
	newPointer->f.setFlowerName(flowerName);
	newPointer->next = NULL;

	string key = flowerName;
	if ((this->head) == NULL || key < (this->head)->f.getFlowerName())
	{
		newPointer->next = this->head;
		this->head = newPointer;
		
		size += 1;
		
		std::cout << flowerName + " has been added into the library." << std::endl;

		return 1;
	}
	else
	{
		temp = this->head;
		while (temp->next != NULL && ((temp->next)->f).getFlowerName() < key)
		{
			temp = temp->next;
		}
		newPointer->next = temp->next;
		temp->next = newPointer;

		size += 1;

		std::cout << flowerName + " has been added into the library." << std::endl;

		return 1;
	}
}

bool FlowerList::remove(string flowerName)
{
	FlowerNode* current;
	current = this->head;

	FlowerNode* trail = NULL;

	if ((this->head) == NULL)
	{
		std::cout << flowerName + " cannot be removed because it's not in the library." << std::endl;
		return 0;
	}
	else if (flowerName == (this->head)->f.getFlowerName())
	{
		this->head = this->head->next;
		delete current;

		std::cout << flowerName + " has been removed from the library." << std::endl;

		size -= 1;

		return 1;
	}
	else
	{
		while (current != NULL)
		{
			if ((current)->f.getFlowerName() == flowerName)
			{
				//remove feature
				FlowerNode* temp = current;

				trail->next = current->next;

				delete temp;

				std::cout << flowerName + " has been removed from the library." << std::endl;

				size -= 1;

				return 1;
			}
			else
			{
				trail = current;
				current = current->next;
			}
		}
		std::cout << flowerName + " cannot be removed because it's not in the library." << std::endl;
		return 0;

	}
}

string FlowerList::printFlowerList() const
{
	string descriptionString = "";

	if (this->head == NULL)
	{
		descriptionString += "Library is empty.";
	}
	else
	{
		FlowerNode* current;
		current = this->head;

		while (current != NULL)
		{
			descriptionString += current->f.printFlower();
			if (current->next != NULL)
			{
				descriptionString += "\n";
			}
			current = current->next;
		}
	}
	return descriptionString;
}

void FlowerList::findFlowers(string feature) const
{
	FlowerNode* current = this->head;

	std::cout << feature + " flowers: ";

	bool anyFlower = false;
	bool first = true;

	while (current != NULL)
	{
		bool haveFeature = current->f.checkFeatures(feature);

		if (haveFeature)
		{
			if (first == false)
			{
				std::cout << ", ";
			}

			std::cout << (current->f).getFlowerName();
			anyFlower = true;
			first = false;
		}
		current = current->next;
	}

	if (anyFlower == false)
	{
		std::cout <<"there is no such flower";
	}
}
