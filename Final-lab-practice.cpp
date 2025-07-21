#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void storeData(int array[], int size);
void display();
int search(int array[], int number, int size);
void evenOdd(int array[], int size, int &even, int &odd);
void reverse(int array[], int array2[], int size);
void salesData(float daySale[], int num_days);
float totalSales(float daySale[], int num_days);
float averageFind(float TOTAL, int num_days);
int belowAverageDays(float daySale[], float AVERAGE, int num_days);
int maximumSaleDays(float daySale[], int num_days);
void displayresult(float TOTAL, float AVERAGE, int BelowAverageDays, int MaximumSaleDays);
void storeresult(float TOTAL, float AVERAGE, int BelowAverageDays, int MaximumSaleDays);

void Display1()
{
    cout << "\n";
    cout << "=========== AI Final paper ============" << endl;
    cout << "\n";
    cout << "X) Part A " << endl;
    cout << "Y) Part B" << endl;
    cout << "\n";
}

int main()
{
    Display1();
    char choice;
    cout << "Enter Choice ( X / Y ) : ";
    cin >> choice;

    switch (choice)
    {
    case 'X':
    case 'x':
    {
        cout << "**************** Problem A *****************" << endl;
        cout << "\n";

        int num_days;
        int items;
        cout << "Enter number of days for which do you want to accept the data into an array : ";
        cin >> num_days;

        float daySale[num_days] = {};
        float TOTAL;
        float AVERAGE;
        int BelowAverageDays;
        int MaximumSaleDays;

        salesData(daySale, num_days);
        TOTAL = totalSales(daySale, num_days);
        AVERAGE = averageFind(TOTAL, num_days);
        BelowAverageDays = belowAverageDays(daySale, AVERAGE, num_days);
        MaximumSaleDays = maximumSaleDays(daySale, num_days);
        displayresult(TOTAL, AVERAGE, BelowAverageDays, MaximumSaleDays);
        storeresult(TOTAL, AVERAGE, BelowAverageDays, MaximumSaleDays);

        break;
    }

    case 'Y':
    case 'y':
    {

        cout << "**************** Problem B *****************" << endl;
        cout << "\n";

        int num;
        cout << "Enter how many integar values do you want to store : ";
        cin >> num;
        int size = num;
        int array[size] = {};
        int array2[size] = {};

        storeData(array, size);

        bool running = true;
        char choice1;

        do
        {
            display();
            cout << "Enter choice (a to d) : ";
            cin >> choice1;
            switch (choice1)
            {
            case 'a':
            {
                int n;
                cout << "Enter the integar value to find : ";
                cin >> n;
                int result = search(array, n, size);
                if (result == -1)
                {
                    cout << "Given integar value not found." << endl;
                }
                else
                {
                    cout << "Given integar value is present at index " << result << " of an array." << endl;
                }
                break;
            }
            case 'b':
            {
                int even = 0;
                int odd = 0;
                evenOdd(array, size, even, odd);
                cout << "Even numbers in array : " << even << endl;
                cout << "Odd numbers in array : " << odd << endl;
                break;
            }
            case 'c':
            {
                cout << "Original Array : " ;
                for (int i = 0; i < size; i++)
                {
                    cout << array[i] << " ";
                }
                cout << "\n";
                reverse(array, array2, size);
                cout << "New Array  : ";
                for (int i = 0; i < size; i++)
                {
                    cout << array2[i] << " ";
                }
            }
            break;
            case 'd':
                running = false;
                cout << "Exiting the program.Good Bye !!" << endl;
                break;
            default:
                cout << "Invalid choice.Please enter choice between a to d." << endl;
                break;
            }

        } while (running);
    }
    break;

    default:
        cout << "Invalid choice.Enter X or Y " << endl;
    }

    return 0;
}

void storeData(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
       int value;
        do
        {
            cout << "Enter integar value " << (i + 1) << " : ";
            cin >> value;
            if (value < 0)
            {
                cout << "Please Enter positive integar value : ";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> value;
            }
        } while (value< 0);
        array[i] = value;
    }
}

