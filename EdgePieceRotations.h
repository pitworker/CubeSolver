#include "CubeConstants.h"

//TODO: fix messed up positions for X, Y, Z; fix messed up orientations

const int ROTATE_POSITION[12][36] = {
			  //U       UI      U2      D       DI      D2      R       RI      R2      L       LI      L2      F       FI      F2      B       BI      B2      M       MI      M2      E       EI      E2      S       SI      S2      X       XI      X2      Y       YI      Y2      Z       ZI      Z2
	/*POS_UB*/ {POS_UR, POS_LU, POS_FU, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_LB, POS_BR, POS_BD, POS_FU, POS_BD, POS_DF, -1,     -1,     -1,     -1,     -1,     -1,     POS_BD, POS_FU, POS_DF, POS_UR, POS_LU, POS_FU, POS_BR, POS_LB, POS_BD},
	/*POS_UR*/ {POS_FU, POS_UB, POS_LU, -1,     -1,     -1,     POS_BR, POS_RF, POS_RD, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_RD, POS_LU, POS_DL, POS_BR, POS_RF, POS_RD, POS_FU, POS_UB, POS_LU, POS_RD, POS_LU, POS_DL},
	/*POS_FU*/ {POS_LU, POS_UR, POS_UB, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_RF, POS_FL, POS_DF, -1,     -1,     -1,     POS_DF, POS_UB, POS_BD, -1,     -1,     -1,     -1,     -1,     -1,     POS_UB, POS_DF, POS_BD, POS_LU, POS_UR, POS_UB, POS_RF, POS_FL, POS_DF},	
	/*POS_LU*/ {POS_UB, POS_FU, POS_UR, -1,     -1,     -1,     -1,     -1,     -1,     POS_FL, POS_LB, POS_DL, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_UR, POS_DL, POS_RD, POS_LB, POS_FL, POS_DL, POS_UB, POS_FU, POS_UR, POS_UR, POS_DL, POS_RD},
	/*POS_RF*/ {-1,    -1,      -1,     -1,     -1,     -1,     POS_UR, POS_RD, POS_BR, -1,     -1,     -1,     POS_DF, POS_FU, POS_FL, -1,     -1,     -1,     -1,     -1,     -1,     POS_BR, POS_FL, POS_LB, -1,     -1,     -1,     POS_UR, POS_RD, POS_BR, POS_FL, POS_BR, POS_LB, POS_DF, POS_FU, POS_FL},
	/*POS_BR*/ {-1,    -1,      -1,     -1,     -1,     -1,     POS_RD, POS_UR, POS_RF, -1,     -1,     -1,     -1,     -1,     -1,     POS_UB, POS_BD, POS_LB, -1,     -1,     -1,     POS_LB, POS_RF, POS_FL, -1,     -1,     -1,     POS_RD, POS_UR, POS_RF, POS_RF, POS_LB, POS_FL, POS_BD, POS_UB, POS_LB},
	/*POS_LB*/ {-1,    -1,      -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_LU, POS_DL, POS_FL, -1,     -1,     -1,     POS_BD, POS_UB, POS_BR, -1,     -1,     -1,     POS_FL, POS_BR, POS_RF, -1,     -1,     -1,     POS_DL, POS_LU, POS_FL, POS_BR, POS_FL, POS_RF, POS_UB, POS_BD, POS_BR},
	/*POS_FL*/ {-1,    -1,      -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_DL, POS_LU, POS_LB, POS_FU, POS_DF, POS_RF, -1,     -1,     -1,     -1,     -1,     -1,     POS_RF, POS_LB, POS_BR, -1,     -1,     -1,     POS_LU, POS_DL, POS_LB, POS_LB, POS_RF, POS_BR, POS_FU, POS_DF, POS_RF},
	/*POS_DF*/ {-1,    -1,      -1,     POS_RD, POS_DL, POS_BD, -1,     -1,     -1,     -1,     -1,     -1,     POS_FL, POS_RF, POS_FU, -1,     -1,     -1,     POS_BD, POS_FU, POS_UB, -1,     -1,     -1,     -1,     -1,     -1,     POS_FU, POS_BD, POS_UB, POS_DL, POS_RD, POS_BD, POS_FL, POS_RF, POS_FU},	
	/*POS_RD*/ {-1,    -1,      -1,     POS_BD, POS_DF, POS_DL, POS_RF, POS_BR, POS_UR, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_DL, POS_UR, POS_LU, POS_RF, POS_BR, POS_UR, POS_DF, POS_BD, POS_DL, POS_DL, POS_UR, POS_LU},
	/*POS_BD*/ {-1,    -1,      -1,     POS_DL, POS_RD, POS_DF, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_BR, POS_LB, POS_UB, POS_UB, POS_DF, POS_FU, -1,     -1,     -1,     -1,     -1,     -1,     POS_DF, POS_UB, POS_FU, POS_RD, POS_DL, POS_DF, POS_LB, POS_BR, POS_UB},
	/*POS_DL*/ {-1,    -1,      -1,     POS_DF, POS_BD, POS_RD, -1,     -1,     -1,     POS_LB, POS_FL, POS_LU, -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     POS_LU, POS_RD, POS_UR, POS_FL, POS_LB, POS_LU, POS_BD, POS_DF, POS_RD, POS_LU, POS_RD, POS_UR}			
};

const int ROTATE_ORIENTATION[12][36] = {
			  //U   UI  U2  D   DI  D2  R   RI  R2  L   LI  L2  F   FI  F2  B   BI  B2  M   MI  M2  E   EI  E2  S   SI  S2  X   XI  X2  Y   YI  Y2  Z   ZI  Z2
	/*POS_UB*/ {1,  0,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  0,  1,  0,  0,  0,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1},
	/*POS_UR*/ {0,  1,  1,  -1, -1, -1, 1,  0,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1,  0,  0,  0},
	/*POS_FU*/ {1,  0,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, 0,  0,  0,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1},	
	/*POS_LU*/ {0,  1,  1,  -1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1,  0,  0,  0},
	/*POS_RF*/ {-1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, 1,  0,  1,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  -1, -1, -1, 0,  1,  1,  0,  0,  0,  1,  0,  1},
	/*POS_BR*/ {-1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, 0,  0,  0,  -1, -1, -1, 0,  1,  1,  0,  0,  0,  1,  0,  1},
	/*POS_LB*/ {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  0,  1,  -1, -1, -1, 0,  1,  1,  -1, -1, -1, 0,  0,  0,  -1, -1, -1, 0,  1,  1,  0,  0,  0,  1,  0,  1},
	/*POS_FL*/ {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  0,  1,  1,  0,  1,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  -1, -1, -1, 0,  1,  1,  0,  0,  0,  1,  0,  1},
	/*POS_DF*/ {-1, -1, -1, 0,  1,  1,  -1, -1, -1, -1, -1, -1, 0,  1,  1,  -1, -1, -1, 0,  0,  0,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1},	
	/*POS_RD*/ {-1, -1, -1, 1,  0,  1,  1,  0,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1,  0,  0,  0},
	/*POS_BD*/ {-1, -1, -1, 0,  1,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  0,  1,  0,  0,  0,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1},
	/*POS_DL*/ {-1, -1, -1, 1,  0,  1,  -1, -1, -1, 0,  1,  1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  1,  0,  1,  0,  1,  1,  0,  0,  0}			
};