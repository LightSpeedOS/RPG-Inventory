#pragma once

#include "Includes.h"

enum mainMenu
{
	BrowseShop = 1,
	BuyItem,
	SellItem,
	Inventory,
	Exit
};

struct Player
{
	string name;
	int col;
};

struct Item
{
	string name;
	int price;
	int damage;
	bool isOwned = false;

	Item(string newName, int newPrice, int newDamage)
	{
		name = newName;
		price = newPrice;
		damage = newDamage;
	}
};

struct Weapon
{
	string name;
	int price;
	int damage;
	bool isOwned = false;
};