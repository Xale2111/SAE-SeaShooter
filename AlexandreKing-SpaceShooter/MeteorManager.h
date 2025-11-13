#pragma once
#include "Meteor.h"

class MeteorManager
{
private:
	uint64_t meteorIDCounter = 0;

	std::vector<Meteor> allMeteors_;
	std::vector<Meteor> removeMeteors_;

	Meteor plasticBag_;
	Meteor plasticBottle_;
	Meteor trash_;
	Meteor louis_;

	float spawnDelay = 0;

public:
	void Load();
	void SpawnMeteor(Time deltaTime);
	void AddRemoveMeteor(Meteor& meteorToRemove);
	void RemoveMeteors();
	std::vector<Meteor>& GetAllMeteors();

	void Reset();
};

