#include <iostream>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
// Function prototypes
void gotoxy(int x, int y);
void color1(int color1);
void Hide_Cursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void main_menu();          // Game header
void menu();               // Game Option
void left_right_side();    // print Maze left right side
void up_down_side();       // print maze up down side
void wall_1(int);          // print wall1
void wall_2(int);          // print wall2
void wall_3(int);          // print wall3
void wall_4(int);          // print wall4
void wall_5(int);          // print wall5
void Reward(int x, int y); // print dollors
void game_Maze1();
void loading();
void starting_page();
char getCharAtxy(short int x, short int y);
void print_bird();
void erase_bird();
void move_bird_up();
void move_bird_down();
void move_bird_right();
void move_bird_left();
void generateBullet();
void makeBulletInactive(int index);
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void moveBullet();
void bird_energy();
void print_enemy1();
void erase_enemy1();
void move_enemy1();
void generate_Enemy1_Bullet();
void move_Enemy1_Bullet();
void makeBulletInactive1(int index);
void print_enemy1_Bullet(int x, int y);
void erase_enemy1_Bullet(int x, int y);
void print_last_enemy();
void erase_last_enemy();
void move_last_enemy();
void generate_last_Enemy_Bullet();
void move_last_Enemy_Bullet();
void makeBulletInactive2(int index);
void print_last_enemy_Bullet(int x, int y);
void erase_last_enemy_Bullet(int x, int y);
void total_score();
void last_enemy_energy();
void bullet_collision_with_enemy();
void clear_last_enemy_energy();
void clear_bird_energy();
void hide_last_enemy_energy();
void store_coordinates();
string getField(string record, int field);
void read_data_from_file();
void press();
void help(); // instructions
void high_score();
void store_high_score();
void read_score_from_file();
void key_instructions();
void game_Maze2();
void story(); // game story

// Arrays + variables
char bird[4][8] = {{' ', ' ', ' ', ' ', '_', '_', ' ', ' '},
                   {'_', '_', '_', '(', ' ', 'o', ')', '>'},
                   {'\\', ' ', '<', '_', '.', ' ', ')', ' '},
                   {' ', '`', '-', '-', '-', '`', '.', ' '}};
int birdX = 6;
int birdY = 10;
char enemy1[3][3] = {{'(', '|', ')'},
                     {' ', '|', ' '},
                     {' ', '!', ' '}};
int enemy1X = 60;
int enemy1Y = 6;

string last_enemy[7][1] = {{"          /')"}, {"  ////  /' )'"}, {" @   \\/'  )'"}, {"< (  (_...)'"}, {"  \\      )"}, {"   \\,,,,/"}, {"     _|_"}};
int last_enemyX = 150;
int last_enemyY = 10;
const int size = 10000;
int bulletX[size];
int bulletY[size];
bool isBulletActive[size];
int enemy1_bulletX[size];
int enemy1_bulletY[size];
bool isenemy1_bulletActive[size];
bool islastenemy_bulletActive[size];
int last_enemy_bulletX[size];
int last_enemy_bulletY[size];
int main_Menu_Count = 0;

