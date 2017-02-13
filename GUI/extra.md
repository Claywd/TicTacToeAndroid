package edu.tamu.claywd1210.tictactoe;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.util.Random;

public class gamePlay extends AppCompatActivity {

    boolean player = false;

    public void getMove(){
        Random rand = new Random();
        int x = rand.nextInt(4);
        int y = rand.nextInt(4);

        if (moves[x][y] != 'X' && moves[x][y] != 'O'){
            moves [x][y] = 'X';
            
        }
        else getMove();
        player = !player;
    };

    Button [][] grid = new Button[5][5];
    
    //Declare Buttons
    Button a1,a2,a3,a4,a5,b1,b2,b3,b4,b5,c1,c2,c3,c4,c5,d1,d2,d3,d4,d5,e1,e2,e3,e4,e5;

    char [][] moves = new char [5][5];
    //int [][]userMoves = new int[][];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game_play);

        Intent intent = getIntent();
        String opponent = intent.getStringExtra("opponent");
        String difficulty = intent.getStringExtra("difficulty");

        if(opponent=="miniMax") {
            Context context = getApplicationContext();
            CharSequence text = "MiniMax Starting...";
            int duration = Toast.LENGTH_LONG;

            Toast toast = Toast.makeText(context, text, duration);
            toast.show();

            // Launch miniMax Function with intentBundle.getString("difficulty")

        }
        else if (opponent == "aStar"){
            Context context = getApplicationContext();
            CharSequence text = "A* Starting...";
            int duration = Toast.LENGTH_LONG;

            Toast toast = Toast.makeText(context, text, duration);
            toast.show();
            //Launch miniMax Function with intentBundle.getString("difficulty")
        }
        else{
            Context context = getApplicationContext();
            CharSequence text = "Computer Picking at Random";
            int duration = Toast.LENGTH_LONG;

            Toast toast = Toast.makeText(context, text, duration);
            toast.show();
        }



        //Declare
        a1 = (Button) findViewById(R.id.a1);
        a2 = (Button) findViewById(R.id.a2);
        a3 = (Button) findViewById(R.id.a3);
        a4 = (Button) findViewById(R.id.a4);
        a5 = (Button) findViewById(R.id.a5);
        b1 = (Button) findViewById(R.id.b1);
        b2 = (Button) findViewById(R.id.b2);
        b3 = (Button) findViewById(R.id.b3);
        b4 = (Button) findViewById(R.id.b4);
        b5 = (Button) findViewById(R.id.b5);
        c1 = (Button) findViewById(R.id.c1);
        c2 = (Button) findViewById(R.id.c2);
        c3 = (Button) findViewById(R.id.c3);
        c4 = (Button) findViewById(R.id.c4);
        c5 = (Button) findViewById(R.id.c5);
        d1 = (Button) findViewById(R.id.d1);
        d2 = (Button) findViewById(R.id.d2);
        d3 = (Button) findViewById(R.id.d3);
        d4 = (Button) findViewById(R.id.d4);
        d5 = (Button) findViewById(R.id.d5);
        e1 = (Button) findViewById(R.id.e1);
        e2 = (Button) findViewById(R.id.e2);
        e3 = (Button) findViewById(R.id.e3);
        e4 = (Button) findViewById(R.id.e4);
        e5 = (Button) findViewById(R.id.e5);

        a1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                a1.setText("X");
                if (moves[1][1]!='X') {moves[1][1]='O';}
            }
        });
        a2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        a3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        a4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        a5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        b4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        b5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        c1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        c2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        c3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        c4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        c5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        d1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        d2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        d3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        d4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        d5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        e1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        e2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        e3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        e4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        e5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        for (int i=0; i<25; i++){
            if (!player) getMove();
            else{
                //toast for player to move
            }

        }


    }
}

/******** THIS WONT WORK BECAUSE THE I AND J ARE STATIC SO THE CODE
CREATES THE BUTTONS AND THEN ASSIGNS THE FINAL VALUE OF I AND J TO 
THE COORDINATES WE ARE USING. WE CANNOT USE DYNAMIC INTEGERS IN CREATION OF onClickLister.****************/


/*int [][] ref = new int[][]{};
for(i=0; i<4; i++){
for ( j=1; j<4; j++){
grid[i][j] = new Button(this); //(Button) findViewById(R.id.(grid[0][0]));
(grid[i][j]).setId(i+1);

final int index = i;
(grid[i][j]).setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View view) {
if (moves[i][j] ==0){
(grid[i][j]).setText("O");
moves[i][j] = 1;
getMove();

}
Log.d("Counting Loops", "" + counter);
}
});
//dynamicview.addView(grid[i][j]);
++counter;}
}*/



