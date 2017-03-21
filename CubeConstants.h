//the values of these constants are arbitrary, but the names 
//associate to Rubik's Cube notation for faces and rotation

//rotations
#define U 0
#define UI 1
#define U2 2

#define D 3
#define DI 4
#define D2 5

#define R 6
#define RI 7
#define R2 8

#define L 9
#define LI 10
#define L2 11

#define F 12
#define FI 13
#define F2 14

#define B 15
#define BI 16
#define B2 17

#define M 18
#define MI 19
#define M2 20

#define E 21
#define EI 22
#define E2 23

#define S 24
#define SI 25
#define S2 26

#define X 27
#define XI 28
#define X2 29

#define Y 30
#define YI 31
#define Y2 32

#define Z 33
#define ZI 34
#define Z2 35

//center positions
#define POS_U 0
#define POS_D 1
#define POS_R 2
#define POS_L 3
#define POS_F 4
#define POS_B 5

//edge positions
#define POS_UB 0
#define POS_UR 1
#define POS_FU 2
#define POS_LU 3
#define POS_RF 4
#define POS_BR 5
#define POS_LB 6
#define POS_FL 7
#define POS_DF 8
#define POS_RD 9
#define POS_BD 10
#define POS_DL 11

//corner positions
#define POS_UBR 0
#define POS_URF 1
#define POS_UFL 2
#define POS_ULB 3
#define POS_DBL 4
#define POS_DLF 5
#define POS_DFR 6
#define POS_DRB 7

//types of cubies
#define CENTER 0
#define EDGE 1
#define CORNER 2