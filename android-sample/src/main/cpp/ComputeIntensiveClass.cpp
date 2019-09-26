/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE WITHOUT COPYING TO YOUR SRC DIRECTORY.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#include "gen/ComputeIntensiveClass.h"

namespace ComputeIntensiveClass {

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public int addInNative(int a, int b)
 * Signature: (II)I
 */
jint addInNative(JNIEnv *env, jobject thiz, jint a, jint b) {
    jint c = a + b;
    return c;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public static void computeSomething(byte[] sth)
 * Signature: ([B)V
 */
void computeSomething(JNIEnv *env, jclass clazz, jbyteArray sth) {
    return;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.String greet()
 * Signature: ()Ljava/lang/String;
 */
jstring greet(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("Hello From Jenny");
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public final void testParamParse(int a, java.lang.String b, long[] c, float[][] d, java.lang.Exception e, java.lang.Class<java.lang.String> f, java.util.HashMap<?,?> g)
 * Signature: (ILjava/lang/String;[J[[FLjava/lang/Exception;Ljava/lang/Class;Ljava/util/HashMap;)V
 */
void testParamParse(JNIEnv *env, jobject thiz, jint a, jstring b, jlongArray c, jobjectArray d, jthrowable e, jclass f, jobject g) {
    return;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public static long returnsLong()
 * Signature: ()J
 */
jlong returnsLong(JNIEnv *env, jclass clazz) {
    return 0;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public static boolean returnsBool()
 * Signature: ()Z
 */
jboolean returnsBool(JNIEnv *env, jclass clazz) {
    return JNI_FALSE;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public static java.lang.Object returnsObject()
 * Signature: ()Ljava/lang/Object;
 */
jobject returnsObject(JNIEnv *env, jclass clazz) {
    return nullptr;
}

/*
 * Class:     io_github_landerlyoung_jennysampleapp_ComputeIntensiveClass
 * Method:    public int computeThenCallback(io.github.landerlyoung.jennysampleapp.Callback listener)
 * Signature: (Lio/github/landerlyoung/jennysampleapp/Callback;)I
 */
jint computeThenCallback(JNIEnv *env, jobject thiz, jobject listener) {
    return 0;
}


} //endof namespace ComputeIntensiveClass
