#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
enum eDir{STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
class cb
{
private:
	int x, y;
	int orix, oriy;
	eDir direction;
public:
	cb(int Posx, int Posy)
	{
		orix = Posx;
		oriy = Posy;
		x = Posx;
		y = Posy;
		direction = UPRIGHT;

	}
	void reset()
	{
		x = orix;
		y = oriy;
		direction = STOP;
	}
	void changed(eDir d)
	{
		direction = d;
	}
	void random()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getx() { return x; }
	inline int gety() { return y; }
	inline eDir getd() { return direction; }
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		case UPRIGHT:
			y--; x++;
			break;


		}




	}
	void print()
	{

	    cout<<x<<y<<direction<<endl;
	}



};
class paddle
{
private:
    int x,y;
    int orix,oriy;
public:
    paddle()
    {

        x=0;
        y=0;
    }
    paddle(int a,int b)
    {
        orix=a;
        oriy=b;
        x=a;
        y=b;

    }
    void reset(){

    x=orix;y=oriy;}
 int getx(){
 return x;}
int gety(){
return y;}
void moveu()
{

    y--;

}
void moved()
{

    y++;
}
void print()
{

    cout<<x<<y<<endl;
}
};
class game
{
private:
    int w,h;
    int score1,score2;
    char u1,d1,u2,d2;
    bool quit;
    cb *ball;
    paddle *p1;
    paddle *p2;
public:
    game(int w1,int h1)
    {

        w=w1;
        h=h1;
        quit=false;
        u1='w'; u2='i';
        d1='s'; d2='k';
        score1=score2=0;
        ball = new cb(w/2,h/2);
        p1= new paddle(1,h/2-3);
        p2=new paddle(w-2,h/2-3);
    }
    ~game()
    {

        delete ball,p1,p2;
    }
    void scoreup(paddle *ptr)
    {

        if(ptr==p1)
            score1++;
        else if(ptr==p2)
            score2++;
        ball->reset();
        p1->reset();
        p2->reset();
    }
    void Draw()
{
    system("cls");
    for(int i=0;i<w+2;i++)
        cout<<"#";
     cout<<endl;
     for(int i=0;i<h;i++)
     {
         for(int j=0;j<w;j++)
         {

             int ballx= ball->getx();
             int bally=ball->gety();
             int pl1x=p1->getx();
             int pl1y=p1->gety();
             int pl2x=p2->getx();
             int pl2y=p2->gety();
             if(j==0)
                cout<<"#";
             if(ballx==j && bally==i)
                cout<<"O";
             else if(pl1x==j && pl1y==i)
             cout<<"\xDB";
             else if(pl1x==j && pl1y+1==i)
             cout<<"\xDB";
             else if(pl1x==j && pl1y+2==i)
             cout<<"\xDB";
             else if(pl1x==j && pl1y+3==i)
             cout<<"\xDB";
              else if(pl2x==j && pl2y==i)
             cout<<"\xDB";
              else if(pl2x==j && pl2y+1==i)
             cout<<"\xDB";
              else if(pl2x==j && pl2y+2==i)
             cout<<"\xDB";
              else if(pl2x==j && pl2y+3==i)
             cout<<"\xDB";


             else
                cout<<" ";

             if(j==w-1)
                cout<<"#";
         }

cout<<endl;
     }
     for(int i=0;i<w+2;i++)
                cout<<"#";
                cout<<endl;

 cout<<score1<<" "<<score2;
}
void input()
{
 ball->Move();
    int ballx= ball->getx();
             int bally=ball->gety();
             int pl1x=p1->getx();
             int pl1y=p1->gety();
             int pl2x=p2->getx();
             int pl2y=p2->gety();
             if(_kbhit())
             {
                 char current=_getch();
                 if(current==u1)
                    if(pl1y>0)
                    p1->moveu();
                 if(current==u2)
                    if(pl2y>0)
                    p2->moveu();
                 if(current==d1)
                    if(pl1y+4<h)
                    p1->moved();
                 if(current==d2)
                 {
                     if(pl2y+4<h)
                        p2->moved();
                     }
                 if(ball->getd()==STOP)
                 {

                     ball->random();

                 }
                 if(current=='q')
                    quit=true;
             }


}
void logic()
{
    int ballx= ball->getx();
             int bally=ball->gety();
             int pl1x=p1->getx();
             int pl1y=p1->gety();
             int pl2x=p2->getx();
             int pl2y=p2->gety();

    for(int i=0;i<4;i++)
    {

        if(ballx==pl1x+1)
            if(bally==pl1y+i)
            ball->changed((eDir)((rand()%3)+4));
    }
    for(int i=0;i<4;i++)
    {

        if(ballx==pl2x-1)
            if(bally==pl2y+i)
            ball->changed((eDir)((rand()%3)+1));
    }
    if(bally==h-1)
        ball->changed(ball->getd()==DOWNRIGHT?UPRIGHT : UPLEFT);
    if(bally==0)
        ball->changed(ball->getd()==UPRIGHT?DOWNRIGHT : DOWNLEFT);
        if(ballx==0)
            scoreup(p2);
        if(ballx==w-1)
           scoreup(p1);
}
void run()
{


    while(!quit)
    {

        Draw();
        input();
        logic();
    }
}

};
int main()
{

game g(40,20);
g.run();



}

