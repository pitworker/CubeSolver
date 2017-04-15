#pragma once
#include <cstdlib>
#include "CubeConstants.h"
#include "CenterPiece.cpp"
#include "EdgePiece.cpp"
#include "CornerPiece.cpp"

class Cube {
private: 
	CenterPiece centerPiece [6];
	EdgePiece edgePiece [12];
	CornerPiece cornerPiece[8];

public:
	Cube() {
		centerPiece[POS_U].set(POS_U, 'W');
		centerPiece[POS_D].set(POS_D, 'Y');
		centerPiece[POS_R].set(POS_R, 'B');
		centerPiece[POS_L].set(POS_L, 'G');
		centerPiece[POS_F].set(POS_F, 'R');
		centerPiece[POS_B].set(POS_B, 'O');

		edgePiece[POS_UB].set(POS_UB, 0, 'W', 'O');
		edgePiece[POS_UR].set(POS_UR, 0, 'W', 'B');
		edgePiece[POS_FU].set(POS_FU, 0, 'R', 'W');
		edgePiece[POS_LU].set(POS_LU, 0, 'G', 'W');
		edgePiece[POS_RF].set(POS_RF, 0, 'B', 'R');
		edgePiece[POS_BR].set(POS_BR, 0, 'O', 'B');
		edgePiece[POS_LB].set(POS_LB, 0, 'G', 'O');
		edgePiece[POS_FL].set(POS_FL, 0, 'R', 'G');
		edgePiece[POS_DF].set(POS_DF, 0, 'Y', 'R');
		edgePiece[POS_RD].set(POS_RD, 0, 'B', 'Y');
		edgePiece[POS_BD].set(POS_BD, 0, 'O', 'Y');
		edgePiece[POS_DL].set(POS_DL, 0, 'Y', 'G');

		cornerPiece[POS_UBR].set(POS_UBR, 0, 'W', 'O', 'B');
		cornerPiece[POS_URF].set(POS_URF, 0, 'W', 'B', 'R');
		cornerPiece[POS_UFL].set(POS_UFL, 0, 'W', 'R', 'G');
		cornerPiece[POS_ULB].set(POS_ULB, 0, 'W', 'G', 'O');
		cornerPiece[POS_DBL].set(POS_DBL, 0, 'Y', 'O', 'G');
		cornerPiece[POS_DLF].set(POS_DLF, 0, 'Y', 'G', 'R');
		cornerPiece[POS_DFR].set(POS_DFR, 0, 'Y', 'R', 'B');
		cornerPiece[POS_DRB].set(POS_DRB, 0, 'Y', 'B', 'O');
	}

	void rotate(int rotationDirection) {
		for(int i = 0; i < 6; i++) {
			centerPiece[i].rotateCubie(rotationDirection);
		}
		for(int i = 0; i < 12; i++) {
			edgePiece[i].rotateCubie(rotationDirection);
		}
		for(int i = 0; i < 8; i++) {
			cornerPiece[i].rotateCubie(rotationDirection);
		}
	}

	CenterPiece getCenterPieceAtPosition(int position) {
		for(int i = 0; i < 6; i++) {
			if(centerPiece[i].getPositionOnCube() == position) {
				return centerPiece[i];
			}
		}
		return CenterPiece();
	}
	EdgePiece getEdgePieceAtPosition(int position) {
		for(int i = 0; i < 12; i++) {
			if(edgePiece[i].getPositionOnCube() == position) {
				return edgePiece[i];
			}
		}
		return EdgePiece();
	}
	CornerPiece getCornerPieceAtPosition(int position) {
		for(int i = 0; i < 8; i++) {
			if(cornerPiece[i].getPositionOnCube() == position) {
				return cornerPiece[i];
			}
		}
		return CornerPiece();
	}

	void setCenterPieceAtPosition(int position, CenterPiece pieceToSetTo) {
		for(int i = 0; i < 6; i++) {
			if(centerPiece[i].getPositionOnCube() == position) {
				centerPiece[i].set(pieceToSetTo);
				break;
			}
		}
	}
	void setEdgePieceAtPosition(int position, EdgePiece pieceToSetTo) {
		for(int i = 0; i < 12; i++) {
			if(edgePiece[i].getPositionOnCube() == position) {
				edgePiece[i].set(pieceToSetTo);
				break;
			}
		}
	}
	void setCornerPieceAtPosition(int position, CornerPiece pieceToSetTo) {
		for(int i = 0; i < 8; i++) {
			if(cornerPiece[i].getPositionOnCube() == position) {
				cornerPiece[i].set(pieceToSetTo);
				break;
			}
		}
	}
	
	void replaceWithCube(Cube cube) {
		for(int i = 0; i < 6; i++) {
			setCenterPieceAtPosition(i, cube.getCenterPieceAtPosition(i));
		}
		for(int i = 0; i < 12; i++) {
			setEdgePieceAtPosition(i, cube.getEdgePieceAtPosition(i));
		}
		for(int i = 0; i < 8; i++) {
			setCornerPieceAtPosition(i, cube.getCornerPieceAtPosition(i));
		}
	}

	int getPositionOfCenterPieceWithColor(char color) {
		for(int i = 0; i < 6; i++) {
			if(getCenterPieceAtPosition(i).getColor(0) == color) {
				return i;
			}
		}
		return -1;
	}
};
