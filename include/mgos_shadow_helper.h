#ifndef MGOS_SHADOW_HELPER_H
#define MGOS_SHADOW_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void mgos_shadow_helper_write(const char* error);

void mgos_shadow_helper_init();

void mgos_shadow_helper_sync(const char* data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif