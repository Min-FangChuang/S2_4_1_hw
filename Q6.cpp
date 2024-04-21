/*Programming: Min-Fang Chuang   Date: 2024/04/15
 *Instruction: Chow-Sing Lin     Class: Program Design
 *
 *store each student's grade by vector and output a histogramof grades
 */
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main() {
	//input - scores
	vector<int>score;
	int Score, Max = -1;
	cout << "Enter student's grades (use '-1' as the end): " << endl;
	while (true) {
		cin >> Score;
		if (Score == -1) {   //enter until -1
			break;
		}
		score.push_back(Score);
		if (Score > Max) { Max = Score; }  //find the maximum score
	}

	//output - the histogram of grades
	vector<int>histogram;
	histogram.resize(Max + 1, 0);

	//compute the histogram
	for (int i = 0;i < score.size();i++) {
		histogram[score[i]]++;
	}

	//display the histogram
	cout << "\nHistogram of grades" << endl;
	for (int i = 0;i <= Max;i++) {
		cout << i << " ";
		for (int j = 1;j <= histogram[i];j++) { cout << "*"; }
		cout<< endl;
	}

	system("pause");
	return(0);
}