int level = 1; // current level
int enemy1_Bullet_Count = 0;
int last_enemy_Bullet_Count = 0;
string enemy1_direction = "Right";
string last_enemy_direction = "Up";
int bulletCount = 0; // bird bullet count
char wall = 219;     // to print wall special symbol
char ch1 = 179;      // to print maze left right side special symbol
char ch2 = 196;      // to print maze up down side symbol
char reward = 36;    // dollor
char bullet = 248;   // all bullets symbol
int bird_Energy = 10;
int enemy_energy = 100;
int timer = 0;  // control enemy1 energy
int timer2 = 0; // control enemy2 energy
int score = 0;
int High_score = 0;
char ch = 244; // to separate values in file symbol
bool level_check = true;
main()
{
    system("cls");
    read_data_from_file();
    read_score_from_file();
    starting_page();
    system("cls");
    main_menu();
    Hide_Cursor();
    while (true)
    {

        main_menu();
        menu();

        if (GetAsyncKeyState(VK_UP))
        {
            if (main_Menu_Count == 0)
            {
                main_Menu_Count = 3;
            }
            else
            {
                main_Menu_Count--;
            }
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (main_Menu_Count == 3)
            {
                main_Menu_Count = 0;
            }
            else
            {
                main_Menu_Count++;
            }
            Sleep(300);
        }

        if (GetAsyncKeyState(VK_RETURN))
        {
            if (main_Menu_Count == 0 && GetAsyncKeyState(VK_RETURN))
            {

                loading();

                while (true)
                {
                    if (level == 1 && level_check == true)
                    {
                        game_Maze1();
                        level_check = false;
                    }
                    if (level == 2 && level_check == true)
                    {

                        game_Maze2();
                        level_check = false;
                    }
                    print_bird();
                    print_enemy1();
                    bird_energy();

                    Sleep(100);
                    key_instructions();
                   
                    total_score();
                    high_score();
                    if (GetAsyncKeyState(VK_UP))
                    {
                        move_bird_up();
                    }
                    if (GetAsyncKeyState(VK_DOWN))
                    {
                        move_bird_down();
                    }
                    if (GetAsyncKeyState(VK_RIGHT))
                    {
                        move_bird_right();
                    }
                    if (GetAsyncKeyState(VK_LEFT))
                    {
                        move_bird_left();
                    }
                    if (GetAsyncKeyState(VK_SPACE))
                    {
                        generateBullet();
                    }
                    if (GetAsyncKeyState(VK_ESCAPE))
                    {
                        level_check = true;
                        level = 1;
                        score = 0;
                        birdX = 6;
                        birdY = 10;
                        bird_Energy = 10;
                        enemy_energy = 100;
                        system("cls");

                        break;
                    }
                    if (GetAsyncKeyState(VK_TAB))
                    {
                        store_coordinates();
                    }
                    if (timer == 10)
                    {

                        generate_Enemy1_Bullet();

                        timer = 0;
                    }

                    timer++;
                    move_Enemy1_Bullet();

                    moveBullet();
                    move_enemy1();
                    if (birdX >= 100)
                    {
                        if (timer2 == 15)
                        {
                            generate_last_Enemy_Bullet();
                            timer2 = 0;
                        }
                        timer2++;
                        last_enemy_energy();
                        print_last_enemy();
                        move_last_enemy();
                    }
                    move_last_Enemy_Bullet();
                    if (birdX <= 100)
                    {
                        hide_last_enemy_energy();
                        erase_last_enemy();
                    }

                    if (bird_Energy <= 0)
                    {
                        gotoxy(35, 39);
                        color1(6);
                        cout << "Your Score is:" << score;
                        color1(7);
                        gotoxy(35, 36);
                        color1(4);
                        cout << "Game Over";
                        color1(7);
                        
                        bird_Energy = 10;
                        level = 1;
                        level_check = true;
                        birdX = 6;
                        birdY = 10;
                        enemy_energy = 100;
                        if (score > High_score)
                        {
                            High_score = score;
                            store_high_score();
                             gotoxy(35, 41);
                             color1(10);
                            cout<<"You have set new High Score:"<<endl;
                            
                            color1(7);
                        }
                        score = 0;
                        Sleep(3000);

                        system("cls");
                        break;
                    }
                    if (enemy_energy <= 0)
                    {
                        if (level == 2)
                        {
                            level = 1;
                            level_check = true;
                          
                            color1(6);
                            gotoxy(35, 36);
                            cout << "Your Score is:" << score;
                            color1(7);
                            color1(5);
                            gotoxy(35, 38);
                            cout << "Congratulations You have Completed All Levels";
                            color1(7);
                            if (score > High_score)
                        { 
                            High_score = score;
                            store_high_score();
                             gotoxy(35, 40);
                             color1(10);
                            cout<<"You have set new High Score:"<<endl;
                              score = 0;
                        
                            color1(7);
                        }
                            Sleep(4500);
                            system("cls");
                            birdX = 6;
                            birdY = 10;
                            bird_Energy = 10;
                            enemy_energy = 100;
                            break;
                        }
                        level++;
                        level_check = true;

                        color1(6);
                        gotoxy(35, 40);
                        cout << "Level Complete"<<endl;
                        birdX = 6;
                        birdY = 10;
                        enemy_energy = 400;
                        bird_Energy=bird_Energy+10;
                        color1(7);
                        Sleep(3000);
                        system("cls");
                    }
                }
            }
            if (main_Menu_Count == 1 && GetAsyncKeyState(VK_RETURN))
            {
                system("cls");
                main_menu();
                story();
                system("cls");
            }
            if (main_Menu_Count == 2 && GetAsyncKeyState(VK_RETURN))
            {
                system("cls");
                main_menu();
                help();
                system("cls");
            }
            if (main_Menu_Count == 3 && GetAsyncKeyState(VK_RETURN))
            {
                system("cls");
                break;
            }
        }
    }
}
void store_high_score()
{
    fstream file;
    file.open("High score.txt", ios::out);
    file << High_score << ch;
    file.close();
}
void read_score_from_file()
{
    string record;
    fstream file;
    file.open("High score.txt", ios ::in);
    while (getline(file, record))
    {
        High_score = stoi(getField(record, 1));
    }
    file.close();
}

