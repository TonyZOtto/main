#pragma once

#include <QObject>

#include <QImage>

class Photo : public QObject
{
    Q_OBJECT
public: // types
    enum Type
    {
        $null           = QImage::Format_Invalid,
        Grey            = QImage::Format_Grayscale8,
        Grey16          = QImage::Format_Grayscale16,
        Color           = QImage::Format_ARGB32,
        Index           = QImage::Format_Indexed8,
        $startNonQImage = 100,
        YPlane,
        CrPlane,
        CbPlane,
        $max
    };
    Q_ENUM(Type);

public:
    explicit Photo(QObject *parent = nullptr);

signals:

public:

public: // static
    static QImage::Format qformat(const Photo::Type aType);
    static bool isPlanar(const Photo::Type aType);

};