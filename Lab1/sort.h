#include <cstdio>

void bubblesort(int arr[], int num){

    for (int i = 0; i < num - 1; i++){

        for (int j = i + 1; j < num; j++){

            if (arr[j] < arr[i]){

                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int num){

    for (int i = 0; i < num - 1; i++) {

        int minIdx = i;
        for (int j = i + 1; j < num; j++) {

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void insertionsort(int arr[], int num){

    for (int i = 1; i < num; i++) {

        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
