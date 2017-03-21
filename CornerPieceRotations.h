#include "CubeConstants.h"

//TODO: fix messed up positions for X, Y, Z; fix messed up orientations

const int ROTATE_POSITION[8][36] = {
			   //U        UI       U2       D        DI       D2       R        RI       R2       L        LI       L2       F        FI       F2       B        BI       B2       M        MI       M2       E        EI       E2       S        SI       S2       X        XI       X2       Y        YI       Y2       Z        ZI       Z2
	/*POS_UBR*/ {POS_URF, POS_ULB, POS_UFL, -1,      -1,      -1,      POS_DRB, POS_URF, POS_DFR, -1,      -1,      -1,      -1,      -1,      -1,      POS_ULB, POS_DRB, POS_DBL, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_DRB, POS_URF, POS_DFR, POS_URF, POS_ULB, POS_UFL, POS_DRB, POS_ULB, POS_DBL},
	/*POS_URF*/ {POS_UFL, POS_UBR, POS_ULB, -1,      -1,      -1,      POS_UBR, POS_DFR, POS_DRB, -1,      -1,      -1,      POS_DFR, POS_UFL, POS_DLF, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_UBR, POS_DFR, POS_DRB, POS_UFL, POS_UBR, POS_ULB, POS_DFR, POS_UFL, POS_DLF},
	/*POS_UFL*/ {POS_ULB, POS_URF, POS_UBR, -1,      -1,      -1,      -1,      -1,      -1,      POS_DLF, POS_ULB, POS_DBL, POS_URF, POS_DLF, POS_DFR, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_ULB, POS_DLF, POS_DBL, POS_ULB, POS_URF, POS_UBR, POS_URF, POS_DLF, POS_DFR},	
	/*POS_ULB*/ {POS_UBR, POS_UFL, POS_URF, -1,      -1,      -1,      -1,      -1,      -1,      POS_UFL, POS_DBL, POS_DLF, -1,      -1,      -1,      POS_DBL, POS_UBR, POS_DRB, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_DBL, POS_UFL, POS_DLF, POS_UBR, POS_UFL, POS_URF, POS_UBR, POS_DBL, POS_DRB},
	/*POS_DBL*/ {-1,      -1,      -1,      POS_DLF, POS_DRB, POS_DFR, -1,      -1,      -1,      POS_ULB, POS_DLF, POS_UFL, -1,      -1,      -1,      POS_DRB, POS_ULB, POS_UBR, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_DLF, POS_ULB, POS_UFL, POS_DRB, POS_DLF, POS_DFR, POS_ULB, POS_DRB, POS_UBR},
	/*POS_DLF*/ {-1,      -1,      -1,      POS_DFR, POS_DBL, POS_DRB, -1,      -1,      -1,      POS_DBL, POS_UFL, POS_ULB, POS_UFL, POS_DFR, POS_URF, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_UFL, POS_DBL, POS_ULB, POS_DBL, POS_DFR, POS_DRB, POS_UFL, POS_DFR, POS_URF},
	/*POS_DFR*/ {-1,      -1,      -1,      POS_DRB, POS_DLF, POS_DBL, POS_URF, POS_DRB, POS_UBR, -1,      -1,      -1,      POS_DLF, POS_URF, POS_UFL, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_URF, POS_DRB, POS_UBR, POS_DLF, POS_DRB, POS_DBL, POS_DLF, POS_URF, POS_UFL},
	/*POS_DRB*/ {-1,      -1,      -1,      POS_DBL, POS_DFR, POS_DLF, POS_DFR, POS_UBR, POS_URF, -1,      -1,      -1,      -1,      -1,      -1,      POS_UBR, POS_DBL, POS_ULB, -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      -1,      POS_DFR, POS_UBR, POS_URF, POS_DFR, POS_DBL, POS_DLF, POS_DBL, POS_UBR, POS_ULB}
};

const int ROTATE_ORIENTATION[8][36] = {
			   //U   UI  U2  D   DI  D2  R   RI  R2  L   LI  L2  F   FI  F2  B   BI  B2  M   MI  M2  E   EI  E2  S   SI  S2  X   XI  X2  Y   YI  Y2  Z   ZI  Z2
	/*POS_UBR*/ {0,  0,  0,  -1, -1, -1, 2,  2,  0,  -1, -1, -1, -1, -1, -1, 1,  1,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 2,  2,  0,  0,  0,  0,  1,  1,  0},
	/*POS_URF*/ {0,  0,  0,  -1, -1, -1, 1,  1,  0,  -1, -1, -1, 2,  2,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  1,  0,  0,  0,  0,  2,  2,  0},
	/*POS_UFL*/ {0,  0,  0,  -1, -1, -1, -1, -1, -1, 2,  2,  0,  1,  1,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2,  2,  0,  0,  0,  0,  1,  1,  0},	
	/*POS_ULB*/ {0,  0,  0,  -1, -1, -1, -1, -1, -1, 1,  1,  0,  -1, -1, -1, 2,  2,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  1,  0,  0,  0,  0,  2,  2,  0},
	/*POS_DBL*/ {-1, -1, -1, 0,  0,  0,  -1, -1, -1, 2,  2,  0,  -1, -1, -1, 1,  1,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 2,  2,  0,  0,  0,  0,  1,  1,  0},
	/*POS_DLF*/ {-1, -1, -1, 0,  0,  0,  -1, -1, -1, 1,  1,  0,  2,  2,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  1,  0,  0,  0,  0,  2,  2,  0},
	/*POS_DFR*/ {-1, -1, -1, 0,  0,  0,  2,  2,  0,  -1, -1, -1, 1,  1,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2,  2,  0,  0,  0,  0,  1,  1,  0},
	/*POS_DRB*/ {-1, -1, -1, 0,  0,  0,  1,  1,  0,  -1, -1, -1, -1, -1, -1, 2,  2,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  1,  0,  0,  0,  0,  2,  2,  0}
}; 
