//
// Created by Pietro on 2019-08-27.
//

#include "AudioPlayer.h"

void AudioPlayer::insertSound(const SoundID &id, const std::string &path, const float &pitch, const float &volume,
                              const bool &looped) {

    if (notYetInserted(id, sounds)) {

        sounds.emplace(id, std::pair<sf::SoundBuffer, sf::Sound>()); //create element in map

        auto &soundBuffer = sounds.find(id)->second.first; //get a reference to the sound buffer
        auto &sound = sounds.find(id)->second.second; //get a reference to the sound

        if (soundBuffer.loadFromFile(path)) { //load sound from file
            sound.setBuffer(soundBuffer);

            //set pitch, volume, and if sound should be looped or not
            sound.setPitch(pitch);
            sound.setVolume(volume);
            sound.setLoop(looped);
        } else {
            std::cout << "Could not load file from this path: " << path << std::endl;
        }
    } else {
        std::cout << "A sound with same id has already been inserted" << std::endl;
    }
}

void AudioPlayer::insertMusic(const MusicID &id, const std::string &path, const bool &looped, const float &pitch,
                              const float &volume) {
    if (notYetInserted(id, tracks)) {

        tracks.emplace(id, std::unique_ptr<sf::Music>(new sf::Music())); //create element in map

        auto &music = tracks.find(id)->second; //get a reference to the music

        if (music->openFromFile(path)) {

            //set pitch, volume, and if music should be looped or not
            music->setPitch(pitch);
            music->setVolume(volume);
            music->setLoop(looped);
        }

    } else {
        std::cout << "A music with same id has already been inserted" << std::endl;
    }
}

void AudioPlayer::play(const SoundID& id) {
    sounds.find(id)->second.second.play();
}

void AudioPlayer::play(const MusicID &id) {
    tracks.find(id)->second->play();
}

void AudioPlayer::pause(const SoundID &id) {
    sounds.find(id)->second.second.pause();
}

void AudioPlayer::pause(const MusicID& id) {
    tracks.find(id)->second->pause();
}

void AudioPlayer::stop(const SoundID &id) {
    sounds.find(id)->second.second.stop();
}

void AudioPlayer::stop(const MusicID &id) {
    tracks.find(id)->second->stop();
}

const bool
AudioPlayer::notYetInserted(const SoundID &id, const std::map<SoundID, std::pair<sf::SoundBuffer, sf::Sound>> &map) {

    bool notInserted = true;

    for (const auto& pair : map) {
        if (pair.first == id)
            notInserted = false;
    }

    return notInserted;
}

const bool AudioPlayer::notYetInserted(const MusicID &id, const std::map<MusicID, std::unique_ptr<sf::Music>> &map) {
    bool notInserted = true;

    for (const auto& pair : map) {
        if (pair.first == id)
            notInserted = false;
    }

    return notInserted;
}
