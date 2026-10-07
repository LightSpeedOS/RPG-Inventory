#pragma once

#include "Weapon.h"

inline void listShop(const vector<Item> items, Item* current)
{
	clear();

	cout << "========= WEAPONS SHOP =========" << endl;
	space();

	if (current == nullptr) cout << "Current Weapon: None" << endl;
	else cout << "Current Weapon: " << current->name << endl;
	space();

	cout << left << setw(4) << "#" << setw(20) << "WEAPON" << "PRICE" << endl;
	cout << "------------------------------" << endl;

	for (size_t i = 0; i < items.size(); i++)
	{
		cout << left << setw(4) << i + 1 << setw(20) << items[i].name << items[i].price << endl;
	}


}

inline void browseShop(vector<Item>& items, Item*& current, Player* player)
{

	listShop(items, current);
	
	space();
	cout << "[1] Buy Item   [2] Sell Item   [R] Return" << endl;

	char key = _getch();

	switch (tolower(key))
	{
	case '1':
		buyItem(items, current, player);
		break;

	case '2':
		sellItem(items, current, player);
		break;

	case 'r':

		return;

	default:
		invalid();
		while (_kbhit()) _getch();
		break;
	}
}









inline void listInventory(const vector<Item>& items)
{
	clear();

	cout << "========= WEAPONS =========" << endl;
	space();

	cout << left << setw(20) << "WEAPON" << "DAMAGE" << endl;
	cout << "---------------------------" << endl;

	for (const Item& i : items)
	{
		
		if (i.isOwned == false) continue;

		cout << left << setw(20) << i.name << " (" << red << i.damage << reset << ")" << endl;
	}
	getKey();
}