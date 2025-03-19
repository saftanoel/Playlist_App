#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Playlist Qt");
    setGeometry(100, 100, 800, 400);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    centralWidget->setLayout(mainLayout);

    mainLayout->addLayout(createLeftLayout());
    mainLayout->addLayout(createMiddleLayout());
    mainLayout->addLayout(createRightLayout());

    songController = new SongController(this);
}

QVBoxLayout* MainWindow::createLeftLayout() {
    QVBoxLayout *leftLayout = new QVBoxLayout;

    songTable = new QTableWidget(0, 3, this);
    songTable->setHorizontalHeaderLabels({"Title", "Artist", "Duration"});
    leftLayout->addWidget(new QLabel("All songs", this));
    leftLayout->addWidget(songTable);

    QGridLayout *formLayout = new QGridLayout;
    formLayout->addWidget(new QLabel("Title:", this), 0, 0);
    titleEdit = new QLineEdit(this);
    formLayout->addWidget(titleEdit, 0, 1);

    formLayout->addWidget(new QLabel("Artist:", this), 1, 0);
    artistEdit = new QLineEdit(this);
    formLayout->addWidget(artistEdit, 1, 1);

    formLayout->addWidget(new QLabel("Duration:", this), 2, 0);
    durationEdit = new QLineEdit(this);
    formLayout->addWidget(durationEdit, 2, 1);

    formLayout->addWidget(new QLabel("Path:", this), 3, 0);
    pathEdit = new QLineEdit(this);
    formLayout->addWidget(pathEdit, 3, 1);

    leftLayout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *addButton = new QPushButton("Add", this);
    QPushButton *deleteButton = new QPushButton("Delete", this);
    QPushButton *updateButton = new QPushButton("Update", this);
    QPushButton *filterButton = new QPushButton("Filter", this);

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(updateButton);
    buttonLayout->addWidget(filterButton);

    leftLayout->addLayout(buttonLayout);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);

    return leftLayout;
}

QVBoxLayout* MainWindow::createMiddleLayout() {
    QVBoxLayout *middleLayout = new QVBoxLayout;
    QPushButton *transferButton = new QPushButton(">", this);
    middleLayout->addWidget(transferButton);

    connect(transferButton, &QPushButton::clicked, this, &MainWindow::onTransferButtonClicked);

    return middleLayout;
}

QVBoxLayout* MainWindow::createRightLayout() {
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(new QLabel("Playlist", this));
    playlistTable = new QTableWidget(0, 1, this);
    rightLayout->addWidget(playlistTable);

    QHBoxLayout *rightButtonLayout = new QHBoxLayout;
    QPushButton *playButton = new QPushButton("Play", this);
    QPushButton *nextButton = new QPushButton("Next", this);
    rightButtonLayout->addWidget(playButton);
    rightButtonLayout->addWidget(nextButton);

    rightLayout->addLayout(rightButtonLayout);

    return rightLayout;
}

void MainWindow::onAddButtonClicked() {
    QString title = titleEdit->text();
    QString artist = artistEdit->text();
    QString duration = durationEdit->text();
    QString path = pathEdit->text();

    if (!title.isEmpty() && !artist.isEmpty() && !duration.isEmpty() && !path.isEmpty()) {
        Song song(title, artist, duration, path);
        songController->addSong(song);

        int row = songTable->rowCount();
        songTable->insertRow(row);
        songTable->setItem(row, 0, new QTableWidgetItem(title));
        songTable->setItem(row, 1, new QTableWidgetItem(artist));
        songTable->setItem(row, 2, new QTableWidgetItem(duration));
    }
}

void MainWindow::onDeleteButtonClicked() {
    int row = songTable->currentRow();
    if (row >= 0) {
        songController->deleteSong(row);
        songTable->removeRow(row);
    }
}

void MainWindow::onTransferButtonClicked() {
    int row = songTable->currentRow();
    if (row >= 0) {
        songController->transferSongToPlaylist(row);

        QString title = songTable->item(row, 0)->text();
        int playlistRow = playlistTable->rowCount();
        playlistTable->insertRow(playlistRow);
        playlistTable->setItem(playlistRow, 0, new QTableWidgetItem(title));
    }
}
