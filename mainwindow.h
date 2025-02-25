// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#pragma once

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>
#include <QMessageBox>
#include <QTimer>

#include <chrono>

#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

QT_BEGIN_NAMESPACE

class QLabel;
class QTimer;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

static constexpr std::chrono::seconds kWriteTimeout = std::chrono::seconds{5};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);
    void handleBytesWritten(qint64 bytes);
    void handleWriteTimeout();

private:
    Ui::MainWindow *ui = nullptr;
    QLabel *status = nullptr;
    Console *console = nullptr;
    SettingsDialog *settings = nullptr;
    qint64 bytesToWrite = 0;
    QTimer *timer = nullptr;
    QSerialPort *serial = nullptr;

    void initActionsConnections();
    void showStatusMessage(const QString &message);
    void showWriteError(const QString &message);
};