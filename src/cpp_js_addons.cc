#include <napi.h>
#include <stdlib.h>
#include <time.h>

using namespace Napi;

Napi::Int32Array CreateArray(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Int32Array result = Napi::Int32Array::New(env, 1000000);
  srand (time(NULL));
  int num;
  for (unsigned int i = 0; i < 1000000; i++) {
    num = rand() % 50000 + 1;
    result[i] = num;
  }
  return result;

}

// Napi::String Method(const Napi::CallbackInfo& info) {
//   Napi::Env env = info.Env();
//   return Napi::String::New(env, "Hello World!");
// }

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "CppJsAddons"),
              Napi::Function::New(env, CreateArray));
  return exports;
}

NODE_API_MODULE(addon, Init)