void store_coordinates()
{
    fstream file;
    file.open("Location.txt", ios::out);
    file << birdX << ch << birdY << ch << score << ch << bird_Energy << ch << enemy_energy << ch << level;
    file.close();
}
void read_data_from_file()
{
    string record;
    fstream file;
    file.open("Location.txt", ios ::in);
    while (getline(file, record))
    {

        birdX = stoi(getField(record, 1));
        birdY = stoi(getField(record, 2));
        score = stoi(getField(record, 3));
        bird_Energy = stoi(getField(record, 4));
        enemy_energy = stoi(getField(record, 5));
        level = stoi(getField(record, 6));
    }
    file.close();
}
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ch)
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void loading()
{
    color1(5);
    system("cls");
    gotoxy(75, 15);
    cout << "===========" << endl;
    gotoxy(75, 16);
    cout << "====   ====" << endl;
    gotoxy(75, 17);
    cout << "==   =   ==" << endl;
    gotoxy(75, 18);
    cout << "=   ===   =" << endl;
    gotoxy(75, 19);
    cout << "======   ==" << endl;
    gotoxy(75, 20);
    cout << "====    ===" << endl;
    gotoxy(75, 21);
    cout << "======   ==" << endl;
    gotoxy(75, 22);
    cout << "=   ===   =" << endl;
    gotoxy(75, 23);
    cout << "==   =   ==" << endl;
    gotoxy(75, 24);
    cout << "====   ====" << endl;
    gotoxy(75, 25);
    cout << "===========" << endl;
    Sleep(500);
    system("cls");
    color1(7);
    gotoxy(75, 15);
    cout << "===========" << endl;
    gotoxy(75, 16);
    cout << "====   ====" << endl;
    gotoxy(75, 17);
    cout << "==   =   ==" << endl;
    gotoxy(75, 18);
    cout << "=   ===   =" << endl;
    gotoxy(75, 19);
    cout << "======   ==" << endl;
    gotoxy(75, 20);
    cout << "=====   ===" << endl;
    gotoxy(75, 21);
    cout << "====   ====" << endl;
    gotoxy(75, 22);
    cout << "===   =====" << endl;
    gotoxy(75, 23);
    cout << "==   ======" << endl;
    gotoxy(75, 24);
    cout << "=        ==" << endl;
    gotoxy(75, 25);
    cout << "===========" << endl;
    Sleep(500);
    system("cls");
    color1(6);
    gotoxy(75, 15);
    cout << "==========" << endl;
    gotoxy(75, 16);
    cout << "====  ====" << endl;
    gotoxy(75, 17);
    cout << "===   ====" << endl;
    gotoxy(75, 18);
    cout << "====  ====" << endl;
    gotoxy(75, 19);
    cout << "====  ====" << endl;
    gotoxy(75, 20);
    cout << "====  ====" << endl;
    gotoxy(75, 21);
    cout << "====  ====" << endl;
    gotoxy(75, 22);
    cout << "====  ====" << endl;
    gotoxy(75, 23);
    cout << "====  ====" << endl;
    gotoxy(75, 24);
    cout << "==      ==" << endl;
    gotoxy(75, 25);
    cout << "==========" << endl;
    color1(7);
    Sleep(400);
    system("cls");
}
void main_menu()
{
    color1(15);
    gotoxy(20 - 17, 1);
    cout << "||                    |                    ||" << endl;
    gotoxy(20 - 17, 2);
    cout << "||____________    __ -+-  ____________     ||" << endl;
    gotoxy(20 - 17, 3);
    cout << "||\\_____     /   /_ \\ |   \\     _____/     ||";
    gotoxy(20 - 17, 4);
    cout << "|| \\_____    \\____/  \\____/    _____/      ||";
    gotoxy(20 - 17, 5);
    cout << "||  \\_____                    _____/       ||" << endl;
    gotoxy(20 - 17, 6);
    cout << "||     \\___________  ___________/          ||" << endl;
    gotoxy(20 - 17, 7);
    cout << "||               /____\\                    ||" << endl;
    gotoxy(3, 9);
    color1(7);
    color1(8);
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";
    color1(7);
    color1(15);
    gotoxy(70 - 17, 1);
    cout << " /$$$$$$$$ /$$        /$$$$$$  /$$$$$$$  /$$$$$$$  /$$     /$$       /$$$$$$$  /$$$$$$ /$$$$$$$  /$$$$$$$  ||" << endl;
    gotoxy(70 - 17, 2);
    cout << "| $$_____/| $$       /$$__  $$| $$__  $$| $$__  $$|  $$   /$$/      | $$__  $$|_  $$_/| $$__  $$| $$__  $$ ||" << endl;
    gotoxy(70 - 17, 3);
    cout << "| $$      | $$      | $$  \\ $$| $$  \\ $$| $$  \\ $$ \\  $$ /$$/       | $$  \\ $$  | $$  | $$  \\ $$| $$  \\ $$ ||" << endl;
    gotoxy(70 - 17, 4);
    cout << "| $$$$$   | $$      | $$$$$$$$| $$$$$$$/| $$$$$$$/  \\  $$$$/        | $$$$$$$   | $$  | $$$$$$$/| $$  | $$ ||" << endl;
    gotoxy(70 - 17, 5);
    cout << "| $$__/   | $$      | $$__  $$| $$____/ | $$____/    \\  $$/         | $$__  $$  | $$  | $$__  $$| $$  | $$ ||" << endl;
    gotoxy(70 - 17, 6);
    cout << "| $$      | $$      | $$  | $$| $$      | $$          | $$          | $$  \\ $$  | $$  | $$  \\ $$| $$  | $$ ||" << endl;
    gotoxy(70 - 17, 7);
    cout << "| $$      | $$$$$$$$| $$  | $$| $$      | $$          | $$          | $$$$$$$/ /$$$$$$| $$  | $$| $$$$$$$/ ||" << endl;
    gotoxy(70 - 17, 8);
    cout << "|__/      |________/|__/  |__/|__/      |__/          |__/          |_______/ |______/|__/  |__/|_______/  ||" << endl;
}
void starting_page()

