// example.dart

import 'dart:ffi' as ffi;
import 'dart:io' show Platform;

typedef hello_func = ffi.Void Function();
typedef Hello = void Function();

void main() {
  var path = '/Users/keifergu/Work/ffi_demo/src/lib/hello.so';

  final dylib = ffi.DynamicLibrary.open(path);

  final hello = dylib.lookupFunction<hello_func, Hello>('hello');
  hello();
}
