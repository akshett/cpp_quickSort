#include <iostream>

template <typename T>
void quicksort(T* arr, int lo, int hi)
{
    //std::cout << "Lo: " << lo << '\n';
    //std::cout << "Hi: " << hi << '\n';
    if (lo >= hi) return;
    int base = lo;
    int i = lo;
    int end = hi;
    T cmp = arr[base];
    while(i <= end)
    {
	//std::cout << "i: " << i << '\n';
	//std::cout << "Base: " << base << '\n';
	//std::cout << "End: " << end << '\n';
        if (arr[i] < cmp)
	{
	    T temp = arr[i];
	    arr[i] = arr[base];
	    arr[base] = temp;
	    i++;
	    base++;
	}
	else if(arr[i] > cmp)
	{
	    T temp = arr[i];
	    arr[i] = arr[end];
	    arr[end] = temp;
	    end--;
	}
	else
	    i++;
    }
    //std::cout << "Base: " << base << '\n';
    //std::cout << "End: " << end << '\n';
    quicksort(arr, lo, base-1);
    quicksort(arr, i, hi);
}

int main()
{
    int arr_size;
    std::cout << "Enter array size: ";
    std::cin >> arr_size;
    int *arr = new int[arr_size];
    for (int i=0; i< arr_size; i++)
    {
        std::cin >> arr[i];
    }
    quicksort(arr, 0, arr_size-1);
    std::cout << "Here is the sorted array:" << '\n';
    for (int j=0; j < arr_size; j++)
    {
        std::cout << arr[j] << " ";
    }
    std::cout << '\n';
    return 0;
}
