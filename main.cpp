#include <iostream>
#include <string>
#include <cstdint>

//////////////////////////////////////////////////////////////////////////
// 2.1
//////////////////////////////////////////////////////////////////////////

class Person {

protected:
	std::string _name{"default"};
	uint8_t _age{ 0 };
	uint8_t _weight{ 0 };
	uint8_t _sex : 1;

public:
	Person(const std::string& name, const uint8_t& sex, const uint8_t& age, const uint8_t& weight)
		: _name(name), _sex(sex), _age(age), _weight(weight) {};

	const std::string GetName() const { return _name; };

	void SetName(const std::string& name) { _name = name; };
	void SetAge(const uint8_t& age) { _age = age; };
	void SetWeight(const uint8_t& weight) { _weight = weight; };
};

class Student : protected Person {

protected:
	uint16_t _year{ 0 };
	static uint16_t _count;

public:
	Student(const std::string& name, const uint8_t& sex, const uint8_t& age, const uint8_t& weight, const uint16_t& year)
		: Person(name, sex, age, weight), _year(year) {
		_count++;
	};

	~Student() { _count--; };

	static const uint16_t GetCount() { return _count; };
	void PrintInfo() const;

	void SetYear(const uint16_t& year) { _year = year; };
	void AddYear() { _year++; };
};

void Student::PrintInfo() const {

	std::cout << "\nStudent: "	<< _name << std::endl;
	std::cout << "Sex: "		<< (_sex ? "female" : "male") << std::endl;
	std::cout << "Age: "		<< static_cast<int>(_age) << std::endl;
	std::cout << "Weight: "		<< static_cast<int>(_weight) << std::endl;
	std::cout << "Study year: "	<< static_cast<int>(_year)<< std::endl;
};

uint16_t Student::_count{ 0 };

//////////////////////////////////////////////////////////////////////////
// 2.2
//////////////////////////////////////////////////////////////////////////

class Fruit {

protected:
	std::string _name{ "" };
	std::string _color{ "" };

	Fruit(const char* name, const char* color) : _name(name), _color(color) {};

public:
	const std::string GetName() const { return _name; };
	const std::string GetColor() const { return _color; };
};

class Apple : public Fruit {

public:
	Apple(const char* color) : Fruit("apple", color) {};
	Apple(const char* name, const char* color) : Fruit(name, color) {};
};

class Banana : public Fruit {

public:
	Banana() : Fruit("banana", "yellow") {};
};

class GrannySmith : public Apple {

public:
	GrannySmith() : Apple("Granny Smith apple", "green") {};
};

//////////////////////////////////////////////////////////////////////////
// 2.3
//////////////////////////////////////////////////////////////////////////

enum class EGameState {};

class Card {

protected:
	std::string sName{ "" };
	uint8_t nValue{ 0 };
	uint8_t bFlipped : 1;
};

class Deck {

protected:
	Card* cards[100];
};

class Hand : public Deck {};

class Entity {

protected:
	Hand* hand{};
	uint8_t nHandCount{ 0 };
};

class Player : public Entity {

protected:
	static uint8_t _playerCount;

public:
	Player() { _playerCount++; };
	~Player() { _playerCount--; };
};

class AI : public Entity {};

class GameInstance {

protected:
	AI* AI;
	Player* Player;
	Entity* ActivePlayer;
	EGameState GameState;
	uint8_t nTurnCount{ 0 };
};

uint8_t Player::_playerCount{ 0 };


int main() {

	//////////////////////////////////////////////////////////////////////////
	// 2.1
	//////////////////////////////////////////////////////////////////////////

	Student s1("Ivan", 0, 18, 72, 1);
	Student s2("Olya", 1, 19, 60, 1);
	Student s3("Victoria", 1, 22, 56, 3);
	Student s4("Dmitry", 0, 21, 87, 4);
	Student s5("Petr", 0, 23, 90, 4);

	std::cout << "There are " << Student::GetCount() << " students!\n";

	s3.PrintInfo();
	s5.PrintInfo();

	//////////////////////////////////////////////////////////////////////////
	// 2.2
	//////////////////////////////////////////////////////////////////////////

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.GetName() << " is " << a.GetColor() << ".\n";
	std::cout << "My " << b.GetName() << " is " << b.GetColor() << ".\n";
	std::cout << "My " << c.GetName() << " is " << c.GetColor() << ".\n";

	return 0;
}
