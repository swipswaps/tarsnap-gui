TARGET = test-app-setup
QT = core gui widgets network sql

VALGRIND = true

# Used in lib/core/optparse.h
VERSION = test
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

FORMS +=						\
	../../forms/setupdialog.ui			\

SOURCES += test-app-setup.cpp				\
	../../lib/core/ConsoleLog.cpp			\
	../../lib/core/TSettings.cpp			\
	../../lib/util/optparse.c			\
	../../lib/util/optparse_helper.c		\
	../../libcperciva/util/getopt.c			\
	../../libcperciva/util/warnp.c			\
	../../src/app-cmdline.cpp			\
	../../src/app-setup.cpp				\
	../../src/backuptask.cpp			\
	../../src/filetablemodel.cpp			\
	../../src/init-shared.cpp			\
	../../src/persistentmodel/archive.cpp		\
	../../src/persistentmodel/job.cpp		\
	../../src/persistentmodel/journal.cpp		\
	../../src/persistentmodel/persistentobject.cpp	\
	../../src/persistentmodel/persistentstore.cpp	\
	../../src/scheduling.cpp			\
	../../src/tarsnaptask.cpp			\
	../../src/taskmanager.cpp			\
	../../src/tasks/tasks-setup.cpp			\
	../../src/tasks/tasks-utils.cpp			\
	../../src/translator.cpp			\
	../../src/utils.cpp				\
	../../src/widgets/busywidget.cpp		\
	../../src/widgets/elidedlabel.cpp		\
	../../src/widgets/setupdialog.cpp

HEADERS +=						\
	../../lib/core/ConsoleLog.h			\
	../../lib/core/TSettings.h			\
	../../lib/util/optparse.h			\
	../../lib/util/optparse_helper.h		\
	../../libcperciva/util/getopt.h			\
	../../libcperciva/util/warnp.h			\
	../../src/app-cmdline.h				\
	../../src/app-setup.h				\
	../../src/backuptask.h				\
	../../src/filetablemodel.h			\
	../../src/init-shared.h				\
	../../src/persistentmodel/archive.h		\
	../../src/persistentmodel/job.h			\
	../../src/persistentmodel/journal.h		\
	../../src/persistentmodel/persistentobject.h	\
	../../src/persistentmodel/persistentstore.h	\
	../../src/scheduling.h				\
	../../src/tarsnaperror.h			\
	../../src/tarsnaptask.h				\
	../../src/taskmanager.h				\
	../../src/tasks/tasks-defs.h			\
	../../src/tasks/tasks-setup.h			\
	../../src/tasks/tasks-utils.h			\
	../../src/taskstatus.h				\
	../../src/translator.h				\
	../../src/utils.h				\
	../../src/widgets/busywidget.h			\
	../../src/widgets/elidedlabel.h			\
	../../src/widgets/setupdialog.h	

RESOURCES += ../../resources/resources.qrc

TRANSLATIONS = resources/translations/tarsnap-gui_en.ts \
               resources/translations/tarsnap-gui_ro.ts

include(../tests-include.pro)

test_home_prep.commands += ; mkdir -p "$${TEST_HOME}/$${TARGET}"
