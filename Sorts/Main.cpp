#include <iostream>
#include <vector>
#include <string>
#include <sstream>




bool inputCheck(std::string userString)
{
	std::string numbers = "0123456789";
	int match = 0;
	for (int i = 0; i < userString.length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (userString[i] == numbers[j])
			{
				match = 1;
				break;
			}
		}
		if (match != 1)
		{
			std::cout << "Please follow the instructions...\n";
			return false;
		}
		match = NULL;
	}
	return true;
}

void arrDisplay(std::vector<int> Arr)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		std::cout << Arr[i] << ' ';
	}
}

class sortClass
{
public:

	std::vector<int> userArr;
	int arrSize = 0;

	void collect()
	{
		userArr.clear();
		std::string arrElement;
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << "Enter Element " << i + 1 << ": ";
			long long int tempVar = NULL;
			std::cin >> arrElement;
			//check if number
			if (!inputCheck(arrElement))
			{
				arrElement = "";
				continue;
			}

			//convert to int and store in vector
			std::stringstream convert(arrElement);
			convert >> tempVar;
			userArr.push_back(tempVar);
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

	std::vector<int> merge(std::vector<int> vec1, std::vector<int> vec2)
	{
		std::vector<int> newVec;

		int idx1 = 0;
		int idx2 = 0;

		size_t size1 = vec1.size();
		size_t size2 = vec2.size();

		while (idx1 < size1 && idx2 < size2)
		{
			if (vec1[idx1] < vec2[idx2])
			{
				newVec.push_back(vec1[idx1]);
				idx1++;
			}
			else
			{

				newVec.push_back(vec2[idx2]);
				idx2++;
			}
		}

		if (idx1 == size1)
		{
			while (idx2 < size2)
			{
				newVec.push_back(vec2[idx2]);
				idx2++;
			}
		}
		else
		{
			while (idx1 < size1)
			{
				newVec.push_back(vec1[idx1]);
				idx1++;
			}
		}

		return newVec;

	}


	std::vector<int> mergesort(std::vector<int> vectorr)
	{
		size_t vecSize = vectorr.size();

		if (vecSize <= 1)
		{
			return vectorr;
		}

		std::vector<int> left;
		std::vector<int> right;

		size_t mid = vecSize / 2;

		for (int i = 0; i < vecSize; i++)
		{
			if (i < mid)
			{
				left.push_back(vectorr[i]);
			}
			else
			{
				right.push_back(vectorr[i]);
			}
		}

		left = mergesort(left);
		right = mergesort(right);

		return merge(left, right);

	};


	std::vector<int> quickSort(std::vector<int> vec)
	{
		size_t vecSize = vec.size();

		if (vecSize <= 1)
		{
			return vec;
		}

		int pivot = vec.back();
		vec.pop_back();

		std::vector<int> lesser;
		std::vector<int> greater;

		for (int i = 0; i < vecSize - 1; i++)
		{
			if (vec[i] < pivot)
			{
				lesser.push_back(vec[i]);
			}
			else
			{
				greater.push_back(vec[i]);
			}
		}

		std::vector<int> tempVec;

		for (size_t i = 0; i < lesser.size(); i++)
		{
			tempVec.push_back(quickSort(lesser)[i]);
		}
		tempVec.push_back(pivot);
		for (size_t i = 0; i < greater.size(); i++)
		{
			tempVec.push_back(quickSort(greater)[i]);
		}

		return tempVec;
	}

	//Other Sorts

};


int main()
{
	sortClass newGame;
	//welcome user 
	std::cout << "Welcome to the sort game! \n";

	int endGame = 0;
	std::string play;
	while (endGame == 0)
	{
		std::cout << "\nIf you do not wish to continue playing, enter the number 9, if you do, enter anything else!\n";
		std::cout << "	Choice: ";
		std::cin >> play;
		if (play == "9")
		{
		std::cout << "\nHope you enjoyed your say! \n\nCya.";
		endGame = 1;
		continue;
		}

		//get array size
		std::string arrsize = "";
		std::cout << "Please enter the array size: ";
		std::cin >> arrsize;

		if (!inputCheck(arrsize))
		{
			continue;
		}
		std::stringstream convert(arrsize);
		convert >> newGame.arrSize;

		//get array elements
		newGame.collect();

		//get what sort user wants to use


		std::string sortChoice = "";
		std::cout << "To chose between the types of sorts, enter the number\n  1: for selection sort. \n  2: for insertion sort. \n  3: for merge sort. \n  4: for quick sort. Or \n  5: enter to restart/quit.";
		
		std::vector<int> oldvec = newGame.userArr;
		while (true)
		{
			std::cout << "\n\nYour choice (1, 2, 3, 4, 5): ";
			std::cin >> sortChoice;


			if (sortChoice == "1") //selection
			{
				std::cout << "Your old array looked like: ";
				arrDisplay(oldvec);

				std::cout << "\nYour new array looks like: ";
				newGame.selectionSort();
				arrDisplay(newGame.userArr);
			}
			else if (sortChoice == "2") //insertion
			{
				std::cout << "Your old array looked like: ";
				arrDisplay(oldvec);

				std::cout << "\nYour new array looks like: ";
				newGame.insertionSort();
				arrDisplay(newGame.userArr);
			}
			else if (sortChoice == "3") //merge
			{
				std::cout << "Your old array looked like: ";
				arrDisplay(oldvec);

				std::cout << "\nYour new array looks like: ";
				arrDisplay(newGame.mergesort(newGame.userArr));
			}
			else if (sortChoice == "4") //qick
			{
				std::cout << "Your old array looked like: ";
				arrDisplay(oldvec);

				std::cout << "\nYour new array looks like: ";
				arrDisplay(newGame.quickSort(newGame.userArr));
			}
			else if (sortChoice == "5")
			{
				break;
			}
	
			else //false input
			{
				std::cout << "Please follow the instructions....\n\n";
				continue;
			}
		}
		
	}
}