#include <cstdio>
#include "Sort.h"

void linearsearch(int arr[], int num){

    int tar;
    printf("\nEnter the number whose index you want to find in the array: ");
    scanf("%d", &tar);
    int a = 0;
    for (int i = 0; i < num; i++){

        if (arr[i] == tar){

            printf("\nTarget found at index %d", i);
            a = 1;
        }
    }
    if (a != 1){

        printf("\nTarget not found");
    }
}

void binarysearch(int arr[], int num){

    int tar;
    printf("\nEnter the number whose index you want to find in the array: ");
    scanf("%d", &tar);
    int a = 0;
    bubblesort(arr, num);
    int left = 0;
    int right = num - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == tar)
            printf("\nTarget was found at index %d in the sorted array", mid);
            a = 1;

        if (arr[mid] < tar)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (a != 1){

        printf("\nTarget not found");
    }  
}

int main(){

    int num;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++){

        printf("\nEnter element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int j = 0; j < num; j++){

        printf("\t%d", arr[j]);
    }
    int choice = 0;
    int option;
    while (choice == 0){

    printf("\n1. Linear Search\n2. Binary Search\n3. Exit\nEnter 1, 2 or 3: ");
    scanf("%d", &option);
    switch (option){

        case 1:

            linearsearch(arr, num);
            break;
        case 2:

            binarysearch(arr, num);
            break;
        case 3:
            choice = 1;
            break;
        }
    }
}
