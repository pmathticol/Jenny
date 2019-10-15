/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#include "NativeDrawableProxy.h"


// external logger function passed by jenny.errorLoggerFunction
void jennySampleErrorLog(JNIEnv* env, const char* error);




jclass NativeDrawableProxy::sClazz = nullptr;

// thread safe init
std::mutex NativeDrawableProxy::sInitLock;
std::atomic_bool NativeDrawableProxy::sInited;

/*static*/ bool NativeDrawableProxy::initClazz(JNIEnv *env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init NativeDrawableProxy::" #val); \
               return false;                       \
           }                                       \
       } while(false)

    if (!sInited) {
        std::lock_guard<std::mutex> lg(sInitLock);
        if (!sInited) {
            auto clazz = env->FindClass(FULL_CLASS_NAME);
            JENNY_CHECK_NULL(clazz);
            sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(clazz));
            env->DeleteLocalRef(clazz);
            JENNY_CHECK_NULL(sClazz);



            sField_nativeHandle_0 = env->GetFieldID(sClazz, "nativeHandle", "J");
            JENNY_CHECK_NULL(sField_nativeHandle_0);


            sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ void NativeDrawableProxy::releaseClazz(JNIEnv *env) {
    if (sInited) {
        std::lock_guard<std::mutex> lg(sInitLock);
        if (sInited) {
            env->DeleteLocalRef(sClazz);
            sClazz = nullptr;
            sInited = false;
        }
    }
}



jfieldID NativeDrawableProxy::sField_nativeHandle_0;


