#include <iostream>

using namespace std;
class shape{

    private:

        int len,bre,hei,area;

    public :

        shape(){

            len = 1;
            bre = 1;
            hei = 1;
        }
        void setlen(int l){

            len = l;
        }
        void setbre(int b){

            bre = b;
        }
        void sethei(int h){

            hei = h;
        }
        int square(){

            area = len * len;
            return area;
        }
        int rectangle(){

            area = len * bre;
            return area;
        }
        int cube(){

            area = 6 * len * len;
            return area;
        }
        int cuboid(){

            area = 2 * ((len * bre) + (bre * hei) + (hei * len));
            return area;
        }
};

int main(){

    shape s;
    int ch = 0;
    do{

        cout << "\n1. Square\n2. Rectangle\n3. Cube\n4. Cuboid\n5. Exit\nEnter 1, 2, 3, 4 or 5: ";
        int l, b, h;
        cin >> ch;
        switch(ch){

            case 1:

                cout << "\nEnter the length of the side of the square: ";
                cin >> l;
                s.setlen(l);
                cout << "\nArea of the square is: " << s.square();
                break;
            case 2:

                cout << "\nEnter the length of the rectangle: ";
                cin >> l;
                cout << "\nEnter the breadth of the rectangle: ";
                cin >> b;
                s.setlen(l);
                s.setbre(b);
                cout << "\nArea of the rectangle is: " << s.rectangle();
                break;
            case 3:

                cout << "\nEnter the length of the side of the cube: ";
                cin >> l;
                s.setlen(l);
                cout << "\nArea of the cube is: " << s.cube();
                break;
            case 4:

                cout << "\nEnter the length of the cuboid: ";
                cin >> l;
                cout << "\nEnter the breadth of the cuboid: ";
                cin >> b;
                cout << "\nEnter the height of the cuboid: ";
                cin >> h;
                s.setlen(l);
                s.setbre(b);
                s.sethei(h);
                cout << "\nArea of the cuboid is: " << s.cuboid();
                break;
        }
    } while (ch != 5);
}