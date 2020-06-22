/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues.
 */
#pragma once

#include <jni.h>
#include <assert.h>                        
#include <atomic>
#include <mutex>

namespace java {
class URLProxy {

public:
    static constexpr auto FULL_CLASS_NAME = "java/net/URL";



private:

    JNIEnv* mJniEnv;
    jobject mJavaObjectReference;

public:

    static bool initClazz(JNIEnv* env);
    
    static void releaseClazz(JNIEnv* env);

    static void assertInited(JNIEnv* env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }

    URLProxy(): URLProxy(nullptr, nullptr) {}
    
    URLProxy(JNIEnv* env, jobject javaObj)
            : mJniEnv(env), mJavaObjectReference(javaObj) {
        if (env) { assertInited(env); }
    }

    URLProxy(const URLProxy& from) = default;
    URLProxy &operator=(const URLProxy &) = default;

    URLProxy(URLProxy&& from) noexcept
           : mJniEnv(from.mJniEnv), mJavaObjectReference(from.mJavaObjectReference) {
        from.mJavaObjectReference = nullptr;
    }
    
    URLProxy& operator=(URLProxy&& from) noexcept {
       mJniEnv = from.mJniEnv;
       std::swap(mJavaObjectReference, from.mJavaObjectReference);
       return *this;
   }

    ~URLProxy() = default;
    
    // helper method to get underlay jobject reference
    jobject operator*() const {
       return mJavaObjectReference;
    }
    
    // helper method to check underlay jobject reference is not nullptr
    operator bool() const {
       return mJavaObjectReference;
    }
    
    // helper method to delete JNI local ref.
    // use only when you really understand JNIEnv::DeleteLocalRef.
    void deleteLocalRef() {
       if (mJavaObjectReference) {
           mJniEnv->DeleteLocalRef(mJavaObjectReference);
           mJavaObjectReference = nullptr;
       }
    }
    
    // === java methods below ===
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, int port, java.lang.String file)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jint port, jstring file) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_0, protocol, host, port, file));
    } 
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, java.lang.String file)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jstring file) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_1, protocol, host, file));
    } 
    
    // construct: public URL(java.lang.String protocol, java.lang.String host, int port, java.lang.String file, java.net.URLStreamHandler handler)
    static URLProxy newInstance(JNIEnv* env, jstring protocol, jstring host, jint port, jstring file, jobject handler) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_2, protocol, host, port, file, handler));
    } 
    
    // construct: public URL(java.lang.String spec)
    static URLProxy newInstance(JNIEnv* env, jstring spec) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_3, spec));
    } 
    
    // construct: public URL(java.net.URL context, java.lang.String spec)
    static URLProxy newInstance(JNIEnv* env, jobject context, jstring spec) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_4, context, spec));
    } 
    
    // construct: public URL(java.net.URL context, java.lang.String spec, java.net.URLStreamHandler handler)
    static URLProxy newInstance(JNIEnv* env, jobject context, jstring spec, jobject handler) noexcept {
       assertInited(env);
       return URLProxy(env, env->NewObject(getClassInitState().sClazz, getClassInitState().sConstruct_5, context, spec, handler));
    } 
    

    // method: public java.lang.String getQuery()
    jstring getQuery() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getQuery_0));
    }

    // method: public java.lang.String getPath()
    jstring getPath() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getPath_0));
    }

    // method: public java.lang.String getUserInfo()
    jstring getUserInfo() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getUserInfo_0));
    }

    // method: public java.lang.String getAuthority()
    jstring getAuthority() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getAuthority_0));
    }

    // method: public int getPort()
    jint getPort() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, getClassInitState().sMethod_getPort_0);
    }

    // method: public int getDefaultPort()
    jint getDefaultPort() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, getClassInitState().sMethod_getDefaultPort_0);
    }

    // method: public java.lang.String getProtocol()
    jstring getProtocol() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getProtocol_0));
    }

    // method: public java.lang.String getHost()
    jstring getHost() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getHost_0));
    }

    // method: public java.lang.String getFile()
    jstring getFile() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getFile_0));
    }

    // method: public java.lang.String getRef()
    jstring getRef() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getRef_0));
    }

    // method: public boolean equals(java.lang.Object obj)
    jboolean equals(jobject obj) const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, getClassInitState().sMethod_equals_0, obj);
    }

    // method: public synchronized int hashCode()
    jint hashCode() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, getClassInitState().sMethod_hashCode_0);
    }

    // method: public boolean sameFile(java.net.URL other)
    jboolean sameFile(jobject other) const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, getClassInitState().sMethod_sameFile_0, other);
    }

    // method: public java.lang.String toString()
    jstring toString() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_toString_0));
    }

    // method: public java.lang.String toExternalForm()
    jstring toExternalForm() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_toExternalForm_0));
    }

    // method: public java.net.URI toURI()
    jobject toURI() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_toURI_0);
    }

    // method: public java.net.URLConnection openConnection()
    jobject openConnection() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_openConnection_0);
    }

    // method: public java.net.URLConnection openConnection(java.net.Proxy proxy)
    jobject openConnection(jobject proxy) const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_openConnection_1, proxy);
    }

    // method: public java.io.InputStream openStream()
    jobject openStream() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_openStream_0);
    }

    // method: public java.lang.Object getContent()
    jobject getContent() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getContent_0);
    }

    // method: public java.lang.Object getContent(java.lang.Class[] classes)
    jobject getContent(jobjectArray classes) const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, getClassInitState().sMethod_getContent_1, classes);
    }

    // method: public static void setURLStreamHandlerFactory(java.net.URLStreamHandlerFactory fac)
    static void setURLStreamHandlerFactory(JNIEnv* env, jobject fac) {
        assertInited(env);
        env->CallStaticVoidMethod(getClassInitState().sClazz, getClassInitState().sMethod_setURLStreamHandlerFactory_0, fac);
    }



