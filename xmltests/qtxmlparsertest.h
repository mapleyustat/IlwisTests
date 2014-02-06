#ifndef QTXMLPARSERTEST_H
#define QTXMLPARSERTEST_H

class QObject;
class QString;
class QXmlItem;
class QXmlQuery;

class QtXmlParserTest: public QObject
{
    Q_OBJECT

public:
    QtXmlParserTest();

private Q_SLOTS:
    void initTestCase();
    void shouldStartParsingAtRootNode();
    void shouldMoveToElementOnNextLevel();
    void shouldMoveToElementOnSameLevel();
    void shouldParseCorrectAttributeValue();
    void cleanupTestCase();

private:


};

#endif // QTXMLPARSERTEST_H
