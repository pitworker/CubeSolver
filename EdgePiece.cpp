#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "EdgePiece.hpp"
using namespace std;

EdgePiece::EdgePiece() {
	position = -1;
	orientation = -1;
	color[0] = '.';
	color[1] = '.';
}
EdgePiece::EdgePiece(int positionOnCube, int orientationOfCubie, char colorOfFace[2]) {
	if(positionOnCube >= POS_UB && positionOnCube <= POS_DL) {
		position = positionOnCube;
	} else {
		position = -1;
	}

	if(orientationOfCubie == 0 || orientationOfCubie == 1) {
		orientation = orientationOfCubie;
	} else {
		orientation = -1;
	}

	for(int i = 0; i < 2; i++) {
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

void EdgePiece::set(int positionOnCube, int orientationOfCubie, char colorOfFace0, char colorOfFace1) {
	if(positionOnCube >= POS_UB && positionOnCube <= POS_DL) {
		position = positionOnCube;
	}

	if(orientationOfCubie == 0 || orientationOfCubie == 1) {
		orientation = orientationOfCubie;
	} 

	char colorOfFace[2] = {colorOfFace0, colorOfFace1};

	for(int i = 0; i < 2; i++) {
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
void EdgePiece::set(EdgePiece piece) {
	position = piece.getPositionOnCube();
	orientation = piece.getOrientation();
	for(int i = 0; i < 2; i++) {
		color[i] = piece.getColorWithoutOrientation(i);
	}
}

char EdgePiece::setColor(int faceOfCubie, char colorOfFace) {
	if(faceOfCubie == 0 || faceOfCubie == 1) {
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
int EdgePiece::setPositionOnCube(int positionOnCube) {
	if(positionOnCube >= POS_UB && positionOnCube <= POS_DL) {
		position = positionOnCube;
		return position;
	}
	return -1;
}
int EdgePiece::setOrientation(int orientationOfCubie) {
	if(orientationOfCubie == 0 || orientationOfCubie == 1) {
		orientation = orientationOfCubie;
		return orientation;
	}
	return -1;
}

char EdgePiece::getColor(int faceOfCubie) {
	if(faceOfCubie == 0 || faceOfCubie == 1) {
		if(orientation == 0) {
			return color[faceOfCubie];
		} else if(orientation == 1 && faceOfCubie == 0) {
			return color[1];
		} else if(orientation == 1 && faceOfCubie == 1) {
			return color[0];
		}
	}
	return 'X';
}
char EdgePiece::getColorWithoutOrientation(int faceOfCubie){
	if(faceOfCubie == 0 || faceOfCubie == 1) {
		return color[faceOfCubie];
	}
	return 'X';
}
int EdgePiece::getPositionOnCube() {
	return position;
}
int EdgePiece::getOrientation() {
	return orientation;
}

bool EdgePiece::isOnFaceOfCube(int faceOfCube) {
	if(faceOfCube == POS_U && position >= POS_UB && position <= POS_LU) {
		return true;
	} else if(faceOfCube == POS_D && position >= POS_DF && position <= POS_DL) {
		return true;
	} else if(faceOfCube == POS_R && (position == POS_UR || position == POS_RF || 
		position == POS_BR || position == POS_RD)) {
		return true;
	} else if(faceOfCube == POS_L && (position == POS_DL || position == POS_LU || 
		position == POS_LB || position == POS_FL)) {
		return true;
	} else if(faceOfCube == POS_B && (position == POS_LB || position == POS_BR || 
		position == POS_UB || position == POS_BD)) {
		return true;
	} else if(faceOfCube == POS_F && (position == POS_FL || position == POS_RF || 
		position == POS_FU || position == POS_DF)) {
		return true;
	}
	return false;
}
bool EdgePiece::canRotate(int rotateDirection) {
	if(ROTATE_POSITION[position][rotateDirection] >= 0) {
		return true;
	}
	return false;
}
int EdgePiece::getTargetPosition(int rotateDirection) {
	return ROTATE_POSITION[position][rotateDirection];
}
int EdgePiece::getTargetOrientation(int rotateDirection) {
	return ROTATE_ORIENTATION[position][rotateDirection];
}
bool EdgePiece::isType(int typeOfCubie) {
	if(typeOfCubie == EDGE) {
		return true;
	}
	return false;
}

void EdgePiece::mutateOrientation(int orientationMutation) {
	if(orientationMutation == 1) {
		if(orientation == 0) {
			setOrientation(1);
		} else if (orientation == 1) {
			setOrientation(0);
		}
	}
}

void EdgePiece::rotateCubie(int rotateDirection) {
	if(canRotate(rotateDirection)) {
		setPositionOnCube(getTargetPosition(rotateDirection));
		mutateOrientation(getTargetOrientation(rotateDirection));
	}
}

bool EdgePiece::hasColor(char colorOfFace) {
	return(color[0] == colorOfFace || color[1] == colorOfFace);
}