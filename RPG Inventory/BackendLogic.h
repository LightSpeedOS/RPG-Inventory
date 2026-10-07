#pragma once

inline bool isValid(const Item* a)
{
	if (a == nullptr) return false;

	return true;
}

inline void noItemSelected()
{
	clear();
	cout << "[!] No Item Selected" << endl;
	cout << "Select an item from the shop first."  << endl;
	pause();
}

inline string tolower(string text)
{
	for (char& c : text)
	{
		c = tolower(c);
	}
	return text;
}

inline void printInfo(const Player* player, const Item* current)

{
	cout << "======== RPG Shop ========" << endl;
	space();

	cout << "Player Col: " << yellow << player->col << reset << endl;
	
	if (current == nullptr) cout << "Current Weapon: None" << endl;
	else cout << "Current Weapon: " << current->name << endl;
}