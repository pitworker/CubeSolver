#pragma once
#include "CubeSolver.hpp"

CubeSolver::CubeSolver(Cube scrambledCube) {
	cubeToSolve.replaceWithCube(scrambledCube);
}

bool CubeSolver::solveCube() {
	currentStates.push_back(CurrentState(cubeToSolve));
	while(!stateIsSolved(currentStates.front()) && currentStates.front().getLengthOfSolution() < 30) {
		for(int i = 0; i < 27; i++) {
			if(!rotationIsRedundant(currentStates.front(), i)) {
				CurrentState newState = currentStates.front().stateAfterRotating(i);
				if(!stateWasAlreadyVisited(newState)) { //TODO: write stateWasAlreadyVisited()
					currentStates.push_back(newState);
				}
				if(stateIsSolved(newState)) {
					solution = newState.getSolution();
					return true;
				}
				previousStates.push_back(PreviousState(currentStates.front().getCube()));
			}
		}
		currentStates.erase(currentStates.begin());
	}
	return false;
}

string CubeSolver::getSolutionNotation() {
	string solutionAsString = "SOLUTION: ";
	for(int i = 0; i < solution.size(); i++) {
		solutionAsString.append(" ");
		solutionAsString.append(VALID_INPUTS[solution[i]]);
	}
	return solutionAsString;
}
Cube CubeSolver::getSolvedCube() {
	for(int i = 0; i < solution.size(); i++) {
		cubeToSolve.rotate(solution[i]);
	}
	return cubeToSolve;
}

bool CubeSolver::stateIsSolved(CurrentState state) {
	PreviousState solvedCube = PreviousState(Cube());
	return solvedCube.matchesCube(state.getCube()); //TODO: check to make sure matchesCube checks related cases as well
}
bool CubeSolver::rotationIsRedundant(CurrentState state, int currentRotation) {
	for(int i = 0; i < 5; i++) {
		if(REDUNDANT_ROTATIONS[state.getLastRotation()][i] == currentRotation) {
			return true; 
		}
	}
	return false;
}
bool CubeSolver::stateWasAlreadyVisited(CurrentState state) {
	for(int i = 0; i < previousStates.size(); i++) {
		if(previousStates[i].matchesCube(state.getCube())) {
			return true;
		}
	}
	return false;
}


// int CubeSolver::scanForCenterWithColor(char color) {
// 	return centerWithColor(color).getPositionOnCube();
// }
// int CubeSolver::scanForEdgeWithColors(char color0, char color1) {
// 	return edgeWithColors(color0, color1).getPositionOnCube();
// }
// int CubeSolver::scanForCornerWithColors(char color0, char color1, char color2) {
// 	return cornerWithColors(color0, color1, color2).getPositionOnCube();
// }

// CenterPiece CubeSolver::centerWithColor(char color) {
// 	for(int i = 0; i < 6; i++) {
// 		if(cubeToSolve.getCenterPieceAtPosition(i).getColor(0) == color) {
// 			return cubeToSolve.getCenterPieceAtPosition(i);
// 		}
// 	}
// 	return CenterPiece();
// }
// EdgePiece CubeSolver::edgeWithColors(char color0, char color1) {
// 	for(int i = 0; i < 12; i++) {
// 		char edgeColor0 = cubeToSolve.getEdgePieceAtPosition(i).getColor(0);
// 		char edgeColor1 = cubeToSolve.getEdgePieceAtPosition(i).getColor(1);
// 		if((edgeColor0 == color0 || edgeColor1 == color0) && (edgeColor0 == color1 || edgeColor1 == color1)) {
// 			return cubeToSolve.getEdgePieceAtPosition(i);
// 		}
// 	}
// 	return EdgePiece();
// }
// CornerPiece CubeSolver::cornerWithColors(char color0, char color1, char color2) {
// 	for(int i = 0; i < 8; i++) {
// 		char cornerColor0 = cubeToSolve.getCornerPieceAtPosition(i).getColor(0);
// 		char cornerColor1 = cubeToSolve.getCornerPieceAtPosition(i).getColor(1);
// 		char cornerColor2 = cubeToSolve.getCornerPieceAtPosition(i).getColor(2);
// 		if((cornerColor0 == color0 || cornerColor1 == color0 || cornerColor2 == color0) && 
// 			(cornerColor0 == color1 || cornerColor1 == color1 || cornerColor2 == color1) &&
// 			(cornerColor0 == color2 || cornerColor1 == color2 || cornerColor2 == color2)) {
// 			return cubeToSolve.getCornerPieceAtPosition(i);
// 		}
// 	}
// 	return CornerPiece();
// }

