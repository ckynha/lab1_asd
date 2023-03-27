#include <iostream>
#include <vector>
#include <algorithm>
#include "generator.h"

using namespace std;

void Generator::generate()
{
    do 
    {
        if (saveFlag) 
        { 
            sequences.push_back(currentSequence); // заносим в список
        } 
    
        count += 1; // считаем количество перестановок
        printSequence();
    } while (next_permutation()); // генерируем следующую перестановку

}

bool Generator::next_permutation() 
{
    int i = n - 2; 
    while (i >= 0 && currentSequence[i] >= currentSequence[i + 1]) // ищем первый элемент справа, который меньше предыдущего
    { 
        i--; 
    }

    if (i < 0) // если перестановка является последней, выходим 
    { 
        return false; 
    } 

    int j = n - 1;
    while (j >= i && currentSequence[j] <= currentSequence[i]) // ищем элемент с каким нужно поменять i-ый
    { 
        j--; 
    } 
        
    swap(currentSequence[i], currentSequence[j]); // меняем i-ый и j-ый элементы
    reverse(currentSequence.begin() + i + 1, currentSequence.end()); // сортируем хвост

    return true;
}

void Generator::permute(int l, int r) // принимаем начальные и конечные индексы
{
    if (l == r) // если для перестановки остался 1 элемент
    {
        if (saveFlag)
        {
            sequences.push_back(currentSequence); // заносим в список
        }
        count += 1;
        printSequence();
    }
    else 
    {
        for (int i = l; i <= r; i++) 
        {
            sort(currentSequence.begin() + l + 1, currentSequence.end()); // сортируем с l + 1 элемента для уникальности каждой перестановки
            swap(currentSequence[l], currentSequence[i]); // фиксируем элемент на первой позиции подмассива (с индексом l), 
                                                          // затем перебираем все оставшиеся элементы подмассива, меняя их местами с фиксированным элементом
            permute(l + 1, r);
        }
    }
}

void Generator::setSaveFlag(bool flag)
{
    saveFlag = flag;
}

void Generator::printSequence()
{
    if (printFlag)
    {
        for (int i = 0; i < n; i++)
        {
            cout << currentSequence[i] << " ";
        }
        cout << endl;
    }
}