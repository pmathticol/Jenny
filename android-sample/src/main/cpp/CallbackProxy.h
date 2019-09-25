/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE WITHOUT COPYING TO YOUR SRC DIRECTORY.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#pragma once

#include <jni.h>
#include <assert.h>

#ifdef __EXCEPTIONS
#include <stdexcept>
#endif

#define CHECK_NULL(val) do {if ((val) == nullptr) return false;} while(false)

class CallbackProxy {
public:
    static constexpr auto FULL_CLASS_NAME = "io/github/landerlyoung/jennysampleapp/Callback";

    static constexpr const jint COMPILE_CONSTANT_INT = 15;
    static constexpr const jint ANOTHER_COMPILE_CONSTANT_INT = 16;

private:
    static jclass sClazz;

    static jmethodID sConstruct_0;
    static jmethodID sConstruct_1;
    static jmethodID sConstruct_2;

    static jmethodID sMethod_onJobStart_0;
    static jmethodID sMethod_onJobStart_1;
    static jmethodID sMethod_onJobDone_2;
    static jmethodID sMethod_onJobProgress_3;

    static jfieldID sField_ANOTHER_COMPILE_CONSTANT_INT_0;
    static jfieldID sField_count_1;
    static jfieldID sField_staticName_2;
    static jfieldID sField_aStaticField_3;
    static jfieldID sField_name_4;
    static jfieldID sField_lock_5;
    static jfieldID sField_staticCount_6;

    const bool mGlobal;
    jobject mJavaObjectReference;

public:
    static bool init_clazz(JNIEnv *env) {
        if (sClazz == nullptr) {
            auto localClazz = env->FindClass(FULL_CLASS_NAME);
            CHECK_NULL(localClazz);
            sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(localClazz));
            CHECK_NULL(sClazz);

            sConstruct_0 = env->GetMethodID(sClazz, "<init>", "()V");
            CHECK_NULL(sConstruct_0);
            sConstruct_1 = env->GetMethodID(sClazz, "<init>", "(I)V");
            CHECK_NULL(sConstruct_1);
            sConstruct_2 = env->GetMethodID(sClazz, "<init>", "(Ljava/util/HashMap;)V");
            CHECK_NULL(sConstruct_2);

            sMethod_onJobStart_0 = env->GetMethodID(sClazz, "onJobStart", "()V");
            CHECK_NULL(sMethod_onJobStart_0);
            sMethod_onJobStart_1 = env->GetMethodID(sClazz, "onJobStart", "(Lio/github/landerlyoung/jennysampleapp/Callback$NestedClass;)V");
            CHECK_NULL(sMethod_onJobStart_1);
            sMethod_onJobDone_2 = env->GetMethodID(sClazz, "onJobDone", "(ZLjava/lang/String;)V");
            CHECK_NULL(sMethod_onJobDone_2);
            sMethod_onJobProgress_3 = env->GetMethodID(sClazz, "onJobProgress", "(J)V");
            CHECK_NULL(sMethod_onJobProgress_3);

            sField_ANOTHER_COMPILE_CONSTANT_INT_0 = env->GetFieldID(sClazz, "ANOTHER_COMPILE_CONSTANT_INT", "I");
            CHECK_NULL(sField_ANOTHER_COMPILE_CONSTANT_INT_0);
            sField_count_1 = env->GetFieldID(sClazz, "count", "I");
            CHECK_NULL(sField_count_1);
            sField_staticName_2 = env->GetStaticFieldID(sClazz, "staticName", "Ljava/lang/String;");
            CHECK_NULL(sField_staticName_2);
            sField_aStaticField_3 = env->GetStaticFieldID(sClazz, "aStaticField", "Ljava/util/List;");
            CHECK_NULL(sField_aStaticField_3);
            sField_name_4 = env->GetFieldID(sClazz, "name", "Ljava/lang/String;");
            CHECK_NULL(sField_name_4);
            sField_lock_5 = env->GetFieldID(sClazz, "lock", "Ljava/lang/Object;");
            CHECK_NULL(sField_lock_5);
            sField_staticCount_6 = env->GetStaticFieldID(sClazz, "staticCount", "I");
            CHECK_NULL(sField_staticCount_6);

            return true;
        }
        return true;
    }

    static void release_clazz(JNIEnv *env) {
        if (sClazz != nullptr) {
            env->DeleteGlobalRef(sClazz);
            sClazz = nullptr;
        }
    }

    //construct
    static jobject newInstance(JNIEnv *env) noexcept {
        if (init_clazz(env)) {
            return env->NewObject(sClazz, sConstruct_0);
        }
        return nullptr;
    }

    //construct
    static jobject newInstance(JNIEnv *env, jint a) noexcept {
        if (init_clazz(env)) {
            return env->NewObject(sClazz, sConstruct_1, a);
        }
        return nullptr;
    }

    //construct
    static jobject newInstance(JNIEnv *env, jobject sth) noexcept {
        if (init_clazz(env)) {
            return env->NewObject(sClazz, sConstruct_2, sth);
        }
        return nullptr;
    }



    ///throw std::runtime_error when construct GlobalRef failed
    CallbackProxy(JNIEnv *env, jobject javaObj, bool global = false)
