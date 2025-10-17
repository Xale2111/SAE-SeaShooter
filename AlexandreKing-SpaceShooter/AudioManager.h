#pragma once
#include <string>
#include <SFML/Audio.hpp>

using namespace sf;


const std::string AudioFilesPath = "assets/audio/";
const std::string EffectsFilesPath = AudioFilesPath + "effects/";
const std::string MusicFilesPath = AudioFilesPath+"musics/";


class AudioManager
{
private:
	std::vector<Music*> allMusics;
	Music* currentBackgroundMusic_;

	std::vector<SoundBuffer> LaserSoundEffects_;
	std::vector<SoundBuffer> BonkSoundEffects_;
	std::vector<SoundBuffer> ExplosionSoundEffects_;
	std::vector<SoundBuffer> CollisionSoundEffects_;

	SoundBuffer defaultBuffer;

	std::array<std::optional<Sound>, 50> currentlyPlayingSound = {};
	int idxSoundArray = 0;

	float effectVolume = 100.f;

	bool LoadSoundEffects(std::string effect, std::vector<SoundBuffer>* soundEffectVector);
	bool LoadMusics();
	void SetDefaultBackgroundMusic();

public:
	bool LoadAll();
	void PlayLaserSoundEffect();
	void PlayBonkSoundEffect();
	void PlayExplosionSoundEffect();
	void PlayCollisionSoundEffect();


};

