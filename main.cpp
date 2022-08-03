#include <iostream>

#define MAX 1000

typedef char *string;

typedef struct
{
    string name;
    int num;
}
object;

object things[MAX];

void merge(int n, int mid, int end);
void mergeSort(int n, int end);



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void merge(int n, int mid, int end)
{
    //printf("inside merge...\n");
    int first_half = mid - n + 1;
    int second_half = end - mid;

    int nums1[first_half], votes2[second_half];
    string names1[first_half], names2[second_half];

    for (int i = 0; i < first_half; i++)
    {
        nums1[i] = things[n + i].num;
        names1[i] = things[n + i].name;

    }

    for (int j = 0; j < second_half; j++)
    {
        votes2[j] = things[mid + 1 + j].num;
        names2[j] = things[mid + 1 + j].name;
    }


    int a, b, c;
    a = 0;
    b = 0;
    c = n;

    while (a < first_half && b < second_half)
    {
        if (nums1[a] <= votes2[b])
        {
            things[c].num = nums1[a];
            things[c].name = names1[a];
            a++;
        }
        else
        {
            things[c].num = votes2[b];
            things[c].name = names2[b];
            b++;
        }
        c++;
    }

    while (a < first_half)
    {
        things[c].num = nums1[a];
        things[c].name = names1[a];
        a++;
        c++;
    }

    while (b < second_half)
    {
        things[c].num = votes2[b];
        things[c].name = names2[b];
        b++;
        c++;
    }

}

void mergeSort(int n, int end)
{

    int mid = n + (end - n) / 2;

    //Checking math...
    //printf("n is: %d\n", n);
    //printf("end is: %d\n", end);
    if (n >= end)
    {
        //printf("n >= end\n");
        return;
    }
    else if (n < end)
    {
        //printf("mid is: %d\n", mid);
        mergeSort(n, mid);
        mergeSort(mid + 1, end);
        //printf("about to merge...\n");
        merge(n, mid, end);
    }

}
