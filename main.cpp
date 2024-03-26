#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

//������������� ���.�������
int* initArray(int *M, int Size) {
    M = new int [Size];
    return M;
}

//������� ������
void deleteArray(int *M) {
    delete [] M; //�������� �������
}

//���������� ������� ����������  ������ �������
void fillArray(int *M, int Size) {
    for (int i = 0; i < Size; i++)
        *(M + i) = 10 + rand() % (50 - 10 + 1);
}

//����� ������� �� �����
void showArray(int *M, int Size) {
    for (int i = 0; i < Size; i++)
        cout << M[i] << " ";
    cout << "\n\n";
}

//�������� ����� �� ������� �����
bool isPrime (int number)
{
    int k = 0;
    for (int i = 1; i <= number; i++)
        if (number%i == 0)
            k++;
    return k == 2 ?  true : false;
}

//�������� ������� ����� �� �������
void delSimpleNumber(int*& M, int& Size) {

   // ������� ���������� ������� ����� � �������
   int m = 0;
   for (int i = 0; i < Size; i++)
   {
        if (isPrime(M[i]))
            m++; //���� ����� �������, ����������� ������� �� 1
   }

    int* newArray = nullptr; // ������� ����� ������
    newArray = initArray(newArray, Size - m); //�������������, ������ ������ �� m (���������� ������� �����
    int indexNewArray = 0; // ���������� ��� ���������� ������ �������

    //�������� ��� �����, ����� ������� � ����� ������
    for (int i = 0; i < Size; i++)
    {
           if (!isPrime(M[i])) //���� ����� �� �������, �������� � ����� ������
           newArray[indexNewArray++] = M[i];
    }
    deleteArray(M); //������� ������ ������
    M = newArray; //���������� ��������� �� ����� ������ (����� ����������� ������� ������)
    Size = Size - m; //��������� ������ �������
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int n = 10; // ����������� �������
    int *M = nullptr; // ���������� ���������
    int a = 10;
    int b = 50;

    M = initArray(M, n);
    fillArray(M, n);
    cout << "��������� ������:\n";
    showArray(M, n);

    delSimpleNumber(M, n);

    cout << "������ ����� ������ �� ������� �����:\n";
    showArray(M, n);

    deleteArray(M); // ����������� ������ ���������� ��� M

    return 0;
}
