#include "MeteorManager.h"

#include <iostream>

#include "Random.h"

void MeteorManager::Load()
{
	plasticBag_.Load(METEOR_SPRITES_PATH + "/bag");
	plasticBottle_.Load(METEOR_SPRITES_PATH + "/bottle");
	trash_.Load(METEOR_SPRITES_PATH + "/trash");
}

void MeteorManager::SpawnMeteor(Time dt)
{
	if (spawnDelay > Random::Int(10,30))
	{
		spawnDelay = 0;
		Meteor newMeteor;
		int meteorRand = Random::Int(0, 2);
		float positionRand = Random::Float(0, 1920);
		int rotationDirectionRand = Random::Int(0, 1);
		int rotationSpeedRand = Random::Int(5, 25);
		float speedRand = Random::Float(120, 180);

		if (rotationDirectionRand == 1)
		{
			rotationSpeedRand *= -1;
		}

		switch (meteorRand)
		{
		case 0:
			newMeteor = plasticBag_;
			break;
		case 1:
			newMeteor = plasticBottle_;
			break;
		case 2:
			newMeteor = trash_;
			break;
		default:
			newMeteor = plasticBag_;
		}
		newMeteor.SetMeteorSize(Random::Float(0.6f, 0.8f));
		newMeteor.SetRotationDegrees(rotationSpeedRand);
		newMeteor.SetSpeed(speedRand);

		float xDir = ((positionRand < 960) ? 1.f : -1.f) * (Random::Float(10,80)  / 100.f);

		newMeteor.SetDirection({ xDir,1 });
		newMeteor.SetPosition({ positionRand,-100 });
		newMeteor.SetId(meteorIDCounter);

		allMeteors_.emplace_back(newMeteor);
		meteorIDCounter++;
	}
	spawnDelay += dt.asSeconds();
}

void MeteorManager::AddRemoveMeteor(Meteor& meteorToRemove)
{
	removeMeteors_.push_back(meteorToRemove);
}

void MeteorManager::RemoveMeteors()
{
	allMeteors_.erase(std::remove_if(allMeteors_.begin(), allMeteors_.end(),
		[&](Meteor& p) {
			return std::any_of(removeMeteors_.begin(), removeMeteors_.end(), [&](Meteor& r) {
				return p.GetId() == r.GetId();
				});
		}),
		allMeteors_.end());
}

std::vector<Meteor>& MeteorManager::GetAllMeteors()
{
	return allMeteors_;
}
