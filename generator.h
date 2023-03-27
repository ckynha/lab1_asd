#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Generator
{
public:
    Generator(int n, bool printFlag = false) : n(n),  printFlag(printFlag)
    {
        currentSequence.resize(n);
        for (int i = 0; i < n; i++)
        {
            currentSequence[i] = i + 1; // заполняем массив от 1 до n
        }
    }

    void generate();

    void permute(int l, int r);

    void setSaveFlag(bool flag);

    int getCount()
    {
        return count;
    }

    vector<vector<int>> getSequences()
    {
        return sequences;
    }

private:
    bool next_permutation();

    void printSequence();

    int n, count = 0;
    bool printFlag = false;
    bool saveFlag = false;
    vector<int> currentSequence;
    vector<vector<int>> sequences;
};
