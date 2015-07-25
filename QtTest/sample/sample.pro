QT       += core
QT       -= gui
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
    TestMainModule.c \
    MainModule.c \
    CUnitRunTest.c

win32: {
#    LIBS += -lws2_32 -ladvapi32 -lmingw32
    LIBS += -lmsvcrt -ladvapi32 -lws2_32
}


INCLUDEPATH += CUnit-2.1-0/include/CUnit/
LIBS += D:\git\cunit\QtTest\sample\CUnit.lib
#LIBS += -LCUnit-2.1-0/lib/ -lcunit_dll -lcunit
# 使用绝对路径,during startup program exited with code 0xc0000135
#LIBS += -LD:\git\cunit\CJ_TEST_C\CUnit-2.1-0\lib -lcunit_dll -lcunit

HEADERS += \
    MainModule.h


OTHER_FILES += \
    CUnit-2.1-0/lib/libcunit_dll.a \
    CUnit-2.1-0/lib/libcunit.a

