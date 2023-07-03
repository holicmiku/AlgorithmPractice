#include<iostream>

using namespace std;

#define N 4
#define R 3

//4 Combination 3 

bool check[N] = { false, };
int answer[R] = { 0, };
int number[N] = { 1,2,3,4 };

void printArray() {
	for (int i = 0; i < R; i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";
}

void permutation(int depth) {
	if (depth == R) {
		printArray();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			answer[depth] = i + 1;
			permutation(depth + 1);
			check[i] = false;
		}
	} 
}

void duplicatePermutation(int depth) {
	if (depth == R) {
		printArray();
		return;
	}

	for (int i = 0; i < N; i++) {
		answer[depth] = i+1;
		duplicatePermutation(depth + 1);
	}
}



void combination(int depth, int next) {
	if (depth == R) {
		printArray();
		return;
	}

	for (int i = next; i < N; i++) {
		answer[depth] = i+1;
		combination(depth + 1, i + 1);
	}
}

void duplicateCombination(int depth, int next) 
{
	if (depth == R) {
		printArray();
		return;
	}

	for (int i = next; i < N; i++) {
		answer[depth] = i + 1;
		duplicateCombination(depth + 1, i);
	}

}

void subSet() {
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cout << number[j] << " ";
			}
		}
		cout << "\n";
	}
}

int main() {

	//permutation(0);
	//duplicatePermutation(0);
	//combination(0, 0);
	//duplicateCombination(0, 0);
	subSet();
	return 0;




}