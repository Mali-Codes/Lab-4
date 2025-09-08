#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // cout manipulations
#include <random>   // this was a doozy to learn
using namespace std;

struct Color { int r, g, b; };

int main() {
    mt19937 gen(random_device{}());              
    // it's a Mersenne Twister that is running the random number generation its also called an engine
    // gen(random...) is the variable name and the temp function thats going to basically get a looooong int
    uniform_int_distribution<int> colorCount(25,50);// this basically tames the big number
    uniform_int_distribution<int> rgb(0,255);  // so does this, both to meet our pararmeters
    // the uniform...  under the hood basically uses math and modulos to shrink the numbers to tame them like said before

     int n = colorCount(gen);   // calling the distribution with n as the variable
    vector<Color> colors;   // the vector part that is the container
    colors.reserve(n);      // says hey make n amount of space so we can fit the n in there

    for (int i = 0; i < n; ++i) {
        colors.push_back(Color{ rgb(gen), rgb(gen), rgb(gen) }); //this is where we actually put the colors in the vector
    }

     // Pretty table timeeeee
    const int Wlabel = 8, Wnum = 8; //W is for width

    cout << left  << setw(Wlabel) << "Color#"
         << right << setw(Wnum)   << "R value"
         << right << setw(Wnum)   << "G value"
         << right << setw(Wnum)   << "B value" << '\n';

    cout << string(Wlabel + 3 * Wnum, '-') << '\n';

    for (int i = 0; i < n; ++i) { // loop to print each color in the table
        cout << left  << setw(Wlabel) << (i + 1)
             << right << setw(Wnum)   << colors[i].r
             << right << setw(Wnum)   << colors[i].g
             << right << setw(Wnum)   << colors[i].b << '\n';
    }
    return 0;

}
