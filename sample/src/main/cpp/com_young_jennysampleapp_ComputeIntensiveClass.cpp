#include "com_young_jennysampleapp_ComputeIntensiveClass.h"
#include "com_young_jennysampleapp_Callback.h"
#include "com_young_jennysampleapp_Callback_NestedClass.h"

#define __USE_ANDROID_LOG__ 1

#if __USE_ANDROID_LOG__ == 1
#include <android/log.h>
#define LOGV(...)   __android_log_print((int)ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...)   __android_log_print((int)ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...)   __android_log_print((int)ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...)   __android_log_print((int)ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...)   __android_log_print((int)ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
#define LOGV(...)
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#endif


//DO NOT CHANGE THIS PART
//java class name: com.young.jennysampleapp.ComputeIntensiveClass
static constexpr const char * const FULL_CLASS_NAME = "com/young/jennysampleapp/ComputeIntensiveClass";
#define constants(cons) com_young_jennysampleapp_ComputeIntensiveClass_ ## cons

//change to whatever you like
#define LOG_TAG "ComputeIntensiveClass"


/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public int addInNative(int a, int b)
 * Signature: (II)I
 */
jint addInNative(JNIEnv *env, jobject thiz, jint a, jint b) {
    LOGI("add %d + %d = %d", a, b, a + b);
    return a + b;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static void computeSomething(byte[] sth)
 * Signature: ([B)V
 */
void computeSomething(JNIEnv *env, jclass clazz, jbyteArray sth) {
    return;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.String greet()
 * Signature: ()Ljava/lang/String;
 */
jstring greet(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("Hello From Jni");
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public final void testParamParse(int a, java.lang.String b, long[] c, float[][] d, java.lang.Exception e, java.lang.Class<java.lang.String> f, java.util.HashMap<?,?> g)
 * Signature: (ILjava/lang/String;[J[[FLjava/lang/Exception;Ljava/lang/Class;Ljava/util/HashMap;)V
 */
void testParamParse(JNIEnv *env, jobject thiz, jint a, jstring b, jlongArray c, jobjectArray d,
                    jthrowable e, jobject f, jobject g) {
    return;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static long returnsLong()
 * Signature: ()J
 */
jlong returnsLong(JNIEnv *env, jclass clazz) {
    return 0;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static boolean returnsBool()
 * Signature: ()Z
 */
jboolean returnsBool(JNIEnv *env, jclass clazz) {
    return JNI_FALSE;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.Object returnsObject()
 * Signature: ()Ljava/lang/Object;
 */
jobject returnsObject(JNIEnv *env, jclass clazz) {
    return 0;
}

/*
 * Class:     com_young_jennysampleapp_ComputeIntensiveClass
 * Method:    public int computeThenCallback(com.young.jennysampleapp.Callback listener)
 * Signature: (Lcom/young/jennysampleapp/Callback;)I
 */
jint computeThenCallback(JNIEnv *env, jobject thiz, jobject listener) {
    LOGV("Hello world");
    com_young_jennysampleapp_Callback callback(env, listener, false);
    callback.onJobStart(env);

    jobject newInstance = com_young_jennysampleapp_Callback::newInstance(env);
    callback.setLock(env, newInstance);
    callback.onJobProgress(env, 20);

    jobject nestedClass = com_young_jennysampleapp_Callback_NestedClass::newInstance(env, listener);
    callback.setLock(env, nestedClass);
    callback.onJobProgress(env, 50);

    callback.setCount(env, 100);
    LOGV("count=%d", callback.getCount(env));
    callback.setLock(env, listener);
    callback.onJobProgress(env, 100);

    LOGV("get CMPILE_TIME_CONSTNT %d", callback.getCOMPILE_CONSTANT_INT(env));

    callback.setCOMPILE_CONSTANT_INT(env, 100);
    LOGV("get after set CMPILE_TIME_CONSTNT %d", callback.getCOMPILE_CONSTANT_INT(env));

    callback.onJobDone(env, JNI_TRUE, env->NewStringUTF("Yes, callback from jni"));
    return 0;
}

static const JNINativeMethod gsNativeMethods[] = {
        {
                /* method name      */ const_cast<char *>("addInNative"),
                /* method signature */ const_cast<char *>("(II)I"),
                /* function pointer */ reinterpret_cast<void *>(addInNative)
        },
        {
                /* method name      */ const_cast<char *>("computeSomething"),
                /* method signature */ const_cast<char *>("([B)V"),
                /* function pointer */ reinterpret_cast<void *>(computeSomething)
        },
        {
                /* method name      */ const_cast<char *>("greet"),
                /* method signature */ const_cast<char *>("()Ljava/lang/String;"),
                /* function pointer */ reinterpret_cast<void *>(greet)
        },
        {
                /* method name      */ const_cast<char *>("testParamParse"),
                /* method signature */ const_cast<char *>("(ILjava/lang/String;[J[[FLjava/lang/Exception;Ljava/lang/Class;Ljava/util/HashMap;)V"),
                /* function pointer */ reinterpret_cast<void *>(testParamParse)
        },
        {
                /* method name      */ const_cast<char *>("returnsLong"),
                /* method signature */ const_cast<char *>("()J"),
                /* function pointer */ reinterpret_cast<void *>(returnsLong)
        },
        {
                /* method name      */ const_cast<char *>("returnsBool"),
                /* method signature */ const_cast<char *>("()Z"),
                /* function pointer */ reinterpret_cast<void *>(returnsBool)
        },
        {
                /* method name      */ const_cast<char *>("returnsObject"),
                /* method signature */ const_cast<char *>("()Ljava/lang/Object;"),
                /* function pointer */ reinterpret_cast<void *>(returnsObject)
        },
        {
                /* method name      */ const_cast<char *>("computeThenCallback"),
                /* method signature */ const_cast<char *>("(Lcom/young/jennysampleapp/Callback;)I"),
                /* function pointer */ reinterpret_cast<void *>(computeThenCallback)
        }
};
static const int gsMethodCount =
        sizeof(gsNativeMethods) / sizeof(JNINativeMethod); //8

/*
 * registe Native functions
 */
void register_com_young_jennysampleapp_ComputeIntensiveClass(JNIEnv *env) {
    jclass clazz = env->FindClass(FULL_CLASS_NAME);
    env->RegisterNatives(clazz, gsNativeMethods, gsMethodCount);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env),
                   JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    register_com_young_jennysampleapp_ComputeIntensiveClass(env);
    //com_young_jennysampleapp_Callback::init_clazz(env);
    bool success = JavaCallbackReflect::init_clazz(env);
    LOGE("init reflect %d", success);
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {

}
