#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "songcontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onTransferButtonClicked();

private:
    QVBoxLayout *createLeftLayout();
    QVBoxLayout *createRightLayout();
    QVBoxLayout *createMiddleLayout();

    QTableWidget *songTable;
    QLineEdit *titleEdit;
    QLineEdit *artistEdit;
    QLineEdit *durationEdit;
    QLineEdit *pathEdit;
    QTableWidget *playlistTable;

    SongController *songController;
};

#endif // MAINWINDOW_H
