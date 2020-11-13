// ArrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class ArrayList
{
private:
    // The array.
    int* memory;
    // The Total Size of the reserved array in memory (The Size).
    int size;
    // The Total size of the used size array in memoryv (The Count).
    int currentIndex;

    // Regrow by moving the whole array to another bigger one.
    // We grow using Buckting by increase full bicket at a time 
    // to save the performance of creating and deleting arrays in memory.
    void ReGrow()
    {
        int* temp = new int[size + 10];
        for (int i = 0; i < size; i++)
        {
            temp[i] = memory[i];
        }

        delete memory;
        size += 10;
        memory = temp;
    }
public:
    // Initialize The ArrayList's Array with starting size 10.
    // Set The Total Size = 10.
    // Set The CurrentIndex to 0.
    ArrayList(int size = 10)
    {
        memory = new int[size];
        this->size = size;
        this->currentIndex = 0;
    }

    // At Destractor delete the array from the memory.
    ~ArrayList()
    {
        delete memory;
    }

    // Add Item to the currentIndex and move currentIndex to next cell.
    void Add(int number)
    {
        memory[currentIndex] = number;
        currentIndex++;
        if (currentIndex == size)
        {
            ReGrow();
        }
    }

    int Get(int index)
    {
        return memory[index];
    }

    int GetSize()
    {
        return size;
    }

    int GetCount()
    {
        return currentIndex;
    }

    // Delete a value by setting this cell's value to the next cell and do the same
    // to next cells till the end (currentIndex).
    int Delete(int index)
    {
        for (int i = index; i < currentIndex; i++)
        {
            memory[i] = memory[i + 1];
        }
        currentIndex--;
    }

    // Clearing all values by set the currentIndex to 0, all other pointers are useless to remove.
    void Clear()
    {
        currentIndex = 0;
    }
};

int main()
{
    std::cout << "Hello Array List!\n";

    ArrayList list;
    list.Add(3);
    list.Add(5);
    list.Add(2);
    list.Add(7);

    for (int i = 0; i < list.GetCount(); i++)
    {
        cout << list.Get(i) << endl;
    }

    list.Delete(2);

    cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
