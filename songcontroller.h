#ifndef SONGCONTROLLER_H
#define SONGCONTROLLER_H

#include <QObject>
#include <QVector>
#include "song.h"

class SongController : public QObject {
    Q_OBJECT

public:
    SongController(QObject *parent = nullptr);

    void addSong(const Song &song);
    void deleteSong(int index);
    void transferSongToPlaylist(int index);

    QVector<Song> getAllSongs() const;
    QVector<Song> getPlaylist() const;

private:
    QVector<Song> allSongs;
    QVector<Song> playlist;
};

#endif // SONGCONTROLLER_H
