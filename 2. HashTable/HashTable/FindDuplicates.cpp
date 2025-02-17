#include <iostream>
#include <stack>
using namespace std;

//findDuplicates: create a new array of the same size. 
//For each element in the source array, if it hasn't been stored in the
//new one, it's put into the new array. If it has, then it's a duplicate.
void findDuplicates(int arr[], int size)
{
	//initialize the newArr
	int* newArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = -1;
	}

	//loop through each element in arr
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		bool found = false;
		//check if arr[i]'s already in the newArr.
		while (count < size && newArr[count]!=-1)
		{
			if (newArr[count] == arr[i])
			{
				found = true;
				break;
			}
			count++;
		}
		//if it has, its a duplicate. if not, then put it into the new array.
		if (found)
		{
			cout << arr[i] << " ";
		}
		else {
			newArr[count] = arr[i];
		}
	}
	delete[] newArr;
}

int main()
{
	int arr[] = { 1,2,2,3 };
	findDuplicates(arr, 4);
}