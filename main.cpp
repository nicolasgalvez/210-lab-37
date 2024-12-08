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
    int modulus;
    int generate_key(string ascii_text)
    {
        int ascii_int = 0;
        for (size_t i = 0; i < ascii_text.length(); i++)
        {
            ascii_int += (int)ascii_text[i];
        }
        return ascii_int % this->modulus;
    }
public:
    HashTable(int modulus) {
        this->modulus = MODULUS;
    }
    void print(int num = 100) {
        cout << "Printing the first " << num << " entries" << endl;
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
    int ascii_key = generate_key(ascii_text);
    // add to the hash table
    this->hash_table[ascii_key].push_back(ascii_text);

    return ascii_key;
    }
    void remove(string ascii_text) {
        int ascii_key = generate_key(ascii_text);
    }
    int find(string ascii_text) {
        int ascii_key = generate_key(ascii_text);
        for (auto it = hash_table.begin(); it != hash_table.end(); it++)
        {
            if (it->first == ascii_key) {
                for (auto values = it->second.begin(); values != it->second.end(); values++)
                {
                    if (*values == ascii_text) {
                        return ascii_key;
                    }
                }
            }
        }
        return -1;
    }
    void clear() {
        this->hash_table.clear();
    }
    void print_meta() {
            // What are the number of keys, and collisions per key?
        for (auto it = hash_table.begin(); it != hash_table.end(); it++)
        {
            cout << "Key: " << it->first << " Collisions: " << it->second.size() << endl;
        }
    }
};

int gen_hash_index(string);
void test(HashTable &);
int loadCodes(HashTable &);

/**
 * Load codes from a file.
 */
int loadCodes(HashTable &hash_table)
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
            grand_total += hash_table.add(line);
        }
        file.close();
    }
    return grand_total;
}

// receives a single string and returns the sum of that string's character's ASCII values.
// int gen_hash_index(string ascii_text)
// {
//     int ascii_int = 0;
//     int hash_index;
//     ;
//     for (size_t i = 0; i < ascii_text.length(); i++)
//     {
//         ascii_int += (int)ascii_text[i];
//     }

//     // add to the hash table
//     hash_table[ascii_int % MODULUS].push_back(ascii_text);

//     return ascii_int;
// }

void test(HashTable &hash_table)
{
    cout << "Running tests" << endl;

    hash_table.print(100);
    hash_table.print_meta();
    // if (loadCodes() != 69893419)
    // {
    //     cout << "Test 3 failed, loadCodes should return 69893419" << endl;
    // }
    // else
    // {
    //     cout << "Test 3 Passed: loadCodes returned 69893419" << endl;
    // }

    // // show the first 100 entries
    // int count = 0;
    // for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    // {
    //     cout << "Key: " << it->first << " ";
    //     for (auto values = it->second.begin(); values != it->second.end(); values++)
    //     {
    //         cout << *values << " ";
    //     }
    //     cout << endl
    //          << endl;
    //     count++;
    //     if (count > 100)
    //     {
    //         break;
    //     }
    // }



    // it seems like the hash looks like a bell curve with a higher modulus.
    // probably wouldn't be the case if the data was more random?
}

int main()
{
    HashTable hash_table(MODULUS);
    loadCodes(hash_table);
    test(hash_table);
    return 0;
}