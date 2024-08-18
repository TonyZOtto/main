#pragma once

#include <QObject>

#include <QTransform>

#include <BrightnessContrast.h>
#include <ByteHistogram.h>
#include <ColorPhoto.h>
#include <Grey16Photo.h>
#include <IndexPhoto.h>
#include <QQColor.h>
#include <Types.h>


class SandboxApplication;
class SandboxScene;

class SandboxEngine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit SandboxEngine(SandboxApplication *parent = nullptr);


public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void start(void) {;}
    void process(const QTransform &xf);

    void setSubjectPhoto(const ColorPhoto &aCP);

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void started(void);

public: // pointers
    SandboxApplication * app();
    SandboxScene * scene();
    QObject * object();

public: // ctors

public: // const

public: // non-const

private slots:

private:
    bool processOnce(const QTransform &xf);
    BrightnessContrast processHistogram(const Grey16Photo aGrey16Photo);
    void setupColorTable();
    void setupColorTableLinear(const BYTE aFrom,
                               const BYTE aTo,
                               const BYTE aOpacity,
                               const QQColor aLoColor,
                               const QQColor aHiColor);
    void setupColorTableBilinear(const BYTE aFrom,
                                const BYTE aTo,
                                const BYTE aOpacity,
                                const QQColor aLoColor,
                                const QQColor aMidColor,
                                const QQColor aHiColor);

private:
    SandboxApplication * mpApplication=nullptr;
    ColorPhoto mSubjectPhoto;
    Grey16Photo mGrey16Photo;
    IndexPhoto mPreviousIndexPhoto;
    IndexPhoto mCurrentIndexPhoto;
    QList<QRgb> mColorTable;
    ByteHistogram mGrey8Histogram;
};

inline SandboxApplication *SandboxEngine::app() { Q_ASSERT(mpApplication); return mpApplication; }
