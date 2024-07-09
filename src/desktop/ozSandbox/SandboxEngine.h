#pragma once

#include <QObject>

#include <ColorPhoto.h>

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
    void setup(void) {;}
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

private:
    SandboxApplication * mpApplication=nullptr;
    ColorPhoto mSubjectPhoto;
};

inline SandboxApplication *SandboxEngine::app() { Q_CHECK_PTR(mpApplication); return mpApplication; }
