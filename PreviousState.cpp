#include "RelatedColors.h"
#include "PreviousState.hpp"

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


PreviousState::PreviousState(Cube cube) {
	addCenters(cube);
	addEdges(cube);
	addCorners(cube);
}

void PreviousState::addCenters(Cube cube) {
	faceU[1][1] = cube.getCenterPieceAtPosition(POS_U).getColor(0);
	faceD[1][1] = cube.getCenterPieceAtPosition(POS_D).getColor(0);
	faceR[1][1] = cube.getCenterPieceAtPosition(POS_R).getColor(0);
	faceL[1][1] = cube.getCenterPieceAtPosition(POS_L).getColor(0);
	faceF[1][1] = cube.getCenterPieceAtPosition(POS_F).getColor(0);
	faceB[1][1] = cube.getCenterPieceAtPosition(POS_B).getColor(0);
}
void PreviousState::addEdges(Cube cube) {
	faceU[0][1] = cube.getEdgePieceAtPosition(POS_UB).getColor(0);
	faceB[0][1] = cube.getEdgePieceAtPosition(POS_UB).getColor(1);

	faceU[1][2] = cube.getEdgePieceAtPosition(POS_UR).getColor(0);
	faceR[0][1] = cube.getEdgePieceAtPosition(POS_UR).getColor(1);

	faceF[0][1] = cube.getEdgePieceAtPosition(POS_FU).getColor(0);
	faceU[2][1] = cube.getEdgePieceAtPosition(POS_FU).getColor(1);

	faceL[0][1] = cube.getEdgePieceAtPosition(POS_LU).getColor(0);
	faceU[1][0] = cube.getEdgePieceAtPosition(POS_LU).getColor(1);

	faceR[1][0] = cube.getEdgePieceAtPosition(POS_RF).getColor(0);
	faceF[1][2] = cube.getEdgePieceAtPosition(POS_RF).getColor(1);

	faceB[1][0] = cube.getEdgePieceAtPosition(POS_BR).getColor(0);
	faceR[1][2] = cube.getEdgePieceAtPosition(POS_BR).getColor(1);

	faceL[1][0] = cube.getEdgePieceAtPosition(POS_LB).getColor(0);
	faceB[1][2] = cube.getEdgePieceAtPosition(POS_LB).getColor(1);

	faceF[1][0] = cube.getEdgePieceAtPosition(POS_FL).getColor(0);
	faceL[1][2] = cube.getEdgePieceAtPosition(POS_FL).getColor(1);

	faceD[0][1] = cube.getEdgePieceAtPosition(POS_DF).getColor(0);
	faceF[2][1] = cube.getEdgePieceAtPosition(POS_DF).getColor(1);

	faceR[2][1] = cube.getEdgePieceAtPosition(POS_RD).getColor(0);
	faceD[1][2] = cube.getEdgePieceAtPosition(POS_RD).getColor(1);

	faceB[2][1] = cube.getEdgePieceAtPosition(POS_BD).getColor(0);
	faceD[2][1] = cube.getEdgePieceAtPosition(POS_BD).getColor(1);

	faceD[1][0] = cube.getEdgePieceAtPosition(POS_DL).getColor(0);
	faceL[2][1] = cube.getEdgePieceAtPosition(POS_DL).getColor(1);
}
void PreviousState::addCorners(Cube cube) {
	faceU[0][2] = cube.getCornerPieceAtPosition(POS_UBR).getColor(0);
	faceB[0][0] = cube.getCornerPieceAtPosition(POS_UBR).getColor(1);
	faceR[0][2] = cube.getCornerPieceAtPosition(POS_UBR).getColor(2);
	
	faceU[2][2] = cube.getCornerPieceAtPosition(POS_URF).getColor(0);
	faceR[0][0] = cube.getCornerPieceAtPosition(POS_URF).getColor(1);
	faceF[0][2] = cube.getCornerPieceAtPosition(POS_URF).getColor(2);

	faceU[2][0] = cube.getCornerPieceAtPosition(POS_UFL).getColor(0);
	faceF[0][0] = cube.getCornerPieceAtPosition(POS_UFL).getColor(1);
	faceL[0][2] = cube.getCornerPieceAtPosition(POS_UFL).getColor(2);

	faceU[0][0] = cube.getCornerPieceAtPosition(POS_ULB).getColor(0);
	faceL[0][0] = cube.getCornerPieceAtPosition(POS_ULB).getColor(1);
	faceB[0][2] = cube.getCornerPieceAtPosition(POS_ULB).getColor(2);

	faceD[2][0] = cube.getCornerPieceAtPosition(POS_DBL).getColor(0);
	faceB[2][2] = cube.getCornerPieceAtPosition(POS_DBL).getColor(1);
	faceL[2][0] = cube.getCornerPieceAtPosition(POS_DBL).getColor(2);

	faceD[0][0] = cube.getCornerPieceAtPosition(POS_DLF).getColor(0);
	faceL[2][2] = cube.getCornerPieceAtPosition(POS_DLF).getColor(1);
	faceF[2][0] = cube.getCornerPieceAtPosition(POS_DLF).getColor(2);

	faceD[0][2] = cube.getCornerPieceAtPosition(POS_DFR).getColor(0);
	faceF[2][2] = cube.getCornerPieceAtPosition(POS_DFR).getColor(1);
	faceR[2][0] = cube.getCornerPieceAtPosition(POS_DFR).getColor(2);

	faceD[2][2] = cube.getCornerPieceAtPosition(POS_DRB).getColor(0);
	faceR[2][2] = cube.getCornerPieceAtPosition(POS_DRB).getColor(1);
	faceB[2][0] = cube.getCornerPieceAtPosition(POS_DRB).getColor(2);
}

