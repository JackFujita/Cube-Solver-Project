//Cube 
#pragma once

//enum Colour {WHITE, RED, ORANGE, BLUE, GREEN, YELLOW};

namespace Cube
{
	class Cube {
	public:
		Cube(); // constructor (no arguments) - automatically initialzes a solved cube
		Cube(char& U1, char& L1, char& F1, char& R1, char& B1, char& D1); // constuctor

	private:
		char* U;
		char* L;
		char* F;
		char* R;
		char* B;
		char* D;
	};

	Cube::Cube(){
		U = new char[9];
		L = new char[9];
		F = new char[9];
		R = new char[9];
		B = new char[9];
		D = new char[9];
	}

	Cube::Cube(char& U1, char& L1, char& F1, char& R1, char& B1, char& D1) {
		U = new char[9];
		L = new char[9];
		F = new char[9];
		R = new char[9];
		B = new char[9];
		D = new char[9];
		for (int i = 0; i < 9; i++) {
			U[i] = U1[i];

		}

	}

}


