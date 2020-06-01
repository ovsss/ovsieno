#include <iostream>
//різні методи сортування масиву

using namespace std;

void initArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 100;

    }
}

void insertionSort(int* arr, int n) //вставками
{
    int key = 0;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
            arr[i + 1] = key;
        }
    }
}

void bubbleSort(int* arr, int n) //бульбашкою

{
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j=(n-1); j>i; j--)
        {
            if (arr[j-1] > arr[j])
            {
                // міняємо елементи місцями
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void swapEl(int* arr, int i)
{
    int buff;
    buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
}

void ShakerSort(int* arr, int n) //перемішуванням
{
    int leftMark = 1;
    int rightMark = n - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if (arr[i - 1] > arr[i]) swapEl(arr, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
            if (arr[i - 1] > arr[i]) swapEl(arr, i);
        rightMark--;
    }

}
void quickSort(int* arr, int n) // швидке
 {
        //покажчики в початок та кінець масиву
        int i = 0;
        int j = n - 1;

        //центральний элемент масиву
        int mid = arr[n / 2];

        //ділимо масив
        do {
            //проходимо по елементах, шукаємо ті, які треба перекинути в другу частину
            //в лівій частині масиву пропускаемо(залишаємо на місці) элементи, які меньші за центральний
            while (arr[i] < mid)
            {
                i++;
            }
            //в правій частині пропускаємо елементи, які більші за центральний
            while (arr[j] > mid)
            {
                j--;
            }

            //міняємо елементи місцями
            if (i <= j)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);


        //рекурсивні виклики, якщо залишилось що сортувати
        if (j > 0) {
            //ліва частина
            quickSort(arr, j + 1);
        }
        if (i < n) {
            //права частина
            quickSort(&arr[i], n - i);
        }
    }
    
void shellSort(int*arr, int n)
{
    //починаємо з великого розриву, потім його зменшуємо
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
             int j;
              for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void outputArr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " | ";
    }

}


void choose(int sort,int* arr, int n)

{
    switch (sort)
    {
    case 1:
        insertionSort(arr, n);
        cout << "\nВідсортований масив: \n";
        outputArr(arr, n);
        break;



    case 2:/*бульбашка*/
        bubbleSort(arr, n);
        cout << "\nВідсортований масив:  \n";
        outputArr(arr, n);
        break;


    case 3:
        ShakerSort(arr, n);
        cout << "\nВідсортований масив:  \n";
        outputArr(arr, n);
        break;

    case 4:
        quickSort(arr, n);
        cout << "\nВідсортований масив:  \n";
        outputArr(arr, n);
        break;

    case 5:
        shellSort(arr, n);
        cout << "\nВідсортований масив:  \n";
        outputArr(arr, n);
        break;

    }
        
}


int main()
{
    setlocale(0, "");
    int n;
    cout << "Введіть розмір масиву:" << endl;
    cin >>n;
        int* arr = new int[n];// наш динамічний одновимірний масив
        initArr(arr, n);
        outputArr(arr, n);
        insertionSort(arr, n);
        bubbleSort(arr, n);
        ShakerSort(arr, n);
        quickSort(arr, n);
        shellSort(arr, n);
       
  
        int sort = 0;
        do {
            cout << "\nОберіть метод сортування:\n"
                "0 - Зупинити програму \n"
                "1 - Сортування вставками \n"
                "2 - Сортування бульбашкою \n"
                "3 - Сортування перемішуванням \n"
                "4 - Швидке сортування \n"
                "5 - Сортування Шелла\n";
            cout << "------\n" ;
            cin >> sort;
            cout << "------" << endl;
            choose(sort, arr, n);

        } while (sort != 0);
      
      


        return 0;
}

