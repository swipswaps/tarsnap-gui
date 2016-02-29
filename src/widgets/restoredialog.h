#ifndef RESTOREDIALOG_H
#define RESTOREDIALOG_H

#include "persistentmodel/archive.h"

#include <QDialog>

namespace Ui
{
class RestoreDialog;
}

class RestoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RestoreDialog(ArchivePtr archive, QWidget *parent = 0);
    ~RestoreDialog();

    ArchiveRestoreOptions getOptions();

private slots:
    void on_cancelButton_clicked();
    void on_restoreButton_clicked();
    void on_chdirRadioButton_toggled(bool checked);
    void on_browseButton_clicked();
    void on_overwriteCheckBox_toggled(bool checked);
    void on_dirLineEdit_editingFinished();
    void on_downloadArchiveRadioButton_toggled(bool checked);
    void on_preservePathsRadioButton_toggled(bool checked);

private:
    Ui::RestoreDialog *_ui;
    ArchivePtr         _archive;
};

#endif // RESTOREDIALOG_H
