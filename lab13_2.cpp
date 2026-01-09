#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}
void updateImage(bool image[][M], int s, int x, int y){
    if(s == 0 && x == 0 && y == 0)
        return;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            double dist = sqrt((i - x)*(i - x) + (j - y)*(j - y));
            if(dist <= s - 1){
                image[i][j] = true;
            }
        }
    }
}
void showImage(const bool image[][M]){
    for(int i = 0; i < M + 2; i++)
        cout << "-";
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << "|";
        for(int j = 0; j < M; j++){
            if(image[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
    for(int i = 0; i < M + 2; i++)
        cout << "-";
    cout << endl;
}