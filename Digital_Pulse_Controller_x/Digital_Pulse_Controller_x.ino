/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Controle Remoto
IRrecv receptor(A7);
decode_results resultado;

// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
const int rs = A1, en = A2, d4 = A3, d5 = A4, d6 = A5, d7 = A6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#pragma region Declarando vars

String vet[2]{"X", "X"};  //Vetor para armazenar os digitos selecionados pulso 1
int i;                    //Variavel com a posição a ser usada no vetor pulso 1
String kakashi;           //String que recebe o vetor 2 digitos em formato string pulso 1
bool dev;                 //Variavel bool para checar qual device pulso 1
String device;            //Variavel string para checar qual device pulso 1
String vet1[2]{"X", "X"}; //Vetor para armazenar os digitos selecionados pulso 2
int i1;                   //Variavel com a posição a ser usada no vetor pulso 2
String kakashi1;          //String que recebe o vetor 2 digitos em formato string pulso 2
bool dev1;                //Variavel bool para checar qual device pulso 2
String device1;           //Variavel string para checar qual device pulso
int g;                    //Variavel para Função trata e converte a em int a entrada a ser acionada Pulso 1
int g1;                   //Variavel para Função trata e converte a em int a entrada a ser acionada Pulso 2
bool curso;               //Variavel bool para usada como cursor no display
String Sasuke;            //Variavel string para armazena a saida
String Sasuke1;           //Variavel string para armazena a saida
String obito;             //Variavel string para armazena a saida
String obito1;            //Variavel string para armazena a saida

String pobito;  //Variavel string para armazena a saida
String pobito1; //Variavel string para armazena a saida

#pragma endregion

void setup()
{  
    pinMode(A0, OUTPUT);
    digitalWrite(A0, HIGH);
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
    pinMode(9, OUTPUT);
    digitalWrite(9, LOW);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A6, OUTPUT);

    receptor.enableIRIn();
    Serial.begin(9600);

    dev = true;
    device = "PRI";
    dev1 = false;
    device1 = "SEC";
    curso = true;

    #pragma region Declarando pinos saida1

    //Definindo os pinos de saida como output.
    pinMode(20, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(35, OUTPUT);
    pinMode(36, OUTPUT);
    pinMode(37, OUTPUT);
    pinMode(38, OUTPUT);
    pinMode(39, OUTPUT);
    pinMode(40, OUTPUT);
    pinMode(41, OUTPUT);
    pinMode(42, OUTPUT);
    pinMode(43, OUTPUT);
    pinMode(44, OUTPUT);
    pinMode(45, OUTPUT);
    pinMode(46, OUTPUT);
    pinMode(47, OUTPUT); 
    pinMode(48, OUTPUT);
    pinMode(49, OUTPUT);
    pinMode(50, OUTPUT);
    pinMode(51, OUTPUT);
    pinMode(52, OUTPUT);
    pinMode(53, OUTPUT);

    #pragma endregion

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    Line1("     SYSTEM ", 0);
    Line2("    STARTING    ", 0);
    delay(1000);
    lcd.clear();
    Line1(" DIGITAL  PULSE ", 0);
    Line2("   CONTROLLER    ",0);
    delay(2000); 
    lcd.clear();
    Serial.println("SYSTEM  STARTING"); //debug
}

