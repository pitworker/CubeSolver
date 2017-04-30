const char RELATED_COLORS[24][6] = {
		//  U   D   F   B   R   L
	/*0*/ {'W','Y','R','O','B','G'},
	/*1*/ {'R','O','Y','W','B','G'},
	/*2*/ {'Y','W','O','R','B','G'},
	/*3*/ {'O','R','W','Y','B','G'},

	/*4*/ {'W','Y','B','G','O','R'},
	/*5*/ {'B','G','Y','W','O','R'},
	/*6*/ {'Y','W','G','B','O','R'},
	/*7*/ {'G','B','W','Y','O','R'},

	/*8*/ {'W','Y','O','R','G','B'},
	/*9*/ {'O','R','Y','W','G','B'},
	/*10*/{'Y','W','R','O','G','B'},
	/*11*/{'R','O','W','Y','G','B'},

	/*12*/{'W','Y','G','B','R','O'},
	/*13*/{'G','B','Y','W','R','O'},
	/*14*/{'Y','W','B','G','R','O'},
	/*15*/{'B','G','W','Y','R','O'},

	/*16*/{'G','B','R','O','W','Y'},
	/*17*/{'R','O','B','G','W','Y'},
	/*18*/{'B','G','O','R','W','Y'},
	/*19*/{'O','R','G','B','W','Y'},

	/*20*/{'B','G','R','O','Y','W'},
	/*21*/{'R','O','G','B','Y','W'},
	/*22*/{'G','B','O','R','Y','W'},
	/*23*/{'O','R','B','G','Y','W'}
};

int indexOfColor(char color) {
	switch(color) {
		case 'W': return 0; break;
		case 'Y': return 1; break;
		case 'R': return 2; break;
		case 'O': return 3; break;
		case 'B': return 4; break;
		case 'G': return 5; break;
		default: return -1; break;
	}
}