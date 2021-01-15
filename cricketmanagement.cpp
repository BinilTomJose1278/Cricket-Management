# include <fstream.h>
# include <stdio.h>
# include <string.h>
# include <process.h>
# include <conio.h>
class cricketmanager
{
private:
floatbatavg();
struct cricket
{
intruns,innings,notout,wickets;
char skill[20];
longPlayercode;
char country[50];
charPlayername[50];
floatbattingavg;
}c;
public:
voidCreatePlayer();
void Display();
void Search();
void Modifications();
void Deletion();
voidAddPlayers();
}M;
/*===============INTRODUCTION===============*/



void introduction()
{
charch;
clrscr();
do
{
cout<<"\n\n";
cout<<"\t ###################################################### \n";
cout<<"\t ************ ************ \n";
cout<<"\t ***** WELCOME TO ***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** !!!!CRICKET MANAGEMENT SYSTEM!!!! ***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** PROGRAMMED BY:- ***** \n";
cout<<"\t ***** --------------- ***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** ===> BINIL TOM JOSE***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** =======> Class XII - A ***** \n";
cout<<"\t ***** ***** \n";
cout<<"\t ***** UNITED INDIAN  SCHOOL ***** \n";
cout<<"\t ************ KUWAIT ************ \n";
cout<<"\t ###################################################### \n";




cout<<"\n Do you Want to go to the Main Menu?(y/n)";
cin>>ch;
}
while(ch =='n'|| ch=='N');
}
/*---------------Calculation of average Batting rate---------------*/
floatcricketmanager::batavg()
{
float a;
a = (c.runs/c.innings);
return a;
}
/*---------------Create Player'S BIO-DATA---------------*/
voidcricketmanager::CreatePlayer()
{
char ch3;
fstream P1;
P1.open("Player.dat",ios::out|ios::binary);
do
{
cout<<"\n Enter the Player's Code ===> ";
cin>>c.Playercode;
cout<<"\n Enter the Player's name ===> ";
gets(c.Playername);






cout<<"\n Enter the Player's Skill ===> ";
gets(c.skill);
cout<<"\n Enter the Player's number of runs ===> ";
cin>>c.runs;
if (strcmpi(c.skill,"Bowler")==0)
{
cout<<"\n Enter the Player's number of wickets ===> ";
cin>>c.wickets;
}
cout<<"\n Enter the Player's number of not outs ===> ";
cin>>c.notout;
cout<<"\n Enter the Player's number of innings played ===> ";
cin>>c.innings;
c.battingavg = batavg();
P1.write((char *)&c,sizeof(c));
cout<<"\n Do you want to add more players (y/n)?";
cin>>ch3;
}
while((ch3=='y') || (ch3=='Y'));
P1.close();
}
/*---------------DISPLAY PLAYER'S BIO-DATA---------------*/
voidcricketmanager::Display()
{
fstream file;




file.open("player.dat",ios::in|ios::binary);
file.read((char *)&c,sizeof(c));
clrscr();
while(!file.eof())
{
cout<<"\n Player's Name ===> ";
puts(c.Playername);
cout<<"\n Player's Code ===> "<<c.Playercode;
cout<<"\n Player's Skill ===> "<<c.skill;
cout<<"\n Player's number of not outs ===>"<<c.notout;
cout<<"\n Player's Runs ===> "<<c.runs;
if(strcmpi(c.skill,"Bowler")==0)
cout<<"\n Player's number of wickets ===>"<<c.wickets;
cout<<"\n Player's number of innings played ===>"<<c.innings;
cout<<"\n Player's Average Rate ===> "<<c.battingavg;
cout<<"\n \n";
cout<<"\n Press Enter to go back to SCM Main Menu!";
getch();
clrscr();
file.read((char *)&c,sizeof(c));
}
file.close();
}
/*---------------SEARCH A REQUIRED PLAYER'S BIO-DATA---------------*/
voidcricketmanager::Search()
{



fstream f1;
longsearchcode;
int A=0;
clrscr();
cout<<"\n enter the player's code to search the particular record: ";
cin>>searchcode;
f1.open("player.dat",ios::in|ios::binary);
f1.read((char*)&c,sizeof(c));
while(!f1.eof())
{
if(c.Playercode==searchcode)
{
cout<<"\n Player's Code ===> "<<c.Playercode;
cout<<"\n Player's Name ===> "<<c.Playername;
cout<<"\n Player's Skill ===> "<<c.skill;
cout<<"\n Player's Number Of Runs ===> "<<c.runs;
cout<<"\n Player's Number Of Not Outs ===> "<<c.notout;
cout<<"\n player's Number Of Wickets ===> "<<c.wickets;
cout<<"\n Player's Number Of Innings Played ===> "<<c.innings;
cout<<"\n Player's Average Rate ===> "<<c.battingavg;
cout<<"\n Press enter to go to SCM Main Menu...";
A=1;
getch();
break;
}
f1.read((char *)&c,sizeof(c));
}
f1.close();

if (A==0)
{
cout<<"\n Player Does Not Exist In Your Team";
cout<<"\n Press Enter To Go Back To SCM Main Menu....";
getch();
}
}
/*----------------MODIFY A PLAYER'S BIO-DATA BASED ON ITS CODE---------------*/
voidcricketmanager::Modifications()
{
fstreamf,t;
long code;
clrscr();
cout<<"\n Enter the player's Code To Modify Record : ";
cin>>code;
t.open("temp.dat",ios::out|ios::binary);
f.open("player.dat",ios::in|ios::binary);
f.read((char*)&c,sizeof(c));
while(!f.eof())
{
if (c.Playercode==code)
{
cout<<"\n Enter the Player's Code ==> ";
cin>>c.Playercode;
cout<<"\n Enter the Player's Name ==> ";





gets(c.Playername);
cout<<"\n Enter the Player's Skill ==> ";
cin>>c.skill;
if(strcmpi(c.skill,"Bowler")==0)
{
cout<<"\n Enter the Player's Number Of Wickets ===> ";
cin>>c.wickets;
}
cout<<"\n Enter the Player's Number Of Runs ==> ";
cin>>c.runs;
cout<<"\n Enter the Player's Number of Innings Played ==> ";
cin>>c.innings;
cout<<"\n Enter the Player's Number Of Not Outs ==> ";
cin>>c.notout;
c.battingavg = batavg();
}
t.write((char *)&c,sizeof(c));
f.read((char *)&c,sizeof(c));
}
t.close();
f.close();
remove("player.dat");
rename("temp.dat","player.dat");
}
/*---------------DELETE/REMOVE A PLAYER'S BIO-DATA BASED ON ITS CODE FROM THE TEAM---------------*/




