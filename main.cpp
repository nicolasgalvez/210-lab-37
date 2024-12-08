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
    int remove(string ascii_text) {
        int find_key = find(ascii_text);
        if (find_key != -1) {
            for (auto it = hash_table.begin(); it != hash_table.end(); it++)
            {
                if (it->first == find_key) {
                    for (auto values = it->second.begin(); values != it->second.end(); values++)
                    {
                        if (*values == ascii_text) {
                            it->second.remove(ascii_text);
                            return find_key;
                        }
                    }
                }
            }
        }
        return -1;
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

    // test find
    cout << "Key for 'E1F3E7DFE660' is " << hash_table.find("E1F3E7DFE660") << endl;

    // test remove
    cout << "Removing 'E1F3E7DFE660' from the hash table" << endl;
    int key = hash_table.remove("E1F3E7DFE660");

    if (key != -1) {
        cout << "Removed from key " << key << endl;
    } else {
        cout << "Could not find 'E1F3E7DFE660' in the hash table" << endl;
    }
    if (hash_table.find("E1F3E7DFE660") != -1) {
        cout << "Verified item has been removed" << endl;
    }
}

int main()
{
    HashTable hash_table(MODULUS);
    loadCodes(hash_table);



       // display menu
    int choice;
    do
    {
            // print the menu
    cout << "1. Print the first 100 entries" << endl;
    cout << "2. Find a key" << endl;
    cout << "3. Remove a key" << endl;
    cout << "0. Exit" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string code;
            cout << "Enter a code: ";
            getline(cin, code);
            tree.insertNode(code);
            break;
        }
        case 2:
        {
            string code;
            cout << "Enter a code to delete: ";
            getline(cin, code);
            tree.remove(code);
            break;
        }
        case 3:
        {
            string code;
            cout << "Enter a code to search for: ";
            getline(cin, code);
            if (tree.searchNode(code))
            {
                cout << "Code found." << endl;
            }
            else
            {
                cout << "Code not found." << endl;
            }
            break;
        }
        case 4:
        {
            string code, replacement;
            cout << "Enter a code to search for: ";
            getline(cin, code);
            cout << "Enter a replacement: ";
            getline(cin, replacement);
            if (tree.modifyNode(code, replacement))
            {
                cout << "Code replaced." << endl;
            }
            else
            {
                cout << "Code not replaced." << endl;
            }
            break;
        }
        case 5:
            tree.displayInOrder();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    test(hash_table);
    return 0;
}