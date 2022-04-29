#include <bits/stdc++.h>
using namespace std;

int p(int a, int b){
	if(b == 0) return 1;
	else if(a == 1) return 1;
	else if(b % 2 == 0) return p(a, b / 2) * p(a, b / 2);
	return a * p(a, b / 2) * p(a, b / 2);
}

int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(0);
	cout << p(10, 5);
	return 0;
}