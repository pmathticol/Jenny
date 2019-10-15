/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#pragma once

#include <jni.h>
#include <assert.h>                        
#include <atomic>
#include <mutex>

namespace java {
class URLConnectionProxy {

public:
    static constexpr auto FULL_CLASS_NAME = "java/net/URLConnection";



private:
    // thread safe init
    static std::atomic_bool sInited;
    static std::mutex sInitLock;

    JNIEnv* mJniEnv;
    jobject mJavaObjectReference;

public:

    static bool initClazz(JNIEnv *env);
    
    static void releaseClazz(JNIEnv *env);

    static void assertInited(JNIEnv *env) {
        auto initClazzSuccess = initClazz(env);
        assert(initClazzSuccess);
    }

    URLConnectionProxy(JNIEnv *env, jobject javaObj)
            : mJniEnv(env), mJavaObjectReference(javaObj) {
        assertInited(env);
    }

    URLConnectionProxy(const URLConnectionProxy &from) = default;
    URLConnectionProxy &operator=(const URLConnectionProxy &) = default;

    URLConnectionProxy(URLConnectionProxy &&from)
           : mJniEnv(from.mJniEnv), mJavaObjectReference(from.mJavaObjectReference) {
        from.mJavaObjectReference = nullptr;
    }

    ~URLConnectionProxy() = default;
    
    // helper method to get underlay jobject reference
    jobject operator*() {
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
    
    // construct: protected URLConnection(java.net.URL url)
    static URLConnectionProxy newInstance(JNIEnv* env, jobject url) noexcept {
       assertInited(env);
       return URLConnectionProxy(env, env->NewObject(sClazz, sConstruct_0, url));
    } 
    

    // method: public static synchronized java.net.FileNameMap getFileNameMap()
    static jobject getFileNameMap(JNIEnv* env) {
        assertInited(env);
        return env->CallStaticObjectMethod(sClazz, sMethod_getFileNameMap_0);
    }

    // method: public static void setFileNameMap(java.net.FileNameMap map)
    static void setFileNameMap(JNIEnv* env, jobject map) {
        assertInited(env);
        env->CallStaticVoidMethod(sClazz, sMethod_setFileNameMap_0, map);
    }

    // method: public abstract void connect()
    void connect() const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_connect_0);
    }

