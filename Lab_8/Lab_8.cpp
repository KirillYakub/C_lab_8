#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
    /* Создать список из целых чисел. Вставить числа 111 и 222 перед первым нулевым элементом. */

    //создаем список и итератор списка;
    list <int> Numbers = { 5, 8, 0, -2, 9, 0, 6 };

    list <int> ::iterator Place;

    cout << "Элементы списка перед добавлением: ";

    //выводи на экран изначальный список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;

    //переводим итератор от начала на два символа вперед, добавляем элементы в список;
    Place = Numbers.begin();
    std::advance(Place, 2);
    Numbers.insert(Place, 111);
    Numbers.insert(Place, 222);

    cout << "Элементы после добавления: ";

    //выводим список;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;
}

//если элемент больше 25 - функция вернет его для удаления из списка;
bool number_single(const double& val)
{
    return val > 25;
}

void medium()
{
    /*Дан список вещественных чисел. Найти среднее значение чисел меньших либо равных 15.
      Удалить из списка элементы, которые больше чем 25. */

    list <double> Numbers = { 5, 8.2, 15.4, 9.1, 20.7, 26, 31.2, -4 };

    list <double> ::iterator Place;

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
        Numbers.remove_if(number_single);
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
    /* Создать циклический список их целых чисел. Найти произведение четных элементов списка, добавить в конец списка данное произведение. */

    list <int> Numbers = { 5, 8, 16, 9, 21, 2, 1, -4 };

    list <int> ::iterator Place, Place_1;

    int size, product = 1;

    /* Когда итератор Place дойдет до конца списка, то он переместиться в начало этого списка.
       Цикл будет продолжаться пока доп. итератор Place_1, находящийся в начале списка
       и Place не будут равны - итератор перешел к первому элементу через последний. */
    do
    {
        Place_1 = Numbers.begin();

        cout << "Изначальный список: ";

        //находим произведение четных чисел;
        for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
        {
            cout << *Place << " ";

            if (*Place % 2 == 0)
            {
                product *= *Place;
            }
        }

        cout << endl << endl << "Произведение четных элементов: " << product << endl << endl;

        //смавим произведение в конец списка;
        Numbers.insert(Place, product);

        size = Numbers.size();

        //перемещаем итератор в начало списка;
        std::advance(Place, -size);
       
    } while (Place != Place_1);

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



