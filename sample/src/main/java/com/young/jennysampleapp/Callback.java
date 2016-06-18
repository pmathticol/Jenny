package com.young.jennysampleapp;

import com.young.jenny.annotation.NativeAccessField;
import com.young.jenny.annotation.NativeReflect;
import com.young.jenny.annotation.NativeReflectMethod;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Author: landerlyoung@gmail.com
 * Date:   2016-06-02
 * Time:   19-58
 * Life with Passion, Code with Creativity.
 */
@NativeReflect(allFields = false, allMethods = false)
public class Callback {

    protected Object lock;

    public static final int COMPILE_CONSTANT_INT = 0;

    @NativeAccessField(getter = true, setter = true, auto = false)
    public final int count = 0;

    public static ArrayList<String> aStaticField;

    @NativeReflectMethod
    public Callback() {
    }

    @NativeReflectMethod
    public Callback(int a) {

    }

    @NativeReflectMethod
    public Callback(HashMap<?,?> sth) {

    }

    @NativeReflect
    public class NestedClass {
        public void hello() {

        }
    }

    public static int aStaticMethod() {
        return 0;
    }

    @NativeReflectMethod
    void onJobDone(boolean success, String result) {

    }

    @NativeReflectMethod
    void onJobProgress(long progress) {

    }

    @NativeReflectMethod
    void onJobStart() {

    }

    int prepareRun() {
        return 0;
    }
}
