package com.example.lowlevel;

public class LedNative {
    static {
        System.loadLibrary("led_ndkjni");
    }

    public native int openDev();
    public native int closeDev();
    public native int devOn();
    public native int devOff();
}

