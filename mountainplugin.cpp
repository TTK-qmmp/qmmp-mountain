#include "mountainplugin.h"
#include "mountainwidget.h"
#include "inlines.h"

#include <QMenu>
#include <QTimer>
#include <QBoxLayout>

MountainPlugin::MountainPlugin(QWidget *parent)
    : Visual(parent)
{
    setWindowTitle(tr("Mountain Widget"));

    m_mountainWidget = new MountainWidget(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_mountainWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    m_timer = new QTimer(this);
    m_timer->setInterval(40);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateVisual()));

    m_screenAction = new QAction(tr("Fullscreen"), this);
    m_screenAction->setCheckable(true);
    connect(m_screenAction, SIGNAL(triggered(bool)), this, SLOT(setFullScreen(bool)));
}

MountainPlugin::~MountainPlugin()
{

}

void MountainPlugin::start()
{
    if(isVisible())
        m_timer->start();
}

void MountainPlugin::stop()
{
    m_timer->stop();
}

void MountainPlugin::updateVisual()
{
    if(takeData(m_left, m_right))
    {
        process(m_left, m_right);
        update();
    }
}

void MountainPlugin::setFullScreen(bool yes)
{
    if(yes)
        setWindowState(windowState() | Qt::WindowFullScreen);
    else
        setWindowState(windowState() & ~Qt::WindowFullScreen);
}

void MountainPlugin::hideEvent(QHideEvent *)
{
    m_timer->stop();
}

void MountainPlugin::showEvent(QShowEvent *)
{
    m_timer->start();
}

void MountainPlugin::contextMenuEvent(QContextMenuEvent *)
{
    QMenu menu(this);
    menu.addAction(m_screenAction);
    menu.exec(QCursor::pos());
}

void MountainPlugin::process(float *left, float *)
{
    constexpr int size = QMMP_VISUAL_NODE_SIZE / 2;
    short dest_l[size];

    calc_freq(dest_l, left);

    float buffer[size];
    for(int i = 0; i < size; ++i)
    {
        buffer[i] = dest_l[i] / ((QMMP_VISUAL_NODE_SIZE << 8) / (8.0 / 2));
    }

    m_mountainWidget->addBuffer(buffer);
}
