package com.game;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        TextView  tv = new TextView(this);
        tv.setText("Num: "+cplus()+"\n"+str() );
        setContentView(tv);
    }

    public native int cplus();
    public native String str();
    

    static {
        System.loadLibrary("hello-jni");
    }
}
