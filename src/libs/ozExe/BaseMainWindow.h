#pragma once

#include <QMainWindow>

class BaseMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BaseMainWindow(QWidget *parent = nullptr);

signals:
};
