package com.android.gl2jni;

import java.lang.String;
/**
 * Created by William on 6/29/2016.
 */
public class AIfunctions {
    static {
        System.loadLibrary("gl2jni");
    }

    public native String aiminimax(String s);
    public native String astar(String msg);
}
