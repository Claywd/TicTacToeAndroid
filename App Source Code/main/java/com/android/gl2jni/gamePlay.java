package com.android.gl2jni;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.Random;
import java.lang.String;
import java.util.Vector;

public class gamePlay extends AppCompatActivity {
    AIfunctions bigdog = new AIfunctions();
    Button [][] grid = new Button [5][5];
    int [][] moves = new int[5][5];
    Button startOver;



    public void tiestuff(){
        for(int i = 0; i<5; ++i){
            for(int j =0; j<5; ++j) {
                moves[i][j] = 1;
            }


        }

    }


    public void getMove(String oppo){
        TextView tv2 = (TextView) findViewById(R.id.textView2);
        int x, y;
        String result= "";
        String board = "";
        for(int i = 0; i<5; ++i){
            for(int j =0; j<5; ++j) {
                if((grid[i][j]).getText().equals("")) {
                    board += "_";
                }
                else{
                    board += ""+(grid[i][j]).getText()+"";
                }

            }


        }
        String gg =  bigdog.aiminimax(board);
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_SHORT;
        CharSequence text = "A* ";
        if ( oppo.equals( "miniMax")){
            text = "MiniMax";
            gg = bigdog.aiminimax(board);}
        else {
            gg = bigdog.astar(board);}
        if(gg.equals("bugg"))
            {
                tiestuff();
                tv2.setText("Tie!");}
        else {
                System.out.println(gg);
                x = Integer.parseInt(Character.toString(gg.charAt(0)));
                y = Integer.parseInt(Character.toString(gg.charAt(1)));


                System.out.println(x + "," + y);
                moves[x][y] = 1;
                (grid[x][y]).setText("X");

                System.out.println(gg.charAt(2));
                if (gg.charAt(2) == '0'){
                    tiestuff();
                    tv2.setText("Loser!");}
                if (gg.charAt(2) == '1'){
                    tiestuff();
                    tv2.setText("Winner!");}
                if (gg.charAt(2) == '2' || gg.equals("")){
                    tiestuff();
                    tv2.setText("Tie!");}
            }



    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game_play);

        Intent intent = getIntent();
        final String opponent = intent.getStringExtra("opponent");
        final String difficulty = intent.getStringExtra("difficulty");

        System.out.println("Difficulty=" + difficulty);
        System.out.println("Opponent=" + opponent);

        startOver = (Button) findViewById(R.id.startOver);

        grid[0][0] = (Button) findViewById(R.id.e1);
        grid[0][1] = (Button) findViewById(R.id.e2);
        grid[0][2] = (Button) findViewById(R.id.e3);
        grid[0][3] = (Button) findViewById(R.id.e4);
        grid[0][4] = (Button) findViewById(R.id.e5);
        grid[1][0] = (Button) findViewById(R.id.d1);
        grid[1][1] = (Button) findViewById(R.id.d2);
        grid[1][2] = (Button) findViewById(R.id.d3);
        grid[1][3] = (Button) findViewById(R.id.d4);
        grid[1][4] = (Button) findViewById(R.id.d5);
        grid[2][0] = (Button) findViewById(R.id.c1);
        grid[2][1] = (Button) findViewById(R.id.c2);
        grid[2][2] = (Button) findViewById(R.id.c3);
        grid[2][3] = (Button) findViewById(R.id.c4);
        grid[2][4] = (Button) findViewById(R.id.c5);
        grid[3][0] = (Button) findViewById(R.id.b1);
        grid[3][1] = (Button) findViewById(R.id.b2);
        grid[3][2] = (Button) findViewById(R.id.b3);
        grid[3][3] = (Button) findViewById(R.id.b4);
        grid[3][4] = (Button) findViewById(R.id.b5);
        grid[4][0] = (Button) findViewById(R.id.a1);
        grid[4][1] = (Button) findViewById(R.id.a2);
        grid[4][2] = (Button) findViewById(R.id.a3);
        grid[4][3] = (Button) findViewById(R.id.a4);
        grid[4][4] = (Button) findViewById(R.id.a5);

