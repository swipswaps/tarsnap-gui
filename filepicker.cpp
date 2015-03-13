#include "filepicker.h"
#include "debug.h"

#include <QSettings>
#include <QKeyEvent>

FilePicker::FilePicker(QWidget *parent, QString startPath) :
    QDialog(parent),
    _ui(new Ui::FilePicker),
    _startPath(startPath)
{
    _ui->setupUi(this);
    _ui->optionsContainer->hide();

    _model.setRootPath(QDir::rootPath());
    _model.setNameFilterDisables(false);
    _ui->treeView->setModel(&_model);
    if(_startPath.isEmpty())
    {
        QString path;
        QSettings settings;
        path = settings.value("app/file_browse_last", QDir::homePath()).toString();
        _ui->treeView->setCurrentIndex(_model.index(path));
    }
    else
    {
        _ui->treeView->setCurrentIndex(_model.index(_startPath));
    }
    _completer.setModel(&_model);
    _completer.setCompletionMode(QCompleter::InlineCompletion);
    _ui->filterLineEdit->setCompleter(&_completer);

    connect(_ui->filterLineEdit, SIGNAL(textEdited(QString)), this, SLOT(updateFilter(QString)));
    connect(_ui->showHiddenCheckBox, &QCheckBox::toggled,
            [=](const bool toggled)
            {
                if(toggled)
                    _model.setFilter(_model.filter() | QDir::Hidden);
                else
                    _model.setFilter(_model.filter() & ~QDir::Hidden);
            });
    connect(_ui->showSystemCheckBox, &QCheckBox::toggled,
            [=](const bool toggled)
            {
                if(toggled)
                    _model.setFilter(_model.filter() | QDir::System);
                else
                    _model.setFilter(_model.filter() & ~QDir::System);
            });
    connect(_ui->hideLinksCheckBox, &QCheckBox::toggled,
            [=](const bool toggled)
            {
                if(toggled)
                    _model.setFilter(_model.filter() | QDir::NoSymLinks);
                else
                    _model.setFilter(_model.filter() & ~QDir::NoSymLinks);
            });
    connect(_ui->showOptionsButton, &QPushButton::clicked,
            [=]()
            {
                _ui->optionsContainer->setVisible(!_ui->optionsContainer->isVisible());
            });
    connect(_ui->filterLineEdit, &QLineEdit::returnPressed,
            [=]()
            {
                if(_completer.currentCompletion().isEmpty())
                    _ui->treeView->setFocus();
            });
}

FilePicker::~FilePicker()
{
    if(_startPath.isEmpty())
    {
        QSettings settings;
        settings.setValue("app/file_browse_last", _model.filePath(_ui->treeView->currentIndex()));
    }
    delete _ui;
}

QStringList FilePicker::getSelectedUris()
{
    QStringList uris;
    QModelIndexList indexList = _ui->treeView->selectionModel()->selectedRows();
    foreach(QModelIndex index, indexList)
    {
        uris << _model.filePath(index);
    }
    return uris;
}

void FilePicker::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        if(_ui->optionsContainer->isVisible())
            _ui->optionsContainer->hide();
        else
            _ui->filterLineEdit->setFocus();
        break;
    default:
        QDialog::keyReleaseEvent(event);
    }
}

void FilePicker::updateFilter(QString filter)
{
    if(filter.isEmpty())
        _model.setNameFilters(QStringList("*"));
    else if(filter.startsWith('/'))
    {
        _ui->treeView->setCurrentIndex(_model.index(filter));
        _ui->treeView->scrollTo(_model.index(filter));
    }
    else
        _model.setNameFilters(QStringList(filter));
}