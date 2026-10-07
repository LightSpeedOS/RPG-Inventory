#include "Weapon.h"

void setUpItems(vector<Item>& shop)
{
	Item codedSword("Coded Sword", 2000, 600);
	shop.push_back(codedSword);

	Item river("Rivers of Blood", 700, 120);
	shop.push_back(river);

	Item bloodThirsty("Bloodthirsty Axe", 400, 50);
	shop.push_back(bloodThirsty);

	Item fullMoon("Full Moon Blade", 400, 80);
	shop.push_back(fullMoon);

	Item undersea("Undersea Cable", 900, 200);
	shop.push_back(undersea);
}

void buyItem(vector<Item>& items, Item* current, Player* player)
{
	listShop(items, current);
	space();

	string nameSearch;

	cout << "Enter name of the Weapon you want to purchase" << endl;
	cout << "Name: ";
	cin >> nameSearch;

	if (nameSearch.empty())
	{
		clear();
		cout << "[!] Name Cannot Be Left Empty" << endl;
		pause();
		return;
	}

	for (size_t i = 0; i < items.size(); i++)
	{
		if (tolower(nameSearch == items[i].name)) items[i].isOwned = true; 
		current = &items[i];
	}

	if (!isValid(current))
	{
		clear();
		cout << "[!] No Weapon Found" << endl;
		pause();
		return;
	}

		if (player->col > current->price)
		{
			clear();
			cout << "[!] You Do Not Have Enough Col" << endl;
			pause();
			return;
		}

		if (current->isOwned)
		{
			clear();
			cout << "[+] You Already Own This Item" << endl;
			pause();
			return;
		}

		const int colSnapshot = player->col;
		player->col -= current->price;
		cout << "[+] " << green << "Successfully " << reset << "Purchased " << current->name << "!" << endl;
	
}

void sellItem(vector<Item>& items, Item* current)
{

}