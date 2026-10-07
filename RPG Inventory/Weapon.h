#pragma once

#include "Struct.h"

void setUpItems(vector<Item>& shop);

void buyItem(vector<Item>& items, Item*& current, Player* player);

void sellItem(vector<Item>& items, Item*& current, Player* player);

