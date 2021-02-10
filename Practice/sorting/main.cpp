#include <iostream>

/**********************************************************************
* class name: FOO
*
* Description:
*        Array Based Stack
*
* Private Methods:
*        See Class below
*
* Public Methods:
*        See Main program
*
* A class created with the express purpose of writing sorting
* algorithms
*
**********************************************************************/

class FOO
{
    private:
        int *A;
        int size;
    
    public:
    FOO()                          //Default constructor of the FOO class
    {
        size = 10;
        A = new int[size];
    }

    FOO(int s)                     //Parameterized constructor of the FOO class
    {
        size = s;
        A = new int[s];    
    }

    void swap( int *a, int *b)    //Swap function to be used in sorting algorithms
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;

    }

    void fill()                   //Fills the array with random integers
    {
        for (int i = 0; i < size; i++)
        {
            A[i] = (rand()%100);
        }
    }

  
    void bubbleSort()               //Bubble sort BigO(n^2)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (A[i] < A[j])
                {
                    swap(&A[i], &A[j]);
                }
            }
        }
    }

    void selectionSort()            //Selection sort BigO(n^2) (worst case)
    {
        int i, j, min;
        
        for (i = 0; i < size; i++)
        {
            min = i;
            
            for (j = i+1; j < size; j++)
            {
                if (A[j] < A[min])
                {
                 min = j;
                }
            }
            swap(&A[i], &A[min]);
        }
    }




    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
};

class ARRAYHEAP             //Could have been called MINHEAP... or BANANA, you know, what ever
{
    private:
    int *a;                // Container
    int currentSize;       // I think this has the current size in it
    int heapSize;          // Size of the array
    int back;              // End of the heap

    /********************************************************************************************
     * leftChild 
     * 
     * Use:
     *     Calculates the index of the left child
     * 
     * Returns:
     *     integer used as an index
     ********************************************************************************************/
    int leftChild(int i)
    {
        return (2 * i);     // I know the parens are not needed, I just think it looks better
    }

    /********************************************************************************************
     * rightChild 
     * 
     * Use:
     *     Calculates the index of the right child
     * 
     * Returns:
     *     integer used as an index
     ********************************************************************************************/
    int rightChild(int i)
    {
        return ((2 * i) + 1);
    }

     /********************************************************************************************
     * parent 
     * 
     * Use:
     *     Calculates the index of the parent
     * 
     * Returns:
     *     integer used as an index
     ********************************************************************************************/
    int parent(int i)
    {
        return (i / 2);
    }
    
    /********************************************************************************************
     * bubbleUp
     * 
     * Use:
     *     "Bubbles" a value up to fufil the heap property after the item is added to the rear of
     *     the array.
     * 
     * Returns:
     *     NULL
     ********************************************************************************************/
    void bubbleUp(int i)
    {
        int p = 0;
        while (i > 0)
        {
            p = parent(i);
            if (a[i] < a[p])
            {
                swap(i,p);
            }else
            {
                return;
            }
        }
    }

    /********************************************************************************************
     * bubbleDown
     * 
     * Use:
     *     "Bubbles" a value down to fufil the heap property after the item is removed and the
     *     last item is swapped to the front
     * 
     * Returns:
     *     NULL
     ********************************************************************************************/
    void bubbleDown(int i)
    {
        int p = 0;
        while (i < back)
        {
            p = parent(i);
            if (a[i] < a[p])
            {
                swap(i,p);
            }else
            {
                return;
            }
        }
    }

    /********************************************************************************************
     * bubbleDown
     * 
     * Use:
     *     Honestly, the name is a dead give away, swiches the data in two indexes
     * 
     * Returns:
     *     NULL
     ********************************************************************************************/
    void swap(int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public:
    
    /********************************************************************************************
     * Default Constructor
     ********************************************************************************************/
    ARRAYHEAP()
    {
        a = new int[100];
        back = -1;
        heapSize = 100;
        currentSize = 0;
    }

    /********************************************************************************************
     * push
     * 
     * Use:
     *     Add data to the heap
     * 
     * Returns:
     *     NULL
     ********************************************************************************************/
    void push(int x)
    {
        a[back] = x;            // Push item into the array
        back++;                 // Move the back of the heap
        currentSize++;          // Increment the size
        bubbleUp(back - 1);     // Move item to the correct spot
    }

    /********************************************************************************************
     * print
     * 
     * Use:
     *     Print out the items in the heap
     * 
     * Returns:
     *     NULL
     ********************************************************************************************/
    void print()
    {
        for (int i = 1; i < currentSize; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    /********************************************************************************************
     * extract
     * 
     * Use:
     *     Remove items from the heap
     * 
     * Returns:
     *     int
     ********************************************************************************************/
    int extract()
    {
        int temp = a[1];    // Copy the top of the heap
        back--;             // Move back to point of the last item in the heap
        a[1] = a[back];     // Swap the back item to the top of the heap
        bubbleDown(1);      // Bubble the top down to the correct location    
    }

};


int main()
{
    FOO bar;
    FOO bar2(15);

    ARRAYHEAP bar3;

    for (int i = 0; i < 30; i++)
    {
        bar3.push((rand()%100)+1);
    }
    
    bar.fill();
    bar2.fill();
   
    std::cout << "Unsorted bar:\n";
    bar.print();
    bar.bubbleSort();

    std::cout << "\nSorted bar:\n";
    bar.print();

    std::cout << "\n\nUnsorted bar2:\n";
    bar2.print();
    bar2.selectionSort();

    std::cout << "\nSorted bar2:\n";
    bar2.print();

    std::cout << std::endl;
    bar3.print();


}