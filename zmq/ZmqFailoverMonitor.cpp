#include "ZmqFailoverMonitor.h"

ZmqFailoverMonitor::ZmqFailoverMonitor(
        zmq::context_t &context,
        const ConnectionInfo &primary,
        const ConnectionInfo &backup)
    : context(context),
      primary(primary),
      backup(backup) {


}
