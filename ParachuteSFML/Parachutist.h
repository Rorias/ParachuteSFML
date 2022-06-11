#pragma once
#include "Position.h"

class Parachutist : public Position
{
public:
	Parachutist();
	~Parachutist();

	void Display();
	void Move();
	void Destroy();

private:

};

