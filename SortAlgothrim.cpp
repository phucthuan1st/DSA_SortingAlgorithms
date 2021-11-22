#include<iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;


template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
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
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
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
	while (++count_cmp && Left < Right)
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

// Hàm selection sort
void selectionSort(int* arr, int n, unsigned long long& count_cmp)
{
	int i, j, min_idx;

	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; ++count_cmp && i < n - 1; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx = i;
		for (j = i + 1; ++count_cmp && j < n; j++)
		{
			if (++count_cmp && arr[j] < arr[min_idx])
			{
				min_idx = j;
			}

		}

		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(arr[min_idx], arr[i]);
	}
}

void ImplMerge(int* arr, int left, int mid, int right, unsigned long long& count_cmp)
{
	int n1 = mid - left + 1; //Số phần tử cho nửa bên trái

	int n2 = right - mid;   //Số phần tử cho nửa bên phải

	//Tạo mảng tạm
	int* Left = new int[n1];
	int* Right = new int[n2];

	//Copy dữ liệu sang mảng tạm
	for (int i = 0; ++count_cmp && i < n1; i++)
	{
		Left[i] = arr[left + i];
	}

	//Copy dữ liệu sang mảng tạm
	for (int j = 0; ++count_cmp && j < n2; j++)
	{
		Right[j] = arr[mid + 1 + j];
	}

	//Khởi tạo chỉ số bắt đầu mảng con đầu tiên
	int i = 0;

	//Khởi tạo chỉ số bắt đầu mảng con thứ hai
	int j = 0;

	//Khởi tạo chỉ số mảng lưu kết quả
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

	//Copy các phần tử còn lại của mảng bên trái vào mảng kết quả nếu có
	while (++count_cmp && i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	//Copy các phần tử còn lại của mảng bên phải vào mảng kết quả nếu có
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
		//Tìm điểm chính giữa để chia mảng thành hai nửa
		int mid = left + (right - left) / 2;

		//Sắp xếp mảng cho nửa bên trái
		mergeSort(arr, left, mid, count_cmp);

		//Sắp xếp mảng cho nửa bên phải
		mergeSort(arr, mid + 1, right, count_cmp);

		//Tạo biến đếm phép so sánh của hàm phụ
		unsigned long long count_cmp_ImplMerge = 0;

		//Hợp nhất hai nửa được sắp xếp ở trên
		ImplMerge(arr, left, mid, right, count_cmp_ImplMerge);

		//Tăng đếm so sánh trong hàm phụ
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
        
    }


int main()
{
	
	int n;
	clock_t start, end;
	double duration;
	ofstream ofs("KQ1.csv");
	ofs << "Data Order,Data Size,Algorithms,Running Time,Comparisions" << endl;
	for (int i = 3; i < 4; i++)
	{
		if (i == 0) ofs << "Sorted Data,";
		if (i == 1) ofs << "Nearly sorted Data,";
		if (i == 2) ofs << "Reverse sorted Data,";
		if (i == 3) ofs << "Randomized Data,";
		for (int j = 5; j < 6; j++)
		{
			if (j == 0)
			{
				n = 10000;
				ofs << n << ",";
			}
			else if (j == 1) {
				n = 30000;
				ofs << n << ",";
			}
			else if (j == 2) {
				n = 50000;
				ofs << n << ",";
			}
			else if (j == 3) {
				n = 100000;
				ofs << n << ",";
			}
			else if (j == 4) {
				n = 300000;
				ofs << n << ",";
			}
			else if (j == 5) {
				n = 500000;
				ofs << n << ",";
			}
			int* arr = new int[n];
			GenerateData(arr, n, i);
			
			for (int k = 0; k < 3; k++)
			{
				if (k == 0 ) {
					ofs << "QuickSort,";
					int* arr1 = arr;
					start = clock();
					unsigned long long count_cmp = 0;
					QuickSort(arr1,0, n-1, count_cmp);
					end = clock();

					duration = (double(end - start)) / CLOCKS_PER_SEC;
					ofs << duration << ",";
					ofs << count_cmp << ",";
					ofs << endl;
					ofs << ",,";
				}
				if (k == 1) {
					ofs << "ShakerSort,";
					int* arr1 = arr;
					start = clock();
					unsigned long long count_cmp = 0;
					shakerSort(arr1, n, count_cmp);
					end = clock();

					duration = (double(end - start)) / CLOCKS_PER_SEC;
					ofs << duration << ",";
					ofs << count_cmp << ",";
					ofs << endl;
					ofs << ",,";
				}
				if (k == 2) {
					if (j != 5) {
						ofs << "CountingSort,";
						int* arr1 = arr;
						start = clock();
						unsigned long long count_cmp = 0;
						counting_sort(arr1, n, count_cmp);
						end = clock();

						duration = (double(end - start)) / CLOCKS_PER_SEC;
						ofs << duration << ",";
						ofs << count_cmp << ",";
						ofs << endl;
						ofs << ",";
					}
					else {
						ofs << "CountingSort,";
						int* arr1 = arr;
						start = clock();
						unsigned long long count_cmp = 0;
						counting_sort(arr1, n, count_cmp);
						end = clock();

						duration = (double(end - start)) / CLOCKS_PER_SEC;
						ofs << duration << ",";
						ofs << count_cmp << ",";
						ofs << endl;
						
					}
				}
			}
		}
	}
	ofs.close();

    
}
