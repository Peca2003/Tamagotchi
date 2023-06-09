#include <iostream>
#include <ctime>
using namespace std;
class Critter
{
public:
	Critter(int hunger = 7, int boredom = 7, int health = 7);
	void Talk();
	void Eat(int food = 5);
	void Play(int fun = 5);
	void Hit(int hurt = 6);
	void Shoot(int damage = 8);
	void Cure(int hp = 5);
	int GetHunger() const;
	int GetBoredom() const;
	int GetHealth() const;
	void Communication() const;
private:
	int m_Hunger;
	int m_Boredom;
	int m_Health;
	string m_DialogOptions[10] = {
		"Yo wassup?\n",
		"Я полагаю, что европейцы опасны и волосаты\n",
		"Штирлиц и Мюллер ездили по очереди на танке. Очередь редела, но не расходилась.\n",
		"Отпусти меня на свободу!\n",
		"Smart nigga shit, 2+2 = 5 тыщ.\n",
		"А, может быть, забудем всё и сбежим?\n",
		"При солнечных затмениях люди замечают похолодание раньше, чем потемнение неба.\n",
		"АУЕ для быдла\n",
		"Влад петушок\n",
		"Slap my ass\n"};
	int GetMood() const;
	void PassTime(int time = 1);
};
Critter::Critter(int hunger, int boredom, int  health):
	m_Hunger(hunger),
	m_Boredom(boredom),
	m_Health(health)
{}
inline int Critter::GetMood() const { return (m_Hunger + m_Boredom + m_Health); }
inline int Critter::GetHunger() const { return m_Hunger; }
inline int Critter::GetBoredom() const { return m_Boredom; }
inline int Critter::GetHealth() const { return m_Health; }
void Critter::Communication() const 
{ 
	cout << m_DialogOptions[rand() % 10];
}
void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
	m_Health += time;
}
void Critter::Talk()
{
	cout << "Я тварь, и я чувствую себя ";
	int mood = GetMood();
	if (mood > 18) { cout << "сумасшедшей.\n"; }
	else if (mood > 13) { cout << "недовольной.\n"; }
	else if (mood > 8) { cout << "хорошо.\n"; }
	else { cout << "счастливой.\n"; }
	cout << "Уровень голода: " << GetHunger() << "\tУровень скуки: " << GetBoredom() << "\tУровень здоровья: " << GetHealth() << "\n\n";
	Communication();
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
	cout << "Уиииии!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0) { m_Boredom = 0; }
	PassTime();
}
void Critter::Hit(int hurt)
{
	cout << "Не бей меня, мне больно!\n";
	m_Health += hurt;
	if (m_Health < 0) { m_Health = 0; }
	PassTime();
}
void Critter::Shoot(int damage)
{
	cout << "Ааааааааааа!\n";
	m_Health += damage;
	if (m_Health < 0) { m_Health = 0; }
	PassTime();
}
void Critter::Cure(int hp)
{
	cout << "Ъуъ!\n";
	m_Health -= hp;
	if (m_Health < 0) { m_Health = 0; }
	PassTime();
}
int main()
{
	srand(time(0));
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
		cout << "3 - Поиграть со своим питомцем\n";
		cout << "4 - Ударить свою лучшую и любимую зверушку\n";
		cout << "5 - Выстрелить в своего единственного и верного друга\n";
		cout << "6 - Вылечить своё существо\n";
		cout << "Выбор: ";
		cin >> choice;
		cout << "\n\n";
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
			case 4:
				crit.Hit();
				break;
			case 5:
				crit.Shoot();
				break;
			case 6:
				crit.Cure();
				break;
			default:
				cout << "\nИдиот, варианта № " << choice << " нет!\n";
		}
	} while (choice != 0);
	return 0;
}
