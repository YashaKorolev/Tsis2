#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <iomanip>




double f(double x) {

	return cos(x) * tanh(x);
}

double f2(double x) {

	return cos(x) * tanh(x) * sin(5 * x);
}
double N(double q, double P) {
	return log(1 - P) / log(1 - q);
}

double fv(int x)
{
	double l = 1.5;
	double d = 2.5;

	return f(l + (d * x / 10001));
}
double fv2(int x)
{
	double l = 1.5;
	double d = 2.5;

	return f2(l + (d * x / 10001));
}
int main()
{

	srand(time(0));

	double a = 1.5;
	double b = 4.0;

	std::vector<double> P;
	std::vector<double> q;

	std::vector<double> Pq;
	std::vector<double> Pq2;


	double x = 0.9;
	for (int i = 0; i < 10; i++)
	{
		P.push_back(x);
		x += 0.01;
	}

	x = 0.005;
	for (int i = 0; i < 20; i++)
	{
		q.push_back(x);
		x += 0.005;
	}
	std::cout << "Dependence of N on P and q" << std::endl;
	std::cout << "|q\\P     ||";
	std::cout << std::fixed << std::setprecision(3);
	for (auto it3 = P.begin(); it3 != P.end(); it3++) {
		std::cout << *it3 << "|";
	}

	std::cout << std::endl;
	std::cout << "______________________________________________________________________" << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	for (std::vector<double>::iterator it_q = q.begin(); it_q != q.end(); it_q++) {
		std::cout << (*it_q) << "  |";
		for (std::vector<double>::iterator it_P = P.begin(); it_P != P.end(); it_P++) {
			int NqP = (int)ceil(N(*it_q, *it_P));
			std::cout << "|";
			printf("%5d", NqP);
			//std::cout << "|";
			double min1 = fv(rand() % 10000);
			double min2 = fv2(rand() % 10000);
			for (int i = 0; i < NqP; i++)
			{


				double r = fv(rand() % 10000);
				if (r < min1)min1 = r;

				r = fv2(rand() % 10000);
				if (r < min2)min2 = r;


			}

			Pq.push_back(min1);
			Pq2.push_back(min2);



		}

		std::cout << std::endl;


	}
	std::cout << std::endl << std::endl;
	std::cout << "f(x)=cos(x) * tanh(x)" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "|q\\P     ||";
	for (auto it3 = P.begin(); it3 != P.end(); it3++) {
		std::cout << *it3 << " |";
	}
	std::cout << std::endl;
	std::cout << "____________________________________________________________________________________________________" << std::endl;
	std::vector<double>::iterator it_Pq = Pq.begin();
	for (std::vector<double>::iterator it_q = q.begin(); it_q != q.end(); it_q++) {
		std::cout << (*it_q) << "  |";
		for (std::vector<double>::iterator it_P = P.begin(); it_P != P.end(); it_P++) {
			std::cout << "|";
			printf("%8.5lf", *it_Pq);
			//std::cout << "|";
			it_Pq++;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "f(x)=cos(x) * tanh(x)*sin(5x)" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "|q\\P     ||";
	for (auto it3 = P.begin(); it3 != P.end(); it3++) {

		std::cout << *it3 << " |";
	}
	std::cout << std::endl;
	std::cout << "____________________________________________________________________________________________________" << std::endl;
	std::vector<double>::iterator it_Pq2 = Pq2.begin();

	for (std::vector<double>::iterator it_q = q.begin(); it_q != q.end(); it_q++) {

		std::cout << (*it_q) << "  |";

		for (std::vector<double>::iterator it_P = P.begin(); it_P != P.end(); it_P++) {
			std::cout << "|";
			printf("%8.5lf", *it_Pq2);
			//std::cout << "|";
			it_Pq2++;
		}
		std::cout << std::endl;
	}

	system("pause");


}
