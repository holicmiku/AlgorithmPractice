#include <iostream>

using namespace std;

#define N 5
#define R 2

int number[N];
int answer[R] = {0,};
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

void SubSet(int num) {
	for (int i = 0; i < (1<<num); i++) {
		for (int j = 0; j < num; j++) {
			if (i & (1 << j)) {
				cout << number[j] << " ";
			}
		}
		cout << "\n";
	}
}

int parent[11];

void Init(int num) {
	
	//if num == 10

	for (int i = 1; i <= num; i++) {
		parent[i] = i;
	}
}

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = Find(parent[x]);

}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
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
	SubSet(N);
}