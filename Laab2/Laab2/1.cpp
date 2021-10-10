/*
Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива.
*/

#include <iostream>
#include <random>

const int row = 9, column = 2;

class Vector
{
private:
	int size=18;
	
	int number;

	int* array;
public:
	

	Vector(int num = 0) : number(num)
	{
		
		array = new int[size];
	}
	
	

	int* Inicializ() {
		for (int i = 0;i < size;i++) {
			if (i % 2 == 0)
				*(array + i) = i * i + 1;
			else
				*(array + i) = (i * i + 1) * -1;
		}

		return array;
	}

	Vector& operator++();	//префикс
	Vector& operator--();	//префикс
	Vector operator++(int); //  постфикс
	Vector operator--(int); //  постфикс
	friend std::ostream& operator<< (std::ostream& out, const Vector& n);


	int operator[] ( int index);

	~Vector(){ delete[] array; }

};

Vector& Vector:: operator++() {
	for (int i = 0; i < sizeof(array) - 1; ++i) {
		array[i] += 1;
	}
	return *this;
}
Vector& Vector:: operator--() {
	for (int i = 0; i < sizeof(array) - 1; ++i) {
		array[i] -= 1;
	}
	return *this;
	
}
Vector Vector::operator--(int) {

	for (int i = 0; i < sizeof(array) - 1; ++i) {
		array[i] -= 1;
	}
	return *this;
}
Vector Vector::operator++(int) {

	for (int i = 0; i < sizeof(array) - 1; ++i) {
		array[i] += 1;
	}
	return *this;
}
std::ostream& operator<< (std::ostream& out, const Vector& n)
{
	out << n.number;
	return out;
}


int Vector::operator[] ( int index)
{
	return array[index];
}


class Matrix
{
private:

	int number;
	static const int row = 9, column = 2; 
	
	int** arr;
public:
	

	Matrix(int num = 0) : number(num)
	{
		 arr = new int* [row];
		for (int i = 0;i < row;++i) {
			arr[i] = new int[column];
		}
	}

	Matrix& operator++();	//префикс
	Matrix& operator--();	//префикс
	Matrix operator++(int); //  постфикс
	Matrix operator--(int); //  постфикс
	friend std::ostream& operator<< (std::ostream& out, const Matrix& n);

		

	int at(int i, int j) {
		return arr[i][j];
	}


	int setAt(int i, int j, int val) {

		arr[i][j] = val;

		return arr[i][j];
	
	}



	int printtt(int** array)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 2; j++)
				std::cout << *(*(array + i) + j) << " "; // array[i][j]
			std::cout << std::endl;
		}
		return 0;
	}

	int newArray(int* array)
	{
		for (int i = 1;i < 18;i++)
			for (int j = i;j > 0 && *(array + j - 1) < *(array + j);j--)
			{
				//swap(array[j - 1], x[j]);
				int temp = *(array + j - 1);
				*(array + j - 1) = *(array + j);
				*(array + j) = temp;

			}
		
		int k = 0;
		for (int i = 0; i < row;i++) {
			for (int j = 0;j < column;j++) {
				*(*(arr + i) + j) = *(array + k++);
			}
		}

		printtt(arr);
		return 0;
	}
	
	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
};

Matrix& Matrix:: operator++() {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			*(*(arr + i) + j) += 1;
		}
	}

	return *this;
}
Matrix& Matrix:: operator--() {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			*(*(arr + i) + j) -= 1;
		}
	}

	return *this;
}
Matrix Matrix::operator--(int) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			*(*(arr + i) + j) -= 1;
		}
	}

	return *this;
}
Matrix Matrix::operator++(int) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			*(*(arr + i) + j) += 1;
		}
	}

	return *this;
}
std::ostream& operator<< (std::ostream& out, const Matrix& n)
{
	out << n.number;
	return out;
}

int main()
{
	
	Vector * v = new Vector();
	Matrix * m = new Matrix();


	v->Inicializ();

	v++;
	++v;
	v--;
	--v;
	
	
	m->setAt(0, 1, 2);
	m->at(0, 1);
	m->newArray(v->Inicializ());

	m++;
	++m;
	--m;
	m--;


	return 0;
}


