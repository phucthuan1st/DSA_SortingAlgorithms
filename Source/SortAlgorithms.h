#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

void GenerateData(int a[], int n, int dataType);
int MenuController(int argc, const char** argv);
void QuickSort(int* a, int lo, int hi, unsigned long long& count_cmp);
void shakerSort(int a[], int n, unsigned long long& count_cmp);
void counting_sort(int input[], int n, unsigned long long& count_cmp);
void bubble_sort(int* a, int n, unsigned long long& count_compare);
void heapSort(int* arr, int n, unsigned long long& count_cmp);
void selectionSort(int* arr, int n, unsigned long long& count_cmp);
void mergeSort(int arr[], int left, int right, unsigned long long& count_cmp);
void shellSort(int a[], int n, unsigned long long& count_compare);
void flashSort(int arr[], int n, unsigned long long& count_compare);
void radix_sort(int* a, int n, unsigned long long& count_compare);
void insertion_sort(int* a, int n, unsigned long long& count_compare);
int* copyArray(int* a, int size);
void printArray(int arr[], int size);
int getAlgorithm(const char* str);
void runAlgorithm(int*a,int n, unsigned long long &count_compare,const char*str, double &time_use);
int* readInputFrom(string file, int& n);
void writeOutputTo(string file, int n, int* a);