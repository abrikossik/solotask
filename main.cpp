#include "header.h"


int main()
{
    std::cout << "Choose type of data:\n1 - int\n2 - double\n3 - char\n4 - string\n5 - Student\n";
    int32_t type{};
    std::cin >> type;
    
    std::cout << "Input size: ";
    int32_t size;
    std::cin >> size;
    
    std::cout << "Choose type of input:\n1 - manually\n2 - random\n3 - read from file\n";
    int32_t method; 
    std::cin >> method;

    std::string inFile = "inputFile.txt";
    std::string outFile = "outputFile.txt";

    bool sort{};

    if (type == 1)
    {
        int32_t* array = new int32_t[size];

        switch (method)
        {
        case 1:
            FillArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            ChooseSort(array, size,sort);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 2)
    {
        double* array = new double[size];
        switch (method)
        {
        case 1:
            FillArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            ChooseSort(array, size, sort);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 3)
    {
        char* array = new char[size];
        switch (method)
        {
        case 1:
            FillArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            ChooseSort(array, size, sort);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 4)
    {
        std::string* array = new std::string[size];
        switch (method)
        {
        case 1:
            FillArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            std::cout << "Uncorrect";
            break;
        case 3:
            ReadFromFile(inFile, array);
            ChooseSort(array, size, sort);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 5)
    {
        Student* array = new Student[size];
        switch (method)
        {
        case 1:
            FillArray(array, size);
            ChooseSort(array, size, sort);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            std::cout << "Uncorrect";
            break;
        case 3:
            ReadFromFile(inFile, array);
            ChooseSort(array, size, sort);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }

    return 0;
}