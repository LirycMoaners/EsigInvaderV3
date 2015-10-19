#pragma once
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int sizeEscouade);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSizeEscouade();

private : 
	int life;
	int dommage;
	int sizeEscouade;

};

