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