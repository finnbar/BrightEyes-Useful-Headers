/* Letters.h for Bright Eyes - set and animate a 5x5 grid
 * Written by Finnbar Keating for TWSU
 * CC-Attribution-BY-ShareAlike;
 */
;
int ref[42];  //this is the reference, which we'll build the letters on
int ref2[42];
int ref3[42];
int ref4[42];
int ref5[42];
int ref6[42];
int ref7[42];
unsigned char DMXreturn[180];
const int lup[] =  //these are the lookup table in seven parts
{
  0  ,0  ,0  ,1  ,2  ,3  ,4  ,5  ,6  ,7  ,8  ,9  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,88 ,89 ,90 ,91 ,92 ,93 ,94 ,95 ,96 ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup2[] =  
{
  0  ,10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,18 ,19 ,20 ,21 ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,97 ,98 ,99 ,100,101,102,103,104,105,106,107,108,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup3[] =  
{
  22 ,23 ,24 ,25 ,26 ,27 ,28 ,29 ,30 ,31 ,32 ,33 ,34 ,35 ,36 ,0  ,0  ,0  ,0  ,0  ,0  ,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup4[] =  
{
  37 ,38 ,39 ,40 ,41 ,42 ,43 ,44 ,45 ,46 ,47 ,48 ,49 ,50 ,51 ,0  ,0  ,0  ,0  ,0  ,0  ,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup5[] =  
{
  52 ,53 ,54 ,55 ,56 ,57 ,58 ,59 ,60 ,61 ,62 ,63 ,64 ,65 ,66 ,0  ,0  ,0  ,0  ,0  ,0  ,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup6[] =  
{
  0  ,67 ,68 ,69 ,70 ,71 ,72 ,73 ,74 ,75 ,76 ,77 ,78 ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,154,155,156,157,158,159,160,161,162,163,164,165,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0};
const int lup7[] =  
{
  0  ,0  ,0  ,79 ,80 ,81 ,82 ,83 ,84 ,85 ,86 ,87 ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,166,167,168,169,170,171,172,173,174,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0};


void startLetter(const int b[]) {   //sets letter in position (frame 1) to be moved by playLetter
    for(int x = 0; x < 5; x++) {   //places letter in lookup arrays
      ref2[x + 36] = b[x];
      ref3[x + 36] = b[x + 5];
      ref4[x + 36] = b[x + 10];
      ref5[x + 36] = b[x + 15];
      ref6[x + 36] = b[x + 20];
  }
}

void playLetter() {    //moves all letters one space to the left
  for(int b = 1; b < 42; b++) {  //mark all new locations with "2"
    if(ref2[b] == 1) {
      ref2[b - 1] = 2;
    }
  }
  for(int b = 1; b < 42; b++) {
    if(ref3[b] == 1) {
      ref3[b - 1] = 2;
    }
  }
  for(int b = 1; b < 42; b++) {
    if(ref4[b] == 1) {
      ref4[b - 1] = 2;
    }
  }
  for(int b = 1; b < 42; b++) {
    if(ref5[b] == 1) {
      ref5[b - 1] = 2;
    }
  }
  for(int b = 1; b < 42; b++) {
    if(ref6[b] == 1) {
      ref6[b - 1] = 2;
    }
  }
  for(int b = 0; b < 42; b++) {   //now reduce all non-zeroes by one.
    if(ref2[b] > 0) {
      ref2[b]--;
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref3[b] > 0) {
      ref3[b]--;
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref4[b] > 0) {
      ref4[b]--;
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref5[b] > 0) {
      ref5[b]--;
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref6[b] > 0) {
      ref6[b]--;
    }
  }
  for(int b = 0; b < 42; b++) {  //write to, but don't send DMX
    if(ref2[b] == 1) {
      if(lup2[b] > 0) {
        DMXreturn[lup2[b]] = 130;
      }
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref3[b] == 1) {
      if(lup3[b] > 0) {
        DMXreturn[lup3[b]] = 130;
      }
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref4[b] == 1) {
      if(lup4[b] > 0) {
        DMXreturn[lup4[b]] = 130;
      }
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref5[b] == 1) {
      if(lup5[b] > 0) {
        DMXreturn[lup5[b]] = 130;
      }
    }
  }
  for(int b = 0; b < 42; b++) {
    if(ref6[b] == 1) {
      if(lup6[b] > 0) {
        DMXreturn[lup6[b]] = 130;
      }
    }
  }
}
