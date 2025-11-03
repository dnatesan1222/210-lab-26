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
    vect.insert(vect.begin() + (vect.size() / 2), "TESTCODE");
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
    vect.erase(vect.begin() + vect.size() / 2);;
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[0] = duration.count();

    start = high_resolution_clock::now();
    it = lst.begin();
    advance(it, lst.size() / 2);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[1] = duration.count();

    start = high_resolution_clock::now();
    auto itS = st.begin();
    advance(itS, st.size() / 2);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    deleting[2] = duration.count();

    display(reading, sorting, insert, deleting);

    return 0;
}

void display(int r[], int s[], int i[], int d[]){
    cout << right << setw(15) << "Operation"
         << right << setw(10) << "Vector"
         << setw(10) << "List"
         << setw(10) << "Set" << endl;
    cout << right << setw(15) << "Read"
         << right << setw(10) << r[0]
         << setw(10) << r[1]
         << setw(10) << r[2] << endl;
    cout << right << setw(15) << "Sort"
         << right << setw(10) << s[0]
         << setw(10) << s[1]
         << setw(10) << s[2] << endl;
    cout << right << setw(15) << "Insert"
         << right << setw(10) << i[0]
         << setw(10) << i[1]
         << setw(10) << i[2] << endl;
    cout << right << setw(15) << "Delete"
         << right << setw(10) << d[0]
         << setw(10) << d[1]
         << setw(10) << d[2] << endl;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