private:
    struct ClassInitState {
    // thread safe init
    std::atomic_bool sInited {};
    std::mutex sInitLock {};

    jclass sClazz = nullptr;
    jmethodID sConstruct_0 = nullptr;
    jmethodID sConstruct_1 = nullptr;
    jmethodID sConstruct_2 = nullptr;
    jmethodID sConstruct_3 = nullptr;
    jmethodID sConstruct_4 = nullptr;
    jmethodID sConstruct_5 = nullptr;

    jmethodID sMethod_getQuery_0 = nullptr;
    jmethodID sMethod_getPath_0 = nullptr;
    jmethodID sMethod_getUserInfo_0 = nullptr;
    jmethodID sMethod_getAuthority_0 = nullptr;
    jmethodID sMethod_getPort_0 = nullptr;
    jmethodID sMethod_getDefaultPort_0 = nullptr;
    jmethodID sMethod_getProtocol_0 = nullptr;
    jmethodID sMethod_getHost_0 = nullptr;
    jmethodID sMethod_getFile_0 = nullptr;
    jmethodID sMethod_getRef_0 = nullptr;
    jmethodID sMethod_equals_0 = nullptr;
    jmethodID sMethod_hashCode_0 = nullptr;
    jmethodID sMethod_sameFile_0 = nullptr;
    jmethodID sMethod_toString_0 = nullptr;
    jmethodID sMethod_toExternalForm_0 = nullptr;
    jmethodID sMethod_toURI_0 = nullptr;
    jmethodID sMethod_openConnection_0 = nullptr;
    jmethodID sMethod_openConnection_1 = nullptr;
    jmethodID sMethod_openStream_0 = nullptr;
    jmethodID sMethod_getContent_0 = nullptr;
    jmethodID sMethod_getContent_1 = nullptr;
    jmethodID sMethod_setURLStreamHandlerFactory_0 = nullptr;


   }; // endof struct ClassInitState

   template <typename T = void>
   static ClassInitState& getClassInitState() {
       static ClassInitState classInitState;
       return classInitState;
   }

};
} // endof namespace java




// external logger function passed by jenny.errorLoggerFunction
void jennySampleErrorLog(JNIEnv* env, const char* error);

namespace java {

/*static*/ inline bool URLProxy::initClazz(JNIEnv* env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init URLProxy::" #val); \
               return false;                       \
           }                                       \
       } while(false)

    auto& state = getClassInitState();
    if (!state.sInited) {
        std::lock_guard<std::mutex> lg(state.sInitLock);
        if (!state.sInited) {
            auto clazz = env->FindClass(FULL_CLASS_NAME);
            JENNY_CHECK_NULL(clazz);
            state.sClazz = reinterpret_cast<jclass>(env->NewGlobalRef(clazz));
            env->DeleteLocalRef(clazz);
            JENNY_CHECK_NULL(state.sClazz);

            state.sConstruct_0 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V");
            JENNY_CHECK_NULL(state.sConstruct_0);

            state.sConstruct_1 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
            JENNY_CHECK_NULL(state.sConstruct_1);

            state.sConstruct_2 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/net/URLStreamHandler;)V");
            JENNY_CHECK_NULL(state.sConstruct_2);

            state.sConstruct_3 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/lang/String;)V");
            JENNY_CHECK_NULL(state.sConstruct_3);

            state.sConstruct_4 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/net/URL;Ljava/lang/String;)V");
            JENNY_CHECK_NULL(state.sConstruct_4);

            state.sConstruct_5 = env->GetMethodID(state.sClazz, "<init>", "(Ljava/net/URL;Ljava/lang/String;Ljava/net/URLStreamHandler;)V");
            JENNY_CHECK_NULL(state.sConstruct_5);


            state.sMethod_getQuery_0 = env->GetMethodID(state.sClazz, "getQuery", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getQuery_0);

            state.sMethod_getPath_0 = env->GetMethodID(state.sClazz, "getPath", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getPath_0);

            state.sMethod_getUserInfo_0 = env->GetMethodID(state.sClazz, "getUserInfo", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getUserInfo_0);

            state.sMethod_getAuthority_0 = env->GetMethodID(state.sClazz, "getAuthority", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getAuthority_0);

            state.sMethod_getPort_0 = env->GetMethodID(state.sClazz, "getPort", "()I");
            JENNY_CHECK_NULL(state.sMethod_getPort_0);

            state.sMethod_getDefaultPort_0 = env->GetMethodID(state.sClazz, "getDefaultPort", "()I");
            JENNY_CHECK_NULL(state.sMethod_getDefaultPort_0);

            state.sMethod_getProtocol_0 = env->GetMethodID(state.sClazz, "getProtocol", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getProtocol_0);

            state.sMethod_getHost_0 = env->GetMethodID(state.sClazz, "getHost", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getHost_0);

            state.sMethod_getFile_0 = env->GetMethodID(state.sClazz, "getFile", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getFile_0);

            state.sMethod_getRef_0 = env->GetMethodID(state.sClazz, "getRef", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_getRef_0);

            state.sMethod_equals_0 = env->GetMethodID(state.sClazz, "equals", "(Ljava/lang/Object;)Z");
            JENNY_CHECK_NULL(state.sMethod_equals_0);

            state.sMethod_hashCode_0 = env->GetMethodID(state.sClazz, "hashCode", "()I");
            JENNY_CHECK_NULL(state.sMethod_hashCode_0);

            state.sMethod_sameFile_0 = env->GetMethodID(state.sClazz, "sameFile", "(Ljava/net/URL;)Z");
            JENNY_CHECK_NULL(state.sMethod_sameFile_0);

            state.sMethod_toString_0 = env->GetMethodID(state.sClazz, "toString", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_toString_0);

            state.sMethod_toExternalForm_0 = env->GetMethodID(state.sClazz, "toExternalForm", "()Ljava/lang/String;");
            JENNY_CHECK_NULL(state.sMethod_toExternalForm_0);

            state.sMethod_toURI_0 = env->GetMethodID(state.sClazz, "toURI", "()Ljava/net/URI;");
            JENNY_CHECK_NULL(state.sMethod_toURI_0);

            state.sMethod_openConnection_0 = env->GetMethodID(state.sClazz, "openConnection", "()Ljava/net/URLConnection;");
            JENNY_CHECK_NULL(state.sMethod_openConnection_0);

            state.sMethod_openConnection_1 = env->GetMethodID(state.sClazz, "openConnection", "(Ljava/net/Proxy;)Ljava/net/URLConnection;");
            JENNY_CHECK_NULL(state.sMethod_openConnection_1);

            state.sMethod_openStream_0 = env->GetMethodID(state.sClazz, "openStream", "()Ljava/io/InputStream;");
            JENNY_CHECK_NULL(state.sMethod_openStream_0);

            state.sMethod_getContent_0 = env->GetMethodID(state.sClazz, "getContent", "()Ljava/lang/Object;");
            JENNY_CHECK_NULL(state.sMethod_getContent_0);

            state.sMethod_getContent_1 = env->GetMethodID(state.sClazz, "getContent", "([Ljava/lang/Class;)Ljava/lang/Object;");
            JENNY_CHECK_NULL(state.sMethod_getContent_1);

            state.sMethod_setURLStreamHandlerFactory_0 = env->GetStaticMethodID(state.sClazz, "setURLStreamHandlerFactory", "(Ljava/net/URLStreamHandlerFactory;)V");
            JENNY_CHECK_NULL(state.sMethod_setURLStreamHandlerFactory_0);



            state.sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ inline void URLProxy::releaseClazz(JNIEnv* env) {
    auto& state = getClassInitState();
    if (state.sInited) {
        std::lock_guard<std::mutex> lg(state.sInitLock);
        if (state.sInited) {
            env->DeleteGlobalRef(state.sClazz);
            state.sClazz = nullptr;
            state.sInited = false;
        }
    }
}


} // endof namespace java
