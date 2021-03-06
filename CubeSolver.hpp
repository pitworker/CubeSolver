#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Cube.cpp"
#include "ValidRotationStrings.hpp"
#include "RedundantRotations.h"
#include "CurrentState.cpp"
#include "PreviousState.cpp"

class CubeSolver {
private:
	Cube cubeToSolve;

	//vector<int> solution;

	//vector<int> cross;
	//vector<int> f2l;
	//vector<int> oll;
	//vector<int> pll;

	vector<CurrentState> currentStates;
	vector<PreviousState> previousStates;
	vector<int> solution;

	bool stateIsSolved(CurrentState state);
	bool rotationIsRedundant(CurrentState state, int currentRotation);
	bool stateWasAlreadyVisited(CurrentState state);

public:
	CubeSolver(Cube scrambledCube);

	//int scanForCenterWithColor(char color); //returns the position of the center piece with the given color
	//int scanForEdgeWithColors(char color0, char color1); //returns the position of the edge piece with the given colors
	//int scanForCornerWithColors(char color0, char color1, char color2); //returns the position of the corner piece with the given colors

	//CenterPiece centerWithColor(char color);
	//EdgePiece edgeWithColors(char color0, char color1);
	//CornerPiece cornerWithColors(char color0; char color1; char color2);

	//void solveCross();
	//void solveF2L();
	//void solveOLL();
	//void solvePLL();

	bool solveCube();

	string getSolutionNotation();
	Cube getSolvedCube();

	CubeSolver& operator = (Cube cube);

	//void setStartingFace();
	//void orientFaceToFace(int faceToOrient, int targetFace);

	//void addToSolution(int rotation);

	//void rotateCubeAccordingToSolution();

	//void placeCrossEdgesOnDownFace();
	//void placeCrossEdgesOnEquatorSlice();
	//void placeCrossEdgesOnUpFace();
};
