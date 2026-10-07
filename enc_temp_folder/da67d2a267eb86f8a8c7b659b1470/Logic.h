#pragma once











inline void listInventory(const vector<Item>& items)
{
	clear();

	cout << "========= WEAPONS =========" << endl;
	space();

	cout << left << setw(20) << "WEAPON" << "DAMAGE" << endl;
	cout << "---------------------------" << endl;

	for (const Item& i : items)
	{

		//if (i.isOwned == false) continue;

		cout << left << setw(20) << i.name << " (" << red << i.damage << reset << ")" << endl;
	}
	getKey();
}