        Random rand = new Random();

        if (difficulty.equals("hard")){
            (grid[2][2]).setText("X");
        }
        else if (difficulty.equals("medium")){
            int[] med = new int[2];
            med[0] = 0;
            med[1] = 4;
            int medx = med[rand.nextInt(med.length)];
            int medy = med[rand.nextInt(med.length)];
            System.out.println("x,y" + medx + ", "+ medy );
                    (grid[medx][medy]).setText("X");
        }
        else {

            final int[] row0_4 = {0,4};
            final int[] col0_4 = {1,2,3};
            final int[] col123 = {0,4};
            final int[] row123 = {1,2,3};

            int choice = rand.nextInt(2);
            int medx, medy;
            if (choice == 0){
                medx = row0_4[rand.nextInt(row0_4.length)];
                medy = col0_4[rand.nextInt(col0_4.length)];
            }
            else {
                medx = row123[rand.nextInt(row123.length)];
                medy = col123[rand.nextInt(col123.length)];
            }
            (grid[medx][medy]).setText("X");
        }
        grid[0][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][0] ==0){
                    (grid[0][0]).setText("O");
                    moves[0][0] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[0][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][1] ==0){
                    (grid[0][1]).setText("O");
                    moves[0][1] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[0][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][2] ==0){
                    (grid[0][2]).setText("O");
                    moves[0][2] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[0][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][3] ==0){
                    (grid[0][3]).setText("O");
                    moves[0][3] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[0][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][4] ==0){
                    (grid[0][4]).setText("O");
                    moves[0][4] = 1;
                    getMove(opponent);
                }
            }
        });




//1

        grid[1][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][0] ==0){
                    (grid[1][0]).setText("O");
                    moves[1][0] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[1][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][1] ==0){
                    (grid[1][1]).setText("O");
                    moves[1][1] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[1][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][2] ==0){
                    (grid[1][2]).setText("O");
                    moves[1][2] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[1][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][3] ==0){
                    (grid[1][3]).setText("O");
                    moves[1][3] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[1][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][4] ==0){
                    (grid[1][4]).setText("O");
                    moves[1][4] = 1;
                    getMove(opponent);
                }
            }
        });



//2

        grid[2][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][0] ==0){
                    (grid[2][0]).setText("O");
                    moves[2][0] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[2][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][1] ==0){
                    (grid[2][1]).setText("O");
                    moves[2][1] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[2][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][2] ==0){
                    (grid[2][2]).setText("O");
                    moves[2][2] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[2][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][3] ==0){
                    (grid[2][3]).setText("O");
                    moves[2][3] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[2][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][4] ==0){
                    (grid[2][4]).setText("O");
                    moves[2][4] = 1;
                    getMove(opponent);
                }
            }
        });


//3

        grid[3][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][0] ==0){
                    (grid[3][0]).setText("O");
                    moves[3][0] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[3][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][1] ==0){
                    (grid[3][1]).setText("O");
                    moves[3][1] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[3][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][2] ==0){
                    (grid[3][2]).setText("O");
                    moves[3][2] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[3][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][3] ==0){
                    (grid[3][3]).setText("O");
                    moves[3][3] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[3][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][4] ==0){
                    (grid[3][4]).setText("O");
                    moves[3][4] = 1;
                    getMove(opponent);
                }
            }
        });



//4

        grid[4][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][0] ==0){
                    (grid[4][0]).setText("O");
                    moves[4][0] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[4][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][1] ==0){
                    (grid[4][1]).setText("O");
                    moves[4][1] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[4][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][2] ==0){
                    (grid[4][2]).setText("O");
                    moves[4][2] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[4][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][3] ==0){
                    (grid[4][3]).setText("O");
                    moves[4][3] = 1;
                    getMove(opponent);
                }
            }
        });
        grid[4][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][4] ==0){
                    (grid[4][4]).setText("O");
                    moves[4][4] = 1;
                    getMove(opponent);
                }
            }
        });
        startOver.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick (View view){
                recreate();
            }

        });



    }
}
