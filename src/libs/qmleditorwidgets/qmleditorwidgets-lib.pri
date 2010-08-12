QT += declarative script
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

contains(CONFIG, dll) {
    DEFINES += BUILD_QMLEDITORWIDGETS_LIB
} else {
    DEFINES += BUILD_QMLEDITORWIDGETS_STATIC_LIB
}

## Input
RESOURCES += \
    resources.qrc

HEADERS += \
    fontsizespinbox.h \
    filewidget.h \
    contextpanewidgetrectangle.h \
    contextpanewidgetimage.h \
    contextpanewidget.h \
    contextpanetextwidget.h \
    colorwidget.h \
    colorbutton.h \
    colorbox.h \
    customcolordialog.h \
    gradientline.h \
    huecontrol.h \
    qmleditorwidgets_global.h

SOURCES += \
    fontsizespinbox.cpp \
    filewidget.cpp \
    contextpanewidgetrectangle.cpp \
    contextpanewidgetimage.cpp \
    contextpanewidget.cpp \
    contextpanetextwidget.cpp \
    colorwidget.cpp \
    colorbox.cpp \
    customcolordialog.cpp \
    huecontrol.cpp \
    gradientline.cpp \
    colorbutton.cpp

FORMS += \
    contextpanewidgetrectangle.ui \
    contextpanewidgetimage.ui \
    contextpanewidgetborderimage.ui \
    contextpanetext.ui

include(easingpane/easingpane.pri)
    

OTHER_FILES += qmleditorwidgets.pri
