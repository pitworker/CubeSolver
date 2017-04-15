#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "Cubie.cpp"
using namespace std;

class CenterPiece: public Cubie {
private:
	#include "CenterPieceRotations.h"
	char color;

public:
	CenterPiece();
	CenterPiece(int positionOnCube, char colorOfFace);
	
	void set(int positionOnCube, char colorOfFace);
	void set(CenterPiece piece);

	char setColor(int faceOfCubie, char colorOfFace);
	int setPositionOnCube(int positionOnCube);
	int setOrientation(int orientationOfCubie);
	
	char getColor(int faceOfCubie);
	int getPositionOnCube();
	int getOrientation();
	
	bool isOnFaceOfCube(int faceOfCube);
	bool canRotate(int rotateDirection);
	int getTargetPosition(int rotateDirection);
	int getTargetOrientation(int rotateDirection);
	bool isType(int typeOfCubie);

	void rotateCubie(int rotateDirection);
};
