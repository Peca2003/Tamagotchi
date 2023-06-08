#include <iostream>
using namespace std;
class Critter
{
public:
	Critter(int hunger = 10, int boredom = 10);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
private:
	int m_Hunger;
	int m_Boredom;
	int GetMood() const;
	void PassTime(int time = 1);
};
Critter::Critter(int hunger, int boredom):
	m_Hunger(hunger),
	m_Boredom(boredom)
{}
inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}
void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}
void Critter::Talk()
{
	cout << "Я тварь, и я чувствую себя ";
	int mood = GetMood();
	if (mood > 15) { cout << "сумасшедшей.\n"; }
	else if (mood > 10) { cout << "недовольной.\n"; }
	else if (mood > 5) { cout << "хорошо.\n"; }
	else { cout << "счастливой.\n"; }
	PassTime();
}
void Critter::Eat(int food)
{
	cout << "Бррупппп.\n";
	m_Hunger -= food;
	if (m_Hunger < 0) { m_Hunger = 0; }
	PassTime();
}
void Critter::Play(int fun)
{
	cout << "Уиииии!.\n";
	m_Boredom -= fun;
	if (m_Boredom < 0) { m_Boredom = 0; }
	PassTime();
}
int main()
{
	setlocale(LC_ALL, "rus");
	Critter crit;
	crit.Talk();
	int choice;
	do
	{
		cout << "\nСмотритель за тварями\n\n";
		cout << "0 - Выход\n";
		cout << "1 - Выслушать своё существо\n";
		cout << "2 - Накормить свою зверушку\n";
		cout << "3 - Поиграть со своим питомцем\n\n";
		cout << "Выбор: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				cout << "Прощай, живодёр!\n";
				break;
			case 1:
				crit.Talk();
				break;
			case 2:
				crit.Eat();
				break;
			case 3:
				crit.Play();
				break;
			default:
				cout << "\nИдиот, варианта № " << choice << " нет!\n";
		}
	} while (choice != 0);
	return 0;
}