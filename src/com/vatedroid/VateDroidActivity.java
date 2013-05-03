package com.vatedroid;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class VateDroidActivity extends Activity
{
    // static initializer loads native library
    static {
        System.loadLibrary("vatedroid");
    }

    // native instance method declaration of initVatedroid
    private native void initVatedroid();

    // native instance method declaration of feedVatedroid
    private native String feedVatedroid(String name, String code);

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        // initialize
        initVatedroid();        

        // feed vatedroid
        String result = feedVatedroid("VateDroid Activity", "var blank");
        Log.d("VATEDROID ACTIVITY VATEDROID 'PRODUCED' RESULT", result);
    }
}
