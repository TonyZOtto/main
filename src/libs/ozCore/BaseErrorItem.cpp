#include "BaseErrorItem.h"

class BaseErrorItemData : public QSharedData
{
public:
};

BaseErrorItem::BaseErrorItem()
    : data(new BaseErrorItemData)
{}

BaseErrorItem::BaseErrorItem(const BaseErrorItem &rhs)
    : data{rhs.data}
{}

BaseErrorItem &BaseErrorItem::operator=(const BaseErrorItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

BaseErrorItem::~BaseErrorItem() {}
