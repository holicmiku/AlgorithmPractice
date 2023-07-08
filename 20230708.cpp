#include <iostream>

using namespace std;

#define N 4
#define R 3

int answer[R];
int number[N];
bool isSelected[N] = { false, };

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

void Subset(int num) {
	for (int i = 0; i < (1<<num); i++) {
		for (int j = 0; j < num; j++) {
			if (i & (1 << j)) {
				cout << number[j] << " ";
			}
		}
		cout << "\n";
	}
}

void Init(int num) {
	for (int i = 1; i <= num; i++) {
		number[i] = i;
	}
}

int Find(int x) {
	if (number[x] == x) {
		return x;
	}

	return number[x] = Find(number[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x < y) {
			number[y] = x;
		}
		else {
			number[x] = y;
		}
	}
}

int main() {

	for (int i = 0; i < N; i++) {
		number[i] = i+1;
	}

	//Permutation(0);
	//DuplicatePermutation(0);
	//Combination(0, 0);
	//DuplicateCombination(0, 0);
	Subset(N);
}