voidcricketmanager::Deletion()
{
fstreamf,t;
long code;
clrscr();
cout<<"\n Enter the Player's Code To Delete ==> ";
cin>>code;
t.open("temp.dat",ios::out|ios::binary);
f.open("player.dat",ios::in|ios::binary);
f.read((char*)&c,sizeof(c));
while(!f.eof())
{
if (c.Playercode!=code)
t.write((char*)&c,sizeof(c));
f.read((char*)&c,sizeof(c));
}
f.close();
t.close();
cout<<"\n Player's Bio-data Successfully Deleted!!";
getch();
remove("player.dat");
rename("temp.dat","player.dat");
}
/*---------------ADD PLAYER'S BIO-DATA TO THE FILE(BOTTOM)---------------*/
voidcricketmanager::AddPlayers()
{
fstream f;
char choice2;

clrscr();
f.open("player.dat",ios::app|ios::binary);
do
{
cout<<"\n Enter the Player's Code ==> ";
cin>>c.Playercode;
cout<<"\n Enter the Player's Name ==> ";
gets(c.Playername);
cout<<"\n Enter the Player's Skill ==> ";
cin>>c.skill;
cout<<"\n Enter the Player's Number Of Runs ==> ";
cin>>c.runs;
cout<<"\n Enter the Player's Number of Innings Played ==> ";
cin>>c.innings;
if(strcmpi(c.skill,"Bowler")==0)
{
cout<<"\n Enter the Player's number of wickets ==> ";
cin>>c.wickets;
}
cout<<"\n Enter the Player's Number Of Not Outs ==> ";
cin>>c.notout;
c.battingavg = batavg();
cout<<"\n Do You Want To Add More Player Records?(yes/No)";
cin>>choice2;
}
while(choice2 == 'Y'||choice2 == 'y');
}
/*---------------MAIN PROGRAM---------------*/

void main()
{
introduction();
clrscr();
int ch4;
do
{
clrscr();
cout<<"\n WELCOME TO SCM MAIN MENU ";
cout<<"\n 1 ==> Create A New Player's Record.";
cout<<"\n 2 ==> Display A Player's Record.";
cout<<"\n 3 ==> Search A Player's Record.";
cout<<"\n 4 ==> Modify A Player's Record.";
cout<<"\n 5 ==> Delete A Player's Record.";
cout<<"\n 6 ==> Add Player Records (Bottom).";
cout<<"\n 7 ==> Exit The SCM Main Menu! \n";
cout<<"\n Enter Your Desired Choice ==> ";
cin>>ch4;
switch(ch4)
{
case 1:M.CreatePlayer();
break;
case 2:M.Display();
break;
case 3:M.Search();
break;
case 4:M.Modifications();
break;

case 5:M.Deletion();
break;
case 6:M.AddPlayers();
break;
case 7:{
cout<<"\n THANK YOU FOR USING OUR MANAGEMENT SERVICE!!!!!";
cout<<"\n FOR FURTHER INFORMATION";
cout<<"\n VISIT OUR WEBSITE";
cout<<"\n http://www.facebook.com/l/6fb43YlV58X8QOtJXQZ39Pxm5Iw;www.cricketmanagement.com";
cout<<"\n THIS IS NOT A JOKE!!!!";
cout<<"\n CONGRATULATIONS!!!!";
cout<<"\n YOU HAVE WON 10,000,000 DOLLARS!!";
cout<<"\n CLICK HERE to claim your prize!";
cout<<"\n *************************************************";
exit(0);
}
}
}
while(ch4 >0 && ch4 < 8);
}
