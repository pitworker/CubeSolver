#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "CenterPiece.hpp"
using namespace std;

CenterPiece::CenterPiece() {
	position = -1;
	color = '.';
	orientation = 0;
}
CenterPiece::CenterPiece(int positionOnCube, char colorOfFace) {
	if(positionOnCube >= POS_U && positionOnCube <= POS_B) {
		position = positionOnCube;
	} else {
		position = -1;
	}
	switch(colorOfFace){
		case 'W':
		case 'Y':
		case 'R':
		case 'O':
		case 'B':
		case 'G':
			color = colorOfFace; break;
		default: color = '.'; break;
	}
	orientation = 0;
}

void CenterPiece::set(int positionOnCube, char colorOfFace) {
	if(positionOnCube >= POS_U && positionOnCube <= POS_B) {
		position = positionOnCube;
	}
	switch(colorOfFace){
		case 'W':
		case 'Y':
		case 'R':
		case 'O':
		case 'B':
		case 'G':
			color = colorOfFace; break;
		default: color = '.'; break;
	}
}

char CenterPiece::setColor(int faceOfCubie, char colorOfFace) {
	if(faceOfCubie == 0) {
		switch(color){
		case 'W':
		case 'Y':
		case 'R':
		case 'O':
		case 'B':
		case 'G':
			color = colorOfFace; 
			return color;
			break;
		default: 
			break;
		}
	}
	return 'X';
}
int CenterPiece::setPositionOnCube(int positionOnCube) {
	if(positionOnCube >= POS_U && positionOnCube <= POS_B){
		position = positionOnCube;
		return position;
	}
	return -1; //implies that the position entered is not on cube.
}
int CenterPiece::setOrientation(int orientationOfCubie) {
	if(orientationOfCubie == 0) {
		return 0; //orientation of center piece will always be 0
	}
	return -1;
}
char CenterPiece::getColor(int faceOfCubie) {
	if(faceOfCubie != 0) {
		return 'X';
	}
	return color;
}
int CenterPiece::getPositionOnCube() {
	return position;
}
int CenterPiece::getOrientation() {
	return orientation;
}

bool CenterPiece::isOnFaceOfCube(int faceOfCube) {
	if(position * 3 == faceOfCube) {
		return true;
	}
	return false;
}
bool CenterPiece::canRotate(int rotateDirection) {
	if(ROTATE_POSITION[position][rotateDirection] >= 0) {
		return true;
	}
	return false;
}
int CenterPiece::getTargetPosition(int rotateDirection) {
	return ROTATE_POSITION[position][rotateDirection];	
}
int CenterPiece::getTargetOrientation(int rotateDirection) {
	if(canRotate(rotateDirection)) {
		return 0;
	}
	return -1;
}
bool CenterPiece::isType(int typeOfCubie) {
	if(typeOfCubie == CENTER) {
		return true;
	}
	return false;
}
void CenterPiece::rotateCubie(int rotateDirection) {
	if(canRotate(rotateDirection)) {
		setPositionOnCube(getTargetPosition(rotateDirection));
	}
}