{
    color1(6);
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "  \t\t\t\t                             .   ,                       " << endl;
    cout << "  \t\t\t\t     '. '.  \\  \\                                       " << endl;
    cout << "  \t\t\t\t    ._ '-.'. `\\  \\                                     " << endl;
    cout << "  \t\t\t\t      '-._; .'; `-.'.                                    " << endl;
    cout << "  \t\t\t\t     `~-.; '.       '.                                   " << endl;
    cout << "  \t\t\t\t      '--,`           '.                                 " << endl;
    cout << "  \t\t\t\t         -='.          ;                                 " << endl;
    cout << "  \t\t\t\t--====-,    -.;        ;                                 " << endl;
    cout << "  \t\t\t\t-=`;    ```,_.;        /                                 " << endl;
    cout << "  \t\t\t\t ,-`'    .-;         |                                   " << endl;
    cout << "  \t\t\t\t .-=`.    .;         ;                                   " << endl;
    cout << "  \t\t\t\t  .;.-   .-;         ,\\                                 " << endl;
    cout << "  \t\t\t\t    `.'   ,=;     .-'  `~.-._                            " << endl;
    cout << "  \t\t\t\t     .';   .';  .'      .'   '-.                         " << endl;
    cout << "  \t\t\t\t       .\\  ;  ;        ,.' _  a',                       " << endl;
    cout << "  \t\t\t\t      ."
            ";   ;      ;"
            "  '-=.)                         "
         << endl;
    cout << "  \t\t\t\t    .' .'   . _;  ;',  ;                                 " << endl;
    cout << "  \t\t\t\t    '-.._`~`.'  \\  ; ; :                                " << endl;
    cout << "  \t\t\t\t         `~'    _'\\\\_ \\\\_                            " << endl;
    cout << "  \t\t\t\t               /=`^^=`"
            "/`)-.                            "
         << endl;
    cout << "  \t\t\t\t            \\ =  _ =     =\\                            " << endl;
    cout << "  \t\t\t\t                `"
            "` `~-. =   ;                          "
         << endl;
    color1(7);
    color1(4);
    gotoxy(66, 11);
    cout << "___________.__      _____ _________________________.___.     " << endl;
    gotoxy(66, 12);
    cout << "\\_   _____/|  |    /  _  \\\\______   \\______   \\__  |   | " << endl;
    gotoxy(66, 13);
    cout << " |    __)  |  |   /  /_\\  \\|     ___/|     ___//   |   | " << endl;
    gotoxy(66, 14);
    cout << " |     \\   |  |__/    |    \\    |    |    |    \\____   | " << endl;
    gotoxy(66, 15);
    cout << " \\___  /   |____/\\____|__  /____|    |____|    / ______| " << endl;
    gotoxy(66, 16);
    cout << "     \\/                  \\/                    \\/       " << endl;
    color1(7);
    color1(1);
    gotoxy(75, 18);
    cout << "__________._____________________   " << endl;
    gotoxy(75, 19);
    cout << "\\______   \\   \\______   \\______ \\ " << endl;
    gotoxy(75, 20);
    cout << " |    |  _/   ||       _/|    |  \\ " << endl;
    gotoxy(75, 21);
    cout << " |    |   \\   ||    |   \\|    `   \\" << endl;
    gotoxy(75, 22);
    cout << " |______  /___||____|_  /_______  /" << endl;
    gotoxy(75, 23);
    cout << "        \\/            \\/        \\/" << endl;
    color1(7);
    color1(2);
    gotoxy(30, 30);
    cout << "___________________________________________________________________________________________________" << endl;
    color1(7);
    Sleep(2000);
}
void color1(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
}
void menu()
{

    gotoxy(30, 12);
    color1(7);
    color1(6);
    cout << "                                      |Main Manu|                      " << endl
         << endl;
    color1(7);
    if (main_Menu_Count == 0)
    {
        color1(6);
        gotoxy(68 - 4, 15);
        cout << "--->Start Game       " << endl;
        color1(7);
        gotoxy(68 - 4, 16);
        cout << "    Game Story       " << endl;
        color1(7);
        gotoxy(68 - 4, 17);
        cout << "      Help     " << endl;
        gotoxy(68 - 4, 18);
        color1(7);
        cout << "      Exit      " << endl;
        getch();
    }
    if (main_Menu_Count == 1)
    {
        color1(7);
        gotoxy(68 - 4, 15);
        cout << "    Start Game       " << endl;
        color1(6);
        gotoxy(68 - 4, 16);
        cout << "--->Game Story       " << endl;
        color1(7);
        gotoxy(68 - 4, 17);
        color1(7);
        cout << "      Help     " << endl;
        gotoxy(68 - 4, 18);
        color1(7);
        cout << "      Exit      " << endl;
        getch();
    }
    if (main_Menu_Count == 2)
    {

        gotoxy(68 - 4, 15);
        cout << "    Start Game       " << endl;
        color1(7);
        gotoxy(68 - 4, 16);
        cout << "    Game Story       " << endl;
        color1(7);
        gotoxy(68 - 4, 17);
        color1(6);
        cout << "--->  Help     " << endl;
        gotoxy(68 - 4, 18);
        color1(7);
        cout << "      Exit      " << endl;
        getch();
    }
    if (main_Menu_Count == 3)
    {
        color1(7);
        gotoxy(68 - 4, 15);
        cout << "    Start Game       " << endl;
        color1(7);
        gotoxy(68 - 4, 16);
        cout << "    Game Story       " << endl;
        color1(7);
        gotoxy(68 - 4, 17);
        cout << "      Help     " << endl;
        gotoxy(68 - 4, 18);
        color1(6);
        cout << "--->  Exit      " << endl;
        color1(7);
        getch();
    }
}

