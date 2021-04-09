package com.example.favoritescripture;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    /** Called when the user taps the Send button */
    public void sendScripture(View view) {
        Intent intent = new Intent(this, DisplayFavoriteScripture.class);

        EditText edit_book    = findViewById(R.id.editBook);
        EditText edit_chapter = findViewById(R.id.editChapter);
        EditText edit_verse   = findViewById(R.id.editVerse);

        String book    = edit_book.getText().toString();
        String chapter = edit_chapter.getText().toString();
        String verse   = edit_verse.getText().toString();

        intent.putExtra("Book", book);
        intent.putExtra("Chapter", chapter);
        intent.putExtra("Verse", verse);

        // e = error
        // w = warning
        // i = information
        // d = debug
        // v = verbose
        Log.d(TAG, "About to create intent with "  + book + ' ' + chapter + ":" + verse);

        startActivity(intent);
    }
}
