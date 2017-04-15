#pragma once
#include "Cube.cpp"

class CurrentState {
private:
	Cube currentCube;

	vector<int> algorithm;

public: 
	CurrentState(Cube cube, vector<int> rotations) {
		currentCube.replaceWithCube(cube);
		algorithm = rotations;
	}

	int getLastRotation() {
		return algorithm[algorithm.back()];
	}
	Cube getCube() {
		return currentCube;
	}

	CurrentState stateAfterRotating(int rotation) {
		Cube newCube;
		newCube.replaceWithCube(currentCube);

		return CurrentState(newCube.rotate(rotation), algorithm.push_back(rotation));
	}
};