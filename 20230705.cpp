#include<iostream>

using namespace std;

#define N 6
#define R 3

int number[N] = { 0, };
bool isSelected[N] = { false, };

int answer[R] = { 0, };

void PrintArray() {
	for (int i = 0; i < R; i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";
}


void Permutation(int depth) {
	if (depth == R) {
		PrintArray();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			answer[depth] = i + 1;
			Permutation(depth + 1);
			isSelected[i] = false;
		}
	}
}

void DuplicatePermutation(int depth) {
	if (depth == R) {
		PrintArray();
		return;
	}

	for (int i = 0; i < N; i++) {
		answer[depth] = i + 1;
		DuplicatePermutation(depth + 1);
	}
}

void Combination(int depth, int next) {
	if (depth == R) {
		PrintArray();
		return;
	}

	for (int i = next; i < N; i++) {
		answer[depth] = i + 1;
		Combination(depth + 1, i + 1);
	}
}

void DuplicateCombination(int depth, int next) {
	if (depth == R) {
		PrintArray();
		return;
	}

	for (int i = next; i < N; i++) {
		answer[depth] = i + 1;
		DuplicateCombination(depth + 1, i);
	}
}

void SubSet() {
	for (int i = 0; i < (1<<N); i++) {
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cout << number[j] << " ";
			}
		}
		cout << "\n";
	}
}

int main() {

	for (int i = 0; i < N; i++) {
		number[i] = i + 1;
	}

	//Permutation(0);
	//DuplicatePermutation(0);
	//Combination(0, 0);
	//DuplicateCombination(0, 0);
	SubSet();

}
