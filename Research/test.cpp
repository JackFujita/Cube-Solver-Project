#include <iostream>
using namespace std;

class Cube {
	public:
		Cube(); // constructor (no arguments) - automatically initialzes a solved cube
		Cube(char* U1, char* L1, char* F1, char* R1, char* B1, char* D1); // constuctor
		void printCube() const;
		~Cube();
	private:
		char* U;
		char* L;
		char* F;
		char* R;
		char* B;
		char* D;
	};

Cube::Cube() {
	U = new char[9];
	L = new char[9];
	F = new char[9];
	R = new char[9];
	B = new char[9];
	D = new char[9];
}

Cube::Cube(char *U1, char *L1, char *F1, char *R1, char *B1, char *D1) {
	U = new char[9];
	L = new char[9];
	F = new char[9];
	R = new char[9];
	B = new char[9];
	D = new char[9];
	for (int i = 0; i < 9; i++) {
		U[i] = U1[i];
		L[i] = L1[i];
		F[i] = F1[i];
		R[i] = R1[i];
		B[i] = B1[i];
		D[i] = D1[i];

	}
}

void Cube::printCube() const {
	for (int i = 0; i < 9; i++) {
		cout << U[i] << endl;
		cout << L[i] << endl;
		cout << F[i] << endl;
		cout << R[i] << endl;
		cout << B[i] << endl;
		cout << D[i] << endl;
	}
}

Cube::~Cube() {
	delete[] U;
	delete[] L;
	delete[] F;
	delete[] R;
	delete[] B;
	delete[] D;
}

int main() {
	char* U1 = new char[9];
	char* L1 = new char[9];
	char* F1 = new char[9];
	char* R1 = new char[9];
	char* B1 = new char[9];
	char* D1 = new char[9];

	for (int i = 0; i < 9; i++) {
		U1[i] = 'U';
		L1[i] = 'L';
		F1[i] = 'F';
		R1[i] = 'R';
		B1[i] = 'B';
		D1[i] = 'D';
	}

	Cube c1(U1, L1, F1, R1, B1, D1);
	c1.printCube();
	return 0;
}