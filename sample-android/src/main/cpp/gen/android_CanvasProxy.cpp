/**
 * File generated by Jenny -- https://github.com/LanderlYoung/Jenny
 *
 * DO NOT EDIT THIS FILE.
 *
 * For bug report, please refer to github issue tracker https://github.com/LanderlYoung/Jenny/issues,
 * or contact author landerlyoung@gmail.com.
 */
#include "android_CanvasProxy.h"


// external logger function passed by jenny.errorLoggerFunction
void jennySampleErrorLog(JNIEnv* env, const char* error);


namespace android {

jclass CanvasProxy::sClazz = nullptr;

// thread safe init
std::mutex CanvasProxy::sInitLock;
std::atomic_bool CanvasProxy::sInited;

/*static*/ bool CanvasProxy::initClazz(JNIEnv *env) {
#define JENNY_CHECK_NULL(val)                      \
       do {                                        \
           if ((val) == nullptr) {                 \
               jennySampleErrorLog(env, "can't init CanvasProxy::" #val); \
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

            sConstruct_0 = env->GetMethodID(sClazz, "<init>", "()V");
            JENNY_CHECK_NULL(sConstruct_0);

            sConstruct_1 = env->GetMethodID(sClazz, "<init>", "(Landroid/graphics/Bitmap;)V");
            JENNY_CHECK_NULL(sConstruct_1);


            sMethod_isHardwareAccelerated_0 = env->GetMethodID(sClazz, "isHardwareAccelerated", "()Z");
            JENNY_CHECK_NULL(sMethod_isHardwareAccelerated_0);

            sMethod_setBitmap_0 = env->GetMethodID(sClazz, "setBitmap", "(Landroid/graphics/Bitmap;)V");
            JENNY_CHECK_NULL(sMethod_setBitmap_0);

            sMethod_isOpaque_0 = env->GetMethodID(sClazz, "isOpaque", "()Z");
            JENNY_CHECK_NULL(sMethod_isOpaque_0);

            sMethod_getWidth_0 = env->GetMethodID(sClazz, "getWidth", "()I");
            JENNY_CHECK_NULL(sMethod_getWidth_0);

            sMethod_getHeight_0 = env->GetMethodID(sClazz, "getHeight", "()I");
            JENNY_CHECK_NULL(sMethod_getHeight_0);

            sMethod_getDensity_0 = env->GetMethodID(sClazz, "getDensity", "()I");
            JENNY_CHECK_NULL(sMethod_getDensity_0);

            sMethod_setDensity_0 = env->GetMethodID(sClazz, "setDensity", "(I)V");
            JENNY_CHECK_NULL(sMethod_setDensity_0);

            sMethod_getMaximumBitmapWidth_0 = env->GetMethodID(sClazz, "getMaximumBitmapWidth", "()I");
            JENNY_CHECK_NULL(sMethod_getMaximumBitmapWidth_0);

            sMethod_getMaximumBitmapHeight_0 = env->GetMethodID(sClazz, "getMaximumBitmapHeight", "()I");
            JENNY_CHECK_NULL(sMethod_getMaximumBitmapHeight_0);

            sMethod_save_0 = env->GetMethodID(sClazz, "save", "()I");
            JENNY_CHECK_NULL(sMethod_save_0);

            sMethod_saveLayer_0 = env->GetMethodID(sClazz, "saveLayer", "(Landroid/graphics/RectF;Landroid/graphics/Paint;I)I");
            JENNY_CHECK_NULL(sMethod_saveLayer_0);

            sMethod_saveLayer_1 = env->GetMethodID(sClazz, "saveLayer", "(Landroid/graphics/RectF;Landroid/graphics/Paint;)I");
            JENNY_CHECK_NULL(sMethod_saveLayer_1);

            sMethod_saveLayer_2 = env->GetMethodID(sClazz, "saveLayer", "(FFFFLandroid/graphics/Paint;I)I");
            JENNY_CHECK_NULL(sMethod_saveLayer_2);

            sMethod_saveLayer_3 = env->GetMethodID(sClazz, "saveLayer", "(FFFFLandroid/graphics/Paint;)I");
            JENNY_CHECK_NULL(sMethod_saveLayer_3);

            sMethod_saveLayerAlpha_0 = env->GetMethodID(sClazz, "saveLayerAlpha", "(Landroid/graphics/RectF;II)I");
            JENNY_CHECK_NULL(sMethod_saveLayerAlpha_0);

            sMethod_saveLayerAlpha_1 = env->GetMethodID(sClazz, "saveLayerAlpha", "(Landroid/graphics/RectF;I)I");
            JENNY_CHECK_NULL(sMethod_saveLayerAlpha_1);

            sMethod_saveLayerAlpha_2 = env->GetMethodID(sClazz, "saveLayerAlpha", "(FFFFII)I");
            JENNY_CHECK_NULL(sMethod_saveLayerAlpha_2);

            sMethod_saveLayerAlpha_3 = env->GetMethodID(sClazz, "saveLayerAlpha", "(FFFFI)I");
            JENNY_CHECK_NULL(sMethod_saveLayerAlpha_3);

            sMethod_restore_0 = env->GetMethodID(sClazz, "restore", "()V");
            JENNY_CHECK_NULL(sMethod_restore_0);

            sMethod_getSaveCount_0 = env->GetMethodID(sClazz, "getSaveCount", "()I");
            JENNY_CHECK_NULL(sMethod_getSaveCount_0);

            sMethod_restoreToCount_0 = env->GetMethodID(sClazz, "restoreToCount", "(I)V");
            JENNY_CHECK_NULL(sMethod_restoreToCount_0);

            sMethod_translate_0 = env->GetMethodID(sClazz, "translate", "(FF)V");
            JENNY_CHECK_NULL(sMethod_translate_0);

            sMethod_scale_0 = env->GetMethodID(sClazz, "scale", "(FF)V");
            JENNY_CHECK_NULL(sMethod_scale_0);

            sMethod_scale_1 = env->GetMethodID(sClazz, "scale", "(FFFF)V");
            JENNY_CHECK_NULL(sMethod_scale_1);

            sMethod_rotate_0 = env->GetMethodID(sClazz, "rotate", "(F)V");
            JENNY_CHECK_NULL(sMethod_rotate_0);

            sMethod_rotate_1 = env->GetMethodID(sClazz, "rotate", "(FFF)V");
            JENNY_CHECK_NULL(sMethod_rotate_1);

            sMethod_skew_0 = env->GetMethodID(sClazz, "skew", "(FF)V");
            JENNY_CHECK_NULL(sMethod_skew_0);

            sMethod_concat_0 = env->GetMethodID(sClazz, "concat", "(Landroid/graphics/Matrix;)V");
            JENNY_CHECK_NULL(sMethod_concat_0);

            sMethod_setMatrix_0 = env->GetMethodID(sClazz, "setMatrix", "(Landroid/graphics/Matrix;)V");
            JENNY_CHECK_NULL(sMethod_setMatrix_0);

            sMethod_getMatrix_0 = env->GetMethodID(sClazz, "getMatrix", "(Landroid/graphics/Matrix;)V");
            JENNY_CHECK_NULL(sMethod_getMatrix_0);

            sMethod_getMatrix_1 = env->GetMethodID(sClazz, "getMatrix", "()Landroid/graphics/Matrix;");
            JENNY_CHECK_NULL(sMethod_getMatrix_1);

            sMethod_clipRect_0 = env->GetMethodID(sClazz, "clipRect", "(Landroid/graphics/RectF;Landroid/graphics/Region$Op;)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_0);

            sMethod_clipRect_1 = env->GetMethodID(sClazz, "clipRect", "(Landroid/graphics/Rect;Landroid/graphics/Region$Op;)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_1);

            sMethod_clipRect_2 = env->GetMethodID(sClazz, "clipRect", "(Landroid/graphics/RectF;)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_2);

            sMethod_clipRect_3 = env->GetMethodID(sClazz, "clipRect", "(Landroid/graphics/Rect;)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_3);

            sMethod_clipRect_4 = env->GetMethodID(sClazz, "clipRect", "(FFFFLandroid/graphics/Region$Op;)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_4);

            sMethod_clipRect_5 = env->GetMethodID(sClazz, "clipRect", "(FFFF)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_5);

            sMethod_clipRect_6 = env->GetMethodID(sClazz, "clipRect", "(IIII)Z");
            JENNY_CHECK_NULL(sMethod_clipRect_6);

            sMethod_clipOutRect_0 = env->GetMethodID(sClazz, "clipOutRect", "(Landroid/graphics/RectF;)Z");
            JENNY_CHECK_NULL(sMethod_clipOutRect_0);

            sMethod_clipOutRect_1 = env->GetMethodID(sClazz, "clipOutRect", "(Landroid/graphics/Rect;)Z");
            JENNY_CHECK_NULL(sMethod_clipOutRect_1);

            sMethod_clipOutRect_2 = env->GetMethodID(sClazz, "clipOutRect", "(FFFF)Z");
            JENNY_CHECK_NULL(sMethod_clipOutRect_2);

            sMethod_clipOutRect_3 = env->GetMethodID(sClazz, "clipOutRect", "(IIII)Z");
            JENNY_CHECK_NULL(sMethod_clipOutRect_3);

            sMethod_clipPath_0 = env->GetMethodID(sClazz, "clipPath", "(Landroid/graphics/Path;Landroid/graphics/Region$Op;)Z");
            JENNY_CHECK_NULL(sMethod_clipPath_0);

            sMethod_clipPath_1 = env->GetMethodID(sClazz, "clipPath", "(Landroid/graphics/Path;)Z");
            JENNY_CHECK_NULL(sMethod_clipPath_1);

            sMethod_clipOutPath_0 = env->GetMethodID(sClazz, "clipOutPath", "(Landroid/graphics/Path;)Z");
            JENNY_CHECK_NULL(sMethod_clipOutPath_0);

            sMethod_getDrawFilter_0 = env->GetMethodID(sClazz, "getDrawFilter", "()Landroid/graphics/DrawFilter;");
            JENNY_CHECK_NULL(sMethod_getDrawFilter_0);

            sMethod_setDrawFilter_0 = env->GetMethodID(sClazz, "setDrawFilter", "(Landroid/graphics/DrawFilter;)V");
            JENNY_CHECK_NULL(sMethod_setDrawFilter_0);

            sMethod_quickReject_0 = env->GetMethodID(sClazz, "quickReject", "(Landroid/graphics/RectF;Landroid/graphics/Canvas$EdgeType;)Z");
            JENNY_CHECK_NULL(sMethod_quickReject_0);

            sMethod_quickReject_1 = env->GetMethodID(sClazz, "quickReject", "(Landroid/graphics/Path;Landroid/graphics/Canvas$EdgeType;)Z");
            JENNY_CHECK_NULL(sMethod_quickReject_1);

            sMethod_quickReject_2 = env->GetMethodID(sClazz, "quickReject", "(FFFFLandroid/graphics/Canvas$EdgeType;)Z");
            JENNY_CHECK_NULL(sMethod_quickReject_2);

            sMethod_getClipBounds_0 = env->GetMethodID(sClazz, "getClipBounds", "(Landroid/graphics/Rect;)Z");
            JENNY_CHECK_NULL(sMethod_getClipBounds_0);

            sMethod_getClipBounds_1 = env->GetMethodID(sClazz, "getClipBounds", "()Landroid/graphics/Rect;");
            JENNY_CHECK_NULL(sMethod_getClipBounds_1);

            sMethod_drawPicture_0 = env->GetMethodID(sClazz, "drawPicture", "(Landroid/graphics/Picture;)V");
            JENNY_CHECK_NULL(sMethod_drawPicture_0);

            sMethod_drawPicture_1 = env->GetMethodID(sClazz, "drawPicture", "(Landroid/graphics/Picture;Landroid/graphics/RectF;)V");
            JENNY_CHECK_NULL(sMethod_drawPicture_1);

            sMethod_drawPicture_2 = env->GetMethodID(sClazz, "drawPicture", "(Landroid/graphics/Picture;Landroid/graphics/Rect;)V");
            JENNY_CHECK_NULL(sMethod_drawPicture_2);

            sMethod_drawArc_0 = env->GetMethodID(sClazz, "drawArc", "(Landroid/graphics/RectF;FFZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawArc_0);

            sMethod_drawArc_1 = env->GetMethodID(sClazz, "drawArc", "(FFFFFFZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawArc_1);

            sMethod_drawARGB_0 = env->GetMethodID(sClazz, "drawARGB", "(IIII)V");
            JENNY_CHECK_NULL(sMethod_drawARGB_0);

            sMethod_drawBitmap_0 = env->GetMethodID(sClazz, "drawBitmap", "(Landroid/graphics/Bitmap;FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_0);

            sMethod_drawBitmap_1 = env->GetMethodID(sClazz, "drawBitmap", "(Landroid/graphics/Bitmap;Landroid/graphics/Rect;Landroid/graphics/RectF;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_1);

            sMethod_drawBitmap_2 = env->GetMethodID(sClazz, "drawBitmap", "(Landroid/graphics/Bitmap;Landroid/graphics/Rect;Landroid/graphics/Rect;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_2);

            sMethod_drawBitmap_3 = env->GetMethodID(sClazz, "drawBitmap", "([IIIFFIIZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_3);

            sMethod_drawBitmap_4 = env->GetMethodID(sClazz, "drawBitmap", "([IIIIIIIZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_4);

            sMethod_drawBitmap_5 = env->GetMethodID(sClazz, "drawBitmap", "(Landroid/graphics/Bitmap;Landroid/graphics/Matrix;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmap_5);

            sMethod_drawBitmapMesh_0 = env->GetMethodID(sClazz, "drawBitmapMesh", "(Landroid/graphics/Bitmap;II[FI[IILandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawBitmapMesh_0);

            sMethod_drawCircle_0 = env->GetMethodID(sClazz, "drawCircle", "(FFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawCircle_0);

            sMethod_drawColor_0 = env->GetMethodID(sClazz, "drawColor", "(I)V");
            JENNY_CHECK_NULL(sMethod_drawColor_0);

            sMethod_drawColor_1 = env->GetMethodID(sClazz, "drawColor", "(ILandroid/graphics/PorterDuff$Mode;)V");
            JENNY_CHECK_NULL(sMethod_drawColor_1);

            sMethod_drawLine_0 = env->GetMethodID(sClazz, "drawLine", "(FFFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawLine_0);

            sMethod_drawLines_0 = env->GetMethodID(sClazz, "drawLines", "([FIILandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawLines_0);

            sMethod_drawLines_1 = env->GetMethodID(sClazz, "drawLines", "([FLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawLines_1);

            sMethod_drawOval_0 = env->GetMethodID(sClazz, "drawOval", "(Landroid/graphics/RectF;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawOval_0);

            sMethod_drawOval_1 = env->GetMethodID(sClazz, "drawOval", "(FFFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawOval_1);

            sMethod_drawPaint_0 = env->GetMethodID(sClazz, "drawPaint", "(Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPaint_0);

            sMethod_drawPath_0 = env->GetMethodID(sClazz, "drawPath", "(Landroid/graphics/Path;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPath_0);

            sMethod_drawPoint_0 = env->GetMethodID(sClazz, "drawPoint", "(FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPoint_0);

            sMethod_drawPoints_0 = env->GetMethodID(sClazz, "drawPoints", "([FIILandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPoints_0);

            sMethod_drawPoints_1 = env->GetMethodID(sClazz, "drawPoints", "([FLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPoints_1);

            sMethod_drawPosText_0 = env->GetMethodID(sClazz, "drawPosText", "([CII[FLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPosText_0);

            sMethod_drawPosText_1 = env->GetMethodID(sClazz, "drawPosText", "(Ljava/lang/String;[FLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawPosText_1);

            sMethod_drawRect_0 = env->GetMethodID(sClazz, "drawRect", "(Landroid/graphics/RectF;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawRect_0);

            sMethod_drawRect_1 = env->GetMethodID(sClazz, "drawRect", "(Landroid/graphics/Rect;Landroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawRect_1);

            sMethod_drawRect_2 = env->GetMethodID(sClazz, "drawRect", "(FFFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawRect_2);

            sMethod_drawRGB_0 = env->GetMethodID(sClazz, "drawRGB", "(III)V");
            JENNY_CHECK_NULL(sMethod_drawRGB_0);

            sMethod_drawRoundRect_0 = env->GetMethodID(sClazz, "drawRoundRect", "(Landroid/graphics/RectF;FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawRoundRect_0);

            sMethod_drawRoundRect_1 = env->GetMethodID(sClazz, "drawRoundRect", "(FFFFFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawRoundRect_1);

            sMethod_drawText_0 = env->GetMethodID(sClazz, "drawText", "([CIIFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawText_0);

            sMethod_drawText_1 = env->GetMethodID(sClazz, "drawText", "(Ljava/lang/String;FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawText_1);

            sMethod_drawText_2 = env->GetMethodID(sClazz, "drawText", "(Ljava/lang/String;IIFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawText_2);

            sMethod_drawText_3 = env->GetMethodID(sClazz, "drawText", "(Ljava/lang/CharSequence;IIFFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawText_3);

            sMethod_drawTextOnPath_0 = env->GetMethodID(sClazz, "drawTextOnPath", "([CIILandroid/graphics/Path;FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawTextOnPath_0);

            sMethod_drawTextOnPath_1 = env->GetMethodID(sClazz, "drawTextOnPath", "(Ljava/lang/String;Landroid/graphics/Path;FFLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawTextOnPath_1);

            sMethod_drawTextRun_0 = env->GetMethodID(sClazz, "drawTextRun", "([CIIIIFFZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawTextRun_0);

            sMethod_drawTextRun_1 = env->GetMethodID(sClazz, "drawTextRun", "(Ljava/lang/CharSequence;IIIIFFZLandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawTextRun_1);

            sMethod_drawVertices_0 = env->GetMethodID(sClazz, "drawVertices", "(Landroid/graphics/Canvas$VertexMode;I[FI[FI[II[SIILandroid/graphics/Paint;)V");
            JENNY_CHECK_NULL(sMethod_drawVertices_0);



            sInited = true;
        }
    }
#undef JENNY_CHECK_NULL
   return true;
}

/*static*/ void CanvasProxy::releaseClazz(JNIEnv *env) {
    if (sInited) {
        std::lock_guard<std::mutex> lg(sInitLock);
        if (sInited) {
            env->DeleteLocalRef(sClazz);
            sClazz = nullptr;
            sInited = false;
        }
    }
}

jmethodID CanvasProxy::sConstruct_0;
jmethodID CanvasProxy::sConstruct_1;

jmethodID CanvasProxy::sMethod_isHardwareAccelerated_0;
jmethodID CanvasProxy::sMethod_setBitmap_0;
jmethodID CanvasProxy::sMethod_isOpaque_0;
jmethodID CanvasProxy::sMethod_getWidth_0;
jmethodID CanvasProxy::sMethod_getHeight_0;
jmethodID CanvasProxy::sMethod_getDensity_0;
jmethodID CanvasProxy::sMethod_setDensity_0;
jmethodID CanvasProxy::sMethod_getMaximumBitmapWidth_0;
jmethodID CanvasProxy::sMethod_getMaximumBitmapHeight_0;
jmethodID CanvasProxy::sMethod_save_0;
jmethodID CanvasProxy::sMethod_saveLayer_0;
jmethodID CanvasProxy::sMethod_saveLayer_1;
jmethodID CanvasProxy::sMethod_saveLayer_2;
jmethodID CanvasProxy::sMethod_saveLayer_3;
jmethodID CanvasProxy::sMethod_saveLayerAlpha_0;
jmethodID CanvasProxy::sMethod_saveLayerAlpha_1;
jmethodID CanvasProxy::sMethod_saveLayerAlpha_2;
jmethodID CanvasProxy::sMethod_saveLayerAlpha_3;
jmethodID CanvasProxy::sMethod_restore_0;
jmethodID CanvasProxy::sMethod_getSaveCount_0;
jmethodID CanvasProxy::sMethod_restoreToCount_0;
jmethodID CanvasProxy::sMethod_translate_0;
jmethodID CanvasProxy::sMethod_scale_0;
jmethodID CanvasProxy::sMethod_scale_1;
jmethodID CanvasProxy::sMethod_rotate_0;
jmethodID CanvasProxy::sMethod_rotate_1;
jmethodID CanvasProxy::sMethod_skew_0;
jmethodID CanvasProxy::sMethod_concat_0;
jmethodID CanvasProxy::sMethod_setMatrix_0;
jmethodID CanvasProxy::sMethod_getMatrix_0;
jmethodID CanvasProxy::sMethod_getMatrix_1;
jmethodID CanvasProxy::sMethod_clipRect_0;
jmethodID CanvasProxy::sMethod_clipRect_1;
jmethodID CanvasProxy::sMethod_clipRect_2;
jmethodID CanvasProxy::sMethod_clipRect_3;
jmethodID CanvasProxy::sMethod_clipRect_4;
jmethodID CanvasProxy::sMethod_clipRect_5;
jmethodID CanvasProxy::sMethod_clipRect_6;
jmethodID CanvasProxy::sMethod_clipOutRect_0;
jmethodID CanvasProxy::sMethod_clipOutRect_1;
jmethodID CanvasProxy::sMethod_clipOutRect_2;
jmethodID CanvasProxy::sMethod_clipOutRect_3;
jmethodID CanvasProxy::sMethod_clipPath_0;
jmethodID CanvasProxy::sMethod_clipPath_1;
jmethodID CanvasProxy::sMethod_clipOutPath_0;
jmethodID CanvasProxy::sMethod_getDrawFilter_0;
jmethodID CanvasProxy::sMethod_setDrawFilter_0;
jmethodID CanvasProxy::sMethod_quickReject_0;
jmethodID CanvasProxy::sMethod_quickReject_1;
jmethodID CanvasProxy::sMethod_quickReject_2;
jmethodID CanvasProxy::sMethod_getClipBounds_0;
jmethodID CanvasProxy::sMethod_getClipBounds_1;
jmethodID CanvasProxy::sMethod_drawPicture_0;
jmethodID CanvasProxy::sMethod_drawPicture_1;
jmethodID CanvasProxy::sMethod_drawPicture_2;
jmethodID CanvasProxy::sMethod_drawArc_0;
jmethodID CanvasProxy::sMethod_drawArc_1;
jmethodID CanvasProxy::sMethod_drawARGB_0;
jmethodID CanvasProxy::sMethod_drawBitmap_0;
jmethodID CanvasProxy::sMethod_drawBitmap_1;
jmethodID CanvasProxy::sMethod_drawBitmap_2;
jmethodID CanvasProxy::sMethod_drawBitmap_3;
jmethodID CanvasProxy::sMethod_drawBitmap_4;
jmethodID CanvasProxy::sMethod_drawBitmap_5;
jmethodID CanvasProxy::sMethod_drawBitmapMesh_0;
jmethodID CanvasProxy::sMethod_drawCircle_0;
jmethodID CanvasProxy::sMethod_drawColor_0;
jmethodID CanvasProxy::sMethod_drawColor_1;
jmethodID CanvasProxy::sMethod_drawLine_0;
jmethodID CanvasProxy::sMethod_drawLines_0;
jmethodID CanvasProxy::sMethod_drawLines_1;
jmethodID CanvasProxy::sMethod_drawOval_0;
jmethodID CanvasProxy::sMethod_drawOval_1;
jmethodID CanvasProxy::sMethod_drawPaint_0;
jmethodID CanvasProxy::sMethod_drawPath_0;
jmethodID CanvasProxy::sMethod_drawPoint_0;
jmethodID CanvasProxy::sMethod_drawPoints_0;
jmethodID CanvasProxy::sMethod_drawPoints_1;
jmethodID CanvasProxy::sMethod_drawPosText_0;
jmethodID CanvasProxy::sMethod_drawPosText_1;
jmethodID CanvasProxy::sMethod_drawRect_0;
jmethodID CanvasProxy::sMethod_drawRect_1;
jmethodID CanvasProxy::sMethod_drawRect_2;
jmethodID CanvasProxy::sMethod_drawRGB_0;
jmethodID CanvasProxy::sMethod_drawRoundRect_0;
jmethodID CanvasProxy::sMethod_drawRoundRect_1;
jmethodID CanvasProxy::sMethod_drawText_0;
jmethodID CanvasProxy::sMethod_drawText_1;
jmethodID CanvasProxy::sMethod_drawText_2;
jmethodID CanvasProxy::sMethod_drawText_3;
jmethodID CanvasProxy::sMethod_drawTextOnPath_0;
jmethodID CanvasProxy::sMethod_drawTextOnPath_1;
jmethodID CanvasProxy::sMethod_drawTextRun_0;
jmethodID CanvasProxy::sMethod_drawTextRun_1;
jmethodID CanvasProxy::sMethod_drawVertices_0;


} // endof namespace android
