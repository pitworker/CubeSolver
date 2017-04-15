#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "Cubie.cpp"
using namespace std;

class EdgePiece: public Cubie {
private:
	#include "EdgePieceRotations.h"
	char color[2];

public:
	EdgePiece();
	EdgePiece(int positionOnCube, int orientationOfCubie, char colorOfFace[2]);

	void set(int positionOnCube, int orientationOfCubie, char colorOfFace0, char colorOfFace1);
	void set(EdgePiece piece);

	char setColor(int faceOfCubie, char colorOfFace);
	int setPositionOnCube(int positionOnCube);
	int setOrientation(int orientationOfCubie);
	
	char getColor(int faceOfCubie);
	char getColorWithoutOrientation(int faceOfCubie);
	int getPositionOnCube();
	int getOrientation();
	
	bool isOnFaceOfCube(int faceOfCube);
	bool canRotate(int rotateDirection);
	int getTargetPosition(int rotateDirection);
	int getTargetOrientation(int rotateDirection);
	bool isType(int typeOfCubie);

	void mutateOrientation(int orientationMutation);

	void rotateCubie(int rotateDirection);

	bool hasColor(char colorOfFace);
};
