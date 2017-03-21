#include <cstdlib>
#include "CubeConstants.h"
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
	virtual bool isType(int typeOfCubie) = 0;

	virtual void rotateCubie(int rotateDirection) = 0;
	
protected: 
	int position;
	int orientation;
};