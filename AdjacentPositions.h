#include "CubeConstants.h"

//Edges

int getAdjacentFaceEdge(int face, int location) {
	if(face == U) {
		switch (location) {
			case 0: return B;
				break;
			case 1: return R;
				break;
			case 2: return F;
				break;
			case 3: return L;
				break;
			default: return -1;
				break;
		}
	} else if(face == D) {
		switch (location) {
			case 0: return F;
				break;
			case 1: return R;
				break;
			case 2: return B;
				break;
			case 3: return L;
				break;
			default: return -1;
				break;
		}
	} else if(face == R) {
		switch (location) {
			case 0: return U;
				break;
			case 1: return B;
				break;
			case 2: return D;
				break;
			case 3: return F;
				break;
			default: return -1;
				break;
		}
	} else if(face == L) {
		switch (location) {
			case 0: return D;
				break;
			case 1: return B;
				break;
			case 2: return U;
				break;
			case 3: return F;
				break;
			default: return -1;
				break;
		}
	} else if(face == F) {
		switch (location) {
			case 0: return L;
				break;
			case 1: return U;
				break;
			case 2: return R;
				break;
			case 3: return D;
				break;
			default: return -1;
				break;
		}
	} else if(face == B) {
		switch (location) {
			case 0: return R;
				break;
			case 1: return U;
				break;
			case 2: return L;
				break;
			case 3: return D;
				break;
			default: return -1;
				break;
		}
	} else {
		return -1;
	}
}

int getAdjacentLocationEdge(int face, int location) {
	int adjacentFace = getAdjacentFaceEdge(face, location);
	if(face == U) {
		switch (adjacentFace) {
			case F: return 1;
				break;
			case L: return 0;
				break;
			case B: return 1;
				break;
			case R: return 2;
				break;
			default: return -1;
				break;
		}
	} else if(face == D) {
		switch (adjacentFace) {
			case F: return 3;
				break;
			case L: return 0;
				break;
			case B: return 3;
				break;
			case R: return 2;
				break;
			default: return -1;
				break;
		}
	} else if(face == F) {
		switch (adjacentFace) {
			case U: return 2;
				break;
			case L: return 3;
				break;
			case D: return 0;
				break;
			case R: return 3;
				break;
			default: return -1;
				break;
		}
	} else if(face == B) {
		switch (adjacentFace) {
			case U: return 0;
				break;
			case L: return 1;
				break;
			case D: return 3;
				break;
			case R: return 1;
				break;
			default: return -1;
				break;
		}
	} else if(face == L) {
		switch (adjacentFace) {
			case U: return 3;
				break;
			case B: return 2;
				break;
			case D: return 3;
				break;
			case F: return 0;
				break;
			default: return -1;
				break;
		}
	} else if(face == R) {
		switch (adjacentFace) {
			case U: return 1;
				break;
			case B: return 0;
				break;
			case D: return 1;
				break;
			case F: return 2;
				break;
			default: return -1;
				break;
		}
	} else {
		return -1;
	}
}

int getAdjacentOrientationEdge(int orientation) {
	switch (orientation) {
		case 0: return 1;
			break;
		case 1: return 0;
			break;
		default: return -1;
			break;
	}
}

//Corners
int getAdjacentFaceCorner(int face, int location) { //need to deal with the fact that there are 3 faces
	if(face == U) {
		switch (location) {
			case 0: return B;
				break;
			case 1: return R;
				break;
			case 2: return F;
				break;
			case 3: return L;
				break;
			default: return -1;
				break;
		}
	} else if(face == D) {
		switch (location) {
			case 0: return F;
				break;
			case 1: return R;
				break;
			case 2: return B;
				break;
			case 3: return L;
				break;
			default: return -1;
				break;
		}
	} else if(face == R) {
		switch (location) {
			case 0: return U;
				break;
			case 1: return B;
				break;
			case 2: return D;
				break;
			case 3: return F;
				break;
			default: return -1;
				break;
		}
	} else if(face == L) {
		switch (location) {
			case 0: return D;
				break;
			case 1: return B;
				break;
			case 2: return U;
				break;
			case 3: return F;
				break;
			default: return -1;
				break;
		}
	} else if(face == F) {
		switch (location) {
			case 0: return L;
				break;
			case 1: return U;
				break;
			case 2: return R;
				break;
			case 3: return D;
				break;
			default: return -1;
				break;
		}
	} else if(face == B) {
		switch (location) {
			case 0: return R;
				break;
			case 1: return U;
				break;
			case 2: return L;
				break;
			case 3: return D;
				break;
			default: return -1;
				break;
		}
	} else {
		return -1;
	}
}

int getAdjacentLocationCorner(int face, int location) { //which face?
	int adjacentFace = getAdjacentFaceEdge(face, location);
	if(face == U) {
		switch (adjacentFace) {
			case F: return 1;
				break;
			case L: return 0;
				break;
			case B: return 1;
				break;
			case R: return 2;
				break;
			default: return -1;
				break;
		}
	} else if(face == D) {
		switch (adjacentFace) {
			case F: return 3;
				break;
			case L: return 0;
				break;
			case B: return 3;
				break;
			case R: return 2;
				break;
			default: return -1;
				break;
		}
	} else if(face == F) {
		switch (adjacentFace) {
			case U: return 2;
				break;
			case L: return 3;
				break;
			case D: return 0;
				break;
			case R: return 3;
				break;
			default: return -1;
				break;
		}
	} else if(face == B) {
		switch (adjacentFace) {
			case U: return 0;
				break;
			case L: return 1;
				break;
			case D: return 3;
				break;
			case R: return 1;
				break;
			default: return -1;
				break;
		}
	} else if(face == L) {
		switch (adjacentFace) {
			case U: return 3;
				break;
			case B: return 2;
				break;
			case D: return 3;
				break;
			case F: return 0;
				break;
			default: return -1;
				break;
		}
	} else if(face == R) {
		switch (adjacentFace) {
			case U: return 1;
				break;
			case B: return 0;
				break;
			case D: return 1;
				break;
			case F: return 2;
				break;
			default: return -1;
				break;
		}
	} else {
		return -1;
	}
}

int getAdjacentOrientationCorner(int face, int adjacentFace, int orientation) {
	if(face == F )
	switch (orientation) {
		case 0: return 1;
			break;
		case 1: return 0;
			break;
		default: return -1;
			break;
	}
}
