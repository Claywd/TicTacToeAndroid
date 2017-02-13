package com.android.gl2jni;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class welcomeScreen extends AppCompatActivity {

    Button miniMax, aStar, easy, medium, hard, start, reset;
    String opponent = "random";
    String difficulty = "easy";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_welcome_screen);

        start = (Button) findViewById(R.id.start);
        reset = (Button) findViewById(R.id.reset);
        miniMax = (Button) findViewById(R.id.miniMax);
        aStar = (Button) findViewById(R.id.aStar);
        easy = (Button) findViewById(R.id.easy);
        medium = (Button) findViewById(R.id.medium);
        hard = (Button) findViewById(R.id.hard);

        miniMax.setOnClickListener(new View.OnClickListener() {
                                       @Override
                                       public void onClick(View view) {
                                           opponent = "miniMax";
                                           ((TextView) findViewById(R.id.chooseOpponent)).setText("Opponent: MiniMax Algorithm");
                                       }
                                   }
        );
        aStar.setOnClickListener(new View.OnClickListener() {
                                     @Override
                                     public void onClick(View view){
                                         opponent = "aStar";
                                         ((TextView) findViewById(R.id.chooseOpponent)).setText("Opponent: A* Algorithm");
                                     }
                                 }
        );
        easy.setOnClickListener(new View.OnClickListener() {
                                    @Override
                                    public void onClick(View view) {
                                        difficulty = "easy";
                                        ((TextView) findViewById(R.id.chooseDifficulty)).setText("Difficulty: Easy");
                                    }
                                }
        );
        medium.setOnClickListener(new View.OnClickListener() {
                                      @Override
                                      public void onClick(View view) {difficulty = "medium";
                                          ((TextView)findViewById(R.id.chooseDifficulty)).setText("Difficulty: Medium");
                                      }
                                  }
        );
        hard.setOnClickListener(new View.OnClickListener() {
                                    @Override
                                    public void onClick(View view) {difficulty = "hard";
                                        ((TextView)findViewById(R.id.chooseDifficulty)).setText("Difficulty: Hard");
                                    }
                                }
        );

        reset.setOnClickListener(new View.OnClickListener() {
                                     @Override
                                     public void onClick(View view) {difficulty = "easy"; opponent = "Random Picker";
                                         ((TextView)findViewById(R.id.chooseDifficulty)).setText("Difficulty: Easy");
                                         ((TextView)findViewById(R.id.chooseOpponent)).setText("Opponent: Random Picker");
                                     }
                                 }
        );

        start.setOnClickListener(new View.OnClickListener() {
                                     @Override
                                     public void onClick(View view) {
                                         Intent intent = new Intent(welcomeScreen.this, gamePlay.class);
                                         Log.d("opponent", opponent);
                                         Log.d("difficulty", difficulty);
                                         intent.putExtra("opponent", opponent);
                                         intent.putExtra("difficulty", difficulty);
                                         startActivity(intent);
                                     }
                                 }
        );
    }
}
