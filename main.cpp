// COMSC-210 | Lab 26 | Diksha Tara Natesan
// IDE used: Vim/Terminal

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <list>
#include <set>
#include <chrono>
using namespace std;
using namespace std::chrono;

//display() neatly outputs the results of the races
//arguments: (4) int[] containing the result data
void display(int [], int [], int [], int []);

int main() {
    int results[25][4][3];
    for (int i = 0; i < 25; i++){
        results[i] = reading();
        



    int reading[3];
    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
    string line;
    vector<string> vect;
    while(getline(fin, line))
	vect.push_back(line);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    reading[0] = duration.count();
 
    start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    list<string> lst;
    while(getline(fin1, line))
        lst.push_back(line);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    reading[1] = duration.count();

    start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
    set<string> st;
    while(getline(fin2, line))
        st.insert(line);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    reading[2] = duration.count();

    int sorting[3];

    start = high_resolution_clock::now();
    sort(vect.begin(), vect.end());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    sorting[0] = duration.count();
    
    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    sorting[1] = duration.count();
    
    sorting[2] = -1;

    int insert[3];
   
    start = high_resolution_clock::now();
    vect.insert(vect.begin() + vect.size() / 2, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    insert[0] = duration.count();

    start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.insert(it, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    insert[1] = duration.count();

    start = high_resolution_clock::now();
    st.insert("TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    insert[2] = duration.count();

    int deleting[3];
    
    start = high_resolution_clock::now();
    vect.clear();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[0] = duration.count();

    start = high_resolution_clock::now();
    lst.clear();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[1] = duration.count();

    start = high_resolution_clock::now();
    st.clear();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[2] = duration.count();

    display(reading, sorting, insert, deleting);

    return 0;
}

int[] reading(){
    int r[3];

    //vector
    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
    string line;
    vector<string> vect;
    while(getline(fin, line))
        vect.push_back(line);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    r[0] = duration.count();

    //list
    start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    list<string> lst;
    while(getline(fin1, line))
        lst.push_back(line);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    r[1] = duration.count();

    //set
    start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
    set<string> st;
    while(getline(fin2, line))
        st.insert(line);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    r[2] = duration.count();
    
    return r;
}

void display(int r[], int s[], int i[], int d[]){
    cout << "\tOperation\tVector\tList\tSet" << endl;
    cout << "\tRead\t\t" << r[0] << '\t' << r[1] << '\t' << r[2] << endl;
    cout << "\tSort\t\t" << s[0] << '\t' << s[1] << '\t' << s[2] << endl;
    cout << "\tInsert\t\t" << i[0] << '\t' << i[1] << '\t' << i[2] << endl;
    cout << "\tDelete\t\t" << d[0] << '\t' << d[1] << '\t' << d[2] << endl;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
