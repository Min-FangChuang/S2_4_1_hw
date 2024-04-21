#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main() {
	vector<int>score;
	int Score, Max = -1;
	cout << "Enter student's grades (use '-1' as the end): " << endl;
	while (true) {
		cin >> Score;
		if (Score == -1) {
			break;
		}
		score.push_back(Score);
		if (Score > Max) { Max = Score; }
	}

	vector<int>histogram;
	histogram.resize(Max + 1, 0);

	for (int i = 0;i < score.size();i++) {
		histogram[score[i]]++;
	}

	cout << "\nHistogram of grades" << endl;
	for (int i = 0;i <= Max;i++) {
		cout << i << " ";
		for (int j = 1;j <= histogram[i];j++) { cout << "*"; }
		cout<< endl;
	}

	system("pause");
	return(0);
}