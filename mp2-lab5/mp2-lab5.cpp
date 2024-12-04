#include "TQueue.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	TQueue<int> q1(15);
	
	/*
	q1.Push(5);
	q1.Push(7);
	q1.Push(6);
	q1.Push(4);
	q1.Push(7);
	q1.Push(1);
	q1.Push(5);
	
	int* arr = new int[q1.getCounterSize()];
	q1.getQ(arr);
	
	for (int i = 0; i < q1.getCounterSize(); i++)
		std::cout << arr[i] << " ";
	*/

	double p = 0.0;
	double q = 0.0;
	std::cout << "Введите вероятность добавления задачи P (0, 100): "; std::cin >> p;
	std::cout << std::endl << "Введите вероятность извлечения задачи Q (0, 100): "; std::cin >> q;

	int countPushSuccess = 0;
	int countPopSuccess = 0;
	int countPushExcept = 0;
	int countPopExcept = 0;

	for (int i = 0; i < 100; i++) {
		int randNumPush = rand() % 100;
		if (randNumPush < p) {
			try {
				q1.Push(i);
				countPushSuccess++;
				std::cout << randNumPush << " < " << p << ", добавить " << i << std::endl;
			}
			catch (...) {
				countPushExcept++;
				std::cout << "Очередь полна, не могу добавить" << std::endl;
			}
		}

		int randNumPop = rand() % 100;
		int tmp = 0;
		if (randNumPop < q) 
			try {
				tmp = q1.Pop();
				countPopSuccess++;
				std::cout << randNumPop << " < " << q << " изъять " << tmp << std::endl;
			}
			catch (...) {
				countPopExcept++;
				std::cout << "Очередь пуста, не могу изъять" << std::endl;
			}
	}

	std::cout << "countPushSuccess = " << countPushSuccess << std::endl;
	std::cout << "countPopSuccess = " << countPopSuccess << std::endl;
	std::cout << "countPushExcept = " << countPushExcept << std::endl;
	std::cout << "countPopExcept = " << countPopExcept << std::endl;
}