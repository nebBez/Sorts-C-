/*

#include <iostream>
#define print(x) std::cout << x << std::endl


class Player
{
public:
	int x, y;
	int speed;

	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}

};

int main()
{
/*
	******LESSON 1 Control statements*****

	int x = 7;
	bool comparison = x == 5;
	if (comparison)
	{
		std::cout << "True";
	}
	else if(!comparison)
		std::cout << "False";

	else
		if(comparison == 1)
			std::cout << "weird huh?";
		else
			std::cout << "Done";
*/
/* LESSON 2: Loops
	bool user;

	std::cout << "Enter 1 for cool 0 for not"; 
	std::cin >> user;
	if (user)
	{
		int i = 0;
		bool condistion = i < 5; 
		for (;condistion;)
		{
			std::cout << 5;
			i++;
			condistion = i < 5;
		}
		std::cout << "Done 1";
	}

	else if (!user)
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << 5;
		}
		std::cout << "Boring done 0"
			;
	}
	while (user < 5);
	{
		std::cout << "Yea";
		user++;
	}

	do
	{
		std::cout << "This gets printed no matter what";

	} while (user < 10);
	{
		std::cout << "while this goes tille condition not met";
		user++;
	}
	std::cout << "continue = continue/restart loop from this point";
	std::cout << "break = end look right now";
	std::cout << "return = this is what is stored in me... end loop";
*/
/* LESSON 3: Pointsers and references

	int var = 8;
	void* ptr = &var;

	int a = 5;
	print(a);
	int& ref = a;
	print(a);

	print(a);
	print(ref);
	ref = 2;
	print(a);
	print(&ref);
	print(&a);
*//*

	Player Player1;
	Player1.x = 5;
	Player1.y = 6;
	Player1.Move(4, 5);
}

*/