package com.example.myfirstapp;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    public static final String EXTRA_MESSAGE = "com.example.myfirstapp.MESSAGE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void sendMessage(View view) {
        // The Intent constructor takes two parameters: a Context and a Class
        // * The Context parameter is used first because the Activity class is a subclass of Context
        // * The Class parameter of the app component, to which the system delivers the Intent,
        //   is, in this case, the activity to start
        Intent intent = new Intent(this, DisplayMessageActivity.class);
        EditText editText = (EditText) findViewById(R.id.editText);
        String message = editText.getText().toString();
        // The putExtra() method adds the value of EditText to the intent. An Intent can carry data
        // types as key-value pairs called extras
        intent.putExtra(EXTRA_MESSAGE, message);
        startActivity(intent);
    }
}