void loop()
{
    lcd.clear();
    MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
    PositioncursorUDLCD(curso);

    if (receptor.decode(&resultado))
    {
        switch (resultado.value)
        {
        #pragma region Numerics

            case (0x61D600FF):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "0";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "0";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D6807F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "1";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "1";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D640BF):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "2";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "2";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D6C03F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "3";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "3";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D620DF):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "4";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "4";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;

            case (0x61D6A05F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "5";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "5";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
                break;

            case (0x61D6609F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "6";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "6";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D6E01F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "7";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "7";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D610EF):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "8";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "8";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;
            case (0x61D6906F):
                if (PositioncursorUDLCD(curso))
                {
                    i = posicao(vet);
                    vet[i] = "9";
                }
                else
                {
                    i1 = posicao2(vet1);
                    vet1[i1] = "9";
                }
                MsgFullLCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2());
            break;

        #pragma endregion

        #pragma region ENTER
            //Enviar comando 'ENTER'
            case (0x61D6A857):
                Serial.println("ENTER"); //Debug
                kakashi = DoisDigitosNew(vet);
                kakashi1 = DoisDigitosNew(vet1); //Concatena vetor

                Serial.println("P1.0: " + vet[0] + " P1.1: " + vet[1] + "; ->" + kakashi);    //debug
                Serial.println("P2.0: " + vet1[0] + " P2.1: " + vet1[1] + "; ->" + kakashi1); //debug
                lcd.clear();
                switch (Decicao(Verificadigitos(kakashi), Verificadigitos2(kakashi1)))
                {
                    case 0:
                    MsgResume0LCD(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2(), Sasuke, Sasuke1, obito, obito1);
                    break;
                    case 1:
                    MsgResume1LCD0(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2(), Sasuke, Sasuke1, obito, obito1);
                    break;
                    case 2:
                    MsgResume2LCD0(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2(), Sasuke, Sasuke1, obito, obito1);
                    break;
                    case 3:
                    MsgResume3LCD0(AlternaEntradasDisplayLCD(), Selected(), AlternaEntradasDisplay2LCD(), Selected2(), Sasuke, Sasuke1, pobito, pobito1);
                    break;
                    default:
                    break;
                }
                delay(250);
                NormalizeVetores();
            break;
        #pragma endregion

        #pragma region Back

            case (0x61D6D827):
                ZeraSaidas();
                Serial.println("BACK: Normaliza Vetores"); //debug
                lcd.clear();
                NormalizeVetores();
                obito = "";
                obito1 = "";
                pobito = "";
                pobito1 = "";
                delay(250);
                lcd.clear();
                break;

        #pragma endregion

        #pragma region Alterna Dispositivos pulso 1 e 2

            case (0x61D6B04F):
                Serial.println("CH+"); //debug
                AlternaEntradas();
            break;
            case (0x61D69867):
                Serial.println("CH-"); //debug
                AlternaEntradas();
            break;
            case (0x61D608F7):
                Serial.println("VOL-"); //debug
                AlternaEntradas2();
            break;
            case (0x61D630CF):
                Serial.println("VOL+"); //debug
                AlternaEntradas2();
            break;

        #pragma endregion

        #pragma region Power, Up & Down, Rec and Stop
           case (0x61D648B7):
            lcd.clear();
            ZeraSaidas();
            delay(500);
            Serial.println("Power acionado - Reset System!"); //debug
            MsgAnimed("RESET");

            asm volatile("jmp 0");
           break;
           case (0x61D618E7):
            Serial.println("REC - Seleção atual:");
            Serial.println("device: " + device);
            Serial.println("P1:  " + kakashi);
            Serial.println("device1: " + device1);
            Serial.println("P2:  " + kakashi1);
           break;
           case (0x61D658A7):
            Serial.println("STOP: Vetores Zerados!"); //debug
            lcd.clear();
            LcdResult_Line1("->Vetores");
            LcdResult_Line2("Zerados!<-", 6);
            NormalizeVetores();
            delay(500);
           break;
           case (0x61D6B847):
            PositioncursorLCD(curso);
            Serial.println("UP"); //debug
           break;
           case (0x61D67887):
            PositioncursorLCD(curso);
            Serial.println("DOWN"); //debug
           break;
           case (0x61D6F00F):
            PositioncursorLCD(curso);
            Serial.println("RIGHT"); //debug
           break;
           case (0x61D6708F):
            PositioncursorLCD(curso);
            Serial.println("LEFT"); //debug
           break;
           case(0x61D6C837): 
            Serial.println("MUTE acionado"); //debug
            Serial.println("TEST PRIMARY/SECONDARY");   //Debug
            TesteSaidas();
           break;
             //Realiza teste das 32 saidas
           case(0x61D650AF): 
            Serial.println("PIC");   //Debug
            Serial.println("TEST PRIMARY");   //Debug
            TestePRIMARY();
           break;     
           case(0x61D6D02F):
            Serial.println("FULL"); //debug
            Serial.println("TEST SECONDARY");   //Debug
            TesteSECONDARY();
           break;
        #pragma endregion
        }
        receptor.resume();
    }
}

#pragma region Mensagem

void MsgLCDdefault()
{
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.print("P1");
 lcd.setCursor(11, 0);
 lcd.print("P2");
}

void LcdResult_Full(String msg1, String msg2)
{
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print(msg1);
 lcd.setCursor(0, 1);
 lcd.print(msg2);
}

void LcdResult_Line1(String msg1, int posicao)
{
 lcd.setCursor(posicao, 0);
 lcd.print(msg1);
}

void LcdResult_Line1(String msg1)
{
 lcd.setCursor(0, 0);
 lcd.print(msg1);
}

void LcdResult_Line2(String msg1, int posicao)
{
 lcd.setCursor(posicao, 1);
 lcd.print(msg1);
}

void LcdResult_Line2(String msg1)
{
 lcd.setCursor(0, 1);
 lcd.print(msg1);
}

void MsgLCD(String msg1, String msg2)
{
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.print("P1");
 lcd.setCursor(11, 0);
 lcd.print("P2");

 lcd.setCursor(1, 1);
 lcd.print(msg1);
 lcd.setCursor(9, 1);
 lcd.print(msg2);
 delay(3000);
}

void Line1(String msg, int posicao)
{
    lcd.setCursor(posicao, 0);
    lcd.print(msg);
}

void Line2(String msg, int posicao)
{
    lcd.setCursor(posicao, 1);
    lcd.print(msg);
}

void Line1LCD(String msg, int posicao)
{
    lcd.setCursor(posicao, 0);
    lcd.print(msg);
}

void Line2LCD(String msg, int posicao)
{ 
    lcd.setCursor(posicao, 1);
    lcd.print(msg);
}

void LCD(String L1, String L2, String Select, int p)
{
    lcd.setCursor(0, 0);
    lcd.print(L1);

    lcd.setCursor(0, 1);
    lcd.print(L2);

    if (p == 0)
    {
        lcd.setCursor(15, 0);
        lcd.print(Select);
    }
    else
    {
        lcd.setCursor(15, 1);
        lcd.print(Select);
    }
    delay(500);
    lcd.clear();
}

