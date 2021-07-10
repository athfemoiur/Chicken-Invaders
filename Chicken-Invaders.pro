QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Chicken.cpp \
    Egg.cpp \
    Game.cpp \
    Gift.cpp \
    Hen.cpp \
    Meat.cpp \
    Spaceship.cpp \
    Superchicken.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bullet.h \
    Chicken.h \
    Egg.h \
    Game.h \
    Gift.h \
    Hen.h \
    Meat.h \
    Spaceship.h \
    Superchicken.h \
    mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Resources.qrc
