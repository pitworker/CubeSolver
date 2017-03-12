#include <cstdlib>

using namespace std;

class Cubie {
public:	
	virtual char setColor(int faceOfCubie, char colorOfFace) = 0;
	virtual int setPositionOnCube(int positionOnCube) = 0;
	virtual int setOrientation(int orientationOfCubie) = 0;
	
	virtual char getColor(int faceOfCubie) = 0;
	virtual int getPositionOnCube() = 0;
	virtual int getOrientation() = 0;
	
	virtual bool isOnFaceOfCube(int faceOfCube) = 0;
	virtual bool canRotate(int rotateDirection) = 0; //moves the cubie to a new position, returns false if rotation doesn't affect it
	virtual int getTargetPosition(int rotateDirection) = 0;
	virtual int getTargetOrientation(int rotateDirection) = 0;
	virtual int isType(int typeOfCubie) = 0;

	virtual void rotateCubie(int rotateDirection) = 0;
	
protected: 
	int position;
	int orientation;
};

class CenterPiece: public Cubie {
private:
	#include "CenterPieceRotations.h"
	char color;

public:
	CenterPiece(int positionOnCube, char colorOfFace) {
		if(positionOnCube >= POS_U && positionOnCube <= POS_B) {
			position = positionOnCube;
		} else {
			position = -1;
		}
		switch(color){
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
	
	char setColor(int faceOfCubie, char colorOfFace) {
		if(face == 0) {
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
	int setPositionOnCube(int positionOnCube) {
		if(positionOnCube >= POS_U && positionOnCube <= POS_B){
			position = positionOnCube;
			return position;
		}
		return -1; //implies that the position entered is not on cube.
	}
	int setOrientation(int orientationOfCubie) {
			if(orientationOfCubie == 0) {
				return 0; //orientation of center piece will always be 0
			}
			return -1;
	}
	
	char getColor(int faceOfCubie) {
		if(faceOfCubie != 0) {
			return 'X';
		}
		return color;
	}
	int getPositionOnCube() {
		return position;
	}
	int getOrientation() {
		return orientation;
	}
	
	bool isOnFaceOfCube(int faceOfCube) {
		if(position * 3 == faceOfCube) {
			return true;
		}
		return false;
	}
	bool canRotate(int rotateDirection) {
		if(ROTATE_POSITION[position][rotateDirection] >= 0) {
			return true;
		}
		return false;
	}
	int getTargetPosition(int rotateDirection) {
		return ROTATE_POSITION[position][rotateDirection];	
	}
	int getTargetOrientation(int rotateDirection) {
		if(canRotate(rotateDirection)) {
			return 0;
		}
		return -1;
	}
	bool isType(int typeOfCubie) {
		if(typeOfCubie == CENTER) {
			return true;
		}
		return false;
	}

	void rotateCubie(int rotateDirection) {
		if(canRotate(rotateDirection)) {
			setPositionOnCube(getTargetPosition(rotateDirection));
		}
	}
};

class EdgePiece: public Cubie {
private:
	#include "EdgePieceRotations.h"
	
	char color[2]

public:
	EdgePiece(int positionOnCube, int orientationOfCubie, char colorOfFace[2]) {
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

	char setColor(int faceOfCubie, char colorOfFace) {
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
		return 'X'
	}
	int setPositionOnCube(int positionOnCube) {
		if(positionOnCube >= POS_UB && positionOnCube <= POS_DL) {
			position = positionOnCube;
			return position;
		}
		return -1;
	}
	int setOrientation(int orientationOfCubie) {
		if(orientationOfCubie == 0 || orientationOfCubie == 1) {
			orientation = orientationOfCubie;
			return orientation;
		}
		return -1;
	}
	
	char getColor(int faceOfCubie) {
		if(faceOfCubie == 0 || faceOfCubie == 1) {
			return color[faceOfCubie];
		}
		return 'X';
	}
	int getPositionOnCube() {
		return position;
	}
	int getOrientation() {
		return orientation;
	}
	
	bool isOnFaceOfCube(int faceOfCube) {
		if(faceOfCube == U && position >= POS_UB && position <= POS_UL) {
			return true;
		} else if(faceOfCube == D && position >= POS_DF && position <= POS_DL) {
			return true;
		} else if(faceOfCube == R && (position == POS_UR || position == POS_FR || 
			position == POS_BR || position == POS_DR)) {
			return true;
		} else if(faceOfCube == L && (position == POS_DL || position == POS_UL || 
			position == POS_BL || position == POS_FL) {
			return true;
		} else if(faceOfCube == B && (position == POS_BL || position == POS_BR || 
			position == POS_UB || position == POS_DB)) {
			return true;
		} else if(faceOfCube == F && (position == POS_FL || position == POS_FR || 
			position == POS_UF || position == POS_DF)) {
			return true;
		}
		return false;
	}
	bool canRotate(int rotateDirection) {
		if(ROTATE_POSITION[position][rotateDirection] >= 0) {
			return true;
		}
		return false;
	}
	int getTargetPosition(int rotateDirection) {
		return ROTATE_POSITION[position][rotateDirection];
	}
	int getTargetOrientation(int rotateDirection) {
		return ROTATE_ORIENTATION[position][rotateDirection];
	}
	bool isType(int typeOfCubie) {
		if(typeOfCubie == EDGE) {
			return true;
		}
		return false;
	}

	void rotateCubie(int rotateDirection) {
		if(canRotate(rotateDirection)) {
			setPositionOnCube(getTargetPosition(rotateDirection));
			setOrientation(getTargetOrientation(rotateDirection));
		}
	}
};

class CornerPiece: public Cubie {
private:
	#include "CornerPieceRotations.h"
	
	char color[3]

public:
	CornerPiece(int positionOnCube, int orientationOfCubie, char colorOfFace[3]) {
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

	char setColor(int faceOfCubie, char colorOfFace) {
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
		return 'X'
	}
	int setPositionOnCube(int positionOnCube) {
		if(positionOnCube >= POS_UBR && positionOnCube <= POS_DRB) {
			position = positionOnCube;
			return position;
		}
		return -1;
	}
	int setOrientation(int orientationOfCubie) {
		if(orientationOfCubie >= 0 && orientationOfCubie < 3) {
			orientation = orientationOfCubie;
			return orientation;
		}
		return -1;
	}
	
	char getColor(int faceOfCubie) {
		if(faceOfCubie >= 0 && faceOfCubie < 3) {
			return color[faceOfCubie];
		}
		return 'X';
	}
	int getPositionOnCube() {
		return position;
	}
	int getOrientation() {
		return orientation;
	}
	
	bool isOnFaceOfCube(int faceOfCube) {
		if(faceOfCube == U && position >= POS_UBR && position <= POS_ULB) {
			return true;
		} else if(faceOfCube == D && position >= POS_DBL && position <= POS_DRB) {
			return true;
		} else if(faceOfCube == R && (position == POS_UBR || position == POS_URF || 
			position == POS_DFR || position == POS_DRB)) {
			return true;
		} else if(faceOfCube == L && (position == POS_UFL || position == POS_ULB || 
			position == POS_DBL || position == POS_DLF) {
			return true;
		} else if(faceOfCube == B && (position == POS_UBR || position == POS_ULB || 
			position == POS_DBL || position == POS_DRB)) {
			return true;
		} else if(faceOfCube == F && (position == POS_URF || position == POS_UFL || 
			position == POS_DLF || position == POS_DFR)) {
			return true;
		}
		return false;
	}
	bool canRotate(int rotateDirection) {
		if(ROTATE_POSITION[position][rotateDirection] >= 0) {
			return true;
		}
		return false;
	}
	int getTargetPosition(int rotateDirection) {
		return ROTATE_POSITION[position][rotateDirection];
	}
	int getTargetOrientation(int rotateDirection) {
		return ROTATE_ORIENTATION[position][rotateDirection];
	}
	bool isType(int typeOfCubie) {
		if(typeOfCubie == CORNER) {
			return true;
		}
		return false;
	}

	void rotateCubie(int rotateDirection) {
		if(canRotate(rotateDirection)) {
			setPositionOnCube(getTargetPosition(rotateDirection));
			setOrientation(getTargetOrientation(rotateDirection));
		}
	}
};
