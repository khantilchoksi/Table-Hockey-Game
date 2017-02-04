//Developed by Alaukika, Khantil, Bhavik
#include <graphics.h>
#include <dos.h>
#include<ctype.h>
#include <time.h>
#include<stdlib.h>
#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

void score1(void);
void textcolor(int color);
void start(void);


int level=0,flag=0;
int scoreA=0,scoreB=0;




struct block
{
	int length;
	int width;
	int xcoordinate;
	int ycoordinate;
}bl1;

struct bat
{
	int length;
	int width;
	int xcoordinate;
	int new_ycoordinate;
	int old_ycoordinate;
}batA, batB; // Create Two Bats For Each User.

struct ball
{
	int radius;
	int speedx;
	int speedy;
	int old_xcenter;
	int old_ycenter;
	int new_xcenter;
	int new_ycenter;
}ball1;

struct score
{
	int score_A;
	int score_B;
}score_game;


void fflushstdin( char c )
{
	while( (c = fgetc( stdin )) != EOF && c != '\n' );
}


// welcome method---------------------------------------------------------------------------------------------------

void welcome()
{

	int gdriver = DETECT, gmode;
	closegraph();
	initgraph(&gdriver, &gmode, "..\\bgi");

	// Intializes Graphics
	int i,j=0, k=0, x,y,co,b ;

	//setcolor(RED);
	//rectangle(50,50,500,400);
	for(i=0;i<3;i++)
	{
		setcolor(pow(2,i));
		rectangle(50+(2*j),80+(2*k),600-(2*j),400-(2*j));
		delay(50);
		j += 5;
		k += 5;
	}
	setcolor(WHITE);
	settextstyle(7,0,6);
	outtextxy(125,200,"TABLE HOCKEY");
	while(!kbhit())
	{
	  //	goto read;
	}
	cleardevice();
	getch();
	//cin.get();
	setbkcolor(WHITE);

	setcolor(7);
	while(!kbhit())
	{

		setcolor(BLUE);
		settextstyle(3,0,3);
		outtextxy(50,50,"F.S. B.E IV COMPUTER SCIENCE 2016-17 BATCH");
		outtextxy(150,120,"Computer Graphics Project ");
		settextstyle(3,0,1);
		outtextxy(130,150,"-----------------------------");
		settextstyle(3,0,2);
		setcolor(CYAN);
		outtextxy(170,240,"Khantil Choksi   - 704006");
		outtextxy(170,280,"Alaukika Diwanji - 704011");
		outtextxy(170,320,"Bhavik Vagadia - 704049");
		/*x=random(750);
		y=random(450);
		co=random(12);
		b=random(12);
		setcolor(b);
		setfillstyle(7,co);
		circle(x,y,5);
		floodfill(x,y,b);
		delay(50);*/
	}
	getch();
}



