// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "console.h"

Console::Console(QWidget *parent) :
    QPlainTextEdit(parent)
{
    document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
}

void Console::putData(const QByteArray &data)
{
    insertPlainText(data);

    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::keyPressEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
}

void Console::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
}

void Console::contextMenuEvent(QContextMenuEvent *e)
{
    Q_UNUSED(e);
}