#include "songcontroller.h"

SongController::SongController(QObject *parent) : QObject(parent) {}

void SongController::addSong(const Song &song) {
    allSongs.append(song);
}

void SongController::deleteSong(int index) {
    if (index >= 0 && index < allSongs.size()) {
        allSongs.remove(index);
    }
}

void SongController::transferSongToPlaylist(int index) {
    if (index >= 0 && index < allSongs.size()) {
        playlist.append(allSongs[index]);
    }
}

QVector<Song> SongController::getAllSongs() const {
    return allSongs;
}

QVector<Song> SongController::getPlaylist() const {
    return playlist;
}
