#ifndef IFSEARCHAPPLICATION_H
#define IFSEARCHAPPLICATION_H

#include <QObject>
#include <BaseApplication>

class IfSearchInitializer;
class IfSearchProperties;

class IfSearchApplication : public BaseApplication
{
    Q_OBJECT
public:
    IfSearchApplication(int argc, char *argv[]);


public: // pointers
    IfSearchInitializer * initializer();
    IfSearchProperties * props();

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void start();
    virtual void finish();

signals:
    void initialized();
    void configured();
    void started();
    void finished();



protected:
    virtual void addOptions();
    virtual void processOptions();

private slots:


private:
    IfSearchInitializer * mpInitializer=nullptr;
    IfSearchProperties * mpProperties=nullptr;

};

inline IfSearchInitializer *IfSearchApplication::initializer()
{
    Q_CHECK_PTR(mpInitializer); return mpInitializer;
}

inline IfSearchProperties *IfSearchApplication::props()
{
    Q_CHECK_PTR(mpProperties); return mpProperties;
}

#endif // IFSEARCHAPPLICATION_H