//select method------------------------------------------------------------------------------------------------------------------
void select()
{
	int gdriver = DETECT, gmode;
	closegraph();
	initgraph(&gdriver, &gmode, "..\\bgi");

	cleardevice();


	//while(!kbhit())
	//{
	settextstyle(3, HORIZ_DIR, 2);
	outtextxy(130,100," WELCOME TO TABLE HOCKEY WORLD!\n\n") ;
	outtextxy(130,140,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	outtextxy(130,200,"Enter 'S' to Start Game       ");
	outtextxy(130,240,"Enter 'H' for Help            ");
	outtextxy(130,280,"Enter 'Q' to Quit             ");
	//outtextxy(130,320,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	//outtextxy(130,380,"Player A - Press W to go up - Press S to go down");
	//outtextxy(130,400,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	//outtextxy(130,420,"Player B - Press Up arrow to go up - Press Down arrow to go down");


	//}
}


//help method-------------------------------------------------------------------------------------------------------
void help()

{int gdriver = DETECT, gmode;
closegraph();
initgraph(&gdriver, &gmode, "..\\bgi");
cleardevice();
do
{
	setcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(70,80,"This is a 2 player game with following controls:");
	setcolor(WHITE);
	outtextxy(70,120,"Player A ");
	setcolor(GREEN);
	outtextxy(70,150,"W - Move Paddle Up");
	outtextxy(70,180,"S - Move Paddle Down");
	setcolor(WHITE);
	outtextxy(70,220,"Player B");
	setcolor(GREEN);
	outtextxy(70,250,"Up Arrow- Move Paddle Up");
	outtextxy(70,280,"Down Arrow- Move Paddle Down");
	setcolor(WHITE);
	outtextxy(70,340,"PRESS 'S' TO START, 'Q' TO QUIT");
}while(!kbhit());
}





//initialize method---------------------------------------------------------------------------------------------------------
void initialize() // Initialize the game.

{
	int gdriver = DETECT, gmode;
	char ch;
	char tempstring [10]; //This String holds score in char format temporarily
	time_t t;// Used to generate random number from system time.
	//Initialise Bat A

	closegraph();
	initgraph(&gdriver, &gmode, "..\\bgi");

	if(score_game.score_A==5 || score_game.score_B==5)
	{
		level=1;

	}
	if(score_game.score_A>14 || score_game.score_B>14 )
	{
		level=2;
	}
	if(score_game.score_A >= 30 ||  score_game.score_B >= 30)
	{
		//Player A or B has won the Game!
		score1();
		start();

	}

	if(level==1 && flag!=1)
	{
		flag=1;
		settextstyle(3,0,1);
		outtextxy(280,220,"LEVEL 1 CLEARED");
		delay(1500);


		cleardevice();
	}


	if(level==2 && flag!=2)
	{
		flag=2;

		settextstyle(3,0,1);
		outtextxy(280,220,"LEVEL 2 CLEARED");
		delay(1500);
		cleardevice();

	}

	//Borders
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);

	//Top edge
	rectangle(30,10,616,18);
	floodfill(60,15, LIGHTGRAY);

	//Bottom edge
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	rectangle(30,432,616,440);
	floodfill(50,435, LIGHTGRAY);

	//Left edge
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	rectangle(30,10,38,440);
	floodfill(32,50, LIGHTGRAY);

	//Right edge
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	rectangle(608,10,616,440);
	floodfill(612,50, LIGHTGRAY);

	// Intialize block
	bl1.length=60;
	bl1.width=60;
	bl1.xcoordinate=280;
	bl1.ycoordinate=230;

	// Intialise Bat A
	batA.length = 60;
	batA.width = 6;
	batA.xcoordinate = 40;
	batA.new_ycoordinate = 260;
	batA.old_ycoordinate = 260;

	// Intialise Bat B
	batB.length = 60;
	batB.width = 6;
	batB.xcoordinate = 600;
	batB.new_ycoordinate = 260;
	batB.old_ycoordinate = 260;


	// Intialise Ball
	ball1.radius = 5;
	ball1.speedx = 2;
	if(level==1 || level==2)
	{
		ball1.speedx=3;
	}
	srand((int) time(&t)); // Seed rand a random number
	ball1.speedy = rand ()%2;// Sets speed from 0 to 2 depending upon remainder.


	if (rand() % 2 == 0)
	{
		ball1.speedx = - ball1.speedx; // Generate Random X direction.
		ball1.speedy = - ball1.speedy; // Generate Random Y direction.
	}
	ball1.old_xcenter = 320;
	ball1.old_ycenter = 300;
	ball1.new_xcenter = 320;
	ball1.new_ycenter = 300;

	// Set Background to white
	setbkcolor (BLACK);

	// Draw Ball at Initial Position
	setfillstyle (1,BLUE);
	//---int x,int y,int xrad,int yrad
	fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);

	// Draw Bats at Intial Position
	//--left,top,right,bottom
	bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
	setfillstyle(1, RED);
	bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
	if(level==2)
	{
		bar (bl1.xcoordinate,bl1.ycoordinate,bl1.xcoordinate+bl1.width,bl1.ycoordinate+bl1.length);
	}


	// Display Score
	textcolor (15);
	settextstyle(1,0,1);
	sprintf (tempstring," %d",score_game.score_A);
	outtextxy (30,450,"A - ");
	outtextxy (58,450,tempstring);

	sprintf (tempstring," %d",score_game.score_B);
	outtextxy (565,450,"B - ");
	outtextxy (592,450,tempstring);

	setcolor(WHITE);
	sprintf (tempstring, "%d", level+1);
	outtextxy (280,450,"Level - ");
	outtextxy (350,450,tempstring);
	// outtextxy (40,472,"Remove This Line by Learn Coding It yourself at www.cencyclopedia.com");


}