    // method: public void setConnectTimeout(int timeout)
    void setConnectTimeout(jint timeout) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setConnectTimeout_0, timeout);
    }

    // method: public int getConnectTimeout()
    jint getConnectTimeout() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getConnectTimeout_0);
    }

    // method: public void setReadTimeout(int timeout)
    void setReadTimeout(jint timeout) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setReadTimeout_0, timeout);
    }

    // method: public int getReadTimeout()
    jint getReadTimeout() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getReadTimeout_0);
    }

    // method: public java.net.URL getURL()
    jobject getURL() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getURL_0);
    }

    // method: public int getContentLength()
    jint getContentLength() const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getContentLength_0);
    }

    // method: public long getContentLengthLong()
    jlong getContentLengthLong() const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getContentLengthLong_0);
    }

    // method: public java.lang.String getContentType()
    jstring getContentType() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContentType_0));
    }

    // method: public java.lang.String getContentEncoding()
    jstring getContentEncoding() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContentEncoding_0));
    }

    // method: public long getExpiration()
    jlong getExpiration() const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getExpiration_0);
    }

    // method: public long getDate()
    jlong getDate() const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getDate_0);
    }

    // method: public long getLastModified()
    jlong getLastModified() const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getLastModified_0);
    }

    // method: public java.lang.String getHeaderField(java.lang.String name)
    jstring getHeaderField(jstring name) const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getHeaderField_0, name));
    }

    // method: public java.lang.String getHeaderField(int n)
    jstring getHeaderField(jint n) const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getHeaderField_1, n));
    }

    // method: public java.util.Map<java.lang.String,java.util.List<java.lang.String>> getHeaderFields()
    jobject getHeaderFields() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getHeaderFields_0);
    }

    // method: public int getHeaderFieldInt(java.lang.String name, int Default)
    jint getHeaderFieldInt(jstring name, jint Default) const {
        return mJniEnv->CallIntMethod(mJavaObjectReference, sMethod_getHeaderFieldInt_0, name, Default);
    }

    // method: public long getHeaderFieldLong(java.lang.String name, long Default)
    jlong getHeaderFieldLong(jstring name, jlong Default) const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getHeaderFieldLong_0, name, Default);
    }

    // method: public long getHeaderFieldDate(java.lang.String name, long Default)
    jlong getHeaderFieldDate(jstring name, jlong Default) const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getHeaderFieldDate_0, name, Default);
    }

    // method: public java.lang.String getHeaderFieldKey(int n)
    jstring getHeaderFieldKey(jint n) const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getHeaderFieldKey_0, n));
    }

    // method: public java.lang.Object getContent()
    jobject getContent() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContent_0);
    }

    // method: public java.lang.Object getContent(java.lang.Class[] classes)
    jobject getContent(jobjectArray classes) const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getContent_1, classes);
    }

    // method: public java.security.Permission getPermission()
    jobject getPermission() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getPermission_0);
    }

    // method: public java.io.InputStream getInputStream()
    jobject getInputStream() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getInputStream_0);
    }

    // method: public java.io.OutputStream getOutputStream()
    jobject getOutputStream() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getOutputStream_0);
    }

    // method: public java.lang.String toString()
    jstring toString() const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_toString_0));
    }

    // method: public void setDoInput(boolean doinput)
    void setDoInput(jboolean doinput) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setDoInput_0, doinput);
    }

    // method: public boolean getDoInput()
    jboolean getDoInput() const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_getDoInput_0);
    }

    // method: public void setDoOutput(boolean dooutput)
    void setDoOutput(jboolean dooutput) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setDoOutput_0, dooutput);
    }

    // method: public boolean getDoOutput()
    jboolean getDoOutput() const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_getDoOutput_0);
    }

    // method: public void setAllowUserInteraction(boolean allowuserinteraction)
    void setAllowUserInteraction(jboolean allowuserinteraction) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setAllowUserInteraction_0, allowuserinteraction);
    }

    // method: public boolean getAllowUserInteraction()
    jboolean getAllowUserInteraction() const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_getAllowUserInteraction_0);
    }

    // method: public static void setDefaultAllowUserInteraction(boolean defaultallowuserinteraction)
    static void setDefaultAllowUserInteraction(JNIEnv* env, jboolean defaultallowuserinteraction) {
        assertInited(env);
        env->CallStaticVoidMethod(sClazz, sMethod_setDefaultAllowUserInteraction_0, defaultallowuserinteraction);
    }

    // method: public static boolean getDefaultAllowUserInteraction()
    static jboolean getDefaultAllowUserInteraction(JNIEnv* env) {
        assertInited(env);
        return env->CallStaticBooleanMethod(sClazz, sMethod_getDefaultAllowUserInteraction_0);
    }

    // method: public void setUseCaches(boolean usecaches)
    void setUseCaches(jboolean usecaches) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setUseCaches_0, usecaches);
    }

    // method: public boolean getUseCaches()
    jboolean getUseCaches() const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_getUseCaches_0);
    }

    // method: public void setIfModifiedSince(long ifmodifiedsince)
    void setIfModifiedSince(jlong ifmodifiedsince) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setIfModifiedSince_0, ifmodifiedsince);
    }

    // method: public long getIfModifiedSince()
    jlong getIfModifiedSince() const {
        return mJniEnv->CallLongMethod(mJavaObjectReference, sMethod_getIfModifiedSince_0);
    }

    // method: public boolean getDefaultUseCaches()
    jboolean getDefaultUseCaches() const {
        return mJniEnv->CallBooleanMethod(mJavaObjectReference, sMethod_getDefaultUseCaches_0);
    }

    // method: public void setDefaultUseCaches(boolean defaultusecaches)
    void setDefaultUseCaches(jboolean defaultusecaches) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setDefaultUseCaches_0, defaultusecaches);
    }

    // method: public void setRequestProperty(java.lang.String key, java.lang.String value)
    void setRequestProperty(jstring key, jstring value) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_setRequestProperty_0, key, value);
    }

    // method: public void addRequestProperty(java.lang.String key, java.lang.String value)
    void addRequestProperty(jstring key, jstring value) const {
        mJniEnv->CallVoidMethod(mJavaObjectReference, sMethod_addRequestProperty_0, key, value);
    }

    // method: public java.lang.String getRequestProperty(java.lang.String key)
    jstring getRequestProperty(jstring key) const {
        return reinterpret_cast<jstring>(mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getRequestProperty_0, key));
    }

    // method: public java.util.Map<java.lang.String,java.util.List<java.lang.String>> getRequestProperties()
    jobject getRequestProperties() const {
        return mJniEnv->CallObjectMethod(mJavaObjectReference, sMethod_getRequestProperties_0);
    }

    // method: public static void setDefaultRequestProperty(java.lang.String key, java.lang.String value)
    static void setDefaultRequestProperty(JNIEnv* env, jstring key, jstring value) {
        assertInited(env);
        env->CallStaticVoidMethod(sClazz, sMethod_setDefaultRequestProperty_0, key, value);
    }

    // method: public static java.lang.String getDefaultRequestProperty(java.lang.String key)
    static jstring getDefaultRequestProperty(JNIEnv* env, jstring key) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallStaticObjectMethod(sClazz, sMethod_getDefaultRequestProperty_0, key));
    }

    // method: public static synchronized void setContentHandlerFactory(java.net.ContentHandlerFactory fac)
    static void setContentHandlerFactory(JNIEnv* env, jobject fac) {
        assertInited(env);
        env->CallStaticVoidMethod(sClazz, sMethod_setContentHandlerFactory_0, fac);
    }

    // method: public static java.lang.String guessContentTypeFromName(java.lang.String fname)
    static jstring guessContentTypeFromName(JNIEnv* env, jstring fname) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallStaticObjectMethod(sClazz, sMethod_guessContentTypeFromName_0, fname));
    }

    // method: public static java.lang.String guessContentTypeFromStream(java.io.InputStream is)
    static jstring guessContentTypeFromStream(JNIEnv* env, jobject is) {
        assertInited(env);
        return reinterpret_cast<jstring>(env->CallStaticObjectMethod(sClazz, sMethod_guessContentTypeFromStream_0, is));
    }


    // field: protected boolean connected
    jboolean getConnected() const {
       
       return mJniEnv->GetBooleanField(mJavaObjectReference, sField_connected_0);

    }

    // field: protected boolean connected
    void setConnected(jboolean connected) const {
        
        mJniEnv->SetBooleanField(mJavaObjectReference, sField_connected_0, connected);
    }


    // field: protected java.net.URL url
    jobject getUrl() const {
       
       return mJniEnv->GetObjectField(mJavaObjectReference, sField_url_1);

    }

    // field: protected java.net.URL url
    void setUrl(jobject url) const {
        
        mJniEnv->SetObjectField(mJavaObjectReference, sField_url_1, url);
    }