void display()
{
    cout << "\n";
    cout << "a) Search for a value in the array" << endl;
    cout << "b) Count even and odd numbers " << endl;
    cout << "c) Reverse the array and save in another array " << endl;
    cout << "d) Exit " << endl;
}

int search(int array[], int number, int size)
{
    int* arrayptr = array;
    for (int i = 0; i < size; i++)
    {
        if (*(arrayptr + i ) == number)
        {
            return i;
        }
    }
    return -1;
}

void evenOdd(int array[], int size, int &even, int &odd)
{

    int* arrayptr = array;
    for (int i = 0; i < size; i++)
    {
        if (*(arrayptr + i) % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
}

void reverse(int array[], int array2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array2[i] = array[size - 1 - i];
    }
}

// Function using pointers 

// void reverseArray (int array[],int array2[], int size)
// {
//     int* arrayptr1 = array;
//     int* arrayptr2 = array2;
    
//     for(int i=0; i<size; i++)
//     {
//        *(arrayptr2 + i) = *(arrayptr1 + size - 1 - i);
//     }
// }

void salesData(float daySale[], int num_days)
{
    int items;
    float price;

    for (int i = 0; i < num_days; i++)
    {
        float total = 0;
        do
        {
            cout << "Enter number of items for day " << (i + 1) << " : ";
            cin >> items;
            if (items < 0)
            {
                cout << "Please enter positive integar : ";
                cin.clear();
                cin.ignore(100, '\n');
                cin >> items;
            }
        } while (items < 0);

        for (int j = 1; j <= items; j++)
        {
            do
            {
                cout << "Enter sale price for item " << j << " : ";
                cin >> price;
                if (price < 0)
                {
                    cout << "Please enter positive integar : ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    cin >> price;
                }
            } while (price < 0);

            total += price;
        }
        daySale[i] = total;
    }
}

float totalSales(float daySale[], int num_days)
{
    float Total = 0;
    for (int i = 0; i < num_days; i++)
    {

        Total += daySale[i];
    }
    return Total;
}

float averageFind(float TOTAL, int num_days)
{
    float average;
    average = TOTAL / num_days;

    return average;
}

int belowAverageDays(float daySale[], float AVERAGE, int num_days)
{
    int count = 0;
    for (int i = 0; i < num_days; i++)
    {
        if (daySale[i] < AVERAGE)
        {
            count++;
        }
    }
    return count;
}

int maximumSaleDays(float daySale[], int num_days)
{
    int maximum_sale_day = daySale[0];
    int count = 0;
    for (int i = 0; i < num_days; i++)
    {
        if (daySale[i] > maximum_sale_day)
        {
            maximum_sale_day = daySale[i];
        }
    }

    for (int j = 0; j < num_days; j++)
    {
        if (maximum_sale_day == daySale[j])
        {
            count++;
        }
    }
    return count;
}

void displayresult(float TOTAL, float AVERAGE, int BelowAverageDays, int MaximumSaleDays)
{
    cout << "\n";
    cout << left << setw(40) << "Total Sale Over the period " << setw(20) << "Average Sale " << setw(30) << "Below Average Days " << setw(20) << "Maximum Sale days " << endl;
    cout << left << setw(40) << TOTAL << setw(20) << AVERAGE << setw(30) << BelowAverageDays << setw(20) << MaximumSaleDays << endl;
}

void storeresult(float TOTAL, float AVERAGE, int BelowAverageDays, int MaximumSaleDays)
{
    ofstream outFile;
    outFile.open("report.txt");

    if (!outFile)
    {
        cout << "Error opening file.Please open correct file." << endl;
        return;
    }

    outFile << left << setw(40) << "Total Sale Over the period " << setw(20) << "Average Sale " << setw(30) << "Below Average Days " << setw(20) << "Maximum Sale days " << endl;
    outFile << left << setw(40) << TOTAL << setw(20) << AVERAGE << setw(30) << BelowAverageDays << setw(20) << MaximumSaleDays << endl;

    outFile.close();
}