/*
		Servn Segment Display
 
                   A
                _______
             F|         |B
              |    G    |
                _______
             E|         |C
              |         |
                _______     o H
                   D
 
		This example code is in the public domain.
 */
#define SEG 8

/* SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegH */
/* Note : SegE and SegF does not supported on NuEdu-NUC131 */
int Segment[]={18,19,20,21,22,23,10,11};
int Control[]={12,13};  /* Seven segment display 1 , 2 */
int Num1=0;
int Num2=0;             
                     /*A,B,C,D,E,F,G,H */
int Number[10][SEG]={ {1,1,1,1,1,1,0,0},  //0
                      {0,1,1,0,0,0,0,0},  //1
                      {1,1,0,1,1,0,1,0},  //2
                      {1,1,1,1,0,0,1,0},  //3
                      {0,1,1,0,0,1,1,0},  //4
                      {1,0,1,1,0,1,1,0},  //5
                      {0,0,1,1,1,1,1,0},  //6
                      {1,1,1,0,0,0,0,0},  //7
                      {1,1,1,1,1,1,1,0},  //8
                      {1,1,1,1,0,1,1,0},  //9    
                  };
void setup() {  
  // put your setup code here, to run once:
  int i,j;
  int clock =12000000; /* 12Mhz */
  Timer1.open(PERIODIC,clock);
  Timer1.setPrescaleFactor(0);
  Timer1.setCompare(clock);  /* 1000 microseconds per tick (1 s) */ 
  Timer1.attachInterrupt(timer_ISR);
  Timer1.start();
	
  for(i=0;i<SEG;i++)
    pinMode(Segment[i],OUTPUT);
  pinMode(Control[0],OUTPUT);  /* Even Segment Display 1 */
  pinMode(Control[1],OUTPUT);  /* Even Segment Display 2 */
}

void loop() {
  lightNumber(1,Num2);  //Select Even Segment Display 2 and disply number i
  delay(2);
  lightNumber(0,Num1);  //Select Even Segment Display 1 and disply number j
  delay(2);  
}


void lightNumber(int ctrl,int num)
{
  int i;
  if(ctrl==0)  
  {
    digitalWrite(Control[ctrl],LOW);
    digitalWrite(Control[ctrl+1],HIGH);
  }
  else
  {
    digitalWrite(Control[ctrl],LOW);
    digitalWrite(Control[ctrl-1],HIGH);
  }
  for(i=0;i<SEG;i++)
    digitalWrite(Segment[i],!Number[num][i]);  
}

void timer_ISR(uint8_t num)
{
  Num1++;
  if(Num1>9)
  {
    Num2++;
    if(Num2>9) Num2=0;
    Num1=0;
  }
}