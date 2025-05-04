#include <cstdio>
#include <iostream>

using namespace std;

class list{

    private:

        int arr[5];
        int size;
    
    public:

        list();
        void insertbeg(int);
        void insertend(int);
        void insertpos(int, int);
        void deletebeg();
        void deleteend();
        void deletepos(int);
        void search(int);
        void display();
        void rotate(int);
};

int main(){

    list l;
    int choice = 0;
    int val;
    int pos;
    int k;
    do{

        printf("\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10: ");
        scanf("%d", &choice);
        switch (choice){

            case 1:

                printf("\nEnter the number to be inserted at the beginning: ");
                scanf("%d", &val);
                l.insertbeg(val);
                break;
            case 2:

                printf("\nEnter the number to be inserted at the end: ");
                scanf("%d", &val);
                l.insertend(val);
                break;
            case 3:

                printf("\nEnter the number to be inserted: ");
                scanf("%d", &val);
                printf("\nEnter the position the number should be inserted in: ");
                scanf("%d", &pos);
                l.insertpos(val, pos);
                break;
            case 4:

                l.deletebeg();
                break;
            case 5:

                l.deleteend();
                break;
            case 6:

                printf("\nEnter the position to be deleted: ");
                scanf("%d", &pos);
                l.deletepos(pos);
                break;
            case 7:

                printf("\nEnter the number to search for: ");
                scanf("%d", &val);
                l.search(val);
                break;
            case 8:

                l.display();
                break;
            case 9:

                printf("\nEnter the number of times to rotate: ");
                scanf("%d", &k);
                l.rotate(k);
                break;
        }
    } while (choice != 10);
}

list::list(){
    
    size = 0;
}

void list::insertbeg(int val){

    if (size == 5){

        printf("\nInsertion is not possible as the list is full.");
    }
    else{

        for (int i = (size - 1); i >= 0; i--){

            arr[i + 1] = arr[i];
        }
        arr[0] = val;
        size++;
    }
}

void list::insertend(int val){

    if (size == 5){

        printf("\nInsertion is not possible as the list is full.");
    }
    else{

        arr[size] = val;
        size++;
    }
}

void list::insertpos(int val, int pos){

    if (size == 5){

        printf("\nInsertion is not possible as the list is full.");
    }
    else{

        if ((pos < 1) || (pos > (size + 1))){

            printf("\nInvalid position.");
        }
        else{

            for (int i = (size -1); i >= pos - 1; i--){

                arr[i + 1] = arr[i];
            }
            arr[pos - 1] = val;
            size++;

        }
    }
}

void list::deletebeg(){

    for (int i = 0; i < size; i++){

        arr[i] = arr[i + 1];
    }
    size--;
}

void list::deleteend(){

    size--;
}

void list::deletepos(int pos){

    if ((pos < 1) || (pos > size)){

            printf("\nInvalid position.");
    }
    else{

        for (int i = (pos - 1); i < size; i++){

            arr[i] = arr[i + 1];
        }
        size--;

    }
}

void list::search(int val){

    int flag = 0;
    if (size == 0){

        printf("\nList is empty.");
    }
    else{

        for (int i = 0; i < size; i++){

            if (arr[i] == val){

                printf("\n%d was found at index %d.", val, i);
                flag = 1;
            }
        }
        if (flag == 0){

            printf("\n%d was not found in the list.", val);
        }
    }
}

void list::display(){

    printf("\n");
    for (int i = 0; i < size; i++){

        printf("\t%d", arr[i]);
    }
}

void list::rotate(int k){

    for (int j = 0; j < k; j++){

        int temp = arr[size - 1];
        for (int i = (size - 1); i > 0; i--){

            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}