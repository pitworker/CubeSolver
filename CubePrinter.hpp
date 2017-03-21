#pragma once
#include <cstdlib>
#include <iostream>
#include "CubeConstants.h"
#include "Cube.cpp"
class CubePrinter {
private:
	char faceU [3][3];
	char faceD [3][3];
	char faceR [3][3];
	char faceL [3][3];
	char faceF [3][3];
	char faceB [3][3];
	Cube rubiksCube;

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

public:
	CubePrinter();

	void updateCenters();
	void updateEdges();
	void updateCorners();

	void updateCube();

	void printCubeNet();
	bool inputRotation();

	int rotationFromString(string input);
};
