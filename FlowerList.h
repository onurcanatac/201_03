//Onurcan Ataç, 22002194
#ifndef FLOWERLIST_H

#define FLOWERLIST_H

#include "Flower.h"
class FlowerList {
public:
	FlowerList();
	FlowerList(const FlowerList& aList);
	~FlowerList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(string flowerName, Flower& flower) const;
	bool retrieve(string flowerName, Flower*& flower) const;
	bool add(string flowerName);
	bool remove(string flowerName);
	string printFlowerList() const;
	void findFlowers(string feature) const;
private:
	struct FlowerNode {
		Flower f;
		FlowerNode* next;
	};
	int size;
	FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
	// ...
	//you may define additional member functions and data members, if necessary
};
#endif