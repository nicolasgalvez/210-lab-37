/**
 * Nick Galvez
 * 210 lab 37
 */
#include <iostream>
#include <fstream>
#include <map>
#include <list>

using namespace std;

// It seems like having a number like this will result in less collisions for the first keys, but the collisions grow as the keys grow.
const int MODULUS = 100003;
// const int MODULUS = 97; // it seems like this results in more, but more even, collisions.

map<int, list<string>> hash_table;


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
    int hash_index;;
    for (size_t i = 0; i < ascii_text.length(); i++)
    {
        /* code */
        ascii_int += (int)ascii_text[i];
    }

    // add to the hash table
    hash_table[ascii_int % MODULUS].push_back(ascii_text);

    return ascii_int;
}

void test()
{
    cout << "Running tests" << endl;
    // if (gen_hash_index("A") != 65) {
    //     cout << "Test 1 failed, A should = 65" << endl;
    // } else {
    //     cout << "Test 1 Passed" << endl;
    // }
    // if (gen_hash_index("AA") != 130) {
    //     cout << "Test 2 failed, AA should = 130" << endl;
    // } else {
    //     cout << "Test 2 Passed" << endl;
    // }
    // if (gen_hash_index("536B9DFC93AF") != 729) {
    //     cout << "Test 3 failed, 536B9DFC93AF should = 729" << endl; // according to chat gpt
    // } else {
    //     cout << "Test 3 Passed" << endl;
    // }

    if (loadCodes() != 69893419) {
        cout << "Test 3 failed, loadCodes should return 69893419" << endl; // according to chat gpt
    } else {
        cout << "Test 3 Passed: loadCodes returned 69893419" << endl;
    }
    
    // show the first 100 entries
    int count = 0;
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {
        cout << "Key: " << it->first << " ";
        for (auto values = it->second.begin(); values != it->second.end(); values++)
        {
            cout << *values << " ";
        }
        cout << endl << endl;
        count++;
        if (count > 100) {
            break;
        }
    }

    // What are the number of keys, and collisions per key?
    int collisions = 0;
    int keys = 0;
    vector<int> collisions_per_key;
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {   
        keys++;
        collisions_per_key.push_back(it->second.size());
        // if (it->second.size() > 1) {
        //     collisions++;
        // }
        cout << "Key: " << it->first << " Collisions: " << it->second.size() << endl;
    }
    // cout << "Keys: " << keys << " Collisions: " << collisions_per_key.size() << endl;

    // it seems like the hash looks like a bell curve with a higher modulus.
    // probably wouldn't be the case if the data was more random?

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