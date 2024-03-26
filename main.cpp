#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

//Инициализация дин.массива
int* initArray(int *M, int Size) {
    M = new int [Size];
    return M;
}

//очистка памяти
void deleteArray(int *M) {
    delete [] M; //удаление массива
}

//заполнение массива случайными  целыми числами
void fillArray(int *M, int Size) {
    for (int i = 0; i < Size; i++)
        *(M + i) = 10 + rand() % (50 - 10 + 1);
}

//вывод массива на экран
void showArray(int *M, int Size) {
    for (int i = 0; i < Size; i++)
        cout << M[i] << " ";
    cout << "\n\n";
}

//проверка числа на простое число
bool isPrime (int number)
{
    int k = 0;
    for (int i = 1; i <= number; i++)
        if (number%i == 0)
            k++;
    return k == 2 ?  true : false;
}

//удаление простых чисел из массива
void delSimpleNumber(int*& M, int& Size) {

   // считаем количество простых чисел в массиве
   int m = 0;
   for (int i = 0; i < Size; i++)
   {
        if (isPrime(M[i]))
            m++; //если число простое, увеличиваем счетчик на 1
   }

    int* newArray = nullptr; // создаем новый массив
    newArray = initArray(newArray, Size - m); //инициализация, размер меньше на m (количество простых чисел
    int indexNewArray = 0; // переменная для индексации нового массива

    //копируем все числа, кроме простых в новый массив
    for (int i = 0; i < Size; i++)
    {
           if (!isPrime(M[i])) //если число не простое, копируем в новый массив
           newArray[indexNewArray++] = M[i];
    }
    deleteArray(M); //удаляем старый массив
    M = newArray; //записываем указатель на новый массив (новая размеченная область памяти)
    Size = Size - m; //обновляем размер массива
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int n = 10; // размерность массива
    int *M = nullptr; // объявление указателя
    int a = 10;
    int b = 50;

    M = initArray(M, n);
    fillArray(M, n);
    cout << "Начальный массив:\n";
    showArray(M, n);

    delSimpleNumber(M, n);

    cout << "Массив после чистки от простых чисел:\n";
    showArray(M, n);

    deleteArray(M); // Освобождаем память выделенную под M

    return 0;
}