#ifdef __EXCEPTIONS
    throw(std::runtime_error)
#else
    noexcept
#endif
            : mGlobal(global) {
        if (init_clazz(env)) {
            mJavaObjectReference = global ? env->NewGlobalRef(javaObj) : javaObj;
        }
#ifdef __EXCEPTIONS
        if (mGlobal && mJavaObjectReference == nullptr) {
            throw std::runtime_error("cannot create global reference");
        }
#endif
    }

    bool isGlobalReferencePresent() {
        return mJavaObjectReference != nullptr;
    }

    ///no copy construct
    CallbackProxy(const CallbackProxy &from) = delete;

    void deleteGlobalReference(JNIEnv *env) {
        if (mGlobal) {
            env->DeleteGlobalRef(mJavaObjectReference);
            mJavaObjectReference = nullptr;
        }
    }

    ~CallbackProxy() {
        assert(!mGlobal || mJavaObjectReference == nullptr);
    }

    void onJobStart(JNIEnv *env) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobStart_0);
    }

    void onJobStart(JNIEnv *env, jobject overrloadedMethod) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobStart_1, overrloadedMethod);
    }

    void onJobDone(JNIEnv *env, jboolean success, jstring result) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobDone_2, success, result);
    }

    void onJobProgress(JNIEnv *env, jlong progress) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobProgress_3, progress);
    }




    void setANOTHER_COMPILE_CONSTANT_INT(JNIEnv *env, jint ANOTHER_COMPILE_CONSTANT_INT) const {
        init_clazz(env);
        env->SetIntField(mJavaObjectReference, sField_ANOTHER_COMPILE_CONSTANT_INT_0, ANOTHER_COMPILE_CONSTANT_INT);
    }

    jint getCount(JNIEnv *env) const {
        init_clazz(env);
        return env->GetIntField(mJavaObjectReference, sField_count_1);
    }

    void setCount(JNIEnv *env, jint count) const {
        init_clazz(env);
        env->SetIntField(mJavaObjectReference, sField_count_1, count);
    }

    static jstring getStaticName(JNIEnv *env) {
        init_clazz(env);
        return reinterpret_cast<jstring>(env->GetStaticObjectField(sClazz, sField_staticName_2));
    }

    static void setStaticName(JNIEnv *env, jstring staticName) {
        init_clazz(env);
        env->SetStaticObjectField(sClazz, sField_staticName_2, staticName);
    }

    static jobject getAStaticField(JNIEnv *env) {
        init_clazz(env);
        return env->GetStaticObjectField(sClazz, sField_aStaticField_3);
    }

    static void setAStaticField(JNIEnv *env, jobject aStaticField) {
        init_clazz(env);
        env->SetStaticObjectField(sClazz, sField_aStaticField_3, aStaticField);
    }

    jstring getName(JNIEnv *env) const {
        init_clazz(env);
        return reinterpret_cast<jstring>(env->GetObjectField(mJavaObjectReference, sField_name_4));
    }



    jobject getLock(JNIEnv *env) const {
        init_clazz(env);
        return env->GetObjectField(mJavaObjectReference, sField_lock_5);
    }

    void setLock(JNIEnv *env, jobject lock) const {
        init_clazz(env);
        env->SetObjectField(mJavaObjectReference, sField_lock_5, lock);
    }

    static jint getStaticCount(JNIEnv *env) {
        init_clazz(env);
        return env->GetStaticIntField(sClazz, sField_staticCount_6);
    }

    static void setStaticCount(JNIEnv *env, jint staticCount) {
        init_clazz(env);
        env->SetStaticIntField(sClazz, sField_staticCount_6, staticCount);
    }



};

#undef CHECK_NULL