#include "header.h"

std::istream& operator>>(std::istream& is, Student& s) 
{
    is >> s.course >> s.group >> s.surname >> s.name >> s.patronymic >> s.grade1 >> s.grade2 >> s.grade3;
    return is;
}


std::ostream& operator<<(std::ostream& os, Student& s) 
{
    os << s.course << ' ' << s.group << ' ' << s.surname << ' ' << s.name << ' ' << s.patronymic << ' ' << s.grade1 << ' ' << s.grade2 << ' ' << s.grade3;
    return os;
}


bool operator>(Student& a,  Student& b)
{
    if (a.course != b.course)
    {
        return a.course > b.course;
    }
    if (a.group != b.group) 
    {
        return a.group > b.group;
    }
    return a.surname + a.name + a.patronymic > b.surname + b.name + b.patronymic;
}


bool operator<(Student& a, Student& b)
{
    if (a.course != b.course)
    {
        return a.course < b.course;
    }
    if (a.group != b.group)
    {
        return a.group < b.group;
    }
    return a.surname + a.name + a.patronymic < b.surname + b.name + b.patronymic;
}


bool operator<=(Student& a, Student& b)
{
    if (a.course != b.course)
    {
        return a.course <= b.course;
    }
    if (a.group != b.group)
    {
        return a.group <= b.group;
    }
    return a.surname + a.name + a.patronymic <= b.surname + b.name + b.patronymic;
}


void FillRandomArray(int32_t* arr, int32_t size) 
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int32_t> dist(0, 1000);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(rng);
    }
}


void FillRandomArray(double* arr, int32_t size)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1000.0);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(rng);
    }
}


void FillRandomArray(char* arr, int32_t size) 
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int32_t> dist(33, 126);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = static_cast<char>(dist(rng));
    }
}
