#include <iostream>
#include <vector>


class sortClass
{
public:

	std::vector<int> userArr;
	int arrSize;

	void collect()
	{
		int arrElement;
		for (int i = 0; i < arrSize; i++)
		{
			std::cin >> arrElement;
			userArr.push_back(arrElement);
		}
	}

	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	void selectionSort()
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			int currentMin = i;
			for (int j = i + 1; j < arrSize; j++)
			{
				if (userArr[j] < userArr[currentMin])
				{
					swap(userArr[j], userArr[currentMin]);
				}

			}
		}

	}

	void insertionSort()
	{
		for (int i = 0; i < arrSize; i++)
		{
			int j = i;
			while (j > 0 && userArr[j] < userArr[j - 1])
			{
				swap(userArr[j], userArr[j - 1]);
				j--; 
			}
		}
	}

	void mergeSplit(int low, int high)
	{
		if (low < high)
		{
			int middle = low + (high - low) / 2;

			mergeSplit(low, middle);

			mergeSplit(middle + 1, high);



		}
	}

	void mergeSort(std::vector<int> arr, int size)
	{

	}

	void quickSort()
	{

	}

	//Other Sorts
};


int main()
{
	sortClass test;
	test.arrSize = 10;
	test.collect();

	// this is the test sort place
	test.insertionSort(); 


	for (int i = 0; i < test.arrSize; i++)
	{
		std::cout << test.userArr[i];
	}

}