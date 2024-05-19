#include <node_api.h>

napi_value Add(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 2;
  napi_value args[2];
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  if (status != napi_ok) return NULL;

  double a, b;
  status = napi_get_value_double(env, args[0], &a);
  if (status != napi_ok) return NULL;
  status = napi_get_value_double(env, args[1], &b);
  if (status != napi_ok) return NULL;

  napi_value result;
  status = napi_create_double(env, a + b, &result);
  if (status != napi_ok) return NULL;

  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 0, Add, NULL, &fn);
  if (status != napi_ok) return NULL;

  status = napi_set_named_property(env, exports, "add", fn);
  if (status != napi_ok) return NULL;

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)