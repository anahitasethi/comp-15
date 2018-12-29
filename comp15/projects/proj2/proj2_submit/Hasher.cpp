/*************************
 * Anahita Sethi
 * COMP 15
 * Project 2
 * Hasher Implementation
 *************************/ 

#include <iostream>
#include "Hasher.h"
#include <fstream>
#include <sstream>

static const int MAX_SIZE = 100;
const double LOAD_FACTOR = 0.75; 
using namespace std; 

//Default constructor 
//Does: Initializes private variables
//Initializes hash table
Hasher::Hasher()
{
    capacity = MAX_SIZE;
    hash_table = new Key*[capacity];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        hash_table[i] = NULL;
    }

    key_count = 0;
    file_count = 0;
}

//Destructor
//Does: calls delete table to destroy
//      allocated memory 
Hasher::~Hasher()
{
    delete_table(capacity);
}

//Function name: delete_table 
//Returns: void 
//Parameters: int
//Does: destroys hash table by deleting nodes of the
//      linked list of each element of the array 
//      in the table 
void Hasher::delete_table(int size)
{
    //Iterates through elements of array in table 
    for (int i = 0; i < size; i++)
    {
        if (hash_table[i] != NULL)
        {
            //Iterates through elements of linked list 
            while (hash_table[i]->next != NULL)
            {
                Key *temp = hash_table[i];
                hash_table[i] = temp->next;
                delete temp;
            }
            delete hash_table[i];
        }
    }
    delete [] hash_table;
}

//Function name: traversal 
//Returns: void
//Parameters: pointer to DirNode, string
//Does: Traverses through directories recursively to
//      open given file 
void Hasher::traversal(DirNode *curr, string directory)
{
    if (curr->is_empty())
    {
        return;
    }

    for (int i = 0; i < curr->num_subdirs(); i++)
    {
        DirNode *Node = curr->get_subdir(i);
        string curr_directory = directory + Node -> get_name() + "/";
        traversal(Node, curr_directory);
    }

    for (int i = 0; i < curr->num_files(); i++)
    {
        string file_pathway = directory + (curr->get_file(i));
        open_file(file_pathway);
        file_count++;
        if (file_count % 5 == 0)
        {
            expand();
        }
    }
}

/********************
* Indexing Functions 
*********************/

//Function name: open_file
//Returns: void 
//Parameters: string 
//Does: Handles file I/O, processes each line
//      and each individual words and hashes them 
//      based on returned index 
//      Gets each line then parses each line
//      into individual words using stringstream
//      Strips nonalphanum characters, converts
//      words to lowercase, then inserts words into
//      hash table at hashed index      
void Hasher::open_file(string filepathway)
{
    ifstream infile; 
    infile.open(filepathway.c_str()); 

    //Checks if file is open 
    if (!infile.is_open())
    {
        cerr << "Error opening file" << endl; 
        exit(1); 
    }

    int line_num = 1; 

    //Iterates through the file 
    while (!infile.eof())
    {
        string whole_line; 
        //Gets each line in the file 
        getline(infile, whole_line);
        stringstream ss(whole_line); 

        string one_word; 
        //Parses each line into individual words 
        while (ss >> one_word)
        {
            //Strips non alphanum characters of word 
            one_word = strip_nonalphanum(one_word); 
            if (one_word != "")
            {
                //Convert characters of word into lower case version 
                string lower_case = lower(one_word); 
                size_t index = hash_word(lower_case); 
                Word info(one_word, Location(filepathway, line_num)); 
                //Inserts item into given index of the hash table 
                insert(hash_table[index], lower_case, info); 
            }
        }
        line_num++;  
    }

    infile.close();
}

//Function name: strip_nonalphanum
//Returns: string 
//Parameters: string
//Does: Calls strip_leading and strip_trailing
//      functions if the string is not empty 
//      Returns the string 
string Hasher::strip_nonalphanum(string s)
{
    if (s.length() == 0)
    {
        return s;
    }
    else
    {   
        s = strip_leading(s); 
        s = strip_trailing(s); 
    }
    return s; 
}

//Function name: strip_leading
//Returns: string
//Parameters: string 
//Does: Returns string if string is empty
//      Makes recursive call if string at
//      first index is not an alphanumeric
//      character 
string Hasher::strip_leading(string s)
{
    if (s.length() == 0)
    {
        return s; 
    }
    else if (!isalnum(s[0]))
    {
        return strip_leading(s.substr(1));
    }
    else
    {
        return s; 
    }
}

//Function name: strip_trailing
//Returns: string
//Parameters: string 
//Does: Returns string if string is empty
//      Makes recursive call if last character
//      is not alphanumeric. 
string Hasher::strip_trailing(string s)
{
    if (s.length() == 0)
    {
        return s; 
    }
    else if (!isalnum(s[s.length() - 1]))
    {
        //Want to get all but last 
        return strip_trailing(s.substr(0, s.length() -1));
    }
    else
    {
        return s; 
    }
}

//Function name: lower
//Returns: string
//Parameters: string
//Does: Iterates through all characters of word and 
//      converts them to lowercase letters
//      Returns lowercase version of word
//      Ensures that words will hash to same value 
//      regardless of case, making searching easier 
string Hasher::lower(string word)
{
    for (int i  = 0; i < (int) word.length(); i++)
    {
        if (isalnum(word[i]))
        {
            word[i] = tolower(word[i]); 
        }
    }

    return word; 
}

//Function name: hash_word
//Returns: size_t (int with a positive value)
//Paramaters: string 
//Does: Uses C++ method of hashing a string to a given index
//      Returns the value of that index  
size_t Hasher::hash_word(string word) const 
{
    hash<string> hasher; 
    size_t index = hasher(word);
    //Ensures that index is within bounds of array 
    index %= capacity; 
    return index;
}

/************************
* Hashtable Functions 
************************/

//Function name: insert
//Returns: void 
//Paramaters: Pointer to address of Key, string, Word info
//Does: Creates new key if it does not already exist
//      If key exists, calls insert_existing helper fxn 
void Hasher::insert(Key *&entered_key, string key, Word info)
{
    //Base case
    //Creates a new key with file path, line number, and line
    if (entered_key == NULL)
    {
        key_count++;    
        entered_key = new Key(key, info);   
    }
    else
    {
        //Calls helper function if key already exists 
        if (entered_key->low_name == key)
        {
            insert_existing(entered_key, info);
        }
        //Recursively calls insert on next item in linked list
        else
        {
            insert(entered_key->next, key, info);
        }
    }   
}

//Function name: insert_existing
//Returns: void
//Parameters: Pointer to address of Key, and Word info 
//Does: If original word exists, pushes word into location vector
//      If it doesn't exist, word gets pushed into vector of words
void Hasher::insert_existing(Key *&entered_key, Word info)
{
    size_t length = (entered_key->words).size();

    for (size_t i = 0; i < length; i++)
    {
        if ((entered_key->words)[i].original_word == info.original_word)
        {
            string pathway = info.locs.back().filepathway;
            int linenumber = info.locs.back().line_number;

            (entered_key->words)[i].locs.push_back(Location(
            pathway, linenumber));
            return;
        }
    }
    entered_key->words.push_back(info);
}

//Function name: expand 
//Parameters: None
//Function: Expands the hash table to twice the size and rehashing
//          by comparing the number of items / capacity to the load factor
void Hasher::expand()
{
    //check to see if expand is nessecary
    float load_factor = (float)key_count/capacity;
    if (load_factor <= LOAD_FACTOR)
    {
        return;
    }

    int curr_capacity = capacity;
    capacity *= 2; 
    Key **temp_table = new Key*[capacity];

    for (int i = 0; i < capacity; i++)
    {
        temp_table[i] = NULL;
    }

    Key *n;
    for (int i = 0; i < curr_capacity; i++)
    {
        n = hash_table[i];
        while (n != NULL)
        {
            initialize_node(n, temp_table);
            n = n->next;
        }
    }

    delete_table(curr_capacity);
    hash_table = temp_table;
}

