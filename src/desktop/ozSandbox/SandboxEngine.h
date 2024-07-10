#pragma once

#include <QObject>

#include <ColorPhoto.h>
#include <GreyPhoto.h>
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
    void objconnect(void) {;}
    void start(void) {;}

    void setSubjectPhoto(const ColorPhoto &aCP);

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void objconnected(void);
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
    GreyPhoto mGreyPhoto;
    IndexPhoto mIndexPhoto;
    QList<QRgb> mColorTable;
};

inline SandboxApplication *SandboxEngine::app() { Q_CHECK_PTR(mpApplication); return mpApplication; }
