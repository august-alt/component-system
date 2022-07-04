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

#include "compositesnapindetailsdialog.h"
#include "ui_compositesnapindetailsdialog.h"

#include "icompositesnapin.h"

namespace gpui
{

CompositeSnapInDetailsDialog::CompositeSnapInDetailsDialog(QWidget *parent, gpui::ISnapIn *snapIn)
    : ISnapInDetailsDialog(parent)
{
    ui->setupUi(this);

    ui->snapInWidget->setSnapIn(snapIn);

    auto compositeSnapIn = dynamic_cast<ICompositeSnapIn*>(snapIn);

    if (compositeSnapIn)
    {
        QMapIterator<QString, QVersionNumber> iterator(compositeSnapIn->getDependencies());
        while (iterator.hasNext())
        {
            ui->listWidget->addItem(iterator.key());
            iterator.next();
        }
    }
}

CompositeSnapInDetailsDialog::~CompositeSnapInDetailsDialog()
{
    delete ui;
}

}
