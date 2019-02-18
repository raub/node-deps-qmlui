#include <QDebug>
#include <QEvent>

#include "event-filter.h"


bool EventFilter::eventFilter(QObject *obj, QEvent *event) {
	qDebug() << "EVENT:" << event->type() << obj << event;
	return QObject::eventFilter(obj, event);
}
