#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Fact(int num){
    if (num == 1)
        return 1;
    return num*Fact(num-1);
}

main() {
    char choice;
    float radians, approx = 1;
    int terms, i, j;

    cout << "Enter [c]os(x), [s]in(x) or [e]^x: ";
    cin >> choice;
    cout << "\nEnter the degrees (in radians): ";
    cin >> radians;
    cout <<"\nEnter the no. of terms: ";
    cin >> terms;

    switch (choice) {
        case 'e':
            for (i = 1; i <= terms; i++)
                approx += ((pow(radians, i))/Fact(i));
            break;

        case 's':
            for(i = 1,j = 1;i <= terms; i++, j = j + 2)
            {
                if(i%2 == 0)
                    approx -= pow(radians,j)/Fact(j);

                else
                    approx += pow(radians,j)/Fact(j);
            }
            break;

        case 'c':
            for(i=1,j=1;i <= terms; i++, j = j + 2)
            {
                if(i%2 == 0)
                    approx += pow(radians,j)/Fact(j);
                else
                    approx -= pow(radians,j)/Fact(j);
            }
            break;
        default:
            cout << "Enter a valid response!\n";
            break;
    }

    cout << "The approximation is: " << approx;

}
