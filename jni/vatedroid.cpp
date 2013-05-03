/* 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vatedroid.h"

v8::Persistent<v8::Context> PrimaryContext;

/**
 *
 */
extern "C" jstring Java_com_vatedroid_VateDroidActivity_feedVatedroid(JNIEnv * env, jobject obj, jstring name, jstring message) {
    jstring retval = env->NewStringUTF("stubbywub");
    return retval;
}

/**
 *
 */
extern "C" void Java_com_vatedroid_VateDroidActivity_initVatedroid(JNIEnv * env, jobject obj) {
    // log what's happening
    __android_log_write(ANDROID_LOG_DEBUG, "VATEDROID NDK", "INITIALIZING VATEDROID");
    // can be placed at any scope resolution level, this will be redeclared in any V8 aware function 

    using namespace v8;

    // create the scope and context
    // governs local handles
    HandleScope localscope;
    // object template used to create the global object of our context
     Local< ObjectTemplate > global = ObjectTemplate::New();
    // declaration and instantiation of the primary context
    PrimaryContext = Context::New(NULL, global);
}
