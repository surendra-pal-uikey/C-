#include <bits/stdc++.h>

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

///check if given number is pallindrome or not

bool functionCheckPallin(int n){
    int storage = n;
    int newNumber = 0;

    if( n < 10 && n >= 0 ){
        return true;
    }

    if( n < 0 ){
        return false;
    }

    while( n > 0 ){
        int rem = n%10;
        newNumber = newNumber*10 + rem;
        n = n/10;
    }

    if( newNumber == storage ){
        return true;
    }
    return false;
}

///print the 1 to n number


void print1ToN(int n){

    //base condition
    if( n == 0 ){
        return;
    }

    //hypothesis

    print1ToN( n-1 );

    //Induction

    cout << n << endl;

}

void insertIntoArrayAtCorrectPos( vector<int> &vec, int value ){

    if( vec.size() == 0 || vec[ vec.size()-1 ] <= value ){
        vec.push_back( value );
        return;
    }

    int temp = vec[ vec.size()-1 ];
    vec.pop_back();

    insertIntoArrayAtCorrectPos( vec, value );
    vec.push_back( temp );

}
void sortArray(vector<int> &vec){
    if( vec.size() == 1 ){
        return;
    }

    int temp = vec[ vec.size()-1 ];
    vec.pop_back();

    sortArray( vec );

    insertIntoArrayAtCorrectPos( vec, temp );

}
void insertIntoStack( stack<int> &st, int value ){

    if( st.size() == 0 || st.top() <= value ){
        st.push( value );
        return;
    }

    int temp = st.top(); st.pop();

    insertIntoStack( st, value );

    st.push( temp );
}
void sortStack( stack<int> &st ){
    if( st.size() == 1 ){
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack( st );

    insertIntoStack( st, temp );

}

//delete the middle element in the stack

void deleteStackMiddleElement( stack<int> &st, int middleIndex  ){

    if( st.empty() ){
        return;
    }

    int n = st.size();
    if( n == middleIndex ){
        st.pop();
    }

    int temp = st.top();
    st.pop();
    deleteStackMiddleElement( st, middleIndex );

    st.push( temp );
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    stack<int> st;

    for(int i = 0; i < n; i++){

        int num;
        cin >> num;

        st.push( num );
    }

    deleteStackMiddleElement( st, (st.size()/2)+1 );

    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
