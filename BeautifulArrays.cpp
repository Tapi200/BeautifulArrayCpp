// BeautifulArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsBeautiful(list<int> seq) {
	for (list<int>::iterator it = seq.begin();
		it != seq.end(); it++) {
		if (*it % 2 != 0) {
			return false;
			break;
		}
	}
	return true;
}

void Iterate(list<int> seq)
{
	list<int>::const_iterator it = seq.begin();
	int x = *it;
	int y = *it++;
	seq.remove(x);
	seq.remove(y);
	seq.push_back(x + y);
}

void Iterate2(list<int> seq, list<int> minorSeq2)
{
	list<int>::iterator it = minorSeq2.begin();

	int x = *it; 
	int y = *it++; 
	seq.remove(x);
	seq.remove(y);
}

void Iterate13(list<int> seq, list<int> minorSeq1, list<int> minorSeq3)
{
	list<int>::iterator it = minorSeq1.begin();
	list<int>::iterator it2 = minorSeq3.begin();

	int x = *it; 
	int y = *it2;
	seq.remove(x);
	seq.remove(y);
}

int main(){
	cout << "Enter number of test cases" << endl;
	int numberOfTestCases;
	cin >> numberOfTestCases;

	for (int k = 1; k <= numberOfTestCases; k++)
	{
		cout << "Enter sequence size" << endl;

		int seqSize;
		cin >> seqSize;

		cout << "Enter the sequence numbers" << endl;

		string input = "";
		cin >> input;

		cout << input << endl;

		input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
		
		vector<int> originalSeq(seqSize);
		for (int i = 0; i < seqSize; i++) {
			originalSeq[i] = input[i];
		}

		for (int i = 0; i < seqSize; i++) {
			cout << originalSeq[i];
		}

		list<int> primeSeq{make_move_iterator(begin(originalSeq)),
			make_move_iterator(end(originalSeq))};
		
		int counta = 0;

		//for (list<int>::iterator it = primeSeq.begin(); it != primeSeq.end(); it++) {
		//	if (*it % 4 == 0) {
		//		primeSeq.remove(*it);
		//	}
		//}

		while (true)
		{
		start:
			list<int> primeSeq1;
			list<int> primeSeq2;
			list<int> primeSeq3;

			for (list<int>::iterator it = primeSeq1.begin(); it != primeSeq1.end(); it++) {
				if (*it % 4 != 1) {
					primeSeq1.remove(*it);
				}
			}

			for (list<int>::iterator it = primeSeq2.begin(); it != primeSeq2.end(); it++) {
				if (*it % 4 != 2) {
					primeSeq2.remove(*it);
				}
			}

			for (list<int>::iterator it = primeSeq3.begin(); it != primeSeq3.end(); it++) {
				if (*it % 4 != 3) {
					primeSeq3.remove(*it);
				}
			}

			if (IsBeautiful(primeSeq))
			{
				//cout << "Sequence is beautiful" << endl;
				break;
			}

			if (primeSeq.size() == 1)
			{
				//cout << "sequence cannot be beautiful" << endl;
				break;
			}

			if (primeSeq2.size() >= 2)
			{
				Iterate2(primeSeq, primeSeq2);
				counta++;
				goto start;
			}

			if (primeSeq1.size() >= 1 && primeSeq3.size() >= 1)
			{
				Iterate13(primeSeq, primeSeq1, primeSeq3);
				counta++;
				goto start;
			}

			if (primeSeq1.size() >= 4)
			{
				Iterate2(primeSeq, primeSeq1);
				counta++;
				goto start;
			}

			if (primeSeq3.size() >= 4)
			{
				Iterate2(primeSeq, primeSeq3);
				counta++;
				goto start;
			}

			Iterate(primeSeq);
			counta++;
		}

		cout << "number of reps is: " << counta << endl;

		return 0;
	}
}