//Function name: initialize_node
//Returns: void 
//Parameters: Key *n, Key **temp_table
//Does: Rehashes the hash table 
//Called from the expand function 
void Hasher::initialize_node(Key *n, Key **temp_table)
{
    //New node gets inserted into the hash table
    Key *node = new Key(n->low_name, n->words);
    //Hashes word to a new index 
    size_t index = hash_word(n->low_name);

    if (temp_table[index] == NULL)
    {
        temp_table[index] = node;
        return;
    }

    //pointer to node at desired index
    Key *pointer = temp_table[index];
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }

    pointer->next = node;
}

/******************
* Query Functions
*******************/ 

//Function name: start_query 
//Returns: void
//Parameters: none 
//Function: Asks for user input and calls function
//to find that inputed word in given file
void Hasher::start_query()
{ 
    string query;
    bool insensitive = false;

    cout << "Query? ";

    while (cin >> query)
    {
        if (query == "@q" || query == "@quit")
        {
            break; 
        }

        else if (query == "@i" || query == "@insensitive")
        {
            if (cin >> query)
            {
                insensitive = true;
                search(insensitive, query);
            }
        }
        else
        {
            insensitive = false;
            search(insensitive, query);
        }

        cout << "Query? ";
    }

    cout << "\nGoodbye! Thank you and have a nice day." << endl; 
}

//Function name: search
//Returns: void 
//Parameters: bool, string 
//Does: checks if word exists in the hash table by iterating through
//      linked list at given index
//      If found, calls function based on whether 
//      it is insensitive/not.
//      If not found, prints out a message to standard out
void Hasher::search(bool insensitive, string input)
{
    //Strips non alphanum characters 
    string key = strip_nonalphanum(input);

    //Converts key to lowercase version of word 
    string key_low = lower(key);

    //Returns index of lowercase version of word
    size_t index = hash_word(key_low);
    bool found  = false;

    //Node points to hash table at returned index 
    Key *node = hash_table[index];

    //Iterates through nodes of linked list while node does not
    //point to null 
    while (node != NULL)
    {
        //Checks if node in linked list is equal to inputed query 
        if (node->low_name == key_low)
        {
            //Makes call to found_word function based on case 
            //of query 
            if(insensitive)
            {
                found = found_word(insensitive, key, node);
                break;
            }
            else
            {
                found = found_word(insensitive, key, node);
                break;
            }
        }
        node = node->next;
    }

    if ((!found) && (insensitive == false))
    {
        cout << key << 
        " Not Found. Try with @insensitive or @i." << endl;
    }
    else if ((!found) && (insensitive == true))
    {
        cout << key << " Not Found." << endl;
    }
}

//Function name: found_word
//Returns: bool 
//Parameters: bool, string word, pointer to Key 
//Does: calls print function depending on case (insensitive or sensitive)
bool Hasher::found_word(bool insensitive, string word, Key *node)
{
    vector <Word> words = node->words;
    int num_words = words.size();

    if (!insensitive)
    {
        for (int i = 0; i < num_words; i++)
        {
            //Finds words with the same key 
            //If found, return true and call print
            if (words[i].original_word== word)
            {
                print_info(words[i].locs);
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < num_words; i++)
        {
            print_info(words[i].locs);
        }
        return true;
    }
    return false;
}

//Function name: print_info
//Returns: void
//Parameters: address of vector of location of words 
//Does: Prints info of words (file pathway, line number, line)
void Hasher::print_info(vector<Location> &location)
{
    string line_appears = "";
    int location_size = location.size();
    ifstream infile;
    bool temp = true;

    for (int i = 0; i < location_size; i++)
    {
        string path = location[i].filepathway;
        int linenumber = location[i].line_number;   

        infile.open(path.c_str());
        //Gets line that the word appears in 
        for (int j = 1; j <= linenumber; j++)
        {
            getline(infile, line_appears);
        }
        infile.close();

        if (i != 0)
        {
            if (path == location[i-1].filepathway && 
                linenumber == location[i-1].line_number)
            {
                temp = false;
            }
        }
        if (temp)
        {
            cout << path << ":" << linenumber << ": " 
                 << line_appears << endl;
        }
        temp = true;
    }   
}