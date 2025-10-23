#include "MeteorManager.h"

#include "Random.h"

void MeteorManager::Load()
{
	plasticBag_.Load(METEOR_SPRITES_PATH + "/bag");
	plasticBottle_.Load(METEOR_SPRITES_PATH + "/bottle");
	trash_.Load(METEOR_SPRITES_PATH + "/trash");
}

void MeteorManager::SpawnMeteor(Time dt)
{
	//if (spawnDelay > 3)
	{
		spawnDelay = 0;
		Meteor newMeteor;
		int meteorRand = Random::Int(0, 2);
		float positionRand = Random::Float(0, 1920);
		int rotationDirectionRand = Random::Int(0, 1);
		int rotationSpeedRand = Random::Int(5, 25);
		float speedRand = Random::Float(75, 120);

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

		float xDir = ((positionRand < 960) ? 1.f : -1.f) * (Random::Float(10,40)  / 100.f);

		newMeteor.SetDirection({ xDir,1 });
		newMeteor.SetPosition({ positionRand,300 });

		allMeteors_.emplace_back(newMeteor);
	}
	spawnDelay += dt.asSeconds();
}

void MeteorManager::AddRemoveMeteor(Meteor& meteorToRemove)
{
}

std::vector<Meteor> MeteorManager::GetAllMeteors()
{
	return allMeteors_;
}
