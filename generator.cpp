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
            sequences.push_back(currentSequence); // ������� � ������
        } 
    
        count += 1; // ������� ���������� ������������
        printSequence();
    } while (next_permutation()); // ���������� ��������� ������������

}

bool Generator::next_permutation() 
{
    int i = n - 2; 
    while (i >= 0 && currentSequence[i] >= currentSequence[i + 1]) // ���� ������ ������� ������, ������� ������ �����������
    { 
        i--; 
    }

    if (i < 0) // ���� ������������ �������� ���������, ������� 
    { 
        return false; 
    } 

    int j = n - 1;
    while (j >= i && currentSequence[j] <= currentSequence[i]) // ���� ������� � ����� ����� �������� i-��
    { 
        j--; 
    } 
        
    swap(currentSequence[i], currentSequence[j]); // ������ i-�� � j-�� ��������
    reverse(currentSequence.begin() + i + 1, currentSequence.end()); // ��������� �����

    return true;
}

void Generator::permute(int l, int r) // ��������� ��������� � �������� �������
{
    if (l == r) // ���� ��� ������������ ������� 1 �������
    {
        if (saveFlag)
        {
            sequences.push_back(currentSequence); // ������� � ������
        }
        count += 1;
        printSequence();
    }
    else 
    {
        for (int i = l; i <= r; i++) 
        {
            sort(currentSequence.begin() + l + 1, currentSequence.end()); // ��������� � l + 1 �������� ��� ������������ ������ ������������
            swap(currentSequence[l], currentSequence[i]); // ��������� ������� �� ������ ������� ���������� (� �������� l), 
                                                          // ����� ���������� ��� ���������� �������� ����������, ����� �� ������� � ������������� ���������
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