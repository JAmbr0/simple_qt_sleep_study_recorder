#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->logSleepButton, &QPushButton::clicked, this, &MainWindow::logSleepTime);
    connect(ui->logStudyButton, &QPushButton::clicked, this, &MainWindow::logStudyTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logSleepTime()
{
    // Retrieve times from QTimeEdits
    QTime startTime = ui->timeEditSleepStart->time();
    QTime endTime = ui->timeEditSleepEnd->time();

    // Get current date for log entry
    QDate currentDate = QDate::currentDate();

    // Format string containing date and sleep times
    QString logEntry = QString("%1: Sleep from %2 to %3\n")
                           .arg(currentDate.toString("yyyy-MM-dd"))
                           .arg(startTime.toString("HH:mm"))
                           .arg(endTime.toString("HH:mm"));

    // Open or create file sleep_log.txt in append mode
    QFile file("/home/josh/Projects/DataLogger/sleep_file.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        // Create text stream to write into file
        QTextStream out(&file);
        out << logEntry;
        file.close();
    } else {
        QMessageBox::warning(this, "File Error", "Could not open sleep_log.txt for writing");
    }
}

void MainWindow::logStudyTime()
{
    // Retrieve times from QTimeEdits
    QTime startTime = ui->timeEditStudyStart->time();
    QTime endTime = ui->timeEditStudyEnd->time();

    // Get current date for log entry
    QDate currentDate = QDate::currentDate();

    // Format string containing date and study times
    QString logEntry = QString("%1: Study from %2 to %3\n")
                           .arg(currentDate.toString("yyyy-MM-dd"))
                           .arg(startTime.toString("HH:mm"))
                           .arg(endTime.toString("HH:mm"));

    // Open or create file study_log.txt in append mode
    QFile file("/home/josh/Projects/DataLogger/study_file.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        // Create text stream to write into file
        QTextStream out(&file);
        out << logEntry;
        file.close();
    } else {
        QMessageBox::warning(this, "File Error", "Could not open study_log.txt for writing");
    }
}
