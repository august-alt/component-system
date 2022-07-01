/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "snapinmanagementwidget.h"
#include "ui_snapinmanagementwidget.h"

#include "isnapin.h"
#include "snapindetailsfactorybase.h"

#include <QTreeWidgetItem>
#include <QTableWidget>

#include <memory>

Q_DECLARE_METATYPE(::gpui::ISnapIn*)

namespace gpui
{

enum TreeItemColumn
{
    FIRST   = 0,
    ENABLED = 0,
    NAME    = 1,
    VERSION = 2,
};

class SnapInManagementWidgetPrivate
{
public:
    Ui::SnapInManagementWidget* ui = nullptr;
    ISnapInManager* manager = nullptr;
    std::unique_ptr<SnapInDetailsFactoryBase> factory;

    SnapInManagementWidgetPrivate()
        : ui(new Ui::SnapInManagementWidget())
        , factory(new SnapInDetailsFactoryBase())
    {
    }

    ~SnapInManagementWidgetPrivate()
    {
        delete ui;
    }

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
};

SnapInManagementWidget::SnapInManagementWidget(QWidget *parent, ISnapInManager *manager)
    : QWidget(parent)
    , d(new SnapInManagementWidgetPrivate())
{
    d->manager = manager;
    d->ui->setupUi(this);

    for (ISnapIn* snapIn : manager->getSnapIns())
    {
        auto snapInItem = new QTreeWidgetItem();

        auto enabled = true;
        auto version = snapIn->getVersion();
        auto displayName = snapIn->getDisplayName();

        snapInItem->setText(ENABLED, enabled ? "Yes" : "No");
        snapInItem->setText(NAME, displayName);
        snapInItem->setText(VERSION, version.toString());

        snapInItem->setData(FIRST, Qt::UserRole, QVariant::fromValue(snapIn));

        d->ui->treeWidget->addTopLevelItem(snapInItem);
    }

    d->ui->treeWidget->expandAll();
}

SnapInManagementWidget::~SnapInManagementWidget()
{
    delete d;
}

void SnapInManagementWidget::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(item);
    Q_UNUSED(column);
}

}