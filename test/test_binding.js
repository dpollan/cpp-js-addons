const CppJsAddons = require("../lib/binding.js");
const assert = require("assert");

assert(CppJsAddons, "The expected function is undefined");

function testBasic()
{
    const result =  CppJsAddons("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");