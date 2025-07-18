
#define userEdgeType RISING
#define  pin1  2 
#define  pin2  3

volatile byte state = LOW ;

typedef struct{
  //GPIO pin
  uint8_t pin;
  //Associated action function
  void (*func)(void);
  //Int trigger type
  uint8_t edgeType;
}mapping_Table_t;

mapping_Table_t table[2];

void action1(void)
{
  Serial.print("Door closed\r\n");
}
void action2(void)
{
  Serial.print("TV turned ON\r\n");
}

void initializeTable(mapping_Table_t *obj, uint8_t pinNum,void (*userActionFunc),uint8_t edgetype_t)
{
	obj->pin=pinNum;
	obj->func=userActionFunc;
  attachInterrupt ( digitalPinToInterrupt ( obj->pin ),obj->func, obj->edgeType) ;
}

void setup ( ) {

Serial.begin(9600);

   pinMode ( pin1 , INPUT_PULLUP) ;
   pinMode ( pin2 , INPUT_PULLUP) ;
  initializeTable(&table[0],(uint8_t)pin1,&action1,userEdgeType);
  initializeTable(&table[1],(uint8_t)pin2,&action2,userEdgeType);

} 

void loop ( )
{


}

