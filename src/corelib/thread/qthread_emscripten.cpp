/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qthread.h"

#include "qplatformdefs.h"

#include <private/qcoreapplication_p.h>

#if defined(Q_OS_BLACKBERRY)
#  include <private/qeventdispatcher_blackberry_p.h>
#else
#  if !defined(QT_NO_GLIB)
#    include "../kernel/qeventdispatcher_glib_p.h"
#  endif
#  include <private/qeventdispatcher_unix_p.h>
#endif

#include "qthreadstorage.h"

#include "qthread_p.h"

#include "qdebug.h"

#include <sched.h>
#include <errno.h>

#ifdef Q_OS_BSD4
#include <sys/sysctl.h>
#endif
#ifdef Q_OS_VXWORKS
#  if (_WRS_VXWORKS_MAJOR > 6) || ((_WRS_VXWORKS_MAJOR == 6) && (_WRS_VXWORKS_MINOR >= 6))
#    include <vxCpuLib.h>
#    include <cpuset.h>
#    define QT_VXWORKS_HAS_CPUSET
#  endif
#endif

#ifdef Q_OS_HPUX
#include <sys/pstat.h>
#endif

#if defined(Q_OS_MAC)
# ifdef qDebug
#   define old_qDebug qDebug
#   undef qDebug
# endif
#ifdef Q_OS_MACX
# include <CoreServices/CoreServices.h>
#endif // Q_OS_MACX

# ifdef old_qDebug
#   undef qDebug
#   define qDebug QT_NO_QDEBUG_MACRO
#   undef old_qDebug
# endif
#endif

#if defined(Q_OS_LINUX) && !defined(QT_LINUXBASE)
#include <sys/prctl.h>
#endif

QT_BEGIN_NAMESPACE

static  QThreadData *currentThreadData = 0;
static  QThread *currentThread = 0;

void QThreadData::clearCurrentThreadData()
{
}

QThreadData *QThreadData::current(bool createIfNecessary)
{
  	if (currentThreadData == NULL)
  	{
  		currentThreadData = new QThreadData;
          currentThreadData->thread = new QThread;
          if (!QCoreApplicationPrivate::theMainThread)
              QCoreApplicationPrivate::theMainThread = currentThreadData->thread;
  	}
  	return currentThreadData;
}


void QAdoptedThread::init()
{

}

/*
   QThreadPrivate
*/

extern "C" {
typedef void*(*QtThreadCallback)(void*);
}

void QThreadPrivate::createEventDispatcher(QThreadData *data)
{

}

#ifndef QT_NO_THREAD

#if (defined(Q_OS_LINUX) || defined(Q_OS_MAC) || defined(Q_OS_QNX))
static void setCurrentThreadName(pthread_t threadId, const char *name)
{

}
#endif

void *QThreadPrivate::start(void *arg)
{
  return 0;
}

void QThreadPrivate::finish(void *arg)
{

}




/**************************************************************************
 ** QThread
 *************************************************************************/

Qt::HANDLE QThread::currentThreadId() Q_DECL_NOTHROW
{
    return (Qt::HANDLE)NULL;
}

#if defined(QT_LINUXBASE) && !defined(_SC_NPROCESSORS_ONLN)
// LSB doesn't define _SC_NPROCESSORS_ONLN.
#  define _SC_NPROCESSORS_ONLN 84
#endif

int QThread::idealThreadCount() Q_DECL_NOTHROW
{
    return 1;
}

void QThread::yieldCurrentThread()
{
}

void QThread::sleep(unsigned long secs)
{

}

void QThread::msleep(unsigned long msecs)
{

}

void QThread::usleep(unsigned long usecs)
{

}


void QThread::start(Priority priority)
{

}

void QThread::terminate()
{

}

bool QThread::wait(unsigned long time)
{
    return true;
}

void QThread::setTerminationEnabled(bool enabled)
{

}

// Caller must lock the mutex
void QThreadPrivate::setPriority(QThread::Priority threadPriority)
{

}

#endif // QT_NO_THREAD

QT_END_NAMESPACE
