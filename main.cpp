/**
 * Nick Galvez
 * 210 lab 37
 */
#include <iostream>
#include <fstream>

using namespace std;

int gen_hash_index(string);
void test();
int loadCodes();
/**
 * Load codes from a file.
 */
int loadCodes()
{
    int grand_total = 0;
    // load codes.txt
    ifstream file("lab-37-data.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // add to the tree.
            grand_total+=gen_hash_index(line);
        }
        file.close();
    }
    return grand_total;
}

// receives a single string and returns the sum of that string's character's ASCII values.
int gen_hash_index(string ascii_text)
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
    if (gen_hash_index("A") != 65) {
        cout << "Test 1 failed, A should = 65" << endl;
    } else {
        cout << "Test 1 Passed" << endl;
    }
    if (gen_hash_index("AA") != 130) {
        cout << "Test 2 failed, AA should = 130" << endl;
    } else {
        cout << "Test 2 Passed" << endl;
    }
    if (gen_hash_index("536B9DFC93AF") != 729) {
        cout << "Test 3 failed, 536B9DFC93AF should = 729" << endl; // according to chat gpt
    } else {
        cout << "Test 3 Passed" << endl;
    }

        if (loadCodes() != 69893419) {
        cout << "Test 3 failed, loadCodes should return 69893419" << endl; // according to chat gpt
    } else {
        cout << "Test 3 Passed: loadCodes returned 69893419" << endl;
    }
    

}

int main()
{
    test();
    // cout << loadCodes() << endl;
    return 0;
}



/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/