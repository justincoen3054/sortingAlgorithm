#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void sort(int num[]);
void display(int num[]);

int main() {
    int x = 0, low = 0, high = 9999, count = 0;
    int numbers[10000];

    string line;
    ifstream myfile;
    myfile.open("data10k.txt");

    while (count < 10000) {
        getline(myfile, line);
        stringstream (line) >> x;
        if (x < 50000) {
            numbers[low] = x;
            low++;
        }
        else if (x >= 50000) {
            numbers[high] = x;
            high--;
        }
        count++;
    }
    myfile.close();
    sort(numbers);
    display(numbers);
    return 0;
}

void sort(int num[]) {
    int n = 0, pass = 0, gap = 10000;
    while (pass < 38) {
        if (gap > 1) {
            gap = (gap/1.2473);
        }
        while ((n+gap) < 10000) {
            if (num[n] > num[n+gap]) {
                swap(num[n], num[n+gap]);
            }
            n++;
        }
        n = 0;
        pass++;
    }
}

void display(int num[]) {
    for (int l = 0; l<10000; l++) {
        cout << num[l] <<endl;
    }
}
