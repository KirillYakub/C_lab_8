#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
    /* Создать однонаправленный список из целых чисел. Вставить числа 111 и 222 перед первым нулевым элементом. */

    //создаем список и итератор списка;
    forward_list <int> Numbers = { 5, 8, 0, -2, 9, 0, 6 };

    forward_list <int> ::iterator Place;

    cout << "Элементы списка перед добавлением: ";

    //выводим на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;

    //переводим итератор от начала на один символ вперед - перед первым нулевым элементом, добавляем элементы в список;
    Place = Numbers.begin();
    advance(Place, 1);
    Numbers.insert_after(Place, 222);
    Numbers.insert_after(Place, 111);

    cout << "Элементы после добавления: ";

    //выводим список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;
}

//если элемент больше 25 - функция вернет его для удаления из списка;
bool number_more_than_twentyfive(const double& number)
{
    return number > 25;
}

void medium()
{
    /*Дан однонаправленный список вещественных чисел. Найти среднее значение чисел меньших либо равных 15.
      Удалить из списка элементы, которые больше чем 25. */

    forward_list <double> Numbers = { 5, 8.2, 15.4, 9.1, 20.7, 26, 31.2, -4 };

    forward_list <double> ::iterator Place;

    double sum = 0;
    int count = 0;

    cout << "Изначальные элементы списка: ";

    //находим среднее значение элементов меньших либо равных 15;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
        if (*Place <= 15)
        {
            sum += *Place;
            count++;
        }
    }

    sum /= count;

    cout << endl << endl << "Среднее значение элементов меньших либо равных 15: " << sum << endl << endl;

    //удаляем элементы большие чем 25;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        Numbers.remove_if(number_more_than_twentyfive);
    }

    cout << "Элементы списка после удаления элементов больших чем 25: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;
}

void hard()
{
    /* Создать циклический двунаправленный список их целых чисел. Найти произведение четных элементов списка, добавить в конец списка данное произведение. */

    list <int> Numbers = { 5, 8, 16, 9, 21, 2, 1, -4 };

    list <int> ::iterator Place;

    list <int> ::reverse_iterator Place_1;

    int size = Numbers.size(), product = 1;

    cout << "Изначальный список: ";

    //выводим список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    advance(Place, -size);
    
    cout << endl << endl;

    //находим произведение четных чисел;
    for (Place_1 = Numbers.rbegin(); Place_1 != Numbers.rend(); Place_1++)
    {
        if (*Place_1 % 2 == 0)
        {
            product *= *Place_1;
        }

        if (*Place_1 == *Place)
        {
            advance(Place_1, -size + 1);
            break;
        }
    }
    
    cout << "Произведение четных элементов: " << product << endl << endl;

    //добавляем элемент в конец списка;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        if (*Place == *Place_1)
        {
            advance(Place, 1);
            Numbers.insert(Place, product);
            advance(Place, -size - 1);
            break;
        }
    }

    cout << "Список после добавления элемента: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}