#pragma once

#include <QObject>

class INDIframe : public QObject
{
    Q_OBJECT
public: // types
    enum Class
    {
        $nullClass = 0,
        Input,
        Capture,
        Marked,
        NoFace,
        Detect,
    };
    Q_ENUM(Class)

public: // ctors
    explicit INDIframe(QObject *parent = nullptr);

signals:
};