bool PreviousState::matchesCube(Cube cube) {
	vector<Cube> alternatesToCheck = matchingCases(cube);

	for(int i = 0; i < alternatesToCheck.size(); i++) {
		if(centersMatch(alternatesToCheck[i]) && cornersMatch(alternatesToCheck[i]) && edgesMatch(alternatesToCheck[i])) {
			return true;
		} else if(relatedCaseMatches(alternatesToCheck[i])) {
			return true;
		}
	}
	return false;
}

bool PreviousState::centersMatch(Cube cube) {
	return (faceU[1][1] == cube.getCenterPieceAtPosition(POS_U).getColor(0) &&
		faceD[1][1] == cube.getCenterPieceAtPosition(POS_D).getColor(0) &&
		faceR[1][1] == cube.getCenterPieceAtPosition(POS_R).getColor(0) &&
		faceL[1][1] == cube.getCenterPieceAtPosition(POS_L).getColor(0) &&
		faceF[1][1] == cube.getCenterPieceAtPosition(POS_F).getColor(0) &&
		faceB[1][1] == cube.getCenterPieceAtPosition(POS_B).getColor(0));
}

bool PreviousState::cornersMatch(Cube cube) {
	return (faceU[0][2] == cube.getCornerPieceAtPosition(POS_UBR).getColor(0) &&
		faceB[0][0] == cube.getCornerPieceAtPosition(POS_UBR).getColor(1) &&
		faceR[0][2] == cube.getCornerPieceAtPosition(POS_UBR).getColor(2) &&
		
		faceU[2][2] == cube.getCornerPieceAtPosition(POS_URF).getColor(0) &&
		faceR[0][0] == cube.getCornerPieceAtPosition(POS_URF).getColor(1) &&
		faceF[0][2] == cube.getCornerPieceAtPosition(POS_URF).getColor(2) &&

		faceU[2][0] == cube.getCornerPieceAtPosition(POS_UFL).getColor(0) &&
		faceF[0][0] == cube.getCornerPieceAtPosition(POS_UFL).getColor(1) &&
		faceL[0][2] == cube.getCornerPieceAtPosition(POS_UFL).getColor(2) &&

		faceU[0][0] == cube.getCornerPieceAtPosition(POS_ULB).getColor(0) &&
		faceL[0][0] == cube.getCornerPieceAtPosition(POS_ULB).getColor(1) &&
		faceB[0][2] == cube.getCornerPieceAtPosition(POS_ULB).getColor(2) &&

		faceD[2][0] == cube.getCornerPieceAtPosition(POS_DBL).getColor(0) &&
		faceB[2][2] == cube.getCornerPieceAtPosition(POS_DBL).getColor(1) &&
		faceL[2][0] == cube.getCornerPieceAtPosition(POS_DBL).getColor(2) &&

		faceD[0][0] == cube.getCornerPieceAtPosition(POS_DLF).getColor(0) &&
		faceL[2][2] == cube.getCornerPieceAtPosition(POS_DLF).getColor(1) &&
		faceF[2][0] == cube.getCornerPieceAtPosition(POS_DLF).getColor(2) &&

		faceD[0][2] == cube.getCornerPieceAtPosition(POS_DFR).getColor(0) &&
		faceF[2][2] == cube.getCornerPieceAtPosition(POS_DFR).getColor(1) &&
		faceR[2][0] == cube.getCornerPieceAtPosition(POS_DFR).getColor(2) &&

		faceD[2][2] == cube.getCornerPieceAtPosition(POS_DRB).getColor(0) &&
		faceR[2][2] == cube.getCornerPieceAtPosition(POS_DRB).getColor(1) &&
		faceB[2][0] == cube.getCornerPieceAtPosition(POS_DRB).getColor(2));
}

