// Playground to test things in
//

#include <iostream>
#include <vector>
#include <algorithm>


struct mystruct {

	int A;
	int B;
	mystruct(int a, int b)
	{
		A = a;
		B = b;
	}
};

std::vector<mystruct*> items;
void heapify(std::vector<mystruct*> a, int i, int b);
void heapSort(std::vector<mystruct*> a, int n);

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		mystruct *a = new mystruct(rand(), rand());
		items.push_back(a);
	}

	mystruct *s = new mystruct(0,0); 
	for (std::vector<mystruct*>::iterator it = items.begin() ; it != items.end(); it++)
	{
		if ((*it)->A > s->A)
		{
			s = (*it);
		}
	}

	int n = sizeof(items) / sizeof(items[0]);

	std::cout << "before heap:\t";
	for (const auto &i : items)
	{
		std::cout << i->A << i->B << ' ';
	}
	system("pause");
		
	heapSort(items, s->A);
		
	std::cout << "\nsorted:\t";
	for (const auto &i : items)
	{
		std::cout << i->A << i->B << ' ';
	}

	system("pause");
	
	
	return 0;
}

void heapify(std::vector<mystruct*> arr, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}



}
// main function to do heap sort 
void heapSort(std::vector<mystruct*> arr, int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		std::swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

