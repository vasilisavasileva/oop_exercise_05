#include<iostream>
#include<algorithm>
#include<locale.h>
#include"Pentagon.h"
#include"stack.h"

void Menu1() {
	std::cout << "1. Добавить фигуру в стек\n";
	std::cout << "2. Удалить фигуру\n";
	std::cout << "3. Вывести фигуру\n";
	std::cout << "4. Вывести все фигуры\n";
	std::cout << "5. Вывести фигуру если площаль больше чем ...\n";
	std::cout << "6. Добавить фигуру по индексу\n";
}

void DeleteMenu() {
	std::cout << "1. Удалить фигуру в вершине стека\n";
	std::cout << "2. Удалить фигуру по индексу\n";
}

void PrintMenu() {
	std::cout << "1. Вывести первую фигуру в стеке\n";
	std::cout << "2. Вывести последнюю фигуру в стеке\n";
	//std::cout << "3. Вывести фигуру по индексу\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	containers::stack<Pentagon<int>> Mystack;
	
	Pentagon<int> TempPentagon;

	while (true) {
		Menu1();
		int n, m, in;
		size_t ind;
		double s;
		std::cin >> n;
		switch (n) {
		case 1:
			TempPentagon.Read(std::cin);
			TempPentagon.Print(std::cout);
			Mystack.push(TempPentagon);
			break;
		case 2:
			DeleteMenu();
			std::cin >> m;
			switch (m) {
			case 1:
				Mystack.pop();
				break;
			case 2:
				std::cin >> ind;
				Mystack.delete_by_index(ind);
				break;
			default:
				break;
			}
			break;
		case 3:
			PrintMenu();
			std::cin >> m;
			switch (m) {
			case 1:
				Mystack.bottom().Print(std::cout);
				std::cout << std::endl;
				break;
			case 2:
				Mystack.top().Print(std::cout);
				std::cout << std::endl;
				break;
			/*case 3:
				std::cin >> in;
				Mystack.print_by_index(in);
				break;*/
			default:
				break;
			}
			break;
		case 4:
			std::for_each(Mystack.begin(), Mystack.end(), [](Pentagon<int>& X) { X.Print(std::cout); std::cout << std::endl; });
			break;
		case 5:
			std::cin >> s;
			std::cout << std::count_if(Mystack.begin(), Mystack.end(), [=](Pentagon<int>& X) {return X.Area() > s; }) << std::endl;
			break;
		case 6:
			std::cout << "Введите индекс\n";
			std::cin >> ind;
			std::cout << "Введите координаты пентагона\n";
			TempPentagon.Read(std::cin);
			Mystack.insert_by_index(ind, TempPentagon);
			break;
		default:
			return 0;
		}
	}
	system("pause");
	return 0;
}