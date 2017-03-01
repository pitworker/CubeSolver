#include <cstdlib>
//#include "CubeConstants.h"
#include "AdjacentPositions.h"

using namespace std;

class Cubie {
public:
	virtual char setColor(int face, char color) = 0; //returns the char for the color
	virtual bool setPosition(int face, int location, int orientation) = 0; //returns true if position chosen exists, returns false if not
	virtual char getColor(int face) = 0; //returns the color on the face of the cubie
	virtual int getWhichFace() = 0; //returns the number identifier for the face of the cube the cube is located on
	virtual int getLocationOnFace(int face) = 0; //returns which position on the face a cubie is positioned
	virtual int getOrientationToFace(int face) = 0; //returns the orientation of the cubie according to the face inputted
	virtual bool rotate(int rotateDirection) = 0; //moves the cubie to a new position, returns false if rotation doesn't affect it
protected: 
	int faceOfCube;
	int faceOfCubie;
	int orientationToFace;
	int locationOnFace;
};

class CenterPiece: public Cubie {
private:
	char colorFace;
public:
	char setColor(int face, char color) {
		if(face == 0) {
			colorFace = color;
			return color;
		}
		return 'x';
	}

	bool setPosition(int face, int location, int orientation) {
		if(face == -1)
			face = faceOfCube;
		if(orientation == -1)
			orientation = orientationToFace;

		if(face >= 0 && face < 6 
			&& location == 0 
			&& orientation >= 0 && orientation < 4) {

			faceOfCube = face;
			orientationToFace = orientation;
			return true;
		}

		return false;
	}

	char getColor(int face) {
		if(face == 0)
			return colorFace;
		return 'x';
	}

	int getWhichFace() {
		return faceOfCube;
	}
};

class EdgePiece: public Cubie {
private:
	int facesOfCube [2];
	int locationsOnFaces [2];
	int orientationToFaces [2];
	char colorFace [2];
	
	void setAdjacentPosition(int face, int location, int orientation) {
		facesOfCube[0] = face;
		locationsOnFaces[0] = location;
		orientationToFaces[0] = orientation;

		facesOfCube[1] = getAdjacentFaceEdge(face, location); //I put these in a header file for the time being
		locationsOnFaces[1] = getAdjacentLocationEdge(face, location);
		orientationToFaces[1] = getAdjacentOrientationEdge(orientation);
	}


public:
	char setColor(int face, char color) {
		if(face == 0 || face == 1) {
			colorFace[face] = color;
			return color;
		}
		return 'x';
	}

	

	bool setPosition(int face, int location, int orientation) {
		if(face == -1)
			face = faceOfCube;
		if(location == -1)
			location = locationOnFace;
		if(orientation == -1)
			orientation = orientationToFace;

		if(face >= 0 && face < 6 
			&& location >= 0 && location < 4 
			&& orientation >= 0 && orientation < 2) {

			faceOfCube = face;
			locationOnFace = location;
			orientationToFace = orientation;
			setAdjacentPosition(face, location, orientation);

			return true;
		}

		return false;
	}

	char getColor(int face) {
		if(face == 0 || face == 1)
			return colorFace[face];
		return 'x';
	}
};

class CornerPiece: public Cubie {
private:
	char colorFace[3];
public:
	char setColor(int face, char color) {
		if(face >= 0 && face < 3) {
			colorFace[face] = color;
			return color;
		}
		return 'x';
	}

	bool setPosition(int face, int location, int orientation) {
		if(face == -1)
			face = faceOfCube;
		if(location == -1)
			location = locationOnFace;
		if(orientation == -1)
			orientation = orientationToFace;

		if(face >= 0 && face < 6 
			&& location >= 0 && location < 4 
			&& orientation >= 0 && orientation < 3) {

			faceOfCube = face;
			locationOnFace = location;
			orientationToFace = orientation;
			return true;
		}

		return false;
	}

	char getColor(int face) {
		if(face >= 0 && face < 3) {
			return colorFace[face];
		}
		return 'x';
	}
};
