#include <cstdlib>
#include <"CubeConstants.h">

class Cube {
private: 
	CenterPiece centerPiece [6];
	EdgePiece edgePiece [12];
	CornerPiece cornerPiece[8];
	char faceU [3][3];
	char faceD [3][3];
	char faceF [3][3];
	char faceB [3][3];
	char faceR [3][3];
	char faceL [3][3];

public:
	Cube() {
		centerPiece[POS_U] = new CenterPiece(POS_U, 'W');
		centerPiece[POS_D] = new CenterPiece(POS_D, 'Y');
		centerPiece[POS_R] = new CenterPiece(POS_R, 'B');
		centerPiece[POS_L] = new CenterPiece(POS_L, 'G');
		centerPiece[POS_F] = new CenterPiece(POS_F, 'R');
		centerPiece[POS_B] = new CenterPiece(POS_B, 'O');

		edgePiece[POS_UB] = new EdgePiece(POS_UB, 0, {'W','O'});
		edgePiece[POS_UR] = new EdgePiece(POS_UR, 0, {'W','B'});
		edgePiece[POS_FU] = new EdgePiece(POS_FU, 0, {'R','W'});
		edgePiece[POS_LU] = new EdgePiece(POS_LU, 0, {'G','W'});
		edgePiece[POS_RF] = new EdgePiece(POS_RF, 0, {'B','R'});
		edgePiece[POS_BR] = new EdgePiece(POS_BR, 0, {'O','B'});
		edgePiece[POS_LB] = new EdgePiece(POS_LB, 0, {'G','O'});
		edgePiece[POS_FL] = new EdgePiece(POS_FL, 0, {'R','G'});
		edgePiece[POS_DF] = new EdgePiece(POS_DF, 0, {'Y','R'});
		edgePiece[POS_RD] = new EdgePiece(POS_RD, 0, {'B','Y'});
		edgePiece[POS_BD] = new EdgePiece(POS_BD, 0, {'O','Y'});
		edgePiece[POS_DL] = new EdgePiece(POS_DL, 0, {'Y','G'});

		cornerPiece[POS_UBR] = new CornerPiece(POS_UBR, 0, {'W', 'O', 'B'});
		cornerPiece[POS_URF] = new CornerPiece(POS_URF, 0, {'W', 'B', 'R'});
		cornerPiece[POS_UFL] = new CornerPiece(POS_UFL, 0, {'W', 'R', 'G'});
		cornerPiece[POS_ULB] = new CornerPiece(POS_ULB, 0, {'W', 'G', 'O'});
		cornerPiece[POS_DBL] = new CornerPiece(POS_DBL, 0, {'Y', 'O', 'G'});
		cornerPiece[POS_DLF] = new CornerPiece(POS_DLF, 0, {'Y', 'G', 'R'});
		cornerPiece[POS_DFR] = new CornerPiece(POS_DFR, 0, {'Y', 'R', 'B'});
		cornerPiece[POS_DRB] = new CornerPiece(POS_DRB, 0, {'Y', 'B', 'O'});
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

	Cubie getCubieAtPosition(int type, int position) {
		if(type == CENTER) {
			for(int i = 0; i < 6; i++) {
				if(centerPiece[i].getPositionOnCube == position) {
					return centerPiece[i];
				}
			}
		}
	}
};