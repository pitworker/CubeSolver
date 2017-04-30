#include "CubeConstants.h"

const int REDUNDANT_ROTATIONS[27][5] = {
	/*U*/ {U,UI,U2,DI,EI},
	/*UI*/{U,UI,U2,D,E},
	/*U2*/{U,UI,U2,D2,E2},

	/*D*/ {D,DI,D2,UI,E},
	/*DI*/{D,DI,D2,U,EI},
	/*D2*/{D,DI,D2,U2,E2},

	/*R*/ {R,RI,R2,LI,MI},
	/*RI*/{R,RI,R2,L,M},
	/*R2*/{R,RI,R2,L2,M2},

	/*L*/ {L,LI,L2,RI,M},
	/*LI*/{L,LI,L2,R,MI},
	/*L2*/{L,LI,L2,R2,M2},

	/*F*/ {F,FI,F2,BI,S},
	/*FI*/{F,FI,F2,B,SI},
	/*F2*/{F,FI,F2,B2,S2},

	/*B*/ {B,BI,B2,FI,SI},
	/*BI*/{B,BI,B2,F,S},
	/*B2*/{B,BI,B2,F2,S2},

	/*M*/ {M,MI,M2,RI,L},
	/*MI*/{M,MI,M2,R,LI},
	/*M2*/{M,MI,M2,R2,L2},

	/*E*/ {E,EI,E2,UI,D},
	/*EI*/{E,EI,E2,U,DI},
	/*E2*/{E,EI,E2,U2,D2},

	/*S*/ {S,SI,S2,F,BI},
	/*SI*/{S,SI,S2,FI,B},
	/*S2*/{S,SI,S2,F2,B2}
};