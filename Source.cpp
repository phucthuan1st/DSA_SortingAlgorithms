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
//
template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Phat sinh du lieu ngau nhien
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// thu tu tang dan
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// giam dan
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// co thu tu
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	//ngau nhien
		GenerateRandomData(a, n);
		break;
	case 1:	// co thu tu
		GenerateSortedData(a, n);
		break;
	case 2:	// thu tu nguoc
		GenerateReverseData(a, n);
		break;
	case 3:	// gan nhu co thu tu
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}


void QuickSort(int* a, int lo, int hi, unsigned long long& count_cmp)
{
	while (++count_cmp && lo < hi) {
		int p = a[hi];
		int i = lo;
		for (int j = lo; ++count_cmp && j < hi; ++j) {
			if (++count_cmp && a[j] < p) {
				swap(a[j], a[i]);
				++i;
			}
		}
		swap(a[i], a[hi]);
		if (++count_cmp && i - lo <= hi - i) {
			QuickSort(a, lo, i - 1, count_cmp);
			lo = i + 1;
		}
		else {
			QuickSort(a, i + 1, hi, count_cmp);
			hi = i - 1;
		}
	}
}

void shakerSort(int a[], int n, unsigned long long& count_cmp)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count_cmp&& Left < Right)
	{
		for (int i = Left; ++count_cmp && i < Right; i++)
		{
			if (++count_cmp && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++count_cmp && i > Left; i--)
		{
			if (++count_cmp && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

void counting_sort(int input[], int n, unsigned long long& count_cmp)
{
	int* output = new int[n];
	int max = input[0];
	int min = input[0];

	int i;
	for (i = 1; ++count_cmp && i < n; i++)
	{
		if (++count_cmp && input[i] > max)
			max = input[i];
		else if (++count_cmp && input[i] < min)
			min = input[i];
	}

	int k = max - min + 1;

	int* count_array = new int[k];
	for (i = 0; ++count_cmp && i < k; i++)
		count_array[i] = 0;

	for (i = 0; ++count_cmp && i < n; i++)
		count_array[input[i] - min]++;

	for (i = 1; ++count_cmp && i < k; i++)
		count_array[i] += count_array[i - 1];

	for (i = 0; ++count_cmp && i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}

	for (i = 0; ++count_cmp && i < n; i++)
		input[i] = output[i];

}

void bubble_sort(int* a, int n, unsigned long long& count_compare) {

	count_compare = 0;
	bool haveSwap = false;

	for (int i = 0; ++count_compare && i < n - 1; i++) {
		for (int j = 0; ++count_compare && j < n - 1; j++) {
			if (++count_compare && a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}

		if (++count_compare && !haveSwap) {
			return;
		} //neu khong co su thay doi cho nao thi tuc la mang da sap xep xong

		haveSwap = false;

	}

}

struct Node {
	int key;
	Node* next;

	Node(int value) {
		key = value;
		next = NULL;
	}

};

struct Queue {
	Node* front;
	Node* rear;

	Queue() {
		front = rear = NULL;
	}

	void enqueue(Node* node) {
		if (rear == NULL)
		{
			front = rear = node;
			return;
		}

		rear->next = node;
		rear = node;

	}

	void dequeue() {
		if (front == NULL)
			return;
		Node* node = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete node;

	}

};

void heapify(int* arr, int n, int i, unsigned long long& count_cmp)
{
	int largest = i; // Initialize largest as root 

	int l = 2 * i + 1; // left = 2*i + 1 

	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if ((++count_cmp && l < n) && (++count_cmp && arr[l] > arr[largest]))
		largest = l;

	// If right child is larger than largest so far 
	if ((++count_cmp && r < n) && (++count_cmp && arr[r] > arr[largest]))
		largest = r;

	// If largest is not root 
	if (++count_cmp && largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest, count_cmp);
	}
}

void heapSort(int* arr, int n, unsigned long long& count_cmp)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; ++count_cmp && i >= 0; i--)
	{
		unsigned long long count_cmp_heapify = 0;

		heapify(arr, n, i, count_cmp_heapify);

		count_cmp += count_cmp_heapify;
	}


	// One by one extract an element from heap 
	for (int i = n - 1; ++count_cmp && i > 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		unsigned long long count_cmp_heapify = 0;

		heapify(arr, i, 0, count_cmp_heapify);

		count_cmp += count_cmp_heapify;
	}
}

// selection Sort
void selectionSort(int* arr, int n, unsigned long long& count_cmp)
{
	int i, j, min_idx;

	// di chuyen danh gioi
	for (i = 0; ++count_cmp && i < n - 1; i++)
	{
		// tim min
		min_idx = i;
		for (j = i + 1; ++count_cmp && j < n; j++)
		{
			if (++count_cmp && arr[j] < arr[min_idx])
			{
				min_idx = j;
			}

		}

		// doi min voi arr[0]
		swap(arr[min_idx], arr[i]);
	}
}

void ImplMerge(int* arr, int left, int mid, int right, unsigned long long& count_cmp)
{
	int n1 = mid - left + 1; //So phan tu trai

	int n2 = right - mid;   //So phan tu phai

	//tao mang tam
	int* Left = new int[n1];
	int* Right = new int[n2];

	//
	for (int i = 0; ++count_cmp && i < n1; i++)
	{
		Left[i] = arr[left + i];
	}

	//
	for (int j = 0; ++count_cmp && j < n2; j++)
	{
		Right[j] = arr[mid + 1 + j];
	}

	//
	int i = 0;

	//
	int j = 0;

	//
	int k = left;
	while ((++count_cmp && i < n1) && (++count_cmp && j < n2))
	{
		if (++count_cmp && Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	//
	while (++count_cmp && i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	//
	while (++count_cmp && j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right, unsigned long long& count_cmp)
{
	if (++count_cmp && left < right)
	{
		//
		int mid = left + (right - left) / 2;

		//
		mergeSort(arr, left, mid, count_cmp);

		//
		mergeSort(arr, mid + 1, right, count_cmp);

		//
		unsigned long long count_cmp_ImplMerge = 0;

		//
		ImplMerge(arr, left, mid, right, count_cmp_ImplMerge);

		//
		count_cmp += count_cmp_ImplMerge;
	}
}

void shellSort(int a[], int n, unsigned long long& count_compare) {
	int interval, i, j, temp;
	for (interval = n / 2; ++count_compare && interval > 0; interval /= 2) {
		for (i = interval; ++count_compare && i < n; i++) {
			temp = a[i];
			for (j = i; (++count_compare && j >= interval) && (++count_compare && a[j - interval] > temp); j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

//Add count comparisions
void flashSort(int arr[], int n, unsigned long long& count_compare)
{
	int max = 0, min = arr[0];
	int m = 0.45 * n;
	int* l = new int[m];

	for (int i = 1; ++count_compare && i < n; ++i) {
		if (++count_compare && arr[i] < min) {
			min = arr[i];
		}
		if (++count_compare && arr[i] > arr[max]) {
			max = i;
		}
	}

	int c1 = (m - 1) / (arr[max] - min);


	for (int k = 0; ++count_compare && k < m; k++) {
		l[k] = 0;
	}
	for (int j = 0; ++count_compare && j < n; ++j) {
		int k = ~~(c1 * (arr[j] - min));
		++l[k];
	}

	for (int p = 1; ++count_compare && p < m; ++p) {
		l[p] = l[p] + l[p - 1];
	}

	int hold = arr[max];
	arr[max] = arr[0];
	arr[0] = hold;

	//permutation
	int move = 0, t, flash;
	int j = 0;
	int k = m - 1;

	while (++count_compare && move < (n - 1)) {
		while (++count_compare && j > (l[k] - 1)) {
			++j;
			k = ~~(c1 * (arr[j] - min));
		}
		if (++count_compare && k < 0) break;
		flash = arr[j];
		while (++count_compare && j != l[k]) {
			k = ~~(c1 * (flash - min));
			hold = arr[t = --l[k]];
			arr[t] = flash;
			flash = hold;
			++move;
		}
	}

	//insertion
	for (j = 1; ++count_compare && j < n; j++) {
		hold = arr[j];
		int i = j - 1;
		while ((++count_compare && i >= 0) && (++count_compare && arr[i] > hold)) {
			arr[i + 1] = arr[i--];
		}
		arr[i + 1] = hold;
	}
}

void radix_sort(int* a, int n, unsigned long long& count_compare) {
	vector<Queue> bucket(10, Queue());

	int max = a[0];
	for (int i = 1; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] > max)
			max = a[i];
	}

	int exp = 1;
	while (++count_compare && max / exp > 0) {
		for (int i = 0; ++count_compare && i < n; i++) {
			Node* node = new Node(a[i]);
			bucket[a[i] / exp % 10].enqueue(node);
		}

		int index = 0;
		for (int i = 0; ++count_compare && i <= 9; i++) {
			while (++count_compare && bucket[i].rear != NULL) {
				a[index++] = bucket[i].front->key;
				bucket[i].dequeue();
			}
		}
		exp *= 10;
	}

}

void insertion_sort(int* a, int n, unsigned long long& count_compare) {
	count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++) {

		int key = a[i];

		int j = i - 1;

		while (++count_compare && j >= 0 && ++count_compare && key < a[j]) {
			a[j + 1] = a[j];
			j--;
		} //doi cac phan tu lon hon khoa sang phai, chen khoa vao vi tri thich hop

		a[j + 1] = key;
	}
}

int* copyArray(int* a, int size) {
	int* b = new int[size];
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}

	return b;
}


void display(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//
int findAlgorithm(const char* str)
{
	if (strcmp(str, "selection-sort") == 0)
	{
		return 1;
	}
	else if (strcmp(str, "insertion-sort") == 0)
	{
		return 2;
	}
	else if (strcmp(str, "bubble-sort") == 0)
	{
		return 3;
	}
	else if (strcmp(str, "shaker-sort") == 0)
	{
		return 4;
	}
	else if (strcmp(str, "shell-sort") == 0)
	{
		return 5;
	}
	else if (strcmp(str, "heap-sort") == 0)
	{
		return 6;
	}
	else if (strcmp(str, "merge-sort") == 0)
	{
		return 7;
	}
	else if (strcmp(str, "quick-sort") == 0)
	{
		return 8;
	}
	else if (strcmp(str, "counting-sort") == 0)
	{
		return 9;
	}
	else if (strcmp(str, "radix-sort") == 0)
	{
		return 10;
	}
	else if (strcmp(str, "flash-sort") == 0)
	{
		return 11;
	}
	else
		return 0;
}

//
void runAlgorithm(int*a,int n, unsigned long long &count_compare,const char*str, double &time_use)
{
	int k = findAlgorithm(str);
	clock_t start, end;
	switch (k)
	{
	case 1: 
		start = clock();
		selectionSort(a, n, count_compare); 
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break; 
	case 2:
		start = clock();
		insertion_sort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 3:
		start = clock();
		bubble_sort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 4:
		start = clock();
		shakerSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 5:
		start = clock();
		shakerSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 6:
		start = clock();
		heapSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 7:
		start = clock();
		//mergeSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 8:
		start = clock();
		//QuickSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 9:
		start = clock();
		counting_sort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 10:
		start = clock();
		radix_sort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 11:
		start = clock();
		flashSort(a, n, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	default:
		cout << str << " does not exist" << endl;
	}
}
//
int* readFromFile(string file, int& n)
{
	fstream f;
	f.open(file, ios::in);
	if (!f.is_open())
	{
		cout << "Failed to open file" << endl; assert(false);
	}
	f >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
	}
	f.close();
	return a;
}
//
void writetoFile(string file, int n, int* a)
{
	fstream f;
	f.open(file, ios::out);
	if (!f.is_open())
	{
		cout << "Failed to open file"; assert(false);
	}
	f << n << endl;
	for (int i = 0; i < n; i++)
	{
		f << a[i] << " ";
	}
	f << endl;
	f.close();
}
//
void copyArr(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}
//
void ouputParam(const char* str, double time_use, unsigned long long count_compare)
{
	if (strcmp(str, "-both") == 0)
	{
		cout << "Running time:" << time_use << endl;
		cout << "Comparisions:" << count_compare << endl;
	}
	else if (strcmp(str, "-time") == 0)
	{
		cout << "Running time:" << time_use << endl;
	}
	else if (strcmp(str, "-comp") == 0)
	{
		cout << "Comparisions:" << count_compare << endl;
	}
	else {
		cout << str << " does not exist" << endl;
	}
}
//
bool isNum(const char*str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}
//
void CMD1(int argc, const char* argv[])
{
	unsigned long long count_compare=0;
	int n;
	
	double time_use;
	int* a = readFromFile(argv[3], n);
	runAlgorithm(a, n, count_compare, argv[2],time_use);
	writetoFile("output.txt", n, a);
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input file:" << argv[3] << endl;
	cout << "--------------------------" << endl;
	ouputParam(argv[4], time_use, count_compare);
}
//
void CMD2(int argc, const char* argv[])
{
	unsigned long long count_compare = 0;
	double time_use;
	int n=atoi(argv[3]);
	int* a=new int[n];
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size:" << argv[3] << endl;
	cout << "Input order:";
	if (strcmp(argv[4], "-rand") == 0)
	{
		GenerateData(a, n, 0);
		cout << "Randommize" << endl;
	}
	else if (strcmp(argv[4], "-sorted") == 0)
	{
		GenerateData(a, n, 1);
		cout << "Sorted" << endl;
	}
	else if (strcmp(argv[4], "-rev") == 0)
	{
		GenerateData(a, n, 2);
		cout << "Reverse" << endl;
	}
	else if (strcmp(argv[4], "-nsorted") == 0)
	{
		GenerateData(a, n, 3);
		cout << "Nearly Sorted" << endl;
	}
	else {
		cout << argv[4] << " does not exist" << endl;
	}
	writetoFile("input.txt", n, a);
	runAlgorithm(a, n, count_compare, argv[2], time_use);
	writetoFile("output.txt", n, a);
	cout << "-------------------------" << endl;
	ouputParam(argv[5], time_use, count_compare);
}
//
void CMD3(int argc, const char* argv[])
{
	unsigned long long count_compare = 0;
	double time_use;
	int n = atoi(argv[3]);
	int* a = new int[n];
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size:" << argv[3] << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		GenerateData(a, n, i);
		if (i == 0)
		{
			writetoFile("input_1.txt", n, a);
			cout << "\nInput order:Randomize" << endl;
			cout << "---------------------" << endl;
			
		}
		else if (i == 1)
		{
			writetoFile("input_2.txt", n, a);
			cout << "\nInput order:Sorted" << endl;
			cout << "---------------------" << endl ;
		}
		else if (i == 2)
		{
			writetoFile("input_3.txt", n, a);
			cout << "\nInput order:Reversed" << endl;
			cout << "---------------------" << endl;
		}
		else 
		{
			writetoFile("input_4.txt", n, a);
			cout << "\nInput order:Nearly Sorted" << endl;
			cout << "---------------------" << endl << endl;
		}
		runAlgorithm(a, n, count_compare, argv[2], time_use);
		ouputParam(argv[4], time_use, count_compare);
	}
}
//
void CMD4(int argc, const char* argv[])
{
	unsigned long long count_compare1 = 0;
	unsigned long long count_compare2 = 0;
	double time_use1;
	double time_use2;
	int n;
	int* a = readFromFile(argv[4], n);
	int* b = copyArray(a, n);
	runAlgorithm(a, n, count_compare1, argv[2], time_use1);
	runAlgorithm(b, n, count_compare2, argv[3], time_use2);
	//writetoFile("output.txt", n, a);
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm:" << argv[2]<<"  |  "<<argv[3] << endl;
	cout << "Input file:" << argv[4] << endl;
	cout << "Input size:" << n << endl;
	cout << "--------------------------" << endl;
	cout << "Running time:" << time_use1<<"  |  "<<time_use2 << endl;
	cout << "Comparisions:" << count_compare1<<"  |  "<<count_compare2 << endl;

}
//
void CMD5(int argc, const char* argv[])
{
	unsigned long long count_compare1 = 0;
	unsigned long long count_compare2 = 0;
	double time_use1;
	double time_use2;
	int n=atoi(argv[4]);
	int* a = new int[n];

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm:" << argv[2] << "  |  " << argv[3] << endl;
	cout << "Input size:" << argv[4] << endl;
	cout << "Input order:";
	
	if (strcmp(argv[5], "-rand") == 0)
	{
		GenerateData(a, n, 0);
		cout << "Randommize" << endl;
	}
	else if (strcmp(argv[5], "-sorted") == 0)
	{
		GenerateData(a, n, 1);
		cout << "Sorted" << endl;
	}
	else if (strcmp(argv[5], "-rev") == 0)
	{
		GenerateData(a, n, 2);
		cout << "Reverse" << endl;
	}
	else if (strcmp(argv[5], "-nsorted") == 0)
	{
		GenerateData(a, n, 3);
		cout << "Nearly Sorted" << endl;
	}
	writetoFile("input.txt", n, a);
	int* b = copyArray(a, n);
	runAlgorithm(a, n, count_compare1, argv[2], time_use1);
	runAlgorithm(b, n, count_compare2, argv[3], time_use2);
	cout << "--------------------------" << endl;
	cout << "Running time:" << time_use1 << "  |  " << time_use2 << endl;
	cout << "Comparisions:" << count_compare1 << "  |  " << count_compare2 << endl;
}
//
int main(int argc,const char*argv[])
{
	if (argc != 5&&argc!=6)
	{
		cout << "Number of arguments is not exactly" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-a")==0)
	{
		
		if (argc == 5)
		{
			if (isNum(argv[3]))
			{
				CMD3(argc, argv);
			}
			else {
				CMD1(argc, argv);
			}
			
		}
		else {
			CMD2(argc, argv);
		}

	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 5)
		{
			CMD4(argc, argv);

		}
		else {
			CMD5(argc, argv);
		}
	}
	
	return 0;
}