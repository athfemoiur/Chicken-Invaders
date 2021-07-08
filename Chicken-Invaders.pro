QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Chicken.cpp \
    Controller.cpp \
    Game.cpp \
    Hen.cpp \
    Spaceship.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bullet.h \
    Chicken.h \
    Controller.h \
    Game.h \
    Hen.h \
    Spaceship.h \
    mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Resources.qrc
