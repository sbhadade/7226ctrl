//Automatic mode autoGear map
static const int gearMap[14][12] PROGMEM  {
{255,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //throttle position %
//-----------------------------------------------------------------------
{   0,       2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2 },
{  10,       2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2 },
{  20,       3,    3,    3,    3,    3,    3,    2,    2,    2,    2,    2 },
{  30,       3,    3,    3,    3,    3,    3,    3,    2,    2,    2,    2 },
{  45,       4,    4,    4,    4,    4,    4,    4,    3,    3,    3,    3 },
{  50,       4,    4,    4,    4,    4,    4,    4,    3,    3,    3,    3 },
{  60,       5,    5,    5,    5,    5,    5,    5,    4,    4,    4,    4 },
{  70,       5,    5,    5,    5,    5,    5,    5,    5,    5,    4,    4 },
{  80,       5,    5,    5,    5,    5,    5,    5,    5,    5,    4,    4 },
{  90,       5,    5,    5,    5,    5,    5,    5,    5,    5,    4,    4 },
{ 100,       5,    5,    5,    5,    5,    5,    5,    5,    5,    4,    4 },
{ 110,       5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5 },
{ 120,       5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5 }};
//vehicle speed, km/h

//MPC map in normal drive (=outside shifts. This is just to make a better mileage, MPC pressure could be 100% outside shifts too.)
static const int mpcNormalMap[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{ -10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{   0,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  20,      20,   25,   30,   30,   35,   53,   83,   93,   93,   95,  100 },
{  30,      15,   20,   25,   25,   30,   53,   80,   90,   90,   95,  100 },
{  40,      10,   15,   20,   20,   28,   53,   80,   85,   85,   90,  100 },
{  50,      10,   15,   20,   20,   28,   53,   80,   85,   85,   90,  100 },
{  60,      10,   15,   20,   20,   27,   53,   80,   85,   85,   90,  100 },
{  70,      10,   15,   20,   20,   27,   53,   80,   85,   85,   90,  100 },
{  80,       9,   15,   20,   20,   27,   53,   80,   85,   85,   90,  100 },
{  90,       9,   15,   20,   20,   27,   53,   80,   85,   85,   90,  100 },
{ 100,       9,   15,   20,   20,   27,   53,   80,   85,   85,   90,  100 }};
//oil temp

//Shift solenoid using time map, ms. Time to keep current flowing to shift pressure solenoid (SPC), shift solenoid,
//and to use shift-depedent maps for modulating pressure control (MPC) solenoid, instead of above map.
static const int shiftTimeMap[14][12] PROGMEM {
{999,       0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //shift pressure %
//-----------------------------------------------------------------------
{ -20,    1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100,  900,  900,  900 },
{ -10,    1100, 1100, 1100, 1100, 1100, 1100, 1100,  900,  900,  900,  900 },
{   0,    1100, 1100, 1100, 1100, 1100, 1100,  900,  900,  900,  900,  900 },
{  10,    1100, 1100, 1100, 1100, 1100, 1100,  900,  900,  900,  900,  900 },
{  20,    1100, 1100, 1100, 1000, 1000, 1000,  900,  900,  900,  900,  900 },
{  30,    1100, 1100, 1100, 1000, 1000,  900,  900,  800,  800,  900,  900 },
{  40,    1000, 1000, 1000, 1000,  900,  800,  900,  800,  800,  900,  900 },
{  50,    1000, 1000, 1000,  900,  900,  800,  900,  800,  800,  900,  900 },
{  60,    1000, 1000, 1000,  900,  800,  800,  800,  800,  800,  900,  900 },
{  70,    1000, 1000,  900,  900,  800,  800,  800,  800,  800,  900,  900 },
{  80,    1000,  900,  900,  800,  800,  800,  800,  800,  800,  900,  900 },
{  90,    1000,  900,  800,  800,  800,  800,  800,  800,  800,  900,  600 },
{ 100,    1000,  900,  800,  800,  800,  800,  800,  800,  800,  900,  600 }};
//oil temp

static const int boostControlPressureMap[14][6] PROGMEM {
{999,        1,    2,    3,    4,    5   },      // gear
//-----------------------------------------------------------------------
{ -20,       0,    0,    0,    0,    0   },
{ -10,       0,    0,    0,    0,    0   },
{   0,       0,    0,    0,    0,    0   },
{  10,       0,    0,    0,    0,    0   },
{  20,       0,    0,    0,    0,    0   },
{  30,       0,    0,    0,    0,    0   },
{  40,       0,    0,    0,    0,    0   },
{  50,       0,    0,    0,    0,    0   },
{  60,       0,    0,    0,    0,    0   },
{  70,       0,    0,    0,    0,    0   },
{  80,     150,  150,  150,  250,  250   },
{  90,     150,  150,  150,  250,  250   },
{ 100,     150,  150,  150,  250,  250   }};
//oil temp

//Shift maps
//******************************************* 1 -> 2 *******************************************

//SPC map, 1 -> 2
static const int spcMap12[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{ -10,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{   0,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{  10,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{  20,      23,   28,   38,   48,   48,   58,   68,   68,  100,  100,  100 },
{  30,      18,   23,   33,   43,   43,   53,   63,   63,  100,  100,  100 },
{  40,      17,   22,   32,   42,   42,   52,   62,   62,  100,  100,  100 },
{  50,      16,   21,   31,   41,   41,   51,   61,   61,  100,  100,  100 },
{  60,      15,   20,   25,   25,   25,   50,   60,   60,  100,  100,  100 },
{  70,      15,   20,   25,   25,   25,   50,   60,   60,  100,  100,  100 },
{  80,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 },
{  90,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 },
{ 100,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 }};
//oil temp

//MPC map, 1 -> 2
static const int mpcMap12[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{ -10,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{   0,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{  10,      36,   41,   51,   61,   61,   71,   78,   88,  100,  100,  100 },
{  20,      23,   28,   38,   48,   48,   58,   68,   68,  100,  100,  100 },
{  30,      18,   23,   33,   43,   43,   53,   63,   63,  100,  100,  100 },
{  40,      17,   22,   32,   42,   42,   52,   62,   62,  100,  100,  100 },
{  50,      16,   21,   31,   41,   41,   51,   61,   61,  100,  100,  100 },
{  60,      15,   20,   25,   25,   25,   50,   60,   60,  100,  100,  100 },
{  70,      15,   20,   25,   25,   25,   50,   60,   60,  100,  100,  100 },
{  80,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 },
{  90,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 },
{ 100,      12,   17,   22,   22,   22,   47,   60,   60,  100,  100,  100 }};
//oil temp




//******************************************* 2 -> 3 *******************************************

//SPC map, 2 -> 3
static const int spcMap23[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{ -10,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{   0,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{  10,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{  20,      67,   67,   67,   64,   74,   74,   72,   72,  100,  100,  100 },
{  30,      80,   80,   80,   80,   80,   80,   75,   75,  100,  100,  100 },
{  40,      80,   80,   80,   80,   80,   80,   72,   72,  100,  100,  100 },
{  50,      80,   80,   80,   80,   80,   80,   72,   72,  100,  100,  100 },
{  60,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  70,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  80,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  90,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100  },
{ 100,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100  }};
//oil temp

/*//MPC map, 2 -> 3
static const int mpcMap23[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{ -10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{   0,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  20,      20,   25,   30,   30,   35,   53,   83,   93,   93,   95,  100 },
{  30,      15,   20,   25,   25,   30,   50,   80,   90,   90,   95,  100 },
{  40,      10,   15,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  50,      10,   15,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  60,      10,   15,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  70,      10,   15,   20,   20,   25,   50,   65,   75,   85,   90,  100 },
{  80,       8,   13,   18,   18,   43,   50,   65,   75,   85,   90,  100 },
{  90,       8,   13,   18,   18,   43,   50,   65,   75,   85,   90,  100 },
{ 100,       8,   13,   18,   18,   43,   50,   65,   75,   85,   90,  100 }};
//oil temp*/
//MPC map, 2 -> 3 beefy
static const int mpcMap23[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{ -10,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{   0,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{  10,      41,   41,   46,   56,   66,   72,   73,   83,  100,  100,  100 },
{  20,      67,   67,   67,   64,   74,   74,   72,   72,  100,  100,  100 },
{  30,      80,   80,   80,   80,   80,   80,   75,   75,  100,  100,  100 },
{  40,      80,   80,   80,   80,   80,   80,   72,   72,  100,  100,  100 },
{  50,      80,   80,   80,   80,   80,   80,   72,   72,  100,  100,  100 },
{  60,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  70,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  80,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100 },
{  90,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100  },
{ 100,      80,   80,   80,   80,   80,   80,   71,   71,  100,  100,  100  }};
//oil temp




//******************************************* 3 -> 4 *******************************************

//SPC map, 3 -> 4
static const int spcMap34[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{ -10,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{   0,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  10,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  20,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  30,      75,   75,   75,  100,  100,  100,  100,  100,  100,  100,  100 },
{  40,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  50,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  60,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  70,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  80,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  90,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{ 100,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 }};
//oil temp

//MPC map, 3 -> 4
static const int mpcMap34[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{ -10,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{   0,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  10,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  20,      75,   75,   95,  100,  100,  100,  100,  100,  100,  100,  100 },
{  30,      75,   75,   75,  100,  100,  100,  100,  100,  100,  100,  100 },
{  40,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  50,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  60,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  70,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  80,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{  90,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 },
{ 100,      75,   75,   100,  100,  100,  100,  100,  100,  100,  100,  100 }};
//oil temp



//******************************************* 4 -> 5 *******************************************

//SPC map, 4 -> 5
static const int spcMap45[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{ -10,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{   0,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{  10,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{  20,      60,   60,   60,   60,   60,   60,   70,   70,  100,  100,  100 },
{  30,      73,   73,   73,   73,   73,   73,   73,   73,  100,  100,  100 },
{  40,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  50,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  60,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  70,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  80,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  90,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{ 100,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 }};
//oil temp

/*//MPC map, 4 -> 5
static const int mpcMap45[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{ -10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{   0,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  100 },
{  20,      20,   25,   30,   30,   35,   53,   83,   93,   93,   95,  100 },
{  30,      15,   20,   25,   25,   30,   50,   80,   90,   90,   95,  100 },
{  40,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  50,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  60,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  70,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  80,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{  90,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 },
{ 100,      10,   16,   20,   20,   25,   50,   75,   85,   85,   90,  100 }};
//oil temp*/
//MPC map, 4 -> 5 beefy
static const int mpcMap45[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{ -10,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{   0,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{  10,      65,   65,   65,   65,   65,   65,   75,   75,  100,  100,  100 },
{  20,      60,   60,   60,   60,   60,   60,   70,   70,  100,  100,  100 },
{  30,      73,   73,   73,   73,   73,   73,   73,   73,  100,  100,  100 },
{  40,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  50,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  60,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  70,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  80,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{  90,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 },
{ 100,      82,   82,   82,   82,   82,   82,   82,   82,  100,  100,  100 }};
//oil temp


//******************************************* 5 -> 4 *******************************************

//SPC map, 5 -> 4
static const int spcMap54[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{ -10,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{   0,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  10,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  20,      58,   78,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  30,      58,   78,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  40,      74,   74,   84,   94,   95,  100,  100,  100,  100,  100,  100 },
{  50,      73,   73,   93,   100,   95,  100,  100,  100,  100,  100,  100 },
{  60,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  70,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  80,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  90,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{ 100,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 }};
//oil temp

//MPC map, 5 -> 4
static const int mpcMap54[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{ -10,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{   0,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  10,      58,   68,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  20,      58,   78,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  30,      58,   78,   93,   98,  100,  100,  100,  100,  100,  100,  100 },
{  40,      74,   74,   84,   94,   95,  100,  100,  100,  100,  100,  100 },
{  50,      73,   73,   93,   100,   95,  100,  100,  100,  100,  100,  100 },
{  60,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  70,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  80,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{  90,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 },
{ 100,      82,   82,   92,   100,   95,  100,  100,  100,  100,  100,  100 }};
//oil temp



//******************************************* 4 -> 3 *******************************************

//SPC map: 4 -> 3
static const int spcMap43[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      51,   51,   51,   71,   71,   81,   88,   88,  90,  90,  90 },
{ -10,      51,   51,   51,   71,   71,   81,   88,   88,  90,  90,  90 },
{   0,      51,   51,   51,   71,   71,   81,   88,   88,  90,  90,  90 },
{  10,      51,   51,   91,   91,   91,   81,   88,   88,  90,  90,  90 },
{  20,      61,   61,   91,   91,   91,   81,   88,   88,  90,  90,  90  },
{  30,      71,   71,   91,   91,   81,   81,   88,   88,  90,  90,  90  },
{  40,     71,   71,   71,   71,   71,   81,   88,   88,  90,  90,  90 },
{  50,      71,   71,   71,   71,   71,  81,   88,   88,  90,  90,  90  },
{  60,    71,   71,   71,   71,   71,    81,   88,   88,  90,  90,  90  },
{  80,     71,   71,   71,   71,   71,   81,   88,   88,  90,  90,  90  },
{  70,     71,   71,   71,   71,   71,    81,   88,   88,  90,  90,  90  },
{  90,      95,   95,   25,   65,   70,   80,   80,   80,  90,  90,  90 },
{ 100,      95,   95,   25,   65,   70,   80,   80,   80,  90,  90,  90 }};
//oil temp

//MPC map, 4 -> 3
static const int mpcMap43[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      51,   51,   51,   51,   61,   81,   88,   88,  90,  90,  90 },
{ -10,      51,   51,   51,   51,   61,   81,   88,   88,  90,  90,  90 },
{   0,      51,   51,   51,   51,   61,   81,   88,   88,  90,  90,  90 },
{  10,      51,   51,   51,   51,   61,   81,   88,   88,  90,  90,  90 },
{  20,      61,   61,   91,   61,   61,   81,   88,   88,  90,  90,  90  },
{  30,      71,   71,   91,   71,   71,   81,   88,   88,  90,  90,  90  },
{  40,     71,   71,   91,   91,   91,   81,   88,   88,  90,  90,  90 },
{  50,      71,   71,   91,   91,   91,  81,   88,   88,  90,  90,  90  },
{  60,    71,   71,   91,   91,   91,    81,   88,   88,  90,  90,  90  },
{  80,     71,   71,   91,   91,   91,   81,   88,   88,  90,  90,  90  },
{  70,     71,   71,   91,   91,   91,    81,   88,   88,  90,  90,  90  },
{  90,      95,   95,   95,   95,   90,   80,   80,   80,  90,  90,  90 },
{ 100,      95,   95,   95,   95,   90,   80,   80,   80,  90,  90,  90 }};
//oil temp



//******************************************* 3 -> 2 *******************************************

//SPC map, 3 -> 2
static const int spcMap32[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{ -10,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{   0,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{  10,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{  20,      48,   48,   48,   48,   68,   68,   78,   85,  90,  90,  90 },
{  30,      35,   35,   35,   35,   60,   60,   70,   70,  90,  90,  90 },
{  40,      34,   34,   34,   34,   54,   54,   64,   64,  90,  90,  90 },
{  50,      32,   32,   32,   32,   52,   52,   62,   62,  90,  90,  90 },
{  60,      31,   31,   31,   31,   51,   51,   61,   61,  90,  90,  90 },
{  70,      30,   30,   30,   30,   50,   50,   60,   60,  90,  90,  90 },
{  80,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 },
{  90,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 },
{ 100,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 }};
//oil temp

/*//MPC map, 3 -> 2
static const int mpcMap32[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  90 },
{ -10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  90 },
{   0,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  90 },
{  10,      23,   28,   33,   33,   38,   56,   86,   96,   96,   98,  90 },
{  20,      20,   25,   30,   30,   35,   53,   83,   93,   93,   95,  90 },
{  30,      15,   20,   25,   25,   30,   50,   80,   90,   90,   95,  90 },
{  40,      10,   15,   20,   20,   45,   50,   75,   85,   85,   90,  90 },
{  50,      10,   15,   20,   20,   45,   60,   75,   85,   85,   90,  90 },
{  60,      10,   15,   20,   20,   45,   60,   75,   85,   85,   90,  90 },
{  70,      10,   15,   20,   20,   45,   60,   75,   85,   85,   90,  90 },
{  80,       8,   13,   18,   18,   43,   40,   65,   75,   75,   90,  90 },
{  90,       8,   13,   18,   18,   43,   40,   65,   75,   75,   90,  90 },
{ 100,       8,   13,   18,   18,   43,   40,   65,   75,   75,   90,  90 }};
//oil temp*/
//MPC map, 3 -> 2 beefy
static const int mpcMap32[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{ -10,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{   0,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{  10,      50,   50,   50,   50,   70,   70,   80,   80,  90,  90,  90 },
{  20,      48,   48,   48,   48,   68,   68,   78,   85,  90,  90,  90 },
{  30,      35,   35,   35,   35,   60,   60,   70,   70,  90,  90,  90 },
{  40,      34,   34,   34,   34,   54,   54,   64,   64,  90,  90,  90 },
{  50,      32,   32,   32,   32,   52,   52,   62,   62,  90,  90,  90 },
{  60,      31,   31,   31,   31,   51,   51,   61,   61,  90,  90,  90 },
{  70,      30,   30,   30,   30,   50,   50,   60,   60,  90,  90,  90 },
{  80,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 },
{  90,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 },
{ 100,      28,   28,   28,   28,   48,   50,   60,   60,  90,  90,  90 }};
//oil temp



//******************************************* 2 -> 1 *******************************************

//SPC map, 2 -> 1
static const int spcMap21[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{ -10,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{   0,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{  10,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{  20,      43,   43,   43,   48,   68,   68,   78,   78,  90,  90,  90 },
{  30,      28,   28,   28,   33,   53,   53,   63,   63,  90,  90,  90 },
{  40,      26,   26,   26,   31,   51,   51,   61,   61,  90,  90,  90 },
{  50,      25,   25,   25,   30,   50,   50,   60,   60,  90,  90,  90 },
{  60,      23,   23,   23,   30,   50,   50,   60,   60,  90,  90,  90 },
{  70,      23,   23,   23,   30,   50,   50,   60,   60,  90,  90,  90 },
{  80,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 },
{  90,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 },
{ 100,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 }};
//oil temp


//MPC map, 2 -> 1
static const int mpcMap21[14][12] PROGMEM {
{999,        0,   10,   20,   30,   40,   50,   60,   70,   80,   90,   100 },   //load %
//-----------------------------------------------------------------------
{ -20,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{ -10,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{   0,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{  10,      45,   45,   45,   50,   70,   70,   80,   80,  90,  90,  90 },
{  20,      43,   43,   43,   48,   68,   68,   78,   78,  90,  90,  90 },
{  30,      28,   28,   28,   33,   53,   53,   63,   63,  90,  90,  90 },
{  40,      26,   26,   26,   31,   51,   51,   61,   61,  90,  90,  90 },
{  50,      25,   25,   25,   30,   50,   50,   60,   60,  90,  90,  90 },
{  60,      23,   23,   23,   30,   50,   50,   60,   60,  90,  90,  90 },
{  70,      23,   23,   23,   30,   50,   50,   60,   60,  90,  90,  90 },
{  80,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 },
{  90,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 },
{ 100,      19,   21,   21,   28,   48,   50,   60,   60,  90,  90,  90 }};
//oil temp
