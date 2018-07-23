#include "mgos.h"
#include "mgos_shadow_helper.h"
#include "mgos_shadow.h"
#include "mgos_aws_shadow.h"
#include "mgos_event.h"

static void _shadow_cb(int ev, void *evd, void *arg)
{
  switch (ev)
  {
    case MGOS_SHADOW_CONNECTED:
      LOG(LL_INFO, ("Device shadow connected"));
      mgos_shadow_helper_write(NULL);
      break;
    case MGOS_SHADOW_GET_ACCEPTED:
    case MGOS_SHADOW_UPDATE_DELTA:
      LOG(LL_INFO, ("Device state received %s (%d)", ((struct mg_str*) evd)->p, ((struct mg_str*) evd)->len));
      mgos_shadow_helper_sync(((struct mg_str*) evd)->p);
      break;
  }
}

void mgos_shadow_helper_init()
{
  LOG(LL_INFO, ("Device state handler starting..."));

  // Ensure AWS shadows are cleared of desired state when updated.
  mgos_aws_clear_desired_state_on_update(true);

  mgos_event_add_group_handler(MGOS_SHADOW_BASE, _shadow_cb, NULL);
}
