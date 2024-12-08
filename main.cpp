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

class HashTable
{
private:
    map<int, list<string>> hash_table;
public:
    void print(int num = 100) {
            int count = 0;
        for (auto it = hash_table.begin(); it != hash_table.end(); it++)
        {
            cout << "Key: " << it->first << " ";
            for (auto values = it->second.begin(); values != it->second.end(); values++)
            {
                cout << *values << " ";
            }
            cout << endl
                << endl;
            count++;
            if (count > num)
            {
                break;
            }
        }
    }
    int add(string ascii_text) {
            int ascii_int = 0;
    int hash_index;

    for (size_t i = 0; i < ascii_text.length(); i++)
    {
        ascii_int += (int)ascii_text[i];
    }

    // add to the hash table
    this->hash_table[ascii_int % MODULUS].push_back(ascii_text);

    return ascii_int;
    }
    void remove(string);
    bool find(string);
    void print();
    void clear();
};

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
            grand_total += gen_hash_index(line);
        }
        file.close();
    }
    return grand_total;
}

// receives a single string and returns the sum of that string's character's ASCII values.
int gen_hash_index(string ascii_text)
{
    int ascii_int = 0;
    int hash_index;
    ;
    for (size_t i = 0; i < ascii_text.length(); i++)
    {
        ascii_int += (int)ascii_text[i];
    }

    // add to the hash table
    hash_table[ascii_int % MODULUS].push_back(ascii_text);

    return ascii_int;
}

void test()
{
    cout << "Running tests" << endl;

    if (loadCodes() != 69893419)
    {
        cout << "Test 3 failed, loadCodes should return 69893419" << endl; // according to chat gpt
    }
    else
    {
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
        cout << endl
             << endl;
        count++;
        if (count > 100)
        {
            break;
        }
    }

    // What are the number of keys, and collisions per key?
    // for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    // {
    //     cout << "Key: " << it->first << " Collisions: " << it->second.size() << endl;
    // }

    // it seems like the hash looks like a bell curve with a higher modulus.
    // probably wouldn't be the case if the data was more random?
}

int main()
{
    HashTable has_table;
    test();
    return 0;
}