bool PreviousState::edgesMatch(Cube cube) {
 	return firstSixEdgesMatch(cube) && secondSixEdgesMatch(cube);
}

bool PreviousState::firstSixEdgesMatch(Cube cube) {
	return (faceU[0][1] == cube.getEdgePieceAtPosition(POS_UB).getColor(0) &&
		faceB[0][1] == cube.getEdgePieceAtPosition(POS_UB).getColor(1) &&

		faceU[1][2] == cube.getEdgePieceAtPosition(POS_UR).getColor(0) &&
		faceR[0][1] == cube.getEdgePieceAtPosition(POS_UR).getColor(1) &&

		faceF[0][1] == cube.getEdgePieceAtPosition(POS_FU).getColor(0) &&
		faceU[2][1] == cube.getEdgePieceAtPosition(POS_FU).getColor(1) &&

		faceL[0][1] == cube.getEdgePieceAtPosition(POS_LU).getColor(0) &&
		faceU[1][0] == cube.getEdgePieceAtPosition(POS_LU).getColor(1) &&

		faceR[1][0] == cube.getEdgePieceAtPosition(POS_RF).getColor(0) &&
		faceF[1][2] == cube.getEdgePieceAtPosition(POS_RF).getColor(1) &&

		faceB[1][0] == cube.getEdgePieceAtPosition(POS_BR).getColor(0) &&
		faceR[1][2] == cube.getEdgePieceAtPosition(POS_BR).getColor(1));
}
bool PreviousState::secondSixEdgesMatch(Cube cube) {
	return (faceL[1][0] == cube.getEdgePieceAtPosition(POS_LB).getColor(0) &&
		faceB[1][2] == cube.getEdgePieceAtPosition(POS_LB).getColor(1) &&

		faceF[1][0] == cube.getEdgePieceAtPosition(POS_FL).getColor(0) &&
		faceL[1][2] == cube.getEdgePieceAtPosition(POS_FL).getColor(1) &&

		faceD[0][1] == cube.getEdgePieceAtPosition(POS_DF).getColor(0) &&
		faceF[2][1] == cube.getEdgePieceAtPosition(POS_DF).getColor(1) &&

		faceR[2][1] == cube.getEdgePieceAtPosition(POS_RD).getColor(0) &&
		faceD[1][2] == cube.getEdgePieceAtPosition(POS_RD).getColor(1) &&

		faceB[2][1] == cube.getEdgePieceAtPosition(POS_BD).getColor(0) &&
		faceD[2][1] == cube.getEdgePieceAtPosition(POS_BD).getColor(1) &&

		faceD[1][0] == cube.getEdgePieceAtPosition(POS_DL).getColor(0) &&
		faceL[2][1] == cube.getEdgePieceAtPosition(POS_DL).getColor(1));
}

vector<Cube> PreviousState::matchingCases(Cube cube) {
	vector<Cube> cases;
	cases.push_back(cube);

	cases.insert(cases.end(), mutatedCases(cube).begin(), mutatedCases(cube).end());

	return cases;
}

vector<Cube> PreviousState::mutatedCases(Cube cube) {
	vector<Cube> cases;

	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	
	cube.rotate(X);

	cube.rotate(Y);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);

	cube.rotate(X);

	cube.rotate(Y);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);

	cube.rotate(X);

	cube.rotate(Y);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);

	cube.rotate(X);
	cube.rotate(Y);

	cube.rotate(Z);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);

	cube.rotate(X);

	cube.rotate(Z2);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);
	cube.rotate(X);
	cases.push_back(cube);

	return cases;
}

bool PreviousState::relatedCaseMatches(Cube cube) {
	for(int i = 0; i < 24; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				faceU[j][k] = RELATED_COLORS[i][indexOfColor(faceU[j][k])];
				faceD[j][k] = RELATED_COLORS[i][indexOfColor(faceD[j][k])];
				faceR[j][k] = RELATED_COLORS[i][indexOfColor(faceR[j][k])];
				faceL[j][k] = RELATED_COLORS[i][indexOfColor(faceL[j][k])];
				faceF[j][k] = RELATED_COLORS[i][indexOfColor(faceF[j][k])];
				faceB[j][k] = RELATED_COLORS[i][indexOfColor(faceB[j][k])];
			}
		}
		if(centersMatch(cube) && cornersMatch(cube) && edgesMatch(cube)) {
			return true;
		}
	}
	return false;
}