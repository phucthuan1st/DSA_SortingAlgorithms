#include "SortAlgorithms.h"

#include "SortAlgorithms.h"

//Get algorithms from input parameters
int getAlgorithm(const char* str)
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


//Run algorithms by parameters
void runAlgorithm(int*a,int n, unsigned long long &count_compare,const char*str, double &time_use)
{
	int k = getAlgorithm(str);
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
		mergeSort(a, 0, n - 1, count_compare);
		end = clock();
		time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
		break;
	case 8:
		start = clock();
		QuickSort(a, 0, n - 1, count_compare);
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
		break;
	}
}


//read array from input file
int* readInputFrom(string file, int& n)
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


//write the output to a file
void writeOutputTo(string file, int n, int* a)
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


//get the ouput parameter from input parameter
void ouputParameter(const char* str, double time_use, unsigned long long count_compare)
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


//check if a string is a number
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


//option 1
void CMD1(int argc, const char* argv[])
{
	unsigned long long count_compare=0;
	int n;
	
	double time_use;
	int* a = readInputFrom(argv[3], n);
	runAlgorithm(a, n, count_compare, argv[2],time_use);
	writeOutputTo("output.txt", n, a);
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input file:" << argv[3] << endl;
	cout << "--------------------------" << endl;
	ouputParameter(argv[4], time_use, count_compare);
}


//option 2
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
	writeOutputTo("input.txt", n, a);
	runAlgorithm(a, n, count_compare, argv[2], time_use);
	writeOutputTo("output.txt", n, a);
	cout << "-------------------------" << endl;
	ouputParameter(argv[5], time_use, count_compare);
}


//option 3
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
			writeOutputTo("input_1.txt", n, a);
			cout << "\nInput order:Randomize" << endl;
			cout << "---------------------" << endl;
			
		}
		else if (i == 1)
		{
			writeOutputTo("input_2.txt", n, a);
			cout << "\nInput order:Sorted" << endl;
			cout << "---------------------" << endl ;
		}
		else if (i == 2)
		{
			writeOutputTo("input_3.txt", n, a);
			cout << "\nInput order:Reversed" << endl;
			cout << "---------------------" << endl;
		}
		else 
		{
			writeOutputTo("input_4.txt", n, a);
			cout << "\nInput order:Nearly Sorted" << endl;
			cout << "---------------------" << endl << endl;
		}
		runAlgorithm(a, n, count_compare, argv[2], time_use);
		ouputParameter(argv[4], time_use, count_compare);
	}
}


//option 4
void CMD4(int argc, const char* argv[])
{
	unsigned long long count_compare1 = 0;
	unsigned long long count_compare2 = 0;
	double time_use1;
	double time_use2;
	int n;
	int* a = readInputFrom(argv[4], n);
	int* b = copyArray(a, n);
	runAlgorithm(a, n, count_compare1, argv[2], time_use1);
	runAlgorithm(b, n, count_compare2, argv[3], time_use2);
	//writeOutputTo("output.txt", n, a);
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm:" << argv[2]<<"  |  "<<argv[3] << endl;
	cout << "Input file:" << argv[4] << endl;
	cout << "Input size:" << n << endl;
	cout << "--------------------------" << endl;
	cout << "Running time:" << time_use1<<"  |  "<<time_use2 << endl;
	cout << "Comparisions:" << count_compare1<<"  |  "<<count_compare2 << endl;

}


//option 5
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
	writeOutputTo("input.txt", n, a);
	int* b = copyArray(a, n);
	runAlgorithm(a, n, count_compare1, argv[2], time_use1);
	runAlgorithm(b, n, count_compare2, argv[3], time_use2);
	cout << "--------------------------" << endl;
	cout << "Running time:" << time_use1 << "  |  " << time_use2 << endl;
	cout << "Comparisions:" << count_compare1 << "  |  " << count_compare2 << endl;
}
//

//Menu control program from input to output
int MenuController(int argc, const char** argv) {
    if (argc != 5 && argc!= 6)
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