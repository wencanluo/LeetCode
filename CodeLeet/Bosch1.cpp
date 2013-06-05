/*
Question 1: Check the containment relationship of two ingredient arrays

An ingredient is defined by its name and its super-ingredient and sub-ingredient.
class Ingredient{
	String name;
	IngredientPointer superIngredient;
	IngredientPointer subIngredient;
}
Each ingredient has a unique name. 
The super-ingredient is the broader category that the current ingredient belongs to. 
The current ingredient is the super-ingredient of its sub-ingredient.
For example, the ingredient "Beef" has the super-ingredient "Meat" and the sub-ingredient "Angus Beef".
We say two ingredients are exchangable if either they are identical(i.e., have the same name),
or they have the super-/sub- relationship.
For example, "Meat" and "Angus Beef" are exchangable since they have super-/sub- relationship 
in the chain of "Meat"-"Beef"-"Angus Beef".

Now please realize the following method.
This method checks if the second ingredient array is contained in the first ingredient array.
We say array A contains array B if each ingredient in array B has an exchangable correspondence in array A.
Use any programming language (C, C++, Java) you are familiar with.
Feel free to change the syntax of the "ingredient" class and the "contains" method.

Boolean contains (ArrayOfIngredient arrayA, ArrayOfIngredient arrayB)
{


}

Author: Wencan Luo
Language: C++
Date: 02/12/2013

*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef Ingredient* IngredientPointer;

class Ingredient{
public:
	string name;
	IngredientPointer superIngredient; //assme NULL if there is no super
	IngredientPointer subIngredient;//assme NULL if there is no sub
};

bool Add2Dict(Ingredient a, map<string, int> &dict)
{
	dict[a.name] = 1;

	//check the super chain
	Ingredient *uper = a.superIngredient;
	while(uper != NULL)
	{
		dict[uper->name] = 1;
		uper = uper->superIngredient;
	}

	//check the sub chain
	Ingredient *sub = a.subIngredient;
	while(sub != NULL)
	{
		dict[sub->name] = 1;
		sub = sub->subIngredient;
	}

	return false;
}

//if the second ingredient array is contained in the first ingredient array
bool contains (vector<Ingredient> arrayA, vector<Ingredient> arrayB) //O(n)
{
	map<string, int> dict;

	//add all the exchangable to the dict
	for(vector<Ingredient>::iterator itA = arrayA.begin(); itA< arrayA.end(); itA++)
	{
		//add only a new chain
		if(dict.find(itA->name) == dict.end()) Add2Dict(*itA, dict);
	}

	for(vector<Ingredient>::iterator itB = arrayB.begin(); itB< arrayB.end(); itB++)
	{
		if(dict.find(itB->name) == dict.end());
		{
			return false;
		}
	}

	return true;
}

void main()
{
	
}