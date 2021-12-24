// task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int InputValidation();
void ArrRand(int* arr_, int size_);
void PrintArr(int* arr_, int size_);
int InteralElementsRight(int* arr_, int size_);
int InteralElementsLeft(int* arr_, int size_);

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Введите размер массива: ";
    int sizeArr = InputValidation();

    int* arr = new int[sizeArr];
    ArrRand(arr, sizeArr);
    PrintArr(arr, sizeArr);
    cout << endl << "Перед первым элементом  " << arr[0] << " и перед последнего элемента " << arr[sizeArr - 1] << " элемент: ";
    if (arr[0] < arr[sizeArr - 1])
        cout << InteralElementsRight(arr, sizeArr);
    else
        cout << InteralElementsLeft(arr, sizeArr);

    return 0;
}

int InputValidation() // проверка корректности введенного значения 
{
    bool isCorrectInput = false; // значение изначально ложно
    int element;
    do
    {
        std::cin >> element; // ввод элемента
        if (std::cin.fail()) //проверка элемента 

        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Input error! Enter again" << std::endl; // вывод ошибки
        }
        else
            isCorrectInput = true; // если элемент прошел проверку на корректное значение, то значение меняется на истинное
    } while (!isCorrectInput);

    return element;
}

void ArrRand(int* arr_, int size_) // функция заполнения массива случайными числами 
{
    for (int i = 0; i < size_; i++)
        arr_[i] = InputValidation();
}

void PrintArr(int* arr_, int size_)  // функция вывода массива
{
    cout << "Массив : ";
    for (int i = 0; i < size_; i++)
        cout << arr_[i] << " ";
}

int InteralElementsRight(int* arr_, int size_) // Если от 1 до 5
{
    int res = 0;
    bool isChech = false;
    for (int i = 1; i < size_ - 2 && !isChech; i++) {
        if (arr_[0]<arr_[i] && arr_[size_ - 1]> arr_[i]) {
            res = i;
            isChech = true;
        }
    }
    return res;
}

int InteralElementsLeft(int* arr_, int size_) // Если от 5  до 1
{
    int res = 0;
    bool isCheck = false;
    for (int i = size_ - 1; i > 0 && !isCheck; i--) {
        if (arr_[0] > arr_[i] && arr_[size_ - 1] < arr_[i])
        {
            res = i;
            isCheck = true;
        }
    }
    return res;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
