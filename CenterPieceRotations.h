#include "CubeConstants.h"

//TODO: fix messed up positions for X, Y, Z

const int ROTATE_POSITION[6][36] = {
			 //U      UI     U2     D      DI     D2     R      RI     R2     L      LI     L2     F      FI     F2     B      BI     B2     M      MI     M2     E      EI     E2     S      SI     S2     X      XI     X2     Y      YI     Y2     Z      ZI     Z2
	/*POS_U*/ {POS_U, POS_U, POS_U, -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    POS_F, POS_B, POS_D, -1,    -1,    -1,    POS_R, POS_L, POS_D, POS_B, POS_F, POS_D, POS_U, POS_U, POS_U, POS_R, POS_L, POS_D},
	/*POS_D*/ {-1,    -1,    -1,    POS_D, POS_D, POS_D, -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    POS_B, POS_F, POS_U, -1,    -1,    -1,    POS_L, POS_R, POS_U, POS_F, POS_B, POS_U, POS_D, POS_D, POS_D, POS_L, POS_R, POS_U},
	/*POS_R*/ {-1,    -1,    -1,    -1,    -1,    -1,    POS_R, POS_R, POS_R, -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   -1,     POS_B, POS_F, POS_L, POS_D, POS_U, POS_L, POS_R, POS_R, POS_R, POS_F, POS_B, POS_L, POS_D, POS_U, POS_L},	
	/*POS_L*/ {-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    POS_L, POS_L, POS_L, -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   -1,     POS_F, POS_B, POS_R, POS_U, POS_D, POS_R, POS_L, POS_L, POS_L, POS_B, POS_F, POS_R, POS_U, POS_D, POS_R},
	/*POS_F*/ {-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    POS_F, POS_F, POS_F, -1,    -1,    -1,    POS_D, POS_U, POS_B, POS_R, POS_L, POS_B, -1,    -1,    -1,    POS_U, POS_D, POS_B, POS_L, POS_R, POS_B, POS_F, POS_F, POS_F},
	/*POS_B*/ {-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    POS_B, POS_B, POS_B, POS_U, POS_D, POS_F, POS_L, POS_R, POS_F, -1,    -1,    -1,    POS_D, POS_U, POS_F, POS_R, POS_L, POS_F, POS_B, POS_B, POS_B}			
};