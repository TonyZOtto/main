#include "Variable.h"

Variable::Variable() {;}
Variable::Variable(const Key &k) { key(k); }
Variable::Variable(const Key &k, const Value &d) { set(k, d); }
Variable::Variable(const Key &k, const Value &c, const Value &d) { set(k, c, d); }

Value Variable::value() const
{
    return current().isNull() ? defalt() : current();
}

bool Variable::isNull() const
{
    return key().isNull() || defalt().isNull();
}

void Variable::set(const Key &k, const Value &d)
{
    key(k), defalt(d);
}

void Variable::set(const Key &k, const Value &c, const Value &d)
{
    key(k), current(c), defalt(d);
}
