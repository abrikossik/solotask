#ifndef header
#define header

#include <iostream>
#include <random>
#include <fstream>
#include <string>

struct Student
{
	int32_t course{};
	int32_t group{};
	std::string surname;
	std::string name;
	std::string patronymic;
	int32_t grade1{};
	int32_t grade2{};
	int32_t grade3{};
};

std::istream& operator>>(std::istream&, Student&);
std::ostream& operator<<(std::ostream&, Student&);

bool operator>(Student&, Student&);
bool operator<(Student&, Student&);
bool operator<=(Student&, Student&);

template<class type>
void FillArray(type* array, int32_t arraySize)
{
	for (int32_t i{}; i < arraySize; ++i)
	{
		std::cin >> array[i];
	}
}

void FillRandomArray(int32_t*, int32_t);
void FillRandomArray(double*, int32_t);
void FillRandomArray(char*, int32_t);


template <class type>
void BubbleSort(type* array, int32_t arraySize,bool sort)
{
	bool isSwaped{ false };
	--arraySize;
	for (int32_t i{}; i < arraySize; ++i)
	{
		for (int32_t j{}; j < arraySize-i ; ++j)
		{
			if ((array[j] > array[j + 1]) ^ sort) 
			{
				std::swap(array[j], array[j + 1]);
				isSwaped = true;
			}
		}
		if (!isSwaped)
		{
			return;
		}
	}
}


template <class type>
void ShakerSort(type* array, int32_t arraySize,bool sort)
{
	bool isSwaped{ true };
	int32_t start{};
	int32_t end{--arraySize};
	while (isSwaped) 
	{
		isSwaped = false;
		for (int32_t i{start}; i < end; ++i)
		{
			if ((array[i] > array[i + 1]) ^ sort)
			{
				std::swap(array[i], array[i + 1]);
				isSwaped = true;
			}
		}
		if (!isSwaped)
		{
			return;
		}
		--end;
		for (int32_t i{end}; i > start; --i)
		{
			if ((array[i - 1] > array[i]) ^ sort) 
			{
				std::swap(array[i - 1], array[i]);
				isSwaped = true;
			}
		}
		++start;
	}
}


template <class type>
void CombSort(type array, int32_t arraySize,bool sort)
{
	int32_t stepSize{ static_cast<int32_t>(arraySize * 4 / 5) };
	bool isSwaped{ true };
	while (stepSize > 1 || isSwaped) 
	{
		if (stepSize > 1) 
		{
			stepSize = static_cast<int32_t>(stepSize * 4 / 5);
		}
		isSwaped = false;
		for (int32_t i{}; i + stepSize < arraySize; ++i) 
		{
			if ((array[i] > array[i + stepSize]) ^ sort)
			{
				std::swap(array[i], array[i + stepSize]);
				isSwaped = true;
			}
		}
	}
}


template <class type>
void InsertionSort(type* array, int32_t arraySize, bool sort)
{
	for (int32_t i{ 1 }; i < arraySize; ++i) 
	{
		for (int32_t j{ i }; j > 0 && ((array[j - 1] > array[j]) ^ sort); --j)
		{
			std::swap(array[j - 1], array[j]);
		}
	}
}


template <class type>
void SelectionSort(type* arr, int32_t size,bool sort)
{
	int32_t min{};
	for (int32_t i{}; i < size - 1; ++i)
	{
		min = i;
		for (int32_t j{ i + 1 }; j < size; ++j)
		{
			if ((arr[j] > arr[min]) ^ sort)
			{
				min = j;
			}
		}
		if (min != i)
		{
			std::swap(arr[i], arr[min]);
		}
	}
}

template <class type>
int32_t QuickSortCompare(type* arr, int32_t min, int32_t max,bool sort)
{
	type pivo{ arr[max] };
	int32_t podPivas{ min - 1 };

	for (int32_t i{ min }; i < max; ++i)
	{
		if ((arr[i] < pivo) ^ sort)
		{
			++podPivas;
			std::swap(arr[i], arr[podPivas]);
		}
	}
	std::swap(arr[max], arr[podPivas + 1]);
	return podPivas + 1;
}

template <class type>
void QuickSort(type* arr, int32_t min, int32_t max,bool sort)
{
	if (min < max)
	{
		int32_t index = QuickSortCompare(arr, min, max,sort);
		QuickSort(arr, min, index - 1,sort);
		QuickSort(arr, index + 1, max,sort);
	}
}


template<class type>
void Merge(type* arr, int32_t left, int32_t mid, int32_t right)
{
	int32_t min{ mid - left + 1 };
	int32_t max{ right - mid };

	type* leftArr = new type[min];
	type* rightArr = new type[max];

	for (int32_t i{}; i < min; ++i) 
	{
		leftArr[i] = arr[left + i];
	}
	for (int32_t j{}; j < max; ++j) 
	{
		rightArr[j] = arr[mid + 1 + j];
	}

	int32_t i{}, j{}, k{ left };

	while (i < min && j < max)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = rightArr[j++];
		}
			
	}

	while (i < min) 
	{
		arr[k++] = leftArr[i++];
	}
	while (j < max) 
	{
		arr[k++] = rightArr[j++];
	}

	delete[] leftArr;
	delete[] rightArr;
}


template<class type>
void MergeSort(type* arr, int32_t left, int32_t right)
{
	if (left < right)
	{
		int32_t mid{ left + (right - left) / 2 };
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}


template <class type>
void ChooseSort(type array, int32_t arraySize,bool sort)
{
	std::cout << "Choose the sort:\n\n1. BubbleSort\n2. ShakerSort\n3. CombSort\n4. InsertionSort\n5. SelectionSort\n6. QuickSort\n7. MergeSort(only up)";
	int16_t choise{};
	std::cin >> choise;
	switch (choise)
	{
	case 1:
		BubbleSort(array, arraySize, sort);
		break;
	case 2:
		ShakerSort(array, arraySize, sort);
		break;
	case 3:
		CombSort(array, arraySize, sort);
		break;
	case 4:
		InsertionSort(array, arraySize, sort);
		break;
	case 5:
		SelectionSort(array, arraySize, sort);
		break;
	case 6:
		QuickSort(array, 0, arraySize - 1,sort);
		break;
	case 7:
		MergeSort(array, 0, arraySize - 1);
		break;
	default:
		break;
	}
}


template<typename T>
void PrintArray(T* arr, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '/n';
}

template<typename T>
void ReadFromFile(std::string filename, T* arr)
{
	std::ifstream in(filename);
	T temp{};
	int32_t size{};
	while (in >> temp)
	{
		++size;
	}
	arr = new T[size];
	in.clear();
	in.seekg(0, std::ios::beg);
	for (int32_t i{}; i < size; ++i)
	{
		in >> arr[i];
	}
	in.close();
}


template<typename T>
void WriteToFile(std::string filename, T* arr, int32_t size)
{
	std::ofstream outFile(filename);
	for (int32_t i{}; i < size; ++i)
    {
        outFile << arr[i] << "\n";
    }
    outFile.close();
}

#endif header