void MsgResume0LCD(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{ 
 lcd.clear();
 delay(400);
 check1();    
}

void MsgResume0(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(um + " " + dois);

    lcd.setCursor(0, 1);
    lcd.print(tres + " " + quatro);
    delay(400);
    check1();
}

//Msg Resume para a opção 1
void MsgResume1(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1Full(um + dois);
    if (um == "PRI")
    {
        Line1("->" + o + um.substring(0, 3), 8);
    }
    else
    {
        Line1("->" + o1 + um.substring(0, 3), 8);
    }
    DisplayMsg2Full(tres + quatro);
    delay(300);
    check1();
}

//Msg Resume para a opção 1
void MsgResume1LCD(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1FullLCD(um +  " " + dois);
    if (um == "PRI")
    {
        Line1LCD("->" + o + um.substring(0, 3), 0); Line1LCD("    ", 9);
        Line2LCD("               ",0);
    }
    else
    {
        Line1LCD("->" + o1 + um.substring(0, 3), 9); Line1LCD("    ", 0);
        Line2LCD("               ",0);
    }
    DisplayMsg2FullLCD(tres+ " "  + quatro);
    delay(500);
    check1();
}

//Msg Resume para a opção 1
void MsgResume1LCD0(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    if (um == "PRI")
    {
        Line1LCD("P1->" + o + um.substring(0, 3), 0); Line1LCD("    ", 9);
        Line2LCD("               ",0);
    }
    else
    {
        Line1LCD("P1->" + o1 + um.substring(0, 3), 0); Line1LCD("    ", 9);
        Line2LCD("               ",0);
    }
    delay(500);
    check1();
}

//Msg Reseume para a opção 2
void MsgResume2(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1Full(um + dois);
    DisplayMsg2Full(tres + quatro);

    if (tres == "SEC")
    {
        Line2("->" + o1 + tres.substring(0, 3), 8);
    }
    else
    {
        Line2("->" + o + tres.substring(0, 3), 8);
    }
    delay(300);
    check1();
}

//Msg Reseume para a opção 2
void MsgResume2LCD(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1FullLCD(um + " " + dois);
    DisplayMsg2FullLCD(tres + " " + quatro);

    if (tres == "SEC")
    {
        Line1LCD("->" + o1 + tres.substring(0, 3), 9); Line1LCD("    ", 0);
        Line2LCD("               ",0);
    }
    else
    {
        Line1LCD("->" + o + tres.substring(0, 3), 0); Line1LCD("    ", 9);
        Line2LCD("               ",0);
    }
    delay(500);
    check1();
}

//Msg Reseume para a opção 2
void MsgResume2LCD0(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();

    if (tres == "SEC")
    {
        Line2LCD("P2->" + o1 + tres.substring(0, 3), 0); Line1LCD("    ", 9);
        Line1LCD("               ",0);
    }
    else
    {
        Line2LCD("P2->" + o + tres.substring(0, 3), 0); Line1LCD("    ", 9);
        Line1LCD("               ",0);
    }
    delay(500);
    check1();
}

//Msg Resume para a opção 3
void MsgResume3(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1Full(um + dois);
    Line1("->" + o + um.substring(0, 3), 8);
    DisplayMsg2Full(tres + quatro);
    Line2("->" + o1 + tres.substring(0, 3), 8);
    delay(300);
    check1();
}

//Msg Resume para a opção 3
void MsgResume3LCD(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
    DisplayMsg1FullLCD(um + " " + dois);
    Line1LCD("->" + o + um.substring(0, 3), 0);
    DisplayMsg2FullLCD(tres + " " + quatro);
    Line1LCD("->" + o1 + tres.substring(0, 3), 9);
    delay(500);
    check1();
}

//Msg Resume para a opção 3
void MsgResume3LCD0(String um, String dois, String tres, String quatro, String p1, String p2, String o, String o1)
{
    lcd.clear();
   // DisplayMsg1FullLCD(um + " " + dois);
    Line1LCD("P1->" + o + um.substring(0, 3), 0);
   // DisplayMsg2FullLCD(tres + " " + quatro);
    Line2LCD("P2->" + o1 + tres.substring(0, 3), 0);
    delay(1000);
    check1();
}

//Msg Resume padrão
void MsgFullLCD(String um, String dois, String tres, String quatro)
{
    lcd.clear();
    DisplayMsg1FullLCD(um + " " + dois);
    DisplayMsg2FullLCD(tres+ " " + quatro);
    delay(100);
}

//Msg Resume padrão
void MsgFull(String um, String dois, String tres, String quatro)
{
    lcd.clear();
    DisplayMsg1Full(um  + dois);
    DisplayMsg2Full(tres + quatro);
    delay(300);
}

//Msg animada up to down p/ 5 caracteres string
void MsgAnimed(String ent)
{
    lcd.clear();
    DisplayMsg1RS(ent + "...........");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("." + ent + "..........");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS(".." + ent + ".........");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("..." + ent + "........");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("...." + ent + ".......");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("....." + ent + "......");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("......" + ent + ".....");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("......." + ent + "....");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("........" + ent + "...");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("........." + ent + "..");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS(".........." + ent + ".");
    DisplayMsg2RS("................");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS(ent + "...........");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("." + ent + "..........");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS(".." + ent + ".........");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("..." + ent + "........");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("...." + ent + ".......");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("....." + ent + "......");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("......" + ent + ".....");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("......." + ent + "....");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("........" + ent + "...");

    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS("........." + ent + "..");
    delay(100);

    lcd.clear();
    DisplayMsg1RS("................");
    DisplayMsg2RS(".........." + ent + ".");
    delay(100);
}

//Msg 1° Linha
void DisplayMsg1Full(String msg)
{
    lcd.setCursor(0, 0);
    lcd.print("P1:" + msg);
}

//Msg 1° Linha
void DisplayMsg1FullLCD(String msg)
{
 MsgLCDdefault();

 lcd.setCursor(1, 1);
 lcd.print(msg);
}

//Msg 2° Linha
void DisplayMsg2Full(String msg)
{   
    MsgLCDdefault();
    lcd.setCursor(0, 1);
    lcd.print("P2:" + msg);
}

//Msg 2° Linha
void DisplayMsg2FullLCD(String msg)
{
    lcd.setCursor(9, 1);
    lcd.print(msg);
}

//Msg 1° Linha
void DisplayMsg1RS(String msg)
{
    lcd.setCursor(0, 0);
    lcd.print(msg);
}

//Msg 2° Linha
void DisplayMsg2RS(String msg)
{
    lcd.setCursor(0, 1);
    lcd.print(msg);
}

#pragma endregion

#pragma region Display & formatacao

//Determina posição do cursor no display
bool Positioncursor(bool ir)
{
    if (ir == true)
    {
        Line1("<-", 14);
        delay(250);
        curso = false;
    }
    else
    {
        Line2("<-", 14);
        delay(250);
        curso = true;
    }
    return ir;
}

//Determina posição do cursor no display
bool PositioncursorLCD(bool ir)
{
    if (ir == true)
    {
        Line1LCD("->", 1);Line1LCD("<-", 5);
        delay(250);
        curso = false;
    }
    else
    {
        Line1LCD("->", 9);Line1LCD("<-", 13);
        delay(250);
        curso = true;
    }
    return ir;
}

//Determina posição do cursor no display
bool PositioncursorUD(bool ir)
{
    if (ir == true)
    {
        Line1("<-", 14);
        delay(250);
        return true;
    }
    else
    {
        Line2("<-", 14);
        delay(250);
        return false;
    }
}

//Determina posição do cursor no display
bool PositioncursorUDLCD(bool ir)
{
    if (ir == true)
    {
        Line1LCD("->", 1);Line1LCD("<-", 5);
        delay(250);
        return true;
    }
    else
    {
        Line1LCD("->", 9);Line1LCD("<-", 13);
        delay(250);
        return false;
    }
}

//Função trata e converte em int a entrada a ser acionada
int Entrada(String y)
{
    if (y.substring(1) == "X" && y.substring(0, 1) != "X")
    {
        y = y.substring(0, 1);
        return y.toInt();
    }
    else
    {
        if (y.substring(1) == "X" && y.substring(0, 1) == "X")
        {
            return -99;
        }
        else
        {
            return y.toInt();
        }
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 1
void AlternaEntradas()
{
    if (dev == false)
    {
        DisplayMsg1Full("SEC");
        dev = true;
        device = "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        dev = false;
        device = "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 1
void AlternaEntradasLCD()
{
    if (dev == false)
    {
        DisplayMsg1FullLCD("SEC");
        dev = true;
        device = "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        dev = false;
        device = "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 1
String AlternaEntrada()
{
    if (dev == false)
    {
        DisplayMsg1Full("SEC");
        dev = true;
        device = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        dev = false;
        device = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 1
String AlternaEntradaLCD()
{
    if (dev == false)
    {
        DisplayMsg1FullLCD("SEC");
        dev = true;
        device = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        dev = false;
        device = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas somente info para display pulso 1
String AlternaEntradasDisplay()
{
    if (dev == false)
    {
        DisplayMsg1Full("SEC");
        device = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        device = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas somente info para display pulso 1
String AlternaEntradasDisplayLCD()
{
    if (dev == false)
    {
        DisplayMsg1FullLCD("SEC");
        device = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        device = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 2
void AlternaEntradas2()
{
    if (dev1 == false)
    {
        DisplayMsg1Full("SEC");
        dev1 = true;
        device1 = "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        dev1 = false;
        device1 = "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas sem retorno pulso 2
void AlternaEntradas2LCD()
{
    if (dev1 == false)
    {
        DisplayMsg1FullLCD("SEC");
        dev1 = true;
        device1 = "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        dev1 = false;
        device1 = "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas pulso 2
String AlternaEntrada2()
{
    if (dev1 == false)
    {
        DisplayMsg1Full("SEC");
        dev1 = true;
        device1 = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        dev1 = false;
        device1 = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas pulso 2
String AlternaEntrada2LCD()
{
    if (dev1 == false)
    {
        DisplayMsg1FullLCD("SEC");
        dev1 = true;
        device1 = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        dev1 = false;
        device1 = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas somente info para display pulso 2
String AlternaEntradasDisplay2()
{
    if (dev1 == false)
    {
        DisplayMsg1Full("SEC");
        device1 = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1Full("PRI");
        device1 = "PRI";
        return "PRI";
    }
}

//Função para alternar entre entradas titulares e reservas somente info para display pulso 2
String AlternaEntradasDisplay2LCD()
{
    if (dev1 == false)
    {
        DisplayMsg1FullLCD("SEC");
        device1 = "SEC";
        return "SEC";
    }
    else
    {
        DisplayMsg1FullLCD("PRI");
        device1 = "PRI";
        return "PRI";
    }
}

//Função para determinar em qual posição do vetor deve ser gravado o número pulso 1
int posicao(String vetor[])
{
    int saida;
    if (vetor[0] == "X")
    {
        saida = 0;
    }
    else
    {
        if (vetor[1] == "X")
        {
            saida = 1;
        }
        else
        {
            Normalizer_P1();
            saida = 0;
        }
    }
    return saida;
}

//Função para determinar em qual posição do vetor deve ser gravado o número puldo 2
int posicao2(String vetor1[])
{
    int saida1;
    if (vetor1[0] == "X")
    {
        saida1 = 0;
    }
    else
    {
        if (vetor1[1] == "X")
        {
            saida1 = 1;
        }
        else
        {
            Normalizer_P2();
            saida1 = 0;
        }
    }
    return saida1;
}

//Normaliza o vetor de 2 digitos para "XX"
void NormalizeVetores()
{
    Normalizer_P1();
    Normalizer_P2();
}

//Normaliza o vetor P1 de 2 digitos para "XX"
void Normalizer_P1()
{
    vet[0] = "X";
    vet[1] = "X";
    kakashi = vet[0] + vet[1];
}

//Normaliza o vetor P2 de 2 digitos para "XX"
void Normalizer_P2()
{
    vet1[0] = "X";
    vet1[1] = "X";
    kakashi1 = vet1[0] + vet1[1];
}

//Atribui o valor do vcetor para string kakashi pulso 1
String Selected()
{
    kakashi = vet[0] + vet[1];
    return kakashi;
}

//Atribui o valor do vcetor para string kakashi1 pulso 2
String Selected2()
{
    kakashi1 = vet1[0] + vet1[1];
    return kakashi1;
}

//Função transforma vetor de 2 digitos em uma string
String DoisDigitosNew(String v[])
{
    String pass = "XX";
    if (v[0] != "X")
    {
        pass = v[0];
    }
    if (v[1] != "X")
    {
        pass = pass + v[1];
    }
    return pass;
}

//Função verifica se é uma entrada válida para pulso 1
bool Verificadigitos(String k1)
{
    bool valida;
    if (k1 == "XX")
    {
        Line1LCD("->ERRO_P1 = X ", 0); 
        delay(600);
        valida = false;
    }
    else
    {
        if (k1 == "00" || k1 == "0")
        {
            Line1LCD("->ERRO_P1 = 0 ", 0); 
            delay(600);
            valida = false;
        }
        else
        {
            if (k1.toInt() >= 17)
            {
                Line1LCD("->ERRO_P1 > 16 ", 0);
                delay(600);
                valida = false;
            }
            else
            {
                valida = true;
                Sasuke = k1;
            }
        }
    }
    return valida;
}

//Função verifica se é uma entrada válida para pulso 1
bool VerificadigitosLCD(String k1)
{
    bool valida;
    if (k1 == "XX")
    {
        lcd.clear();
        DisplayMsg1Full("->Er_P1 = X");
        delay(400);
        valida = false;
    }
    else
    {
        if (k1 == "00" || k1 == "0")
        {
            lcd.clear();
            DisplayMsg1Full("->Er_P1= 0");
            delay(400);
            valida = false;
        }
        else
        {
            if (k1.toInt() >= 17)
            {
                lcd.clear();
                DisplayMsg1Full("->Er_P1 > 16");
                delay(400);
                valida = false;
            }
            else
            {
                valida = true;
                Sasuke = k1;
            }
        }
    }
    return valida;
}

//Função verifica se é uma entrada válida para pulso 2
bool Verificadigitos2(String k2)
{
    bool valida1;
    if (k2 == "XX")
    {
       Line2LCD("->ERRO_P2 = X ", 0); 
        delay(600);
        valida1 = false;
    }
    else
    {
        if (k2 == "00" || k2 == "0")
        {
            Line2LCD("->ERRO_P2 = 0 ", 0); 
            delay(600);
            valida1 = false;
        }
        else
        {
            if (k2.toInt() >= 17)
            {
                Line2LCD("->ERRO_P2 > 16 ", 0);                
                delay(600);
                valida1 = false;
            }
            else
            {
                valida1 = true;
                Sasuke1 = k2;
            }
        }
    }
    return valida1;
}

//Função verifica se é uma entrada válida para pulso 2
bool Verificadigitos2LCD(String k2)
{
    bool valida1;
    if (k2 == "XX")
    {
        lcd.clear();
        DisplayMsg2Full("->Er_P2 = X");
        delay(400);
        valida1 = false;
    }
    else
    {
        if (k2 == "00" || k2 == "0")
        {
            lcd.clear();
            DisplayMsg2Full("->Er_P2 = 0");
            delay(400);
            valida1 = false;
        }
        else
        {
            if (k2.toInt() >= 17)
            {
                lcd.clear();
                DisplayMsg2Full("->Er_P2 > 16");
                delay(400);
                valida1 = false;
            }
            else
            {
                valida1 = true;
                Sasuke1 = k2;
            }
        }
    }
    return valida1;
}

#pragma endregion

#pragma region IO

//Função verifica dispositivo selecionado e escreve na saida
void DigitalIO(String sl, int in)
{
    if (sl == "PRI")
    {
        Serial.print("DigitalIO - TitularIO: ");
        switch (in)
        {
        case (1):
            EscrevaSaida(22);
            obito = "22";
            break;
        case (2):
            EscrevaSaida(23);
            obito = "23";
            break;
        case (3):
            EscrevaSaida(24);
            obito = "24";
            break;
        case (4):
            EscrevaSaida(25);
            obito = "25";
            break;
        case (5):
            EscrevaSaida(26);
            obito = "26";
            break;
        case (6):
            EscrevaSaida(27);
            obito = "27";
            break;
        case (7):
            EscrevaSaida(28);
            obito = "28";
            break;
        case (8):
            EscrevaSaida(29);
            obito = "29";
            break;
        case (9):
            EscrevaSaida(30);
            obito = "30";
            break;
        case (10):
            EscrevaSaida(31);
            obito = "31";
            break;
        case (11):
            EscrevaSaida(32);
            obito = "32";
            break;
        case (12):
            EscrevaSaida(33);
            obito = "33";
            break;
        case (13):
            EscrevaSaida(34);
            obito = "34";
            break;
        case (14):
            EscrevaSaida(35);
            obito = "35";
            break;
        case (15):
            EscrevaSaida(36);
            obito = "36";
            break;
        case (16):
            EscrevaSaida(37);
            obito = "37";
            break;
        }
    }
    else
    {
        Serial.print("DigitalIO - ReservaIO: ");
        switch (in)
        {
        case (1):
            EscrevaSaida(38);
            obito1 = "38";
            break;
        case (2):
            EscrevaSaida(39);
            obito1 = "39";
            break;
        case (3):
            EscrevaSaida(40);
            obito1 = "40";
            break;
        case (4):
            EscrevaSaida(20);
            obito1 = "20";
            break;
        case (5):
            EscrevaSaida(42);
            obito1 = "42";
            break;
        case (6):
            EscrevaSaida(21);
            obito1 = "21";
            break;
        case (7):
            EscrevaSaida(44);
            obito1 = "44";
            break;
        case (8):
            EscrevaSaida(45);
            obito1 = "45";
            break;
        case (9):
            EscrevaSaida(46);
            obito1 = "46";
            break;
        case (10):
            EscrevaSaida(47);
            obito1 = "47";
            break;
        case (11):
            EscrevaSaida(48);
            obito1 = "48";
            break;
        case (12):
            EscrevaSaida(49);
            obito1 = "49";
            break;
        case (13):
            EscrevaSaida(50);
            obito1 = "50";
            break;
        case (14):
            EscrevaSaida(51);
            obito1 = "51";
            break;
        case (15):
            EscrevaSaida(52);
            obito1 = "52";
            break;
        case (16):
            EscrevaSaida(53);
            obito1 = "53";
            break;
        }
    }
}

//Função especifica para DigitalIOfull determinar os valores dos 2 pulsos
void Op1Op2(String sl, int in, String sl1, int in1)
{
    if (sl == "PRI")
    {
        Serial.print("DigitalIOfull - TitularIO: ");
        switch (in)
        {
        case (1):
            pobito = "22";
            break;
        case (2):
            pobito = "23";
            break;
        case (3):
            pobito = "24";
            break;
        case (4):
            pobito = "25";
            break;
        case (5):
            pobito = "26";
            break;
        case (6):
            pobito = "27";
            break;
        case (7):
            pobito = "28";
            break;
        case (8):
            pobito = "29";
            break;
        case (9):
            pobito = "30";
            break;
        case (10):
            pobito = "31";
            break;
        case (11):
            pobito = "32";
            break;
        case (12):
            pobito = "33";
            break;
        case (13):
            pobito = "34";
            break;
        case (14):
            pobito = "35";
            break;
        case (15):
            pobito = "36";
            break;
        case (16):
            pobito = "37";
            break;
        }
    }
    else
    {
        Serial.print("DigitalIOfull - ReservaIO: ");
        switch (in)
        {
        case (1):
            pobito = "38";
            break;
        case (2):
            pobito = "39";
            break;
        case (3):
            pobito = "40";
            break;
        case (4):
            pobito = "20";
            break;
        case (5):
            pobito = "42";
            break;
        case (6):
            pobito = "21";
            break;
        case (7):
            pobito = "44";
            break;
        case (8):
            pobito = "45";
            break;
        case (9):
            pobito = "46";
            break;
        case (10):
            pobito = "47";
            break;
        case (11):
            pobito = "48";
            break;
        case (12):
            pobito = "50";
            break;
        case (13):
            pobito = "51";
            break;
        case (14):
            pobito = "52";
            break;
        case (15):
            pobito = "53";
            break;
        case (16):
            pobito = "53";
            break;
        }
    }

    if (sl1 == "PRI")
    {
        Serial.print("DigitalIOfull - TitularIO: ");
        switch (in1)
        {
        case (1):
            pobito1 = "22";
            break;
        case (2):
            pobito1 = "23";
            break;
        case (3):
            pobito1 = "24";
            break;
        case (4):
            pobito1 = "25";
            break;
        case (5):
            pobito1 = "26";
            break;
        case (6):
            pobito1 = "27";
            break;
        case (7):
            pobito1 = "28";
            break;
        case (8):
            pobito1 = "29";
            break;
        case (9):
            pobito1 = "30";
            break;
        case (10):
            pobito1 = "31";
            break;
        case (11):
            pobito1 = "32";
            break;
        case (12):
            pobito1 = "33";
            break;
        case (13):
            pobito1 = "34";
            break;
        case (14):
            pobito1 = "35";
            break;
        case (15):
            pobito1 = "36";
            break;
        case (16):
            pobito1 = "37";
            break;
        }
    }
    else
    {
        Serial.print("DigitalIOfull - ReservaIO: ");
        switch (in1)
        {
        case (1):
            pobito1 = "38";
            break;
        case (2):
            pobito1 = "39";
            break;
        case (3):
            pobito1 = "40";
            break;
        case (4):
            pobito1 = "20";
            break;
        case (5):
            pobito1 = "42";
            break;
        case (6):
            pobito1 = "21";
            break;
        case (7):
            pobito1 = "44";
            break;
        case (8):
            pobito1 = "45";
            break;
        case (9):
            pobito1 = "46";
            break;
        case (10):
            pobito1 = "47";
            break;
        case (11):
            pobito1 = "48";
            break;
        case (12):
            pobito1 = "49";
            break;
        case (13):
            pobito1 = "50";
            break;
        case (14):
            pobito1 = "51";
            break;
        case (15):
            pobito1 = "52";
            break;
        case (16):
            pobito1 = "53";
            break;
        }
    }
}

//Função verifica dispositivos selecionado e escreve na saida
void DigitalIOfull(String sl, int in, String sl1, int in1)
{
    if (sl == "PRI")
    {
        Serial.print("DigitalIOfull - TitularIO: ");
        switch (in)
        {
        case (1):
            EscrevaSaida(22);
            break;
        case (2):
            EscrevaSaida(23);
            break;
        case (3):
            EscrevaSaida(24);
            break;
        case (4):
            EscrevaSaida(25);
            break;
        case (5):
            EscrevaSaida(26);
            break;
        case (6):
            EscrevaSaida(27);
            break;
        case (7):
            EscrevaSaida(28);
            break;
        case (8):
            EscrevaSaida(29);
            break;
        case (9):
            EscrevaSaida(30);
            break;
        case (10):
            EscrevaSaida(31);
            break;
        case (11):
            EscrevaSaida(32);
            break;
        case (12):
            EscrevaSaida(33);
            break;
        case (13):
            EscrevaSaida(34);
            break;
        case (14):
            EscrevaSaida(35);
            break;
        case (15):
            EscrevaSaida(36);
            break;
        case (16):
            EscrevaSaida(37);
            break;
        }
    }
    else
    {
        Serial.print("DigitalIOfull - ReservaIO: ");
        switch (in)
        {
        case (1):
            EscrevaSaida(38);
            break;
        case (2):
            EscrevaSaida(39);
            break;
        case (3):
            EscrevaSaida(40);
            break;
        case (4):
            EscrevaSaida(20);
            break;
        case (5):
            EscrevaSaida(42);
            break;
        case (6):
            EscrevaSaida(21);
            break;
        case (7):
            EscrevaSaida(44);
            break;
        case (8):
            EscrevaSaida(45);
            break;
        case (9):
            EscrevaSaida(46);
            break;
        case (10):
            EscrevaSaida(47);
            break;
        case (11):
            EscrevaSaida(48);
            break;
        case (12):
            EscrevaSaida(49);
            break;
        case (13):
            EscrevaSaida(50);
            break;
        case (14):
            EscrevaSaida(51);
            break;
        case (15):
            EscrevaSaida(52);
            break;
        case (16):
            EscrevaSaida(53);
            break;
        }
    }

    if (sl1 == "PRI")
    {
        Serial.print("DigitalIOfull - TitularIO: ");
        switch (in1)
        {
        case (1):
            EscrevaSaida(22);
            break;
        case (2):
            EscrevaSaida(23);
            break;
        case (3):
            EscrevaSaida(24);
            break;
        case (4):
            EscrevaSaida(25);
            break;
        case (5):
            EscrevaSaida(26);
            break;
        case (6):
            EscrevaSaida(27);
            break;
        case (7):
            EscrevaSaida(25);
            break;
        case (8):
            EscrevaSaida(29);
            break;
        case (9):
            EscrevaSaida(30);
            break;
        case (10):
            EscrevaSaida(31);
            break;
        case (11):
            EscrevaSaida(32);
            break;
        case (12):
            EscrevaSaida(33);
            break;
        case (13):
            EscrevaSaida(34);
            break;
        case (14):
            EscrevaSaida(35);
            break;
        case (15):
            EscrevaSaida(36);
            break;
        case (16):
            EscrevaSaida(37);
            break;
        }
    }
    else
    {
        Serial.print("DigitalIOfull - ReservaIO: ");
        switch (in1)
        {
        case (1):
            EscrevaSaida(38);
            break;
        case (2):
            EscrevaSaida(39);
            break;
        case (3):
            EscrevaSaida(40);
            break;
        case (4):
            EscrevaSaida(20);
            break;
        case (5):
            EscrevaSaida(42);
            break;
        case (6):
            EscrevaSaida(21);
            break;
        case (7):
            EscrevaSaida(44);
            break;
        case (8):
            EscrevaSaida(45);
            break;
        case (9):
            EscrevaSaida(46);
            break;
        case (10):
            EscrevaSaida(47);
            break;
        case (11):
            EscrevaSaida(48);
            break;
        case (12):
            EscrevaSaida(49);
            break;
        case (13):
            EscrevaSaida(50);
            break;
        case (14):
            EscrevaSaida(51);
            break;
        case (15):
            EscrevaSaida(52);
            break;
        case (16):
            EscrevaSaida(53);
            break;
        }
    }
}

//Função recebe dois booleanos e verificar qual(s) pulsos são válidos
int Decicao(bool u, bool d)
{
    int key = 0;

    if (u == false && d == false)
    {
        check();
        Serial.println("Result: P1P2_NOT_OK"); //debug
        key = 0;
    }

    if (u == true && d == false)
    {
        check();
        g = Entrada(Selected());
        DigitalIO(device, g);
        key = 1;
        Serial.println("Result: P1_OK"); //Debug
    }

    if (u == false && d == true)
    {
        check();
        g1 = Entrada(Selected2());      
        DigitalIO(device1, g1);
        key = 2;
        Serial.println("Result: P2_OK"); //Debug
    }
                
    if (u == true && d == true)
    {
        check();
        g = Entrada(Selected());
        g1 = Entrada(Selected2());
        //DigitalIO(device, g);
        //DigitalIO(device1, g1);
        DigitalIOfull(device, g, device1, g1);
        Op1Op2(device, g, device1, g1);
        key = 3;
        Serial.println("Result: P1P2_OK"); //Debug
    }
    return key;
}

//Função printa na serial valores e dispositivos selecionados nos pulsos
void check()
{
    Serial.println("Check:");
    Serial.println("Device: " + device + " P1:  " + kakashi);
    Serial.println("Device1: " + device1 + " P2:  " + kakashi1);
}

//Função printa na serial valores e dispositivos selecionados nos pulsos
void check1()
{
    Serial.println("Check1:");
    Serial.println("Device: " + device + " P1:  " + kakashi);
    Serial.println("Device1: " + device1 + " P2:  " + kakashi1);

    Serial.println("obito: " + obito);
    Serial.println("obito1: " + obito1);
    Serial.println("pobito: " + pobito);
    Serial.println("pobito1: " + pobito1);
}

//Função que zera(LOW) todas as saidas
void ZeraSaidas()
{
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, LOW);
    digitalWrite(40, LOW);
    digitalWrite(41, LOW);
    digitalWrite(42, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
    digitalWrite(50, LOW);
    digitalWrite(51, LOW);
    digitalWrite(52, LOW);
    digitalWrite(53, LOW);

    MsgAnimed("_LOW_");
    Serial.println("As saidas foram desativadas!"); //Debug
}

//Função que escreve(HIGH) na saida que é o parametro de entrada
void EscrevaSaida(int num)
{
    String myString = String(num);
    digitalWrite(num, HIGH);                                   //Escreva na saida selecionada.
    Serial.println("Arduino out: " + myString + " Acionada!"); //Debug
    delay(250);
    digitalWrite(num, LOW);                                   //Escreva na saida selecionada.
    Serial.println("Arduino out: " + myString + " Desativada!"); //Debug
}

//função para teste das saidas
void TesteSaidas()
{   
    lcd.clear();
    Line1("   TEST START", 0);
    Line2("      FULL", 0);
    delay(4000);
    for (size_t i = 21; i <= 52; i++)
    {

    int num =  i + 1;
    int n =  i - 20;
    String myStringN = String(n);
    String myString = String(num);
    
    
    lcd.clear();         
    

    if(n <= 16)
    {
        Line1(" PRIMARY-INPUT", 0);
        Line2("  " + myStringN + "  ACTIVED!", 0);  
        digitalWrite(num, HIGH);   //Escreva na saida selecionada.
        delay(500);
        digitalWrite(num, LOW);  //Escreva na saida selecionada.
    }
    else
    {   
        if (num == 43)
        {
            Line1("SECONDARY-INPUT", 0);
            Line2("  6  ACTIVED!", 0);     
            digitalWrite(21, HIGH);   //Escreva na saida selecionada.
            delay(500);
            digitalWrite(21, LOW);  //Escreva na saida selecionada.
        }
        else
        {
            if (num == 41)
                {
                     Line1("SECONDARY-INPUT", 0);
                     Line2("  4  ACTIVED!", 0);     
                     digitalWrite(20, HIGH);   //Escreva na saida selecionada.
                     delay(500);
                     digitalWrite(20, LOW);  //Escreva na saida selecionada.
                }
            else
                {
                    Line1("SECONDARY-INPUT", 0);
                    myStringN = String(n - 16);
                    Line2("  " + myStringN + "  ACTIVED!", 0);     
                    digitalWrite(num, HIGH);   //Escreva na saida selecionada.      
                    delay(500);
                    digitalWrite(num, LOW);  //Escreva na saida selecionada.
                }
        }      
    }

    
    }
    Serial.println("TEST FULL FINISH!"); //Debug   
    delay(500);

    Line1("TEST FULL FINISH!", 0);
    lcd.clear();

    asm volatile("jmp 0"); 
    
}

//função para teste das saidas
void TestePRIMARY()
{   
    lcd.clear();
    Line1("   TEST START  ", 0);
    Line2("    PRIMARY   ", 0);
    delay(4000);
    for (size_t i = 21; i <= 36; i++)
    {

      int num =  i + 1;
      int n =  i - 20;
      String myStringN = String(n);
      String myString = String(num);


      lcd.clear();         


      if(n <= 16)
      {
          Line1(" PRIMARY-INPUT", 0);
          Line2("  " + myStringN + "  ACTIVED!", 0);  
          digitalWrite(num, HIGH);   //Escreva na saida selecionada.
          delay(500);
          digitalWrite(num, LOW);  //Escreva na saida selecionada.
      }

    }
    
    Serial.println("TEST PRIMARY FINISH!"); //Debug   
    delay(500);

    Line1("TEST PRIMARY FINISH!", 0);
    lcd.clear();

    asm volatile("jmp 0"); 
    
}

//função para teste das saidas
void TesteSECONDARY()
{   

    lcd.clear();
    Line1("   TEST START  ", 0);
    Line2("    SECONDARY  ", 0);
    delay(4000);
    for (size_t i = 21; i <= 52; i++)
    {

    int num =  i + 1;
    int n =  i - 20;
    String myStringN = String(n);
    String myString = String(num);
    
    
    lcd.clear();         
    

    if(n <= 16)
    {

    }
    else
    {   
        if (num == 43)
        {
            Line1("SECONDARY-INPUT", 0);
            Line2("  6  ACTIVED!", 0);     
            digitalWrite(21, HIGH);   //Escreva na saida selecionada.
            delay(500);
            digitalWrite(21, LOW);  //Escreva na saida selecionada.
        }
        else
        {
            if (num == 41)
                {
                     Line1("SECONDARY-INPUT", 0);
                     Line2("  4  ACTIVED!", 0);     
                     digitalWrite(20, HIGH);   //Escreva na saida selecionada.
                     delay(500);
                     digitalWrite(20, LOW);  //Escreva na saida selecionada.
                }
            else
                {
                    Line1("SECONDARY-INPUT", 0);
                    myStringN = String(n - 16);
                    Line2("  " + myStringN + "  ACTIVED!", 0);     
                    digitalWrite(num, HIGH);   //Escreva na saida selecionada.      
                    delay(500);
                    digitalWrite(num, LOW);  //Escreva na saida selecionada.
                }
        }      
    }

    
    }
    Serial.println("TEST  SECONDARY FINISH!"); //Debug   
    delay(500);

    Line1("TEST SECONDARY!", 0);
    Line2("FINISH!", 0);
    lcd.clear();

    asm volatile("jmp 0"); 

}

#pragma endregion       
