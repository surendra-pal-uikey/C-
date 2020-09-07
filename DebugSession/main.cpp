#include <iostream>

using namespace std;


//printing the substring of the tree

void printSubstringUtil(string str, int currentIndex, string result, int n){
    if( currentIndex == n ){
        cout << result << endl;
        cout << "____________________________________" << endl;
        return;
    } else {
        printSubstringUtil(str, currentIndex+1, result + str[currentIndex], n);
        printSubstringUtil(str, currentIndex+1, result, n);
    }
}
void printSubstring(string str){
    int n = str.length();
    printSubstringUtil(str, 0, "", n); //(string, currentIndex, result, size)
}
/////////////////////////////////////////////////////////////////////////


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    cin >> str;

    printSubstring(str);
    return 0;
}