// void CubeSolver::solveCross() {
// 	setStartingFace();
	
// 	placeCrossEdgesOnDownFace();
// 	placeCrossEdgesOnEquatorSlice();
// 	placeCrossEdgesOnUpFace();
// }
// void CubeSolver::solveF2L() {

// }
// void CubeSolver::solveOLL() {

// }
// void CubeSolver::solvePLL() {

// }

// void CubeSolver::setStartingFace() {
// 	orientFaceToFace(scanForCenterWithColor('W'), POS_D);
// }
// void CubeSolver::orientFaceToFace(int faceToOrient, int targetFace) {
// 	if(faceToOrient != targetFace && faceToOrient >= 0 && faceToOrient < 6 && targetFace >= 0 && targetFace < 6) {
// 		if(faceToOrient == POS_U || faceToOrient == POS_D) {
// 			int direction = faceToOrient - POS_U; //will be 0 if face is POS_U and 1 if face is POS_D
// 			if(targetFace == POS_U || targetFace == POS_D) {
// 				addToSolution(Z2);
// 			} else if(targetFace == POS_R) {
// 				addToSolution(Z + direction);
// 			} else if(targetFace == POS_L) {
// 				addToSolution(ZI - direction);
// 			} else if(targetFace == POS_F) {
// 				addToSolution(XI - direction);
// 			} else if(targetFace == POS_B) {
// 				addToSolution(X + direction);
// 			}
// 		} else if(faceToOrient == POS_R || faceToOrient == POS_L) {
// 			int direction = faceToOrient - POS_R; //will be 0 if face is POS_R and 1 if face is POS_L
// 			if(targetFace == POS_R || targetFace == POS_L) {
// 				addToSolution(Y2);
// 			} else if(targetFace == POS_U) {
// 				addToSolution(ZI - direction);
// 			} else if(targetFace == POS_D) {
// 				addToSolution(Z + direction);
// 			} else if(targetFace == POS_F) {
// 				addToSolution(Y + direction);
// 			} else if(targetFace == POS_B) {
// 				addToSolution(YI - direction);
// 			}
// 		} else if(faceToOrient == POS_F || faceToOrient == POS_B) {
// 			int direction = faceToOrient - POS_F; //will be 0 if face is POS_F and 1 if face is POS_B
// 			if(targetFace == POS_F || targetFace == POS_B) {
// 				addToSolution(X2);
// 			} else if(targetFace == POS_U) {
// 				addToSolution(X + direction);
// 			} else if(targetFace == POS_D) {
// 				addToSolution(XI - direction);
// 			} else if(targetFace == POS_R) {
// 				addToSolution(YI - direction);
// 			} else if(targetFace == POS_L) {
// 				addToSolution(Y + direction);
// 			}
// 		} 
// 	}
// }

// void CubeSolver::addToSolution(int rotation) {
// 	cubeToSolve.rotate(rotation);
// 	solution.push_back(rotation);
// }

// void CubeSolver::rotateCubeAccordingToSolution() {
// 	for(int i = 0; i < solution.size(); i++) {
// 		cubeToSolve.rotate(solution[i]);
// 	}
// }

// void CubeSolver::placeCrossEdgesOnDownFace() {
// 	for(int i = POS_DF; i <= POS_DL; i++) {
// 		EdgePiece currentPiece = cubeToSolve.getEdgePieceAtPosition(i);
// 		if(currentPiece.hasColor('W')) {
// 		 	int nonWhiteFace = 0;
// 		 	if(currentPiece.getColor(0) == 'W') {
// 		 		nonWhiteFace = 1;
// 		 	}
// 		 	if(currentPiece.isOnFaceOfCube(cubeToSolve.getPositionOfCenterWithColor(currentPiece.getColor(nonWhiteFace)))) {
// 		 		if(currentPiece.getOrientation() == 1) {
// 		 			//algorithm to flip the edge over
// 		 		} else {
// 		 			//cubie is in the correct place with correct orientation
// 		 		}
// 		 	} else {
// 		 		if(currentPiece.getOrientation() == 0) {
// 		 		//algorithm to place correctly oriented edge in correct position
// 		 		} else {
// 		 		//algorithm to place incorrectly oriented edge in correct position with correct orientation
// 		 		}
// 		 		i--; //you need to check the piece at this position again to make sure you did not place another white edge piece in here
// 		 	}
// 		 }
// 	}
// }
// void CubeSolver::placeCrossEdgesOnEquatorSlice() {

// }
// void CubeSolver::placeCrossEdgesOnUpFace() {

// }