/**
 * Nick Galvez
 * 210 lab 37
 */
#include <iostream>
#include <fstream>

using namespace std;

int sum_ascii(string);
void test();

// receives a single string and returns the sum of that string's character's ASCII values.
int sum_ascii(string ascii_text)
{
    int ascii_int = 0;
    for (size_t i = 0; i < ascii_text.length(); i++)
    {
        /* code */
        ascii_int += (int)ascii_text[i];
    }
    return ascii_int;
}

void test()
{
    cout << "Running tests" << endl;
    if (sum_ascii("A") != 65) {
        cout << "Test 1 failed, A should = 65" << endl;
    } else {
        cout << "Test 1 Passed" << endl;
    }
    if (sum_ascii("AA") != 130) {
        cout << "Test 2 failed, AA should = 130" << endl;
    } else {
        cout << "Test 2 Passed" << endl;
    }
        if (sum_ascii("AA") != 130) {
        cout << "Test 3 failed, AA should = 130" << endl;
    } else {
        cout << "Test 3 Passed" << endl;
    }
}

int main()
{
    test();

    return 0;
}



/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/