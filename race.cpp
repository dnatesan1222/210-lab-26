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
void display(int [][]);

void display(int [][][]);

int main() {
	int results[15][4][3];

	for (int i = 0; i < 15; i++){
		//inserting
		auto start = high_resolution_clock::now();
		ifstream fin("codes.txt");
		string line;
		vector<string> vect;
		while(getline(fin, line))
			vect.push_back(line);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
		results[i][0][0] = duration.count();

		start = high_resolution_clock::now();
		ifstream fin1("codes.txt");
		list<string> lst;
		while(getline(fin1, line))
			lst.push_back(line);
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][0][1] = duration.count();

		start = high_resolution_clock::now();
		ifstream fin2("codes.txt");
		set<string> st;
		while(getline(fin2, line))
			st.insert(line);
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][0][2] = duration.count();

		//sorting
		start = high_resolution_clock::now();
		sort(vect.begin(), vect.end());
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][1][0] = duration.count();

		start = high_resolution_clock::now();
		lst.sort();
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][1][1] = duration.count();

		results[i][1][2] = -1;

		//inserting
		start = high_resolution_clock::now();
		vect.insert(vect.begin() + (vect.size() / 2), "TESTCODE");
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][2][0] = duration.count();

		start = high_resolution_clock::now();
		auto it = lst.begin();
		advance(it, lst.size() / 2);
		lst.insert(it, "TESTCODE");
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][2][1] = duration.count();

		start = high_resolution_clock::now();
		st.insert("TESTCODE");
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][2][2] = duration.count();

		//deleting
		start = high_resolution_clock::now();
		vect.erase(vect.begin() + vect.size() / 2);;
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][3][0] = duration.count();

		start = high_resolution_clock::now();
		it = lst.begin();
		advance(it, lst.size() / 2);
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][3][1] = duration.count();

		start = high_resolution_clock::now();
		auto itS = st.begin();
		advance(itS, st.size() / 2);
		end = high_resolution_clock::now();
		duration = duration_cast<milliseconds>(end - start);
		results[i][3][2] = duration.count();
		
		if (i != 0){
			results[i][0][0] += results[i-1][0][0];
                        results[i][0][1] += results[i-1][0][1];
                        results[i][0][2] += results[i-1][0][2];

                        results[i][1][0] += results[i-1][1][0];
                        results[i][1][1] += results[i-1][1][1];
                        results[i][1][2] += results[i-1][1][2];

                        results[i][2][0] += results[i-1][2][0];
                        results[i][2][1] += results[i-1][2][1];
                        results[i][2][2] += results[i-1][2][2];

                        results[i][3][0] += results[i-1][3][0];
                        results[i][3][1] += results[i-1][3][1];
                        results[i][3][2] += results[i-1][3][2];
		}
	}
	display(results);

	return 0;
}

void display(int r[15][4][3]){
	for (int i = 0; i < 15; i++)
		display(r[i]);
}

void display(int r[4][3]){
	cout << right << setw(15) << "Operation"
		<< right << setw(10) << "Vector"
		<< setw(10) << "List"
		<< setw(10) << "Set" << endl;
	cout << right << setw(15) << "Read"
		<< right << setw(10) << r[0][0]
		<< setw(10) << r[0][1]
		<< setw(10) << r[0][2] << endl;
	cout << right << setw(15) << "Sort"
		<< right << setw(10) << r[1][0]
		<< setw(10) << r[1][1]
		<< setw(10) << r[1][2] << endl;
	cout << right << setw(15) << "Insert"
		<< right << setw(10) << r[2][0]
		<< setw(10) << r[2][1]
		<< setw(10) << r[2][2] << endl;
	cout << right << setw(15) << "Delete"
		<< right << setw(10) << r[3][0]
		<< setw(10) << r[3][1]
		<< setw(10) << r[3][2] << endl;
}
/* syntax examples:
   auto start = high_resolution_clock::now()
   auto end = high_resolution_clock::now()
   auto duration = duration_cast<milliseconds>(end - start)
   duration.count() references elapsed milliseconds
 */
