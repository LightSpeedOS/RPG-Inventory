#pragma once

#include "Struct.h"
#include "Logic.h"
#include "BackendLogic.h"

void setUpItems(vector<Item>& shop);

void buyItem(vector<Item>& items, Item* current);

void sellItem(vector<Item>& items, Item* current);

