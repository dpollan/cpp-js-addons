const addon = require('../build/Release/cpp-js-addons-native');
console.log('Hello world from console.');
console.log(addon);
r = addon.CppJsAddons;
console.log(r());
