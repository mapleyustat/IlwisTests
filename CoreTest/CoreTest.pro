#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T11:26:24
#
#-------------------------------------------------

QT       -= gui
QT       +=core testlib

include(../global.pri)

TARGET = CoreTest
TEMPLATE = lib

DESTDIR = $$PWD/../../libraries/$$PLATFORM$$CONF/$$TARGET
DLLDESTDIR = $$PWD/../../output/$$PLATFORM$$CONF/bin/testcases

DEFINES += CORETEST_LIBRARY

SOURCES += coretest.cpp \
    util/coordinatetest.cpp \
    util/sizetest.cpp \
    util/numericrangetest.cpp \
    util/locationtest.cpp \
    util/juliantimetests.cpp \
    catalog/tst_resourcetest.cpp \
    ilwisobjects/domain/domaintimetests.cpp

HEADERS += coretest.h\
        coretest_global.h \
    util/coordinatetest.h \
    util/sizetest.h \
    util/numericrangetest.h \
    util/locationtest.h \
    util/juliantimetests.h \
    catalog/tst_resourcetest.h \
    ilwisobjects/domain/domaintimetests.h

OTHER_FILES +=

unix|win32: LIBS += -L$$PWD/../../libraries/$$PLATFORM$$CONF/TestSuite/ -lTestSuite

INCLUDEPATH += $$PWD/../TestSuite
DEPENDPATH += $$PWD/../TestSuite
