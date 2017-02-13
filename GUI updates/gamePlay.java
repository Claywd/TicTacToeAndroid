package edu.tamu.claywd1210.tictactoe;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.Random;
import java.lang.String;
import java.util.Vector;

public class gamePlay extends AppCompatActivity {

    Button [][] grid = new Button [5][5];
    int [][] moves = new int[5][5];
    Button startOver;
    int count;

    public void getMove(){
        String result= "";
        boolean win = false;             //Temporary value for win, need win logic

//Begin Random Picker
        Random rand = new Random();

        if (count <24) {
            final int[] row0 = {0, 1, 2, 3, 4};
            final int[] col0 = {0, 1, 2, 3, 4};
            final int[] col1 = {0, 1, 2, 3, 4};
            final int[] row1 = {0, 1, 2, 3, 4};
            final int[] col2 = {0, 1, 2, 3, 4};
            final int[] row2 = {0, 1, 2, 3, 4};
            final int[] col3 = {0, 1, 2, 3, 4};
            final int[] row3 = {0, 1, 2, 3, 4};
            final int[] col4 = {0, 1, 2, 3, 4};
            final int[] row4 = {0, 1, 2, 3, 4};


            int choice = rand.nextInt(4);
            int x = 0;
            int y = 0;
            if (choice == 0) {
                x = row0[rand.nextInt(row0.length)];
                y = col0[rand.nextInt(col0.length)];
            } else if (choice == 1) {
                x = row1[rand.nextInt(row1.length)];
                y = col1[rand.nextInt(col1.length)];
            } else if (choice == 2) {
                x = row2[rand.nextInt(row2.length)];
                y = col2[rand.nextInt(col2.length)];
            } else if (choice == 3) {
                x = row3[rand.nextInt(row3.length)];
                y = col3[rand.nextInt(col3.length)];
            } else if (choice == 4) {
                x = row4[rand.nextInt(row4.length)];
                y = col4[rand.nextInt(col4.length)];
            }

            if (moves[x][y] == 0) {
                (grid[x][y]).setText("X");
                moves[x][y] = 1;
                Log.d("Number of Moves", " " + count);
                count++;
            } else getMove();
        }
        else win = true;
// End Random Picker

// Begin Win Dialogue

        if (win){
        AlertDialog.Builder helpBuilder = new AlertDialog.Builder(this);
        helpBuilder.setTitle("Match Summary");

            helpBuilder.setMessage(" You are the " + result);

            helpBuilder.setPositiveButton("Main Menu",
                    new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            Intent intent = new Intent(gamePlay.this, welcomeScreen.class);
                            startActivity(intent);
                        }
                    });
            helpBuilder.setNegativeButton("Start Over",
                    new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            recreate();
                        }
                    });
            AlertDialog helpDialog = helpBuilder.create();
            helpDialog.show();
        }
// end Win Dialogue
        };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game_play);

        Intent intent = getIntent();
        String opponent = intent.getStringExtra("opponent");
        String difficulty = intent.getStringExtra("difficulty");

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
            moves [2][2] = 1;
            count++;
        }
        else if (difficulty.equals("medium")){
        int[] med = new int[2];
        med[0] = 0;
        med[1] = 4;
        int medx = med[rand.nextInt(med.length)];
        int medy = med[rand.nextInt(med.length)];
        System.out.println("x,y" + medx + ", "+ medy );
        (grid[medx][medy]).setText("X");
            moves [medx][medy] = 1;
            count++;
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
            count++;
        }
        grid[0][0].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][0] ==0){
                    (grid[0][0]).setText("O");
                    moves[0][0] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[0][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][1] ==0){
                    (grid[0][1]).setText("O");
                    moves[0][1] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[0][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][2] ==0){
                    (grid[0][2]).setText("O");
                    moves[0][2] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[0][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][3] ==0){
                    (grid[0][3]).setText("O");
                    moves[0][3] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[0][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[0][4] ==0){
                    (grid[0][4]).setText("O");
                    moves[0][4] = 1;
                    count++;
                    getMove();
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
                    count++;
                    getMove();
                }
            }
        });
        grid[1][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][1] ==0){
                    (grid[1][1]).setText("O");
                    moves[1][1] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[1][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][2] ==0){
                    (grid[1][2]).setText("O");
                    moves[1][2] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[1][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][3] ==0){
                    (grid[1][3]).setText("O");
                    moves[1][3] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[1][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[1][4] ==0){
                    (grid[1][4]).setText("O");
                    moves[1][4] = 1;
                    count++;
                    getMove();
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
                    count++;
                    getMove();
                }
            }
        });
        grid[2][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][1] ==0){
                    (grid[2][1]).setText("O");
                    moves[2][1] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[2][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][2] ==0){
                    (grid[2][2]).setText("O");
                    moves[2][2] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[2][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][3] ==0){
                    (grid[2][3]).setText("O");
                    moves[2][3] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[2][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[2][4] ==0){
                    (grid[2][4]).setText("O");
                    moves[2][4] = 1;
                    count++;
                    getMove();
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
                    count++;
                    getMove();
                }
            }
        });
        grid[3][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][1] ==0){
                    (grid[3][1]).setText("O");
                    moves[3][1] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[3][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][2] ==0){
                    (grid[3][2]).setText("O");
                    moves[3][2] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[3][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][3] ==0){
                    (grid[3][3]).setText("O");
                    moves[3][3] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[3][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[3][4] ==0){
                    (grid[3][4]).setText("O");
                    moves[3][4] = 1;
                    count++;
                    getMove();
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
                    count++;
                    getMove();
                }
            }
        });
        grid[4][1].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][1] ==0){
                    (grid[4][1]).setText("O");
                    moves[4][1] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[4][2].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][2] ==0){
                    (grid[4][2]).setText("O");
                    moves[4][2] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[4][3].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][3] ==0){
                    (grid[4][3]).setText("O");
                    moves[4][3] = 1;
                    count++;
                    getMove();
                }
            }
        });
        grid[4][4].setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moves[4][4] ==0){
                    (grid[4][4]).setText("O");
                    moves[4][4] = 1;
                    count++;
                    getMove();
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
