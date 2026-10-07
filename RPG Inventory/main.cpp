#include "Includes.h"
#include "Struct.h"
#include "Logic.h"
#include "BackendLogic.h"
#include "Weapon.h"

using namespace std;

auto main() -> int
{
	Player player("Jamaal", 2000);
	vector<Weapon> weapons;
	vector<Item> items;
	setUpItems(items);

	Item* currentWeapon = nullptr;
	int mainOption;

	while (true)
	{
		clear();

		printInfo(&player, currentWeapon);

		cout << "[1] Browse Shop" << endl;
		cout << "[2] Buy Item" << endl;
		cout << "[3] Sell Item" << endl;
		cout << "[4] View Inventory" << endl;
		cout << "[5] Exit" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		switch (mainOption)
		{
		case BrowseShop:
			browseShop(items, currentWeapon, &player);
			break;

		case BuyItem:
			buyItem(items, currentWeapon, &player);
			break;

		case SellItem:
			sellItem(items, currentWeapon, &player);
			break;

		case Inventory:
			listInventory(items);
			break;

		case Exit:
			shutDown();
			break;
		}
	}
}