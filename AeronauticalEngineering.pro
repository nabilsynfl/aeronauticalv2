QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    kecepatangravitasi.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menghitungatmosferisa.cpp \
    perhitunganangkatpesawat.cpp \
    perhitungantarikpesawat.cpp

HEADERS += \
    kecepatangravitasi.h \
    login.h \
    mainwindow.h \
    menghitungatmosferisa.h \
    perhitunganangkatpesawat.h \
    perhitungantarikpesawat.h

FORMS += \
    kecepatangravitasi.ui \
    login.ui \
    mainwindow.ui \
    menghitungatmosferisa.ui \
    perhitunganangkatpesawat.ui \
    perhitungantarikpesawat.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
