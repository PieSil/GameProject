//
// Created by Pietro on 2019-08-27.
//

#ifndef GAMEPROJECT_AUDIOPLAYER_H
#define GAMEPROJECT_AUDIOPLAYER_H

#include "SFML/Audio.hpp"
#include <iostream>
#include <map>


enum class SoundID {
    FIREBALL, HIT, PARALYZING, MELEE, HEAL, GUARDUP
};

enum class MusicID {
    LEVEL, SELECTION, ENDING
};

class AudioPlayer {
public:
    AudioPlayer() = default;
    ~AudioPlayer() = default;

    void insertSound(const SoundID &id, const std::string &path, const float &pitch = 1., const float &volume = 100, const bool &looped = false);
    void insertMusic(const MusicID &id, const std::string &path, const bool &looped = true, const float &pitch = 1.,
                     const float &volume = 100);

    void play(const SoundID& id);
    void play(const MusicID& id);

    void pause(const SoundID& id);
    void pause(const MusicID& id);

    void stop(const SoundID& id);
    void stop(const MusicID& id);

    void stopAllMusic();

private:

    const bool notYetInserted(const SoundID &id, const std::map<SoundID, std::pair<sf::SoundBuffer, sf::Sound>> &map);
    const bool notYetInserted(const MusicID &id, const std::map<MusicID, std::unique_ptr<sf::Music>> &map);

    std::map<SoundID, std::pair<sf::SoundBuffer, sf::Sound>> sounds;
    std::map<MusicID, std::unique_ptr<sf::Music>> tracks;
};


#endif //GAMEPROJECT_AUDIOPLAYER_H
