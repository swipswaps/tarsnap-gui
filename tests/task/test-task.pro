TARGET = test-task
QT = core

VALGRIND = true

HEADERS  +=						\
	../../lib/core/ConsoleLog.h			\
	../../lib/core/TSettings.h			\
	../../src/tarsnaptask.h				\
	../../src/tasks/tasks-utils.h			\
	../../src/utils.h				\
	../qtest-platform.h

SOURCES += test-task.cpp				\
	../../lib/core/ConsoleLog.cpp			\
	../../lib/core/TSettings.cpp			\
	../../src/tarsnaptask.cpp			\
	../../src/tasks/tasks-utils.cpp			\
	../../src/utils.cpp

include(../tests-include.pro)
