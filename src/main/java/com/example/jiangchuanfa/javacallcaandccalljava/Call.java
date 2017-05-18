package com.example.jiangchuanfa.javacallcaandccalljava;

import android.content.Context;
import android.util.Log;

/**
 * Created by crest on 2017/5/18.
 *
 *
 */

public class Call {

    private final Context context;

    {
        System.loadLibrary("HelloJni");
    }

    public Call(Context context) {
        this.context = context;
    }


    public native int[] increaseArrayEles(int[] intArray);//JavaCallC


    public native void callbackAdd();//C Call Java
    public int add(int x, int y) {
        Log.e("TAG","add() x=" + x+" y="+y);
        return x + y;
    }


}