void game_Maze1()
{
    gotoxy(75, 2);
    {
        color1(1);
        cout << "Level 1";
        color1(7);
    }
    color1(2);
    left_right_side();
    up_down_side();
    color1(7);
    color1(5);
    Reward(34, 8);
    Reward(38, 31);
    Reward(40, 15);
    Reward(15, 27);
    Reward(88, 10);
    Reward(85, 32);
    Reward(115, 30);
    color1(7);
    color1(6);
    wall_1(25);
    wall_1(26);
    wall_1(27);
    wall_2(50);
    wall_2(51);
    wall_2(52);
    wall_3(75);
    wall_3(76);
    wall_3(77);
    wall_4(100);
    wall_4(101);
    wall_4(102);
    wall_5(125);
    wall_5(126);
    wall_5(127);
    color1(7);
}
void game_Maze2()
{
    gotoxy(75, 2);
    {
        color1(1);
        cout << "Level 2";
        color1(7);
    }
    color1(6);
    left_right_side();
    up_down_side();
    color1(7);
    color1(2);
    Reward(34, 8);
    Reward(34, 10);
    Reward(34, 9);
    Reward(38, 31);
    Reward(38, 29);
    Reward(38, 25);
    Reward(40, 15);
    Reward(40, 16);
    Reward(40, 17);
    Reward(15, 27);
    Reward(17, 27);
    Reward(115, 30);
    Reward(88, 10);
    Reward(85, 32);
    Reward(82, 33);
    Reward(89, 32);
    color1(7);
    color1(15);
    wall_1(100);
    wall_1(101);
    wall_1(102);
    wall_2(75);
    wall_2(76);
    wall_2(77);
    wall_3(25);
    wall_3(26);
    wall_3(27);
    wall_4(125);
    wall_4(126);
    wall_4(127);
    wall_5(50);
    wall_5(51);
    wall_5(52);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void wall_1(int x)
{

    for (int i = 5; i < 34; i++)
    {
        gotoxy(x, 1 + i);
        if (i >= 13 && i <= 18)
        {
            continue;
        }
        else
        {

            cout << wall;
        }
    }
}
void wall_2(int x)
{

    for (int i = 5; i < 34; i++)
    {
        gotoxy(x, 1 + i);
        if (i >= 22 && i <= 27)
        {
            continue;
        }
        else
        {

            cout << wall;
        }
        cout << endl;
    }
}
void wall_3(int x)
{

    for (int i = 5; i < 34; i++)
    {
        gotoxy(x, 1 + i);
        if (i >= 10 && i <= 15)
        {
            continue;
        }
        else
        {

            cout << wall;
        }
        cout << endl;
    }
}
void wall_4(int x)
{

    for (int i = 5; i < 34; i++)
    {
        gotoxy(x, 1 + i);
        if (i >= 19 && i <= 24)
        {
            continue;
        }
        else
        {

            cout << wall;
        }
    }
}
void wall_5(int x)
{

    for (int i = 5; i < 34; i++)
    {
        gotoxy(x, 1 + i);
        if (i >= 14 && i <= 20)
        {
            continue;
        }
        else
        {

            cout << wall;
        }
    }
}
void left_right_side()
{

    for (int j = 0; j <= 30; j++)
    {
        gotoxy(5, 5 + j);
        cout << ch1;
    }
    for (int j = 0; j <= 30; j++)
    {
        gotoxy(165, 5 + j);
        cout << ch1;
    }
}
void up_down_side()
{

    for (int j = 0; j <= 160; j++)
    {
        gotoxy(5 + j, 5);
        cout << ch2;
    }
    for (int j = 0; j <= 160; j++)
    {
        gotoxy(5 + j, 35);
        cout << ch2;
    }
}
void print_bird()
{
    color1(9);
    for (int row = 0; row < 4; row++)
    {
        gotoxy(birdX, birdY + row);
        for (int col = 0; col < 8; col++)
        {
            cout << bird[row][col];
        }
        cout << endl;
    }
    color1(7);
}
void erase_bird()
{

    for (int row = 0; row < 4; row++)
    {
        gotoxy(birdX, birdY + row);
        for (int col = 0; col < 8; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void move_bird_up()
{

    char next1 = getCharAtxy(birdX, birdY - 1);
    char next2 = getCharAtxy(birdX + 1, birdY - 1);
    char next3 = getCharAtxy(birdX + 2, birdY - 1);
    char next4 = getCharAtxy(birdX + 3, birdY - 1);
    char next5 = getCharAtxy(birdX + 4, birdY - 1);
    char next6 = getCharAtxy(birdX + 5, birdY - 1);
    char next7 = getCharAtxy(birdX + 6, birdY - 1);
    char next8 = getCharAtxy(birdX + 7, birdY - 1);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ' && next8 == ' ' || (next1 == reward || next2 == reward || next3 == reward || next4 == reward || next5 == reward || next6 == reward || next7 == reward || next8 == reward))
    {
        erase_bird();
        birdY = birdY - 1;
        print_bird();
        if (next1 == reward || next2 == reward || next3 == reward || next4 == reward || next5 == reward || next6 == reward || next7 == reward || next8 == reward)
        {
            score = score + 10;
            bird_Energy++;
        }
    }
    if (next1 == wall || next2 == wall || next3 == wall || next4 == wall || next5 == wall || next6 == wall || next7 == wall || next8 == wall)
    {
        clear_bird_energy();
        bird_Energy = bird_Energy - 5;
    }
}
void move_bird_down()
{
    char next1 = getCharAtxy(birdX, birdY + 4);
    char next2 = getCharAtxy(birdX + 1, birdY + 4);
    char next3 = getCharAtxy(birdX + 2, birdY + 4);
    char next4 = getCharAtxy(birdX + 3, birdY + 4);
    char next5 = getCharAtxy(birdX + 4, birdY + 4);
    char next6 = getCharAtxy(birdX + 5, birdY + 4);
    char next7 = getCharAtxy(birdX + 6, birdY + 4);
    char next8 = getCharAtxy(birdX + 7, birdY + 4);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ' && next8 == ' ' || (next1 == reward || next2 == reward || next3 == reward || next4 == reward || next5 == reward || next6 == reward || next7 == reward || next8 == reward))
    {
        erase_bird();
        birdY = birdY + 1;
        print_bird();
        if (next1 == reward || next2 == reward || next3 == reward || next4 == reward || next5 == reward || next6 == reward || next7 == reward || next8 == reward)
        {
            score = score + 10;
            bird_Energy++;
        }
    }
    if (next1 == wall || next2 == wall || next3 == wall || next4 == wall || next5 == wall || next6 == wall || next7 == wall || next8 == wall)
    {
        clear_bird_energy();
         bird_Energy = bird_Energy - 5;
    }
}
void move_bird_right()
{
    char next1 = getCharAtxy(birdX + 8, birdY);
    char next2 = getCharAtxy(birdX + 8, birdY + 1);
    char next3 = getCharAtxy(birdX + 8, birdY + 2);
    char next4 = getCharAtxy(birdX + 8, birdY + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' || (next1 == reward || next2 == reward || next3 == reward || next4 == reward))
    {
        erase_bird();
        birdX = birdX + 1;
        print_bird();
        if (next1 == reward || next2 == reward || next3 == reward || next4 == reward)
        {
            score = score + 10;
            bird_Energy++;
        }
    }
    if (next1 == wall || next2 == wall || next3 == wall || next4 == wall)
    {
        clear_bird_energy();
         bird_Energy = bird_Energy - 5;
    }
}
void move_bird_left()
{
    char next1 = getCharAtxy(birdX - 1, birdY);
    char next2 = getCharAtxy(birdX - 1, birdY + 1);
    char next3 = getCharAtxy(birdX - 1, birdY + 2);
    char next4 = getCharAtxy(birdX - 1, birdY + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' || (next1 == reward || next2 == reward || next3 == reward || next4 == reward))
    {
        erase_bird();
        birdX = birdX - 1;
        print_bird();
        if (next1 == reward || next2 == reward || next3 == reward || next4 == reward)
        {
            score = score + 10;
            bird_Energy++;
        }
    }
    if (next1 == wall || next2 == wall || next3 == wall || next4 == wall)
    {
        clear_bird_energy();
         bird_Energy = bird_Energy - 5;
    }
}

void generateBullet()
{
    bulletX[bulletCount] = birdX + 8;
    bulletY[bulletCount] = birdY + 1;
    isBulletActive[bulletCount] = true;
    gotoxy(birdX + 8, birdY + 1);
    char next = getCharAtxy(birdX + 8, birdY + 1);
    if (next == ' ')
    {
        cout << bullet;
        bulletCount++;
    }
}

void moveBullet()
{
    for (int index = 0; index < bulletCount; index++)
    {
        if (isBulletActive[index] == true)
        {
            char nextLocation = getCharAtxy(bulletX[index] + 1, bulletY[index]);
            if (nextLocation != ' ')
            {
                if (nextLocation != wall && nextLocation != bullet && nextLocation != ch1 && nextLocation != reward)
                {
                    clear_last_enemy_energy();
                    enemy_energy = enemy_energy - 10;
                    score = score + 50;
                    
                
                }
                eraseBullet(bulletX[index], bulletY[index]);
                makeBulletInactive(index);
            }
            else
            {
                eraseBullet(bulletX[index], bulletY[index]);
                bulletX[index] = bulletX[index] + 1;
                printBullet(bulletX[index], bulletY[index]);
            }
        }
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    color1(4);
    cout << bullet;
    color1(7);
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index)
{
    isBulletActive[index] = false;
}
void bird_energy()
{
    color1(6);
    gotoxy(7, 4);
    cout << "Bird Energy:" << bird_Energy;
    color1(7);
}
void clear_bird_energy()
{
    color1(6);
    gotoxy(7, 4);
    cout << "Bird Energy:      ";
    color1(7);
}
void print_last_enemy()
{
    color1(4);
    for (int row = 0; row < 7; row++)
    {
        gotoxy(last_enemyX, last_enemyY + row);
        cout << last_enemy[row][1];
    }
    color1(7);
}
void erase_last_enemy()
{
    for (int row = 0; row < 7; row++)
    {
        gotoxy(last_enemyX, last_enemyY + row);
        cout << "              ";
    }
}
void move_last_enemy()
{
    if (last_enemy_direction == "Up")
    {
        char next = getCharAtxy(last_enemyX, last_enemyY - 1);
        if (next == ' ')
        {
            erase_last_enemy();
            last_enemyY--;
            print_last_enemy();
        }
        if (next != ' ')
        {
            last_enemy_direction = "Down";
        }
    }
    if (last_enemy_direction == "Down")
    {
        char next = getCharAtxy(last_enemyX, last_enemyY + 7);
        if (next == ' ')
        {
            erase_last_enemy();
            last_enemyY++;
            print_last_enemy();
        }
        if (next != ' ')
        {
            last_enemy_direction = "Up";
        }
    }
}
void generate_last_Enemy_Bullet()
{
    {
        last_enemy_bulletX[last_enemy_Bullet_Count] = last_enemyX - 1;
        last_enemy_bulletY[last_enemy_Bullet_Count] = last_enemyY + 4;
        islastenemy_bulletActive[last_enemy_Bullet_Count] = true;
        gotoxy(last_enemyX - 1, last_enemyY + 4);
        cout << bullet;
        last_enemy_Bullet_Count++;
    }
}
void move_last_Enemy_Bullet()
{
    for (int index = 0; index < last_enemy_Bullet_Count; index++)
    {
        if (islastenemy_bulletActive[index] == true)
        {
            char nextLocation = getCharAtxy(last_enemy_bulletX[index] - 1, last_enemy_bulletY[index]);
            if (nextLocation != ' ')
            {

                if (nextLocation != wall && nextLocation != bullet)
                {
                    clear_bird_energy();
                    bird_Energy = bird_Energy - 10;
                    
                }
                erase_last_enemy_Bullet(last_enemy_bulletX[index], last_enemy_bulletY[index]);
                makeBulletInactive2(index);
            }
            else
            {
                erase_last_enemy_Bullet(last_enemy_bulletX[index], last_enemy_bulletY[index]);
                last_enemy_bulletX[index] = last_enemy_bulletX[index] - 1;
                print_last_enemy_Bullet(last_enemy_bulletX[index], last_enemy_bulletY[index]);
            }
        }
    }
}

void makeBulletInactive2(int index)
{
    islastenemy_bulletActive[index] = false;
}

void print_last_enemy_Bullet(int x, int y)
{
    gotoxy(x, y);
    color1(3);
    cout << bullet;
    color1(7);
}
void erase_last_enemy_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

/// @brief //end of monster/
void print_enemy1()
{
    color1(4);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << enemy1[row][col];
        }
        cout << endl;
    }
    color1(7);
}
void erase_enemy1()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void move_enemy1()
{
    if (enemy1_direction == "Left")
    {
        char next = getCharAtxy(enemy1X + 3, enemy1Y);
        if (next == ' ')
        {
            erase_enemy1();
            enemy1X++;
            print_enemy1();
        }
        if (next != ' ')
        {
            enemy1_direction = "Right";
        }
    }
    if (enemy1_direction == "Right")
    {
        char next = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next == ' ')
        {
            erase_enemy1();
            enemy1X--;
            print_enemy1();
        }
        if (next != ' ')
        {
            enemy1_direction = "Left";
        }
    }
}
void generate_Enemy1_Bullet()
{
    {

        enemy1_bulletX[enemy1_Bullet_Count] = enemy1X;
        enemy1_bulletY[enemy1_Bullet_Count] = enemy1Y + 2;
        isenemy1_bulletActive[enemy1_Bullet_Count] = true;
        gotoxy(enemy1X, enemy1Y + 2);
        cout << bullet;
        enemy1_Bullet_Count++;
    }
}
void move_Enemy1_Bullet()
{
    for (int index = 0; index < enemy1_Bullet_Count; index++)
    {
        if (isenemy1_bulletActive[index] == true)
        {
            char nextLocation = getCharAtxy(enemy1_bulletX[index], enemy1_bulletY[index] + 1);
            if (nextLocation != ' ')
            {
                erase_enemy1_Bullet(enemy1_bulletX[index], enemy1_bulletY[index]);
                if (nextLocation != ch2 && nextLocation != bullet && nextLocation != reward)
                {
                    clear_bird_energy();
                    bird_Energy=bird_Energy-5;
                }
                makeBulletInactive1(index);
            }
            else
            {
                erase_enemy1_Bullet(enemy1_bulletX[index], enemy1_bulletY[index]);
                enemy1_bulletY[index] = enemy1_bulletY[index] + 1;
                print_enemy1_Bullet(enemy1_bulletX[index], enemy1_bulletY[index]);
            }
        }
    }
}

void makeBulletInactive1(int index)
{
    isenemy1_bulletActive[index] = false;
}

void print_enemy1_Bullet(int x, int y)
{
    gotoxy(x, y);
    color1(3);
    cout << bullet;
    color1(7);
}
void erase_enemy1_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void Reward(int x, int y)
{
    gotoxy(x, y);

    cout << reward;
}
void total_score()
{
    gotoxy(5, 36);
    color1(1);
    cout << "Score:" << score;
    color1(7);
}
void high_score()
{
    gotoxy(5, 37);
    color1(1);
    cout << "High Score:" << High_score;
    color1(7);
}
void key_instructions()
{
    color1(13);
    gotoxy(135, 36);
    cout << "Press Escape Key to Exit Game";
    gotoxy(135, 37);
    cout << "Press TAB Key To Store Progress";
    color1(7);
}

void last_enemy_energy()
{
    gotoxy(135, 4);
    color1(12);
    cout << "Last Enemy Energy:" << enemy_energy;
    color1(7);
}
void clear_last_enemy_energy()
{
    gotoxy(135, 4);
    color1(12);
    cout << "Last Enemy Energy      ";
    color1(7);
}
void hide_last_enemy_energy()
{
    gotoxy(135, 4);
    color1(12);
    cout << "                      ";
    color1(7);
}
void help()
{
    gotoxy(2, 15);
    color1(2);
    cout << "  Help Menu" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    cout << "\n";
    color1(4);
    cout << "  * Please Follow the instructions given on page:" << endl
         << endl;
    color1(7);
    color1(15);
    cout << "  * Press Enter Key to use any Main Menu option:" << endl;
    cout << "  * Press Right Arrow Key to  Move Bird Right:" << endl;
    cout << "  * Press Left Arrow Key to  Move Bird Left:" << endl;
    cout << "  * Press UP Arrow Key to  Move Bird Up:" << endl;
    cout << "  * Press Down Arrow Key to  Move Bird Down:" << endl;
    cout << "  * Press Space Key to Generate  Bird Bullets:" << endl;
    cout << "  * Press ESCAPE Key to  Exit Game:" << endl;
    cout << "  * Press TAB key to Store Progress:" << endl
         << endl;
    color1(7);
    color1(4);
    cout << "  --->IF you need any other help kindly contact us:" << endl
         << endl;
    color1(7);
    color1(6);
    cout << "   Name              M.Awais Ashraf  " << endl;
    cout << "   Gmail             mhawais431@gmail.com" << endl;
    cout << "   Contact Number    03154193750" << endl;
    color1(7);
    press();
}
void press()
{
    cout << "\n";
    color1(11);
    cout << "Press any key to continue:";
    getch();
    color1(7);
}
void story()
{
    gotoxy(2, 15);
    color1(2);
    cout << "  Game Story" << endl;
    color1(7);
    color1(9);
    cout << "-------------------->>>" << endl
         << endl;
    cout << "\n";
    color1(15);
    cout << "\tThe game is about a Bird who can shoot bullets and has to face Three enemies . The first enemy moves" << endl;
    cout << "\thorizontally and shoots bullets, while the second enemy moves vertically and also shoots bullets.Third Enemy(walls). The player " << endl;
    cout << "\thas to avoid getting hit by the enemies' bullets and colliding with the wall. By shooting the enemies and" << endl;
    cout << "\tcollecting rewards, the player can increase his score." << endl
         << endl;
    color1(7);
    color1(4);
    cout << "\tThe ultimate objective of the game is to achieve the highest possible score and pass Levels." << endl;
    color1(7);
    press();
}