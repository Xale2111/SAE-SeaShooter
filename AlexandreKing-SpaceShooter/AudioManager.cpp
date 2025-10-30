#include "AudioManager.h"

#include <iostream>


bool AudioManager::LoadSoundEffects(std::string effect, std::vector<SoundBuffer>* soundEffectVector)
{
	std::string path = EffectsFilesPath + effect;

	if (std::filesystem::is_empty(path))
	{
		return false;
	}

	// Load every effect of a type --------------------------------------------------------------------------------------------------
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		if (entry.path().extension() != ".wav")
		{
			std::cout << "Wrong file extension.\n";
			soundEffectVector->clear();
			return false;
		}
		soundEffectVector->emplace_back(entry.path());
	}
	return true;
}

bool AudioManager::LoadMusics()
{
	std::string path = MusicFilesPath;

	if (std::filesystem::is_empty(path))
	{
		return false;
	}

	// Load every effect of a type --------------------------------------------------------------------------------------------------
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		if (entry.path().extension() != ".wav")
		{
			std::cout << "Wrong file extension.\n";
			allMusics.clear();
			return false;
		}
		std::cout << entry.path() << std::endl;
		Music* music = new Music(entry.path());
		allMusics.emplace_back(music);
	}

	return true;
}

//Public function
void AudioManager::SetDefaultBackgroundMusic()
{
	if (allMusics.size() >0)
	{
		currentBackgroundMusic_ = allMusics[0];
		//TODO:put volume to 50 as default value
		currentBackgroundMusic_->setVolume(0);
		currentBackgroundMusic_->play();
	}
}

bool AudioManager::LoadAll()
{
	if(!LoadSoundEffects("laser", &LaserSoundEffects_))
		std::cout << "Effect 'Laser' couldn't be loaded" << std::endl;
	if(!LoadSoundEffects("bonk", &BonkSoundEffects_))
		std::cout << "Effect 'Bonk' couldn't be loaded" << std::endl;
	if(!LoadSoundEffects("explosion", &ExplosionSoundEffects_))
		std::cout << "Effect 'Explosion' couldn't be loaded" << std::endl;
	if (!LoadSoundEffects("collision", &CollisionSoundEffects_))
		std::cout << "Effect 'Collision' couldn't be loaded" << std::endl;
	if (!LoadMusics())
		std::cout << "Musics couldn't be loaded"<<std::endl;
	SetDefaultBackgroundMusic();
	return true;
}

void AudioManager::PlayLaserSoundEffect()
{
	int soundToUse = rand() % LaserSoundEffects_.size();
	auto& slot = currentlyPlayingSound[idxSoundArray];

	slot.emplace(LaserSoundEffects_[soundToUse]);
	slot->setVolume(effectVolume);
	slot->play();

	idxSoundArray = (idxSoundArray + 1) % currentlyPlayingSound.size();
}

void AudioManager::PlayBonkSoundEffect()
{
	int soundToUse = rand() % BonkSoundEffects_.size();
	auto& slot = currentlyPlayingSound[idxSoundArray];

	slot.emplace(BonkSoundEffects_[soundToUse]); 
	slot->setVolume(effectVolume);
	slot->play();

	idxSoundArray = (idxSoundArray + 1) % currentlyPlayingSound.size();
}

void AudioManager::PlayExplosionSoundEffect()
{
	int soundToUse = rand() % ExplosionSoundEffects_.size();
	auto& slot = currentlyPlayingSound[idxSoundArray];

	slot.emplace(ExplosionSoundEffects_[soundToUse]);
	slot->setVolume(effectVolume);
	slot->play();

	idxSoundArray = (idxSoundArray + 1) % currentlyPlayingSound.size();
}

void AudioManager::PlayCollisionSoundEffect()
{
	int soundToUse = rand() % CollisionSoundEffects_.size();
	auto& slot = currentlyPlayingSound[idxSoundArray];

	slot.emplace(CollisionSoundEffects_[soundToUse]);
	slot->setVolume(effectVolume);
	slot->play();

	idxSoundArray = (idxSoundArray + 1) % currentlyPlayingSound.size();
}





