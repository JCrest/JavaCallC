#include <jni.h>
//
// Created by crest on 2017/5/18.
//
#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
JNIEXPORT jintArray JNICALL Java_com_example_jiangchuanfa_javacallcaandccalljava_Call_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarray){
    jsize size = (*env)->GetArrayLength(env,jarray);
    jint jArrayNative [size];
    (*env)->GetIntArrayRegion(env,jarray,0,size,jArrayNative);
    int i;
    for (int i = 0; i <size ; ++i) {
        *(jArrayNative+i)+=10;
    }
    (*env)->SetIntArrayRegion(env,jarray,0,size,jArrayNative);
    return jarray;
};

JNIEXPORT void JNICALL Java_com_example_jiangchuanfa_javacallcaandccalljava_Call_callbackAdd
        (JNIEnv *env, jobject jobj){
    jclass jclazz =(*env)->FindClass(env,"com/example/jiangchuanfa/javacallcaandccalljava/Call");
    jmethodID jmethodIDs =(*env)->GetMethodID(env,jclazz,"add","(II)I");
    jobject jobjs =(*env)->AllocObject(env,jclazz);
    int size = (*env)->CallIntMethod(env,jobjs,jmethodIDs,18,25);
    printf("size==%d\n",size);
    LOGE("size==%d\n",size);
};
