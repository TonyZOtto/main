#pragma once

#include <QSharedDataPointer>

class BaseErrorItemData;

class BaseErrorItem
{
public:
    BaseErrorItem();
    BaseErrorItem(const BaseErrorItem &);
    BaseErrorItem &operator=(const BaseErrorItem &);
    ~BaseErrorItem();

private:
    QSharedDataPointer<BaseErrorItemData> data;
};
