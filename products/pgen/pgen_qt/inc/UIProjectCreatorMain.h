/*
    UIProjectCreatorMain.h
    
///
/// CBTek LLC ("COMPANY") CONFIDENTIAL
/// Copyright (c) 2016 CBTek, All Rights Reserved.
///
/// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
/// herein are proprietary to COMPANY and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret or copyright law.
/// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
/// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
/// Confidentiality and Non-disclosure agreements explicitly covering such access.
///
/// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes
/// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
/// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
/// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
/// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
///

*/

#ifndef _CBTEK_PRODUCTS_DEVELOPMENT_PROJECT_CREATOR_UIPROJECTCREATORMAIN_H
#define _CBTEK_PRODUCTS_DEVELOPMENT_PROJECT_CREATOR_UIPROJECTCREATORMAIN_H
#include <QDialog>
#include <QDir>
#include <QTreeWidgetItem>


class Ui_UIProjectCreatorMain;

namespace cbtek {
namespace products {
namespace development {
namespace projectgen {



class UIProjectCreatorMain : public QDialog
{
    Q_OBJECT

public:
	//! Constructor for UIProjectCreatorMain
	/*!
		Detailed description for UIProjectCreatorMain
        @param      parent points to embedding super widget. Defaults to null.
	*/
    explicit UIProjectCreatorMain(const QString &rootProjectFolder="",
                                  QWidget *parent = 0);
    
    
	//! Descructor for UIProjectCreatorMain
    ~UIProjectCreatorMain();
private:
    /** 
    * MOC generated ui class for this widget
    */
     Ui_UIProjectCreatorMain *m_ui;

     bool m_toggleTree;
     QDir m_rootProjectDir;
     QDir m_commonProjectDir;
     QDir m_productsProjectDir;

     bool m_isFlash;
     int m_flashValue;
     int m_flashTimerId;
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
private slots:

    void onShowFlash();
     void onCreateCodeBase();
     void onCreateCPPLibrary();
     void onCreateCPPApplication();
     void onCreateQtLibrary();
     void onCreateQtApplication();
     void onCancel();
     void onBrowse();

};

}}}}//end namespace

#endif // _CBTEK_PRODUCTS_DEVELOPMENT_PROJECT_CREATOR_UIPROJECTCREATORMAIN_H
