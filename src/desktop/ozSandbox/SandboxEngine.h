#pragma once

#include <QObject>

#include <QTransform>

#include <BrightnessContrast.h>
#include <ByteHistogram.h>
#include <ColorImage.h>
#include <Grey16Image.h>
#include <IndexedImage.h>
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

    void setSubjectImage(const ColorImage &aCP);

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
    BrightnessContrast processHistogram(const Grey16Image aGrey16Image);
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
    ColorImage mSubjectImage;
    Grey16Image mGrey16Image;
    IndexedImage mPreviousIndexedImage;
    IndexedImage mCurrentIndexedImage;
    QList<QRgb> mColorTable;
    ByteHistogram mGrey8Histogram;
};

inline SandboxApplication *SandboxEngine::app() { Q_ASSERT(mpApplication); return mpApplication; }
