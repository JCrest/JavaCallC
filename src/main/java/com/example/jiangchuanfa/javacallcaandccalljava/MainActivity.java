package com.example.jiangchuanfa.javacallcaandccalljava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private Call call;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        call = new Call(this);
        System.out.println("加上一句话看看变化如何");
    }

    public void JavaCallC(View v) {
        int[] array = {1, 2, 3, 4, 5, 6};
        call.increaseArrayEles(array);
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }
    
    public void CCallJava(View v) {
        call.callbackAdd();
    }


}
