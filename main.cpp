#include <iostream>
#include "generator.h"

using namespace std;

int main()
{
    Generator g(4, true);
    g.setSaveFlag(true);
    g.generate();
    cout << g.getCount() << endl;
    return 0;
}