//movebat method-----------------------------------------------------------------------------------------------
void movebat (char input)

{
	switch (input)
	{
	case 'W' :
		if (batA.new_ycoordinate > 20) // Move only when bat is not touching the top so it doesnt jump out of screen.
		{
			batA.old_ycoordinate = batA.new_ycoordinate;
			batA.new_ycoordinate --;
			batA.new_ycoordinate --;
			setfillstyle (1,0); // Remove last postion.
			bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
			setfillstyle (1,BLUE); // Display New postion.
			bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
		}
		break;

	case 'S' :
		if (batA.new_ycoordinate+batA.length < 430) // Make sure bat doesnot go below the screen.
		{
			batA.old_ycoordinate = batA.new_ycoordinate;
			batA.new_ycoordinate ++;
			batA.new_ycoordinate ++;
			setfillstyle (1,0); // Remove last postion.
			bar (batA.xcoordinate,batA.old_ycoordinate,batA.xcoordinate+batA.width,batA.old_ycoordinate+batA.length);
			setfillstyle (1,BLUE); // Display New postion.
			bar (batA.xcoordinate,batA.new_ycoordinate,batA.xcoordinate+batA.width,batA.new_ycoordinate+batA.length);
		}
		break;
	case 'U' :  //up arrow key for player B
		if (batB.new_ycoordinate > 20) // Move only when bat is not touching the top so it doesnt jump out of screen.
		{
			batB.old_ycoordinate = batB.new_ycoordinate;
			batB.new_ycoordinate --;
			batB.new_ycoordinate --;
			setfillstyle (1,0); // Remove last postion.
			bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
			setfillstyle (1,RED); // Display New postion.
			bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
		}
		break;

	case 'D' : //down arrow key for Player B
		if (batB.new_ycoordinate+batB.length < 430) // Make sure bat doesnot go below the screen.
		{
			batB.old_ycoordinate = batB.new_ycoordinate;
			batB.new_ycoordinate ++;
			batB.new_ycoordinate ++;
			setfillstyle (1,0); // Remove last postion.
			bar (batB.xcoordinate,batB.old_ycoordinate,batB.xcoordinate+batB.width,batB.old_ycoordinate+batB.length);
			setfillstyle (1,RED); // Display New postion.
			bar (batB.xcoordinate,batB.new_ycoordinate,batB.xcoordinate+batB.width,batB.new_ycoordinate+batB.length);
		}
		break;
	}

}


//score1 method------------------------------------------------------------------------------------------------------
void score1()
{
	int gdriver = DETECT, gmode;
	char ch;
	char ascore [5] =" ";
	char bscore[5] = " ";
	closegraph();
	initgraph(&gdriver, &gmode, "..\\bgi");

	setcolor(WHITE);
	rectangle(30,30,600,130);

	settextstyle(3,0,1);
	outtextxy(250,40,"GAME OVER!");

	sprintf(ascore," %d", score_game.score_A);
	outtextxy(200,70,"Score of Player A -  ");
	outtextxy(380,70, ascore);

	sprintf(bscore," %d", score_game.score_B);
	outtextxy(200,100,"Score of Player B -  ");
	outtextxy(380,100, bscore);
	outtextxy(250,300,"THANK YOU!");

	rectangle(30,170,600,270);


	if(score_game.score_A >  score_game.score_B)
	{
		do
		{
			settextstyle(3,0,1);
			outtextxy(190,190,"PLAYER A WON THE GAME.");
			outtextxy(180,220,"PRESS ENTER KEY TO RESTART.");
		}while(!kbhit());
		fflushstdin( ch );
		return;
	}
	else
	{

		do
		{
			settextstyle(3,0,1);
			outtextxy(190,190,"PLAYER B WON THE GAME.");
			outtextxy(180,220,"PRESS ENTER KEY TO RESTART");
		}while(!kbhit());
		fflushstdin(ch);
		return;
	}

}


