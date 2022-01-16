//Onurcan Ataç, 22002194
#ifndef FLOWER_H

#define FLOWER_H
 
#include <string>

using namespace std;

class Flower {
public:
	Flower();
	Flower(string flowerName);
	Flower(const Flower& aFlower);
	~Flower();
	bool isEmpty() const;
	int getLength() const;
	bool add(string feature);
	bool remove(string feature);
	string printFlower() const;
	string getFlowerName();
	void setFlowerName(string flowerName);
	bool checkFeatures(string feature) const;
private:
	struct FeatureNode {
		string feature;
		FeatureNode* next;
	};
	int size;
	string flowerName;
	FeatureNode* head; //the features are stored in a sorted singly linear linked list
	// ...
	//you may define additional member functions and data members, if necessary
};

#endif