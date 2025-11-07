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

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
QDialog *VisualMountainFactory::createConfigDialog(QWidget *parent)
#else
QDialog *VisualMountainFactory::createSettings(QWidget *parent)
#endif
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

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(mountain, VisualMountainFactory)
#endif
