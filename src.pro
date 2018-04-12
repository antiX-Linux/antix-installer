QT       += core gui widgets

TEMPLATE = app
TARGET = minstall
TRANSLATIONS += translations/minstall_ca.ts \
                translations/minstall_cs.ts \
                translations/minstall_de.ts \
                translations/minstall_el.ts \
                translations/minstall_es.ts \
                translations/minstall_fr.ts \
                translations/minstall_hu.ts \
                translations/minstall_it.ts \
                translations/minstall_ja.ts \
                translations/minstall_nl.ts \
                translations/minstall_pl.ts \
                translations/minstall_pt_BR.ts \
                translations/minstall_pt.ts \
                translations/minstall_ro.ts \
                translations/minstall_ru.ts \
		translations/minstall_sk.ts \
                translations/minstall_sv.ts \
                translations/minstall_uk.ts
FORMS += memain.ui meinstall.ui
HEADERS += mmain.h minstall.h
SOURCES += app.cpp mmain.cpp minstall.cpp
LIBS += -lcrypt
CONFIG += release warn_on thread qt
