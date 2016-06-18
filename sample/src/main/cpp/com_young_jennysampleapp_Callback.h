#pragma once

#include <jni.h>
#include <assert.h>

#ifdef __EXCEPTIONS
#include <stdexcept>
#endif

#define CHECK_NULL(val) do {if ((val) == nullptr) return false;} while(false)

class com_young_jennysampleapp_Callback {
public:
    static constexpr const char *const FULL_CLASS_NAME = "com/young/jennysampleapp/Callback";

    static constexpr const jint COMPILE_CONSTANT_INT = 15;
    static constexpr const jint ANOTHER_COMPILE_CONSTANT_INT = 16;

private:
    static jclass sClazz;

    static jmethodID sConstruct_0;
    static jmethodID sConstruct_1;
    static jmethodID sConstruct_2;

    static jmethodID sMethod_setName_0;
    static jmethodID sMethod_prepareRun_1;
    static jmethodID sMethod_onJobStart_2;
    static jmethodID sMethod_onJobDone_3;
    static jmethodID sMethod_onJobProgress_4;
    static jmethodID sMethod_aStaticMethod_5;

    static jfieldID sField_count_0;
    static jfieldID sField_staticName_1;
    static jfieldID sField_aStaticField_2;
    static jfieldID sField_name_3;
    static jfieldID sField_lock_4;
    static jfieldID sField_staticCount_5;

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

            sMethod_setName_0 = env->GetMethodID(sClazz, "setName", "(Ljava/lang/String;)V");
            CHECK_NULL(sMethod_setName_0);
            sMethod_prepareRun_1 = env->GetMethodID(sClazz, "prepareRun", "()I");
            CHECK_NULL(sMethod_prepareRun_1);
            sMethod_onJobStart_2 = env->GetMethodID(sClazz, "onJobStart", "()V");
            CHECK_NULL(sMethod_onJobStart_2);
            sMethod_onJobDone_3 = env->GetMethodID(sClazz, "onJobDone", "(ZLjava/lang/String;)V");
            CHECK_NULL(sMethod_onJobDone_3);
            sMethod_onJobProgress_4 = env->GetMethodID(sClazz, "onJobProgress", "(J)V");
            CHECK_NULL(sMethod_onJobProgress_4);
            sMethod_aStaticMethod_5 = env->GetStaticMethodID(sClazz, "aStaticMethod", "()I");
            CHECK_NULL(sMethod_aStaticMethod_5);

            sField_count_0 = env->GetFieldID(sClazz, "count", "I");
            CHECK_NULL(sField_count_0);
            sField_staticName_1 = env->GetStaticFieldID(sClazz, "staticName", "Ljava/lang/String;");
            CHECK_NULL(sField_staticName_1);
            sField_aStaticField_2 = env->GetStaticFieldID(sClazz, "aStaticField", "Ljava/util/ArrayList;");
            CHECK_NULL(sField_aStaticField_2);
            sField_name_3 = env->GetFieldID(sClazz, "name", "Ljava/lang/String;");
            CHECK_NULL(sField_name_3);
            sField_lock_4 = env->GetFieldID(sClazz, "lock", "Ljava/lang/Object;");
            CHECK_NULL(sField_lock_4);
            sField_staticCount_5 = env->GetStaticFieldID(sClazz, "staticCount", "I");
            CHECK_NULL(sField_staticCount_5);

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
    com_young_jennysampleapp_Callback(JNIEnv *env, jobject javaObj, bool global)
#ifdef __EXCEPTIONS
    throw(std::runtime_error)
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

    bool isGlobalJavaReferencePresent() {
        return mJavaObjectReference != nullptr;
    }

    ///no copy construct
    com_young_jennysampleapp_Callback(const com_young_jennysampleapp_Callback &from) = delete;

    void deleteGlobalReference(JNIEnv *env) {
        if (mGlobal) {
            env->DeleteGlobalRef(mJavaObjectReference);
            mJavaObjectReference = nullptr;
        }
    }

    ~com_young_jennysampleapp_Callback() {
        assert(!mGlobal || mJavaObjectReference == nullptr);
    }

    void setName(JNIEnv *env, jstring name) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_setName_0, name);
    }

    jint prepareRun(JNIEnv *env) const {
        return env->CallIntMethod(mJavaObjectReference, sMethod_prepareRun_1);
    }

    void onJobStart(JNIEnv *env) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobStart_2);
    }

    void onJobDone(JNIEnv *env, jboolean success, jstring result) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobDone_3, success, result);
    }

    void onJobProgress(JNIEnv *env, jlong progress) const {
        env->CallVoidMethod(mJavaObjectReference, sMethod_onJobProgress_4, progress);
    }

    static jint aStaticMethod(JNIEnv *env) {
        init_clazz(env);
        return env->CallStaticIntMethod(sClazz, sMethod_aStaticMethod_5);
    }



    jint getCount(JNIEnv *env) const {
        init_clazz(env);
        return env->GetIntField(mJavaObjectReference, sField_count_0);
    }


    void setCount(JNIEnv *env, jint count) const {
        init_clazz(env);
        env->SetIntField(mJavaObjectReference, sField_count_0, count);
    }



    static jstring getStaticName(JNIEnv *env) {
        init_clazz(env);
        return env->GetStaticObjectField(sClazz, sField_staticName_1);
    }


    static void setStaticName(JNIEnv *env, jstring staticName) {
        init_clazz(env);
        env->SetStaticObjectField(sClazz, sField_staticName_1, staticName);
    }



    static jobject getAStaticField(JNIEnv *env) {
        init_clazz(env);
        return env->GetStaticObjectField(sClazz, sField_aStaticField_2);
    }


    static void setAStaticField(JNIEnv *env, jobject aStaticField) {
        init_clazz(env);
        env->SetStaticObjectField(sClazz, sField_aStaticField_2, aStaticField);
    }



    jstring getName(JNIEnv *env) const {
        init_clazz(env);
        return env->GetObjectField(mJavaObjectReference, sField_name_3);
    }




    jobject getLock(JNIEnv *env) const {
        init_clazz(env);
        return env->GetObjectField(mJavaObjectReference, sField_lock_4);
    }


    void setLock(JNIEnv *env, jobject lock) const {
        init_clazz(env);
        env->SetObjectField(mJavaObjectReference, sField_lock_4, lock);
    }



    static jint getStaticCount(JNIEnv *env) {
        init_clazz(env);
        return env->GetStaticIntField(sClazz, sField_staticCount_5);
    }


    static void setStaticCount(JNIEnv *env, jint staticCount) {
        init_clazz(env);
        env->SetStaticIntField(sClazz, sField_staticCount_5, staticCount);
    }





};

//static fields
jclass com_young_jennysampleapp_Callback::sClazz = nullptr;
jmethodID com_young_jennysampleapp_Callback::sConstruct_0 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sConstruct_1 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sConstruct_2 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_setName_0 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_prepareRun_1 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_onJobStart_2 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_onJobDone_3 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_onJobProgress_4 = nullptr;
jmethodID com_young_jennysampleapp_Callback::sMethod_aStaticMethod_5 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_count_0 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_staticName_1 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_aStaticField_2 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_name_3 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_lock_4 = nullptr;
jfieldID com_young_jennysampleapp_Callback::sField_staticCount_5 = nullptr;


#undef CHECK_NULL