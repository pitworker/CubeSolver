#pragma once
#include <cstdlib>
#include <iostream>
#include "CubeConstants.h"
#include "CubePrinter.hpp"
#include "CubeSolver.cpp"
#include "Cube.cpp"

//cube net layout:
//    UUU
//    UUU
//    UUU
//LLL FFF RRR BBB
//LLL FFF RRR BBB
//LLL FFF RRR BBB
//    DDD
//    DDD
//    DDD

CubePrinter::CubePrinter() {
	updateCube();
}

void CubePrinter::updateCenters() {
	faceU[1][1] = rubiksCube.getCenterPieceAtPosition(POS_U).getColor(0);
	faceD[1][1] = rubiksCube.getCenterPieceAtPosition(POS_D).getColor(0);
	faceR[1][1] = rubiksCube.getCenterPieceAtPosition(POS_R).getColor(0);
	faceL[1][1] = rubiksCube.getCenterPieceAtPosition(POS_L).getColor(0);
	faceF[1][1] = rubiksCube.getCenterPieceAtPosition(POS_F).getColor(0);
	faceB[1][1] = rubiksCube.getCenterPieceAtPosition(POS_B).getColor(0);
}
void CubePrinter::updateEdges() {
	faceU[0][1] = rubiksCube.getEdgePieceAtPosition(POS_UB).getColor(0);
	faceB[0][1] = rubiksCube.getEdgePieceAtPosition(POS_UB).getColor(1);

	faceU[1][2] = rubiksCube.getEdgePieceAtPosition(POS_UR).getColor(0);
	faceR[0][1] = rubiksCube.getEdgePieceAtPosition(POS_UR).getColor(1);

	faceF[0][1] = rubiksCube.getEdgePieceAtPosition(POS_FU).getColor(0);
	faceU[2][1] = rubiksCube.getEdgePieceAtPosition(POS_FU).getColor(1);

	faceL[0][1] = rubiksCube.getEdgePieceAtPosition(POS_LU).getColor(0);
	faceU[1][0] = rubiksCube.getEdgePieceAtPosition(POS_LU).getColor(1);

	faceR[1][0] = rubiksCube.getEdgePieceAtPosition(POS_RF).getColor(0);
	faceF[1][2] = rubiksCube.getEdgePieceAtPosition(POS_RF).getColor(1);

	faceB[1][0] = rubiksCube.getEdgePieceAtPosition(POS_BR).getColor(0);
	faceR[1][2] = rubiksCube.getEdgePieceAtPosition(POS_BR).getColor(1);

	faceL[1][0] = rubiksCube.getEdgePieceAtPosition(POS_LB).getColor(0);
	faceB[1][2] = rubiksCube.getEdgePieceAtPosition(POS_LB).getColor(1);

	faceF[1][0] = rubiksCube.getEdgePieceAtPosition(POS_FL).getColor(0);
	faceL[1][2] = rubiksCube.getEdgePieceAtPosition(POS_FL).getColor(1);

	faceD[0][1] = rubiksCube.getEdgePieceAtPosition(POS_DF).getColor(0);
	faceF[2][1] = rubiksCube.getEdgePieceAtPosition(POS_DF).getColor(1);

	faceR[2][1] = rubiksCube.getEdgePieceAtPosition(POS_RD).getColor(0);
	faceD[1][2] = rubiksCube.getEdgePieceAtPosition(POS_RD).getColor(1);

	faceB[2][1] = rubiksCube.getEdgePieceAtPosition(POS_BD).getColor(0);
	faceD[2][1] = rubiksCube.getEdgePieceAtPosition(POS_BD).getColor(1);

	faceD[1][0] = rubiksCube.getEdgePieceAtPosition(POS_DL).getColor(0);
	faceL[2][1] = rubiksCube.getEdgePieceAtPosition(POS_DL).getColor(1);
}
void CubePrinter::updateCorners() {
	faceU[0][2] = rubiksCube.getCornerPieceAtPosition(POS_UBR).getColor(0);
	faceB[0][0] = rubiksCube.getCornerPieceAtPosition(POS_UBR).getColor(1);
	faceR[0][2] = rubiksCube.getCornerPieceAtPosition(POS_UBR).getColor(2);
	
	faceU[2][2] = rubiksCube.getCornerPieceAtPosition(POS_URF).getColor(0);
	faceR[0][0] = rubiksCube.getCornerPieceAtPosition(POS_URF).getColor(1);
	faceF[0][2] = rubiksCube.getCornerPieceAtPosition(POS_URF).getColor(2);

	faceU[2][0] = rubiksCube.getCornerPieceAtPosition(POS_UFL).getColor(0);
	faceF[0][0] = rubiksCube.getCornerPieceAtPosition(POS_UFL).getColor(1);
	faceL[0][2] = rubiksCube.getCornerPieceAtPosition(POS_UFL).getColor(2);

	faceU[0][0] = rubiksCube.getCornerPieceAtPosition(POS_ULB).getColor(0);
	faceL[0][0] = rubiksCube.getCornerPieceAtPosition(POS_ULB).getColor(1);
	faceB[0][2] = rubiksCube.getCornerPieceAtPosition(POS_ULB).getColor(2);

	faceD[2][0] = rubiksCube.getCornerPieceAtPosition(POS_DBL).getColor(0);
	faceB[2][2] = rubiksCube.getCornerPieceAtPosition(POS_DBL).getColor(1);
	faceL[2][0] = rubiksCube.getCornerPieceAtPosition(POS_DBL).getColor(2);

	faceD[0][0] = rubiksCube.getCornerPieceAtPosition(POS_DLF).getColor(0);
	faceL[2][2] = rubiksCube.getCornerPieceAtPosition(POS_DLF).getColor(1);
	faceF[2][0] = rubiksCube.getCornerPieceAtPosition(POS_DLF).getColor(2);

	faceD[0][2] = rubiksCube.getCornerPieceAtPosition(POS_DFR).getColor(0);
	faceF[2][2] = rubiksCube.getCornerPieceAtPosition(POS_DFR).getColor(1);
	faceR[2][0] = rubiksCube.getCornerPieceAtPosition(POS_DFR).getColor(2);

	faceD[2][2] = rubiksCube.getCornerPieceAtPosition(POS_DRB).getColor(0);
	faceR[2][2] = rubiksCube.getCornerPieceAtPosition(POS_DRB).getColor(1);
	faceB[2][0] = rubiksCube.getCornerPieceAtPosition(POS_DRB).getColor(2);
}

