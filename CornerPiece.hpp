#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "Cubie.cpp"
using namespace std;

class CornerPiece: public Cubie {
private:
	#include "CornerPieceRotations.h"
	char color[3];

public:
	CornerPiece();
	CornerPiece(int positionOnCube, int orientationOfCubie, char colorOfFace[3]);

	void set(int positionOnCube, int orientationOfCubie, char colorOfFace0, char colorOfFace1, char colorOfFace3);
	void set(CornerPiece piece);

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

	//bool hasColor(char colorOfFace);

	int getFaceWithColor(char colorOfFace);
};
