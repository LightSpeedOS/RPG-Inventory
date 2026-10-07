#include "Weapon.h"
#include "BackendLogic.h"
#include "Logic.h"

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

void buyItem(vector<Item>& items, Item*& current, Player* player)
{
	listShop(items, current);
	space();

	string nameSearch;

	if (current != nullptr)
	{
		clear();
		cout << "[!] Sell Your Weapon Before Buying a New One" << endl;
		pause();
		return;
	}

	cout << "Enter name of the Weapon you want to purchase" << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, nameSearch);

	if (nameSearch.empty())
	{
		clear();
		cout << "[!] Name Cannot Be Left Empty" << endl;
		pause();
		return;
	}

	for (Item& item : items)
	{
		if (tolower(nameSearch) == tolower(item.name))
		{
			current = &item;
			break;
		}
	}

	if (!isValid(current))
	{
		clear();
		cout << "[!] No Weapon Found" << endl;
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

	if (player->col < current->price)
	{
		clear();
		cout << "[!] You Do Not Have Enough Col" << endl;
		pause();
		return;
	}

		const int colSnapshot = player->col;
		player->col -= current->price;
		current->isOwned = true;

		space();
		cout << "[+] " << green << "Successfully " << reset << "Purchased " << current->name << "!" << endl;
		cout << "Player Col: " << colSnapshot << " -> " << player->col << " (" << red << "-" << current->price << reset << ")" << endl;
		getKey();
}

void sellItem(vector<Item>& items, Item*& current, Player* player)
{
	clear();

	if (!isValid(current))
	{
		noItemSelected();
	}

	cout << "Are You Sure You Want To Sell " << current->name << "?" << endl;
	cout << "[Y] Yes   [N] No" << endl;

	char key = _getch();
	
	switch (tolower(key))
	{
	case 'y':
	{
		clear();

		const int colSnapshot = player->col;
		player->col += current->price;

		space();
		cout << "[+] " << green << "Successfully " << reset << "Sold " << current->name << endl;
		cout << "Player Col: " << colSnapshot << " -> " << player->col << " (" << green << "+" << current->price << reset << ")" << endl;

		current->isOwned = false;
		current = nullptr;
		getKey();
		return;
	}
		
	case 'n':

		return;

	default:
		invalid();
		while (_kbhit()) _getch();
		break;
	}
}