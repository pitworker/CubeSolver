#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "CornerPiece.hpp"
using namespace std;
CornerPiece::CornerPiece() {
	position = -1;
	orientation = -1;
	color[0] = '.';
	color[1] = '.';
	color[2] = '.';
}
CornerPiece::CornerPiece(int positionOnCube, int orientationOfCubie, char colorOfFace[3]) {
	if(positionOnCube >= POS_UBR && positionOnCube <= POS_DRB) {
		position = positionOnCube;
	} else {
		position = -1;
	}

	if(orientationOfCubie >= 0 && orientationOfCubie < 3) {
		orientation = orientationOfCubie;
	} else {
		orientation = -1;
	}

	for(int i = 0; i < 3; i++) {
		switch(colorOfFace[i]) {
			case 'W':
			case 'Y':
			case 'R':
			case 'O':
			case 'G':
			case 'B': 
				color[i] = colorOfFace[i]; break;
			default: 
				color[i] = '.'; break;
		}
	}
}

void CornerPiece::set(int positionOnCube, int orientationOfCubie, char colorOfFace0, char colorOfFace1, char colorOfFace2) {
	if(positionOnCube >= POS_UBR && positionOnCube <= POS_DRB) {
		position = positionOnCube;
	}

	if(orientationOfCubie >= 0 && orientationOfCubie < 3) {
		orientation = orientationOfCubie;
	}

	char colorOfFace[3] = {colorOfFace0, colorOfFace1, colorOfFace2};

	for(int i = 0; i < 3; i++) {
		switch(colorOfFace[i]) {
			case 'W':
			case 'Y':
			case 'R':
			case 'O':
			case 'G':
			case 'B': 
				color[i] = colorOfFace[i]; break;
			default: break;
		}
	}
}
void CornerPiece::set(CornerPiece piece) {
	position = piece.getPositionOnCube();
	orientation = piece.getOrientation();
	for(int i = 0; i < 3; i++) {
		color[i] = piece.getColorWithoutOrientation(i);
	}
}

char CornerPiece::setColor(int faceOfCubie, char colorOfFace) {
	if(faceOfCubie >= 0 && faceOfCubie < 3) {
		switch(colorOfFace) {
			case 'W':
			case 'Y':
			case 'R':
			case 'O':
			case 'G':
			case 'B': 
				color[faceOfCubie] = colorOfFace; 
				return color[faceOfCubie];
				break;
			default: 
				break;
		}
	}
	return 'X';
}
int CornerPiece::setPositionOnCube(int positionOnCube) {
	if(positionOnCube >= POS_UBR && positionOnCube <= POS_DRB) {
		position = positionOnCube;
		return position;
	}
	return -1;
}
int CornerPiece::setOrientation(int orientationOfCubie) {
	if(orientationOfCubie >= 0 && orientationOfCubie < 3) {
		orientation = orientationOfCubie;
		return orientation;
	}
	return -1;
}

char CornerPiece::getColor(int faceOfCubie) {
	if(faceOfCubie >= 0 && faceOfCubie < 3) {
		if(orientation == 0) {
			return color[faceOfCubie];
		} else if(orientation == 1 && faceOfCubie < 2) {
			return color[faceOfCubie + 1];
		} else if(orientation == 1 && faceOfCubie == 2) {
			return color[0];
		} else if(orientation == 2 && faceOfCubie > 0) {
			return color[faceOfCubie - 1];
		} else if(orientation == 2 && faceOfCubie == 0) {
			return color[2];
		}
	}
	return 'X';
}
char CornerPiece::getColorWithoutOrientation(int faceOfCubie) {
	if(faceOfCubie >= 0 && faceOfCubie < 3) {
		return color[faceOfCubie];
	}
	return 'X';
}
int CornerPiece::getPositionOnCube() {
	return position;
}
int CornerPiece::getOrientation() {
	return orientation;
}

bool CornerPiece::isOnFaceOfCube(int faceOfCube) {
	if(faceOfCube == POS_U && position >= POS_UBR && position <= POS_ULB) {
		return true;
	} else if(faceOfCube == POS_D && position >= POS_DBL && position <= POS_DRB) {
		return true;
	} else if(faceOfCube == POS_R && (position == POS_UBR || position == POS_URF || 
		position == POS_DFR || position == POS_DRB)) {
		return true;
	} else if(faceOfCube == POS_L && (position == POS_UFL || position == POS_ULB || 
		position == POS_DBL || position == POS_DLF)) {
		return true;
	} else if(faceOfCube == POS_B && (position == POS_UBR || position == POS_ULB || 
		position == POS_DBL || position == POS_DRB)) {
		return true;
	} else if(faceOfCube == POS_F && (position == POS_URF || position == POS_UFL || 
		position == POS_DLF || position == POS_DFR)) {
		return true;
	}
	return false;
}
bool CornerPiece::canRotate(int rotateDirection) {
	if(ROTATE_POSITION[position][rotateDirection] >= 0) {
		return true;
	}
	return false;
}
int CornerPiece::getTargetPosition(int rotateDirection) {
	return ROTATE_POSITION[position][rotateDirection];
}
int CornerPiece::getTargetOrientation(int rotateDirection) {
	return ROTATE_ORIENTATION[position][rotateDirection];
}
bool CornerPiece::isType(int typeOfCubie) {
	if(typeOfCubie == CORNER) {
		return true;
	}
	return false;
}

void CornerPiece::mutateOrientation(int orientationMutation) {
	int mutatedOrientation = orientation + orientationMutation;

	if(mutatedOrientation > 2 && orientation == 1) {
		mutatedOrientation = -2 + orientationMutation;
	} else if (mutatedOrientation > 2 && orientation == 2) {
		mutatedOrientation = -1 + orientationMutation;
	}

	setOrientation(mutatedOrientation);
}

void CornerPiece::rotateCubie(int rotateDirection) {
	if(canRotate(rotateDirection)) {
		setPositionOnCube(getTargetPosition(rotateDirection));
		mutateOrientation(getTargetOrientation(rotateDirection));
	}
}

bool CornerPiece::hasColor()