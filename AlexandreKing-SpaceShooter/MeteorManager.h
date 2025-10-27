#pragma once
#include "Meteor.h"

const std::string METEOR_SPRITES_PATH = "assets/sprites/meteor";

class MeteorManager
{
private:
	std::vector<Meteor> allMeteors_;

	Meteor plasticBag_;
	Meteor plasticBottle_;
	Meteor trash_;

	float spawnDelay = 3;

public:
	void Load();
	void SpawnMeteor(Time deltaTime);
	void AddRemoveMeteor(Meteor& meteorToRemove);
	std::vector<Meteor>& GetAllMeteors();

	//Spawn Meteor every X seconds (add rand)
	//Meteor can be between size 0.5 and 1.5
	//Can randomly spawn 1 or 2 meteor at the same time (75% chance 1, 25% chance 2)
};