// moveball method ---------------------------------------------------------------------------------------------
void moveball ()
{
	ball1.old_xcenter = ball1.new_xcenter;
	ball1.old_ycenter = ball1.new_ycenter;
	ball1.new_xcenter = ball1.new_xcenter + ball1.speedx;
	ball1.new_ycenter = ball1.new_ycenter + ball1.speedy;
	setcolor (0);
	setfillstyle (1,0); // Remove last postion.
	fillellipse (ball1.old_xcenter,ball1.old_ycenter,ball1.radius,ball1.radius);
	setfillstyle (1,15); // Display New postion.
	fillellipse (ball1.new_xcenter,ball1.new_ycenter,ball1.radius,ball1.radius);
	// Reflect From Top
	if ( ball1.new_ycenter - ball1.radius < 20 )
		ball1.speedy = -ball1.speedy;

	// Reflect From Bottom
	if ( ball1.new_ycenter + ball1.radius > 430 )
		ball1.speedy = -ball1.speedy;

	if(level==2)
	{
		if(ball1.new_ycenter + ball1.radius >225 && ball1.new_ycenter - ball1.radius <295 && ball1.new_xcenter + ball1.radius>280 && ball1.new_xcenter - ball1.radius<340)
			ball1.speedy = -ball1.speedy;
		if(ball1.new_xcenter + ball1.radius > 275 && ball1.new_xcenter - ball1.radius < 345 && ball1.new_ycenter - ball1.radius <290 && ball1.new_ycenter + ball1.radius >230)
			ball1.speedx= -ball1.speedx;
	}
}


//physics method ------------------------------------------------------------------------------------------------------
void physics ()

{
	char tempstring [10];
	if ( ball1.new_xcenter - ball1.radius <= 49)
	{
		if (ball1.new_ycenter > batA.new_ycoordinate && ball1.new_ycenter < batA.new_ycoordinate+batA.length)
		{
			ball1.speedx = - ball1.speedx;
			ball1.speedy = rand () % 2;
			// Sets speed from 0 to 2 depending upon remainder.
			if (rand() % 2 == 0) ball1.speedy = - ball1.speedy; // Generate Random Y direction.
		}
		else // Reintialize entire game with new score
		{
			if(level==1 )
			{score_game.score_B ++;
			}
			if(level==2 )
			{score_game.score_B ++;
			score_game.score_B ++;
			}
			score_game.score_B ++;
			initialize();

			return;
		}
	}

	if ( ball1.new_xcenter +  ball1.radius > 593)

	{
		if (ball1.new_ycenter > batB.new_ycoordinate && ball1.new_ycenter < batB.new_ycoordinate+batB.length)
		{
			ball1.speedx = - ball1.speedx;
			ball1.speedy = rand ()%2;// Sets speed from 0 to 2 depending upon remainder.
			if (rand() % 2 == 0) ball1.speedy = - ball1.speedy; // Generate Random Y direction.
		}
		else // Reintialize game with new score
		{
			if(level==1)
			{

				score_game.score_A ++;

			}

			if(level==2)
			{

				score_game.score_A ++;
				score_game.score_A ++;

			}
			score_game.score_A ++;
			initialize ();
			return;
		}

	}

}



//play method -----------------------------------------------------------------------------------------------------------------
void play ()
{
	// Check wether key press is Q if so exit loop
	while (inportb (0X60) != 16)

	{
		delay (10); // Reduce game speed to human playable level
		if (inportb (0X60) == 17)  movebat ('W');
		if (inportb (0X60) == 31)  movebat ('S');
		if (inportb (0X60) == 72)  movebat ('U');
		if (inportb (0X60) == 80)  movebat ('D');
		moveball ();
		physics ();
	}
}

//start method ---------------------------------------------------------------------------------------------------------------
void start()
{

	char choice=' ';
	level=0;
	flag=0;
	score_game.score_A = 0;// Intialise score in Main This Time
	score_game.score_B = 0;// It improves Efficiency
	cleardevice();
	fflushstdin( choice );
	do
	{
		select();
		choice=toupper(getch());
		if(choice=='S')
		{
			initialize ();
			play();
		}
		else if(choice=='H')
		{
			help();

		}

	}while(choice=='H');
}



//main method -------------------------------------------------------------------------------------------------------------
int main ()

{
	welcome();
	start();

	return 0;
}

