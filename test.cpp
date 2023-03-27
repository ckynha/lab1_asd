#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "generator.h"
#include <vector>

using namespace std;

int factorial(int n)
{
    int result = 1; 
    for (int i = 1; i <= n; i++) 
    {
        result = result * i; 
    }
    return result; 
}

TEST_CASE("Sequences Test", "[vector]")
{
    // нерекурсивный случай
    int n = 4;
    
	Generator g(n, true);
    g.setSaveFlag(true);
	g.generate();

    vector<vector<int>> seq = g.getSequences();
    vector<int> seq0 = { 1, 2, 3, 4 };
    vector<int> seq1 = { 1, 2, 4, 3 };
    vector<int> seq2 = { 1, 3, 2, 4 };
    

	REQUIRE(g.getCount() == factorial(n));
    REQUIRE(seq[0] == seq0);
    REQUIRE(seq[1] == seq1);
    REQUIRE(seq[2] == seq2);

    // нерекурсивный случай #2
    n = 3;

    Generator g2(n, true);
    g2.setSaveFlag(true);
    g2.generate();

    seq = g2.getSequences();
    seq0 = { 1, 2, 3 };
    seq1 = { 1, 3, 2 };
    seq2 = { 2, 1, 3 };

    REQUIRE(g2.getCount() == factorial(n));
    REQUIRE(seq[0] == seq0);
    REQUIRE(seq[1] == seq1);
    REQUIRE(seq[2] == seq2);
    
    // рекурсивный случай
    n = 3;

    Generator g3(n, true);
    g3.setSaveFlag(true);
    g3.permute(0, n - 1);

    vector<vector<int>> seq_2 = g3.getSequences();
    seq0 = { 1, 2, 3 };
    seq1 = { 1, 3, 2 };
    seq2 = { 2, 1, 3 };
    
    REQUIRE(g3.getCount() == factorial(n));
    REQUIRE(seq_2[0] == seq0);
    REQUIRE(seq_2[1] == seq1);
    REQUIRE(seq_2[2] == seq2);

    REQUIRE(seq_2 == seq); // проверка рекурсивного и нерекурсивного способа



    //REQUIRE();
    
}