private:
    static jclass sClazz;
    static jmethodID sConstruct_0;

    static jmethodID sMethod_getFileNameMap_0;
    static jmethodID sMethod_setFileNameMap_0;
    static jmethodID sMethod_connect_0;
    static jmethodID sMethod_setConnectTimeout_0;
    static jmethodID sMethod_getConnectTimeout_0;
    static jmethodID sMethod_setReadTimeout_0;
    static jmethodID sMethod_getReadTimeout_0;
    static jmethodID sMethod_getURL_0;
    static jmethodID sMethod_getContentLength_0;
    static jmethodID sMethod_getContentLengthLong_0;
    static jmethodID sMethod_getContentType_0;
    static jmethodID sMethod_getContentEncoding_0;
    static jmethodID sMethod_getExpiration_0;
    static jmethodID sMethod_getDate_0;
    static jmethodID sMethod_getLastModified_0;
    static jmethodID sMethod_getHeaderField_0;
    static jmethodID sMethod_getHeaderField_1;
    static jmethodID sMethod_getHeaderFields_0;
    static jmethodID sMethod_getHeaderFieldInt_0;
    static jmethodID sMethod_getHeaderFieldLong_0;
    static jmethodID sMethod_getHeaderFieldDate_0;
    static jmethodID sMethod_getHeaderFieldKey_0;
    static jmethodID sMethod_getContent_0;
    static jmethodID sMethod_getContent_1;
    static jmethodID sMethod_getPermission_0;
    static jmethodID sMethod_getInputStream_0;
    static jmethodID sMethod_getOutputStream_0;
    static jmethodID sMethod_toString_0;
    static jmethodID sMethod_setDoInput_0;
    static jmethodID sMethod_getDoInput_0;
    static jmethodID sMethod_setDoOutput_0;
    static jmethodID sMethod_getDoOutput_0;
    static jmethodID sMethod_setAllowUserInteraction_0;
    static jmethodID sMethod_getAllowUserInteraction_0;
    static jmethodID sMethod_setDefaultAllowUserInteraction_0;
    static jmethodID sMethod_getDefaultAllowUserInteraction_0;
    static jmethodID sMethod_setUseCaches_0;
    static jmethodID sMethod_getUseCaches_0;
    static jmethodID sMethod_setIfModifiedSince_0;
    static jmethodID sMethod_getIfModifiedSince_0;
    static jmethodID sMethod_getDefaultUseCaches_0;
    static jmethodID sMethod_setDefaultUseCaches_0;
    static jmethodID sMethod_setRequestProperty_0;
    static jmethodID sMethod_addRequestProperty_0;
    static jmethodID sMethod_getRequestProperty_0;
    static jmethodID sMethod_getRequestProperties_0;
    static jmethodID sMethod_setDefaultRequestProperty_0;
    static jmethodID sMethod_getDefaultRequestProperty_0;
    static jmethodID sMethod_setContentHandlerFactory_0;
    static jmethodID sMethod_guessContentTypeFromName_0;
    static jmethodID sMethod_guessContentTypeFromStream_0;

    static jfieldID sField_connected_0;
    static jfieldID sField_url_1;

};
} // endof namespace java