void CubePrinter::updateCube() {
	updateCenters();
	updateEdges();
	updateCorners();
}

void CubePrinter::printCubeNet() {
	for(int i = 0; i < 3; i ++) {
		cout << "    ";
		for(int j = 0; j < 3; j ++) {
			cout << faceU[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			cout << faceL[i][j];
		}
		cout << " ";
		for(int j = 0; j < 3; j ++) {
			cout << faceF[i][j];
		}
		cout << " ";
		for(int j = 0; j < 3; j ++) {
			cout << faceR[i][j];
		}
		cout << " ";
		for(int j = 0; j < 3; j ++) {
			cout << faceB[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < 3; i ++) {
		cout << "    ";
		for(int j = 0; j < 3; j ++) {
			cout << faceD[i][j];
		}
		cout << endl;
	}
}
bool CubePrinter::inputRotation() {
	string input = "";

	cout << endl << "Input Rotation: ";
	cin >> input;

	if(input == "ESC") {
		return false;
	} else if(input == "MULT") {
		inputMultipleRotations();
	} else if(input == "SOLVE") {
		rubiksCube.replaceWithCube(solvePuzzle(rubiksCube));
	} else {
		int inputRotationValue = rotationFromString(input);

		if(inputRotationValue >= 0) {
			rubiksCube.rotate(inputRotationValue);
		} else {
			cout << "INVALID INPUT" << endl;
			inputRotation();
		}
	}

	updateCube();
	cout << endl << endl;
	return true;
}

void CubePrinter::inputMultipleRotations() {
	string input = "";
	cout << "Input multiple rotations: ";
	cin >> input;

	for(int i = 0; i < input.length(); i++) {
		string rotation = "";
		if(input[i] == 'U' || input[i] == 'D' || input[i] == 'R' || input[i] == 'L' || 
			input[i] == 'F' || input[i] == 'B' || input[i] == 'M' || input[i] == 'E' ||
			input[i] == 'S' || input[i] == 'X' || input[i] == 'Y' || input[i] == 'Z') {

			rotation += input[i];

			if(i + 1 < input.length() && (input[i + 1] == 'i' || input[i + 1] == '2')) {
				rotation += input[i + 1];
				i++;
			}

			rubiksCube.rotate(rotationFromString(rotation));
		} else if(input[i] != ' ') {
			cout << endl << "INVALID INPUT AT CHAR " << i;
		}
	}
}

int CubePrinter::rotationFromString(string input) {
	#include "ValidRotationStrings.hpp"

	for(int i = 0; i < 36; i ++) {
		if(VALID_INPUTS [i] == input) {
			return i;
		}
	}
	
	return -1;
}

Cube CubePrinter::solvePuzzle(Cube scrambledCube) {
	CubeSolver solver = CubeSolver(scrambledCube);
	solver.solveFullCube();
	cout << endl << solver.getSolutionNotation() << endl;
	return solver.getSolvedCube();
}

int main(int argc, char const *argv[])
{
	CubePrinter rubiksCubePrinter = CubePrinter();

	bool continueRunning = true;

	while(continueRunning) {
		rubiksCubePrinter.printCubeNet();
		continueRunning = rubiksCubePrinter.inputRotation();
	}
	return 0;
}
