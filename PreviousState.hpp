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

	void addCenters(Cube cube);
	void addEdges(Cube cube);
	void addCorners(Cube cube);

	bool centersMatch(Cube cube);
	bool cornersMatch(Cube cube);
	bool edgesMatch(Cube cube);

	bool firstSixEdgesMatch(Cube cube);
	bool secondSixEdgesMatch(Cube cube);
	
	vector<Cube> matchingCases(Cube cube);
	vector<Cube> mutatedCases(Cube cube);
	bool relatedCaseMatches(Cube cube);

public:
	PreviousState(Cube cube);

	bool matchesCube(Cube cube);	
};