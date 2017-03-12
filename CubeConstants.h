//the values of these constants are arbitrary, but the names 
//associate to Rubik's Cube notation for faces and rotation

//rotations
const int U = 0;
const int UI = 1;
const int U2 = 2;

const int D = 3;
const int DI = 4;
const int D2 = 5;

const int R = 6;
const int RI = 7;
const int R2 = 8;

const int L = 9;
const int LI = 10;
const int L2 = 11;

const int F = 12;
const int FI = 13;
const int F2 = 14;

const int B = 15;
const int BI = 16;
const int B2 = 17;

const int M = 18;
const int MI = 19;
const int M2 = 20;

const int E = 21;
const int EI = 22;
const int E2 = 23;

const int S = 24;
const int SI = 25;
const int S2 = 26;

const int X = 27;
const int XI = 28;
const int X2 = 29;

const int Y = 30;
const int YI = 31;
const int Y2 = 32;

const int Z = 33;
const int ZI = 34;
const int Z2 = 35;

//center positions
const int POS_U = 0;
const int POS_D = 1;
const int POS_R = 2;
const int POS_L = 3;
const int POS_F = 4;
const int POS_B = 5;

//edge positions
const int POS_UB = 0;
const int POS_UR = 1;
const int POS_FU = 2;
const int POS_LU = 3;
const int POS_RF = 4;
const int POS_BR = 5;
const int POS_LB = 6;
const int POS_FL = 7;
const int POS_DF = 8;
const int POS_RD = 9;
const int POS_BD = 10;
const int POS_DL = 11;

//corner positions
const int POS_UBR = 0;
const int POS_URF = 1;
const int POS_UFL = 2;
const int POS_ULB = 3;
const int POS_DBL = 4;
const int POS_DLF = 5;
const int POS_DFR = 6;
const int POS_DRB = 7;

//types of cubies
const int CENTER = 0;
const int EDGE = 1;
const int CORNER = 2;