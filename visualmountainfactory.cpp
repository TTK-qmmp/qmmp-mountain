#include "visualmountainfactory.h"
#include "mountainplugin.h"

#include <QMessageBox>

VisualProperties VisualMountainFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("Mountain Plugin");
    properties.shortName = "mountain";
    properties.hasAbout = true;
    return properties;
}

Visual *VisualMountainFactory::create(QWidget *parent)
{
    return new MountainPlugin(parent);
}

QDialog *VisualMountainFactory::createConfigDialog(QWidget *parent)
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualMountainFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About Mountain Visual Plugin"),
                       tr("Qmmp Mountain Visual Plugin") + "\n" +
                       tr("This plugin adds Mountain visualization") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualMountainFactory::translation() const
{
    return QString();
}
