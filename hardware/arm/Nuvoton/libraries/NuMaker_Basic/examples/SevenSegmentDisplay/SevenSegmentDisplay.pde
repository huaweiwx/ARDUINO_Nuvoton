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
  for(i=0;i<SEG;i++)
    pinMode(Segment[i],OUTPUT);
  pinMode(Control[0],OUTPUT);  /* Even Segment Display 1 */
  pinMode(Control[1],OUTPUT);  /* Even Segment Display 2 */
}

void loop() {
  // put your main code here, to run repeatedly: 
  int i,j,k,c;
  for(i=0;i<10;i++)  
  {
      for(j=0;j<10;j++)  
      {
        c=100;
        while(c--)
        {
         lightNumber(1,i);  //Select Even Segment Display 2 and disply number i
         delay(2);
         lightNumber(0,j);  //Select Even Segment Display 1 and disply number j
         delay(2);         
        }
      }
  }  
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