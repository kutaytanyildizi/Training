#include <iostream>
#include <vector>

enum class GroceryItem { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

std::ostream& operator<<(std::ostream& os, GroceryItem groceryItem)
{
	std::underlying_type_t<GroceryItem> value = std::underlying_type_t<GroceryItem>(groceryItem);

	switch (groceryItem)
	{
		case GroceryItem::Milk:
			os << "Milk";
			break;
		case GroceryItem::Bread:
			os << "Bread";
			break;
		case GroceryItem::Apple:
			os << "Apple";
			break;
		case GroceryItem::Orange:
			os << "Orange";
			break;
		default:
			os << "Invalid Item";
			break;
	}
	os << " : " << value;
	return os;
}

bool isValidGroceryItem(GroceryItem groceryItem)
{
	switch (groceryItem)
	{
		case GroceryItem::Milk:
		case GroceryItem::Bread:
		case GroceryItem::Apple:
		case GroceryItem::Orange:	
			return true;
		default:
			return false;
	}
}

void displayGroceryList(const std::vector<GroceryItem>& groceryList)
{
	std::cout << "=================" << std::endl;

	int invalidItemCounter{ 0 };
	int validItemCounter{ 0 };

	for (GroceryItem groceryItem : groceryList)
	{
		std::cout << groceryItem << std::endl;

		if (isValidGroceryItem(groceryItem))
		{
			validItemCounter++;
		}
		else
		{
			invalidItemCounter++;
		}
	}

	std::cout << "=================" << std::endl;
	std::cout << "Valid Items : " << validItemCounter << std::endl;
	std::cout << "Invalid Items : " << invalidItemCounter << std::endl;
	std::cout << "Total Items : " << validItemCounter + invalidItemCounter << std::endl;
}

void useOfScopedEnumsWithOverloadedInsertionOperator()
{
	std::cout << "*****Use of Scoped Enums with Overloaded Insertion Operators*****" << std::endl;

	std::vector<GroceryItem> shoppingList;

	shoppingList.push_back(GroceryItem::Apple);
	shoppingList.push_back(GroceryItem::Milk);
	shoppingList.push_back(GroceryItem::Orange);

	int Helicopter{ 1000 };

	//shoppingList.push_back(Helicopter); // This statement generates a compile error
	shoppingList.push_back(GroceryItem(Helicopter));
	shoppingList.push_back(GroceryItem(350));

	displayGroceryList(shoppingList);

	std::cout << "*****************************************************************" << std::endl;
	std::cout << std::endl;
}

class Player
{
private:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);

public:
	enum class Mode { Attack, Defense, Idle };
	enum class Direction { North, South, East, West };

	Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North) :
		name{ name }, mode{ mode }, direction{ direction } {}

	std::string get_name() const {
		return name;
	}
	void set_name(std::string name) {
		this->name = name;
	}

	Mode get_mode() const { return mode; }
	void set_mode(Mode mode) {
		this->mode = mode;
	}

	Direction get_direction() const { return direction; }
	void set_direction(Direction direction) {
		this->direction = direction;
	}
private:
	std::string name;
	Mode mode;
	Direction direction;
};

std::string get_player_mode(Player::Mode mode) 
{
	std::string result;
	switch (mode) {
	case Player::Mode::Attack:
		result = "Attack";
		break;
	case Player::Mode::Defense:
		result = "Defense";
		break;
	case Player::Mode::Idle:
		result = "Idle";
		break;
	};
	return result;
}

std::string get_player_direction(Player::Direction direction) 
{
	std::string result;
	switch (direction) {
	case Player::Direction::North:
		result = "North";
		break;
	case Player::Direction::South:
		result = "South";
		break;
	case Player::Direction::East:
		result = "East";
		break;
	case Player::Direction::West:
		result = "West";
		break;
	};
	return result;
}

std::ostream& operator<<(std::ostream& os, const Player& p) 
{
	os << "Player name:      " << p.get_name() << "\n"
	   << "Player mode:      " << get_player_mode(p.mode) << "\n"
	   << "Player direction: " << get_player_direction(p.direction)
	   << std::endl;
	return os;
}

void useOfScopedEnumsWithPlayerClass()
{
	std::cout << "*****Use of Scoped Enums with Player Class*****" << std::endl;

	Player p1{ "Cloud Strife", Player::Mode::Attack, Player::Direction::North };
	Player p2{ "Tifa Lockhart", Player::Mode::Defense, Player::Direction::West };
	Player p3{ "Sephiroth", Player::Mode::Idle, Player::Direction::South };

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;

	std::cout << "***********************************************" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "*********SCOPED ENUMS**********" << std::endl;

	useOfScopedEnumsWithOverloadedInsertionOperator();
	useOfScopedEnumsWithPlayerClass();

	return 0;
}