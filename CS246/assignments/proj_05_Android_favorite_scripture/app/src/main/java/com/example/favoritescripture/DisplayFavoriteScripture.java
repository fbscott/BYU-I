package com.example.favoritescripture;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class DisplayFavoriteScripture extends AppCompatActivity {

    private static final String TAG = "DisplayFavoriteScripture";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display_favorite_scripture);

        // Get the Intent that started this activity and extract the string
        Intent intent = getIntent();

        String getBook    = intent.getStringExtra("Book");
        String getChapter = intent.getStringExtra("Chapter");
        String getVerse   = intent.getStringExtra("Verse");

        String fullScripture = getBook + ' ' + getChapter + ":" + getVerse;

        // e = error
        // w = warning
        // i = information
        // d = debug
        // v = verbose
        Log.d(TAG, "About to create intent with "  + fullScripture);

        // Capture the layout's TextView and set the string as its text
        TextView displayFaveScript = findViewById(R.id.strFavoriteScripture);
        displayFaveScript.setText(fullScripture);
    }

    public void saveScripture(View view) {

    }
}
