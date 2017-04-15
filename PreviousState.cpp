#pragma once
#include "Cube.cpp"

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

class PreviousState {
private:
	char faceU [3][3];
	char faceD [3][3];
	char faceR [3][3];
	char faceL [3][3];
	char faceF [3][3];
	char faceB [3][3];

	bool cornersMatch(Cube cube);
	bool edgesMatch(Cube cube);

	bool firstSixEdgesMatch(Cube cube);
	bool secondSixEdgesMatch(Cube cube);
	
	vector<Cube> possibleMatches(Cube cube);

public:
	PreviousState(Cube cube);

	bool matchesCube(Cube cube);
};