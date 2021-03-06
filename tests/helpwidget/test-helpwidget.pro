TARGET = test-helpwidget
QT = core gui widgets

VALGRIND = true

FORMS +=						\
	../../forms/aboutwidget.ui			\
	../../forms/consolewidget.ui			\
	../../forms/helpwidget.ui

RESOURCES += ../../resources/resources.qrc

HEADERS  +=						\
	../../src/widgets/helpwidget.h			\
	../../src/widgets/popuppushbutton.h		\
	../../tests/qtest-platform.h

SOURCES += test-helpwidget.cpp				\
	../../src/widgets/helpwidget.cpp		\
	../../src/widgets/popuppushbutton.cpp

include(../tests-include.pro)
