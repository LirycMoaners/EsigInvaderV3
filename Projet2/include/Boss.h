#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
public:
	Boss(int life, int dommage);

	Boss();
	~Boss();
};

