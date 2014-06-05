#ifndef CATALOGTEST_H
#define CATALOGTEST_H

#include <QString>
#include <QTest>
#include <QDir>
#include "kernel.h"
#include "testmacros.h"
#include "ilwistestclass.h"

class CatalogTest : public IlwisTestCase
{
    Q_OBJECT
public:
    CatalogTest();

    NEW_TEST(CatalogTest)    ;

private slots:
    void readCatalog();
};

#endif // CATALOGTEST_H
