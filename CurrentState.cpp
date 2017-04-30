#pragma once
#include "Cube.cpp"

class CurrentState {
private:
	Cube currentCube;

	vector<int> algorithm;

public: 
	CurrentState(){}
	CurrentState(Cube cube, vector<int> rotations) {
		currentCube.replaceWithCube(cube);
		algorithm = rotations;
	}

	CurrentState(Cube cube) {
		currentCube.replaceWithCube(cube);
	}

	int getLastRotation() {
		return algorithm[algorithm.back()];
	}

	int getLengthOfSolution() {
		return algorithm.size();
	}
	
	Cube getCube() {
		return currentCube;
	}

	CurrentState stateAfterRotating(int rotation) {
		Cube newCube;
		newCube.replaceWithCube(currentCube);

		newCube.rotate(rotation);

		vector<int> newAlgorithm = algorithm;
		newAlgorithm.push_back(rotation);

		return CurrentState(newCube, newAlgorithm);
	}

	vector<int> getSolution() {
		return algorithm;
	}
	
	void replaceWith(CurrentState other) {
		currentCube.replaceWithCube(other.getCube());
		algorithm = other.getSolution();
	}
};
