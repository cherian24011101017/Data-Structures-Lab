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
    for (int k = 0; k < num; k++){

        printf("\t%d", arr[k]);
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
    for (int k = 0; k < num; k++){

        printf("\t%d", arr[k]);
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
    for (int k = 0; k < num; k++){

        printf("\t%d", arr[k]);
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

    printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\nEnter 1, 2 ,3 or 4: ");
    scanf("%d", &option);
    switch (option){

        case 1:

            bubblesort(arr, num);
            break;
        case 2:

            selectionsort(arr, num);
            break;
        case 3:

            insertionsort(arr, num);
            break;
        case 4:
            choice = 1;
            break;
        }
    }
}
