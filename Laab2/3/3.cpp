/*
Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных. Класс должен содержать метод serialize() для
сохранения данных класса в файл и метод deserialize() для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
serialize(const std::string& filename) и deserialize(const std::string&
filename) для работы с файлом с указанным в параметре именем.

Класс КОНДИЦИОНЕР.
Данные: фирма, модель, вес, температура, режим, год выпуска.
Создать 2 кондиционера в куче и проинициализировать их с помощью конструкторов с
параметрами. Еще один кондиционер создать отдельно в стеке и установить его данные
с помощью сеттеров. В главной функции проимитировать настройку кондиционеров
персоналом помещений – установить каждому режим; если выбран режим охлаждения,
то установить также температуру. Проделать эту процедуру три раза. Вывести
информацию об использовании кондиционеров – режим, в котором на данный момент
работает техника, среднее изменение температуры за весь период настройки.

*/


#include <iostream>
#include <string>
#include <fstream>

class Condition {

public:

	const char* firma;
	const char* model;
	double ves;
	double temp;
	int rezhim;
	int year;
	double* array;


	static int count() {
		static int count = 0;
		return count++;
	}

	Condition(const char* firm, const char * modelC, double vesC, double tempC, int rezhimC, int yearC) {
		firma = firm;
		model = modelC;
		ves = vesC;
		temp = tempC;
		rezhim = rezhimC;
		year = yearC;

		count();
	}

	Condition(const char* firm, const char* modelC, double vesC,  int yearC) {
		firma = firm;
		model = modelC;
		ves = vesC;
		year = yearC;

		count();
	}


	Condition() {
		firma = "Ford";
		model = "S5";
		ves = 63.7;
		temp = 5.7;
		rezhim = 1;
		year = 2021;

		count();
	}


	void setcond( const char firm[],  const char setmodel[], double setves, double settemp, int setrezhim, int setyear) {
		firma = firm;
		model = setmodel;
		ves = setves;
		temp = settemp;
		rezhim = setrezhim;
		year = setyear;

		count();
	}

	void getCond() {
		std::cout << firma << "\n";
		std::cout << model << "\n";
		std::cout << ves << "\n";
		if(temp !=0)
			std::cout << temp << "\n";
		if(rezhim !=0)
			std::cout << rezhim << "\n";
		std::cout << year << "\n";
	}




	void serialize() {
		std::ofstream out("D:\\file.txt", std::ios::app);
		if (out.is_open())
		{
	

			out << firma << std::endl;
			out << model << std::endl;
			out << ves << std::endl;
			if (temp != 0)
				out << temp<< std::endl;
			if (rezhim != 0)
				out << rezhim << std::endl;
			out << year << std::endl;
		}
		out.close();
	}


	void deserialize() {
		std::string line;

		std::ifstream in("D:\\file.txt"); 
		if (in.is_open())
		{
			while (getline(in, line))
			{
				std::cout << line << std::endl;
			}
		}
		in.close();     

	}

	void serialize(const std::string& filename) {
		std::ofstream out(filename, std::ios::app);
		if (out.is_open())
		{


			out << firma << std::endl;
			out << model << std::endl;
			out << ves << std::endl;
			if (temp != 0)
				out << temp << std::endl;
			if (rezhim != 0)
				out << rezhim << std::endl;
			out << year << std::endl;
		}
		out.close();
	}

	void deserialize(const std::string& filename) {
		std::string line;

		std::ifstream in(filename);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				std::cout << line << std::endl;
			}
		}
		in.close();
	}
	

};


void medianaTemp(double* arr) {
	double summm = 0;
	int n = sizeof(arr);
	arr = new double[n];
	if (n % 2 == 0) {
		std::cout << arr[n / 2];
	}
	else {
		std::cout << (arr[n / 2] + arr[n / 2 + 1]) / 2;
	}

}



int main() {

	

	setlocale(LC_ALL, "");
	double* array = new double[100];
	int count = 0;
	Condition c1 = Condition("Firma", "C4", 44.6,5.0, 1, 2019);
	c1.getCond();
	array[++count] = c1.temp;
	c1.serialize();

	Condition c2 = Condition();
	c2.getCond();
	array[++count] = c2.temp;
	c2.serialize();

	Condition c3;
	c3.firma = "ABOBA";
	c3.model = "F5";
	c3.ves = 56.4;
	c3.temp = -3.0;
	c3.rezhim = 0;
	c3.year = 2020;
	c3.getCond();
	array[++count] = c3.temp;

	std::cout << "\n";
	Condition c4 = Condition("Sda", "4", 34.9, 2007);
	c4.getCond();
	array[++count] = c4.temp;

	Condition c5;
	c5.setcond("asd", "5", 75.0, -15.0, 0, 2005);
	c5.getCond();
	array[++count] = c5.temp;

	std::cout << "Режим техники: " << c1.rezhim << " " << c2.rezhim << " " << c3.rezhim << " " << c4.rezhim << " " << c5.rezhim;
	medianaTemp(array);

	std::cout << "\n";

	c1.deserialize();


	return 0;
}