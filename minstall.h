//
//  Copyright (C) 2003-2009 by Warren Woodford
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#include <sys/stat.h>
#include <sys/swap.h>
#include <unistd.h>
#include <dirent.h>
#include <QFile>
#include <QMessageBox>
#include <QProcess>
#include <QTimer>
#include <QProgressDialog>
#include <QtConcurrent/QtConcurrent>
#include "ui_meinstall.h"

class MInstall : public QWidget, public Ui::MeInstall {
    Q_OBJECT
protected:
    QProcess *proc;
    QTimer *timer;
    QProgressBar *bar;
    QFutureWatcher<void> futureWatcher;
    QTreeWidgetItem *webminItem;
    QTreeWidgetItem *sshItem;
    QTreeWidgetItem *cupsItem;
    QTreeWidgetItem *mysqlItem;
    QTreeWidgetItem *cpufreqItem;
    QTreeWidgetItem *anacronItem;
    QTreeWidgetItem *wicdItem;
    QTreeWidgetItem *gdomapItem;
    QTreeWidgetItem *uuiddItem;
    QTreeWidgetItem *dbusItem;
    QTreeWidgetItem *cronItem;
    QTreeWidgetItem *acpisupportItem;
    QTreeWidgetItem *gpmItem;
    QTreeWidgetItem *sudoItem;
    QTreeWidgetItem *postfixItem;
    QTreeWidgetItem *sanedItem;
    QTreeWidgetItem *rsyncItem;
    QTreeWidgetItem *bindItem;
    QTreeWidgetItem *dhcpItem;
    QTreeWidgetItem *spamassassinItem;
    QTreeWidgetItem *shorewallItem;
    QTreeWidgetItem *snortItem;
    QTreeWidgetItem *squidItem;
    QTreeWidgetItem *bluetoothItem;
    QTreeWidgetItem *guarddogItem;
    QTreeWidgetItem *networkmanagerItem;
    QTreeWidgetItem *isdnItem;
    QTreeWidgetItem *nfsItem;
    QTreeWidgetItem *openvpnItem;
    QTreeWidgetItem *smartmontoolsItem;
    QTreeWidgetItem *acpidItem;
    QTreeWidgetItem *hddtempItem;
    QTreeWidgetItem *acpifakekeyItem;
    QTreeWidgetItem *havegedItem;
    QTreeWidgetItem *avahiItem;


    QDialog *mmn;


public:
    /** constructor */
    MInstall(QWidget* parent=0);
    /** destructor */
    ~MInstall();

    bool abortInstall;

    int removedItemIndex;
    QString removedItem;

    void goBack(QString msg);
    void unmountGoBack(QString msg);

    // helpers
    static QString getCmdOut(QString cmd);
    static QStringList getCmdOuts(QString cmd);
    static QString getCmdValue(QString cmd, QString key, QString keydel, QString valdel);
    static QStringList getCmdValues(QString cmd, QString key, QString keydel, QString valdel);
    static bool replaceStringInFile(QString oldtext, QString newtext, QString filepath);
    static int getPartitionNumber();
    static int command(const QString &string);
    bool is32bit();
    bool is64bit();
    bool isInsideVB();
    bool isGpt(QString drv);
    bool isUefi();
    int runCmd(QString cmd);

    void buildServiceList();
    void copyLinux();
    void installLinux();
    void prepareToInstall();
    void setLocale();
    void setServices();
    void updatePartitionWidgets();
    void updateStatus(QString msg, int val);
    bool checkDisk();
    bool installLoader();
    bool makeChosenPartitions();
    bool makeDefaultPartitions();
    bool makeFloppy();
    bool makeGrub(int rootdev, QString rootpart, const char *rootmnt, bool initrd);
    bool makeLinuxPartition(QString dev, const char *type, bool bad, QString label);
    bool makeSwapPartition(QString dev);
    bool makeEsp(QString drv, int size);
    bool mountPartition(QString dev, const char *point, const char *mopts);
    bool removeKernel();
    bool setComputerName();
    bool setPasswords();
    bool setUserInfo();
    bool setUserName();

    void gotoPage(int next);
    void pageDisplayed(int next);
    int showPage(int curr, int next);
    void stopInstall();
    void firstRefresh(QDialog *main);
    void refresh();

public slots:
    virtual void on_passwordCheckBox_stateChanged(int);
    virtual void on_nextButton_clicked();
    virtual void on_backButton_clicked();
    virtual void on_abortInstallButton_clicked();
    virtual void on_qtpartedButton_clicked();
    virtual void on_diskCombo_activated(QString item = "");
    virtual void on_rootCombo_activated(QString item = "");
    virtual void on_rootTypeCombo_activated(QString item = "");
    void procAbort();
    virtual bool close();
    //    void moreClicked(QListViewItem *item);
    void delStart();
    void delDone(int, QProcess::ExitStatus exitStatus);
    void delTime();

    void copyStart();
    void copyDone(int, QProcess::ExitStatus exitStatus);
    void copyTime();
    void procTime();

private slots:
    void on_viewServicesButton_clicked();
    void on_homeCombo_activated(const QString &arg1);
    void on_grubBootCombo_activated(QString item = "");
    void on_closeButton_clicked();
};
