
#include "DxLib.h"


#define GAME_WIDTH 800		//画面の横幅
#define GAME_HEIGHT 600		//画面の縦幅
#define GAME_COLOR 32		//使用する画面の色の数



#define GAME_WINDOW_NAME "GAME_TITLE"
#define GAME_WINDOW_MODECHANGE	TRUE

#define GAME_FPS_SPEED                       60		//FPS数

#define SET_WINDOW_ST_MODE_DEFAULT          0
#define SET_WINDOW_ST_MODE_TITLE_NON        1
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE 2
#define SET_WINDOW_ST_MODE_FLAME_NONE		3

#define GAME_TITLEIMAGE "TITLEIMAGE\\Title.png"						//タイトル画像
#define GAME_TITLE_BACKIMAGE "BACKIMAGE\\TITLE_BACK.jpg"			//タイトル背景画像

#define GAME_PROLOGUE "BACKIMAGE\\PROLOGUE.png"						//プロローグ

#define GAME_MUSIC_OP        "MUSIC\\op.mp3"        //タイトル画面BGM
#define GAME_MUSIC_MAP_BGM   "MUSIC\\MAP_BGM.mp3"   //道中BGM
#define GAME_MUSIC_BOSS      "MUSIC\\BOSS_BGM.mp3"  //BOSSBGM


#define GAME_MAP_1 "GAME_MAP\\A2.png"           //マップチップの画像
#define GAME_MAP_2 "GAME_MAP\\Cave1-EarthA5.png"
#define GAME_MAP_3 "GAME_MAP\\Cave1-RockA5.png"
#define GAME_MAP_4 "GAME_MAP\\Ruin-F.png"
#define ITEM       "ITEMIMAGE\\ITEM.png"  //アイテムの画像

//マップのcsv
#define GAME_MAP_CSV_1 "GAME_MAP\\F1.csv"				//1階
#define GAME_MAP_CSV_2 "GAME_MAP\\F2.csv"				//2階
#define GAME_MAP_CSV_3 "GAME_MAP\\F3.csv"				//3階
#define GAME_MAP_CSV_4 "GAME_MAP\\F4.csv"				//4階
#define GAME_MAP_CSV_5 "GAME_MAP\\Boss.csv"				//ボス

#define GAME_MAP_CSV_6 "GAME_MAP\\map_under.csv"		//map下地

#define GAME_MAP_CSV_7 "GAME_MAP\\Bossmap_under.csv"	//ボスmap下地

#define GAME_MAP_CSV_1_K "GAME_MAP\\kaidan.csv"			//1階の階段
#define GAME_MAP_CSV_2_K "GAME_MAP\\kaidan2.csv"		//2階の階段
#define GAME_MAP_CSV_3_K "GAME_MAP\\kaidan3.csv"		//3階の階段
#define GAME_MAP_CSV_4_K "GAME_MAP\\kaidan4.csv"		//4階の階段

#define GAME_MAP_CSV_1_A "GAME_MAP\\F1atari.csv"        //1階の当たり判定
#define GAME_MAP_CSV_2_A "GAME_MAP\\F2atari.csv"		//2階の当たり判定
#define GAME_MAP_CSV_3_A  "GAME_MAP\\F3atari.csv"		//3階の当たり判定
#define GAME_MAP_CSV_4_A  "GAME_MAP\\F4atari.csv"		//4階の当たり判定
#define GAME_MAP_CSV_BOSS "GAME_MAP\\bossatari.csv"		//ボスmapの当たり判定

//マップの名称
#define GAME_MAP_NAME_SITA		"MAPDATA_SITA"
#define GAME_MAP_F1				"MAPDATA_F1"
#define GAME_MAP_F2				"MAPDATA_F2"
#define GAME_MAP_F3				"MAPDATA_F3"
#define GAME_MAP_F4				"MAPDATA_F4"
#define GAME_MAP_F1_K			"MAPDATA_F1_KAIDAN"
#define GAME_MAP_F2_K			"MAPDATA_F2_KAIDAN"
#define GAME_MAP_F3_K			"MAPDATA_F3_KAIDAN"
#define GAME_MAP_F4_K			"MAPDATA_F4_KAIDAN"
#define GAME_MAP_F1_ITEM		"MAPDATA_F1_ITEM"
#define GAME_MAP_BOSS_SITA		"MAPDATA_BOSS_UNDER"
#define GAME_MAP_BOSS			"MAPDATA_BOSS"

#define GAME_MAP_BUN_YOKO_CNT_MAX 16		//各マップチップの横の最大分割数
#define GAME_MAP_BUN_TATE_CNT_MAX 16		//各マップチップの縦の最大分割数

#define GAME_MAP_1_YOKO_MAX 16		//GAME_MAP_1の横の最大分割数
#define GAME_MAP_1_TATE_MAX 12		//GAME_MAP_1の縦の最大分割数

#define GAME_MAP_2_YOKO_MAX 8		//GAME_MAP_2の横の最大分割数
#define GAME_MAP_2_TATE_MAX 16	    //GAME_MAP_2の縦の最大分割数

#define GAME_MAP_3_YOKO_MAX 8		//GAME_MAP_3の横の最大分割数
#define GAME_MAP_3_TATE_MAX 16	    //GAME_MAP_3の縦の最大分割数

#define GAME_MAP_4_YOKO_MAX 16		//GAME_MAP_4の横の最大分割数
#define GAME_MAP_4_TATE_MAX 16	    //GAME_MAP_4の縦の最大分割数

#define GAME_MAP_YOKO 50		//ゲームマップの横サイズ
#define GAME_MAP_TATE 38		//ゲームマップの縦サイズ

#define GAME_MAP_YOKO_SIZE 32	//ゲームマップの1マスのサイズ
#define GAME_MAP_TATE_SIZE 32

#define GAME_MAP_OK_KIND 100 //通行できるマップの種類
#define GAME_MAP_NG_KIND 100 //通行できないマップの種類

#define GAME_MAP_KAIDAN 4    //階段の数

#define GAME_CHARA                "CHARAIMAGE\\char_p04.png"  //キャラの画像
#define GAME_CHARA_BUN_YOKO_CNT 12		//キャラの分割数(横)
#define GAME_CHARA_BUN_TATE_CNT 8       //キャラの分割数(縦)
#define GAME_CHARA_YOKO_SIZE 24			//キャラの大きさ(横)
#define GAME_CHARA_TATE_SIZE 32			//キャラの大きさ(縦)
#define GAME_CHARA_MOTION_NUM 12		//キャラの画像数
#define GAME_CHARA_KIND_YOKO 3		    //キャラの横の種類
#define GAME_CHARA_KIND_TATE 4		    //キャラの縦の種類

#define GAME_CHARA_START_X 5	       //キャラの最初の位置
#define GAME_CHARA_START_Y 2           //キャラの最初の位置
#define GAME_CHARA_SPEED 2             //キャラのスピード

#define GAME_PLAYER_ITEM_MAX 100  //プレイヤーのアイテム保持MAX


//アイテム関連
#define GAME_ITEMIMAGE_CSV_1   "ITEMIMAGE\\F1_アイテム.csv"  //1階のアイテム
#define GAME_ITEM_BUN_YOKO_CNT 4		//アイテムの分割数(横)
#define GAME_ITEM_BUN_TATE_CNT 4		//アイテムの分割数(縦)
#define GAME_ITEM_YOKO_SIZE 32			//アイテムの大きさ(横)
#define GAME_ITEM_TATE_SIZE 32			//アイテムの大きさ(縦)


#define GAME_MAP_KIND		5
#define GAME_MAP_ITEM_KIND	4			//アイテムの種類

//敵関連

#define GAME_ENE_COBRA_IMAGE   "ENEIMAGE\\cobras.png"

#define GAME_ENE_BOSS_IMAGE    "ENEIMAGE\\oni.png"    //BOSSの画像

#define GAME_BOSS_FIRST_MUKI_D 0 //最初の画像の向き(下)
#define GAME_BOSS_FIRST_MUKI_L 3 //最初の画像の向き(左)
#define GAME_BOSS_FIRST_MUKI_R 6 //最初の画像の向き(右)
#define GAME_BOSS_FIRST_MUKI_U 9 //最初の画像の向き(上)

#define GAME_ENE_BOSS_BUN_YOKO_CNT 4 //BOSSの分割数
#define GAME_ENE_BOSS_BUN_TATE_CNT 4

#define GAME_ENE_BOSS_YOKO_SIZE 64 //BOSSの大きさ
#define GAME_ENE_BOSS_TATE_SIZE 112

#define GAME_ENE_BOSS_MOTION_NUM 16 //BOSSの画像数

#define GAME_ENE_BOSS_KIND_YOKO 4 //BOSSの画像数
#define GAME_ENE_BOSS_KIND_TATE 4 //BOSSの画像数

#define GAME_BOSS_NUM 1	//bossの数
#define GAME_BOSS_SPEED 2 //BOSSのスピード

//#######列挙型#########

enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_PUOLOGUE,	//プロローグ画面
	GAME_SCENE_PLAY,	//プレイ画面
//	GAME_SCENE_GAMEOVER,	//GameOver画面
//    GAME_SCENE_MOVE_SCENE,	//シーン遷移画面
GAME_SCENE_END		//エンド画面
};

enum GAME_MAP_SCENE
{
	GAME_MAP_SCENE_F1, //F1
	GAME_MAP_SCENE_F2, //F2
	GAME_MAP_SCENE_F3, //F3
	GAME_MAP_SCENE_F4, //F4
	GAME_MAP_SCENE_BOSS //BOSS
}; //マップの種類

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 54
}; //キャラの種類の列挙型



enum MAP_IMAGE {
	M_S = 5,   //階段
	M_B = 15   //空白
};

enum ITEM_NAME {
	BRANCH,  //枝
	COPPER,  //銅
	IRON,   //鉄
	GOLD    //金
}; //アイテムの名前

struct STRUCT_GAZOU {
	int Handle;			//画像のハンドル
	char FilePath[128];	//ファイルのパス
	int X;				//横の位置
	int Y;				//縦の位置
	int Width;			//横のサイズ
	int Height;			//縦のサイズ
	int C_Width;		//横の中心位置
	int C_Height;		//縦の中心位置
}; //画像構造体

struct STRUCT_IMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//画像のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];	//縦の中心位置

};	//STRUCT_IMAGE構造体

struct STRUCT_MAP
{
	char name[64];	//マップの名称
	char FilePath[128];		//ファイルのパス
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];	//マップのCSVのデータ
	int mapdate_Init[GAME_MAP_TATE][GAME_MAP_YOKO];	//マップのCSVデータ

	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //画像のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];	//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //縦の中心位置

	int mapNGKind[GAME_MAP_NG_KIND];					//マップ判定の種類(通行できない)
	int mapOKKind[GAME_MAP_OK_KIND];					//マップ判定の種類(通行できる)

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];			//当たり判定の領域(通行できない)
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//当たり判定の領域(通行できない)(最初)

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];			//当たり判定の領域(通行できる)
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//当たり判定の領域(通行できる)(最初)

	RECT rectMap_Item[GAME_MAP_TATE][GAME_MAP_YOKO];			//アイテム当たり判定の領域(通行できる)
	RECT rectMap_Item_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//当たり判定の領域(通行できる)(最初)

	RECT rectMap_Kaidan[GAME_MAP_TATE][GAME_MAP_YOKO];		//階段
	RECT rectMap_Kaidan_First[GAME_MAP_TATE][GAME_MAP_YOKO];

}; //MAP構造体

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//画像のハンドル
	int X[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//横の位置
	int Y[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//縦の位置
	int Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];		//縦のサイズ
	int Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//横のサイズ
	int C_Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//横の中心位置
	int C_Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//縦の中心位置
}; //STRUCT_CHARAIMAGE構造体

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charimage;	//画像
	int Handle[GAME_CHARA_MOTION_NUM];//画像のハンドル
	int X;							//縦の位置
	int Y;							//横の位置
	int Width;						//横のサイズ
	int Height;						//縦のサイズ
	int C_Width;					//横の中心位置
	int C_Height;					//縦の中心位置
	int NowHandleNum;				//現在の画像のハンドル
	int NowHandleCnt;				//現在のハンドルカウント
	int NowHandleCntMAX;			//現在のハンドルカウントMAX

	int Speed;						//速度
	int MoveDistX;					//移動距離X
	int MoveDistY;					//移動距離Y

	BOOL CanMoveUp;					//上に行けるか
	BOOL CanMoveDown;				//下の行けるか
	BOOL CanMoveLeft;				//左の行けるか
	BOOL CanMoveRight;				//右に行けるか

	BOOL ScrollOK_X;				//スクロールできるかどうか
	BOOL ScrollOK_Y;

	int atariX;			//当たり判定のX位置
	int atariY;			//当たり判定のY位置
	int atariWidth;		//当たり判定の幅
	int atariHeight;	//当たり判定の高さ	
	RECT atariRect;		//当たり判定の矩形領域

	char name[255];		//名前


	int item[GAME_MAP_ITEM_KIND]; //持っているアイテムの数

	RECT rect_act;	//行動の領域
	RECT rect_item;  //情報の領域[アイテム]

	int act_kind;				//行動の種類
	BOOL IsActKeyDown_left;		//行動を押したとき(右)
	BOOL IsActKeyDown_right;	//行動を押したとき(左)

}; //STRUCT_CHARADATA構造体

struct STRUCT_BOSS
{
	STRUCT_CHARAIMAGE bossimage;	//画像
	int Handle[GAME_ENE_BOSS_MOTION_NUM];//画像のハンドル
	int X;							//縦の位置
	int Y;							//横の位置
	int Width;						//横のサイズ
	int Height;						//縦のサイズ
	int C_Width;					//横の中心位置
	int C_Height;					//縦の中心位置
	int NowHandleNum;				//現在の画像のハンドル
	int NowHandleCnt;				//現在のハンドルカウント
	int NowHandleCntMAX;			//現在のハンドルカウントMAX

	int Speed;

	BOOL CanMoveLeft;					//左に行けるか
	BOOL CanMoveRight;					//右に行けるか

	BOOL IsAlive;						//生きているかどうか
	BOOL IsView;						//表示できるとき
	int muki;							//敵の向き
	int viewStartPointX;				//プレイヤーがこのX位置まで来ると敵が表示される
	int viewStartPointY;				//プレイヤーがこのY位置まで来ると敵が表示される
	int SetFirstX;						//敵の最初のX位置
	int SetFirstY;						//敵の最初のY位置
	int SetFirstmuki;					//敵の最初の向き
	int IsPassed;						//通過した

	int atariX;							//当たり判定のX位置
	int atariY;							//当たり判定のY位置
	int atariWidth;						//当たり判定の幅
	int atariHeight;					//当たり判定の高さ
	RECT atariRect;						//当たり判定の矩形領域
}; //BOSS構造体

struct STRUCT_MUSIC
{
	int Handle;					//音のハンドル
	char FilePath[128];			//ファイルのパス
	int Playtype;				//音の再生方法
};	//音構造体

//###### 名前の再定義 ########
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAP MAP;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;
typedef STRUCT_BOSS BOSS;
typedef STRUCT_MUSIC MUSIC;

GAZOU  BackGround;	//タイトル背景画像
GAZOU  BackGround_T;  //タイトル画像
GAZOU  BackGround_P;	//プロローグ
GAZOU  Boss;			//ボス

MAP MapImage;
MAP MapImage_U[GAME_MAP_KIND];  //下地のマップ画像
MAP MapImage_W[GAME_MAP_KIND];  //壁などのマップ画像
MAP MapImage_S[GAME_MAP_KIND];  //階段のマップ画像
MAP MapImage_A[GAME_MAP_KIND];  //当たり判定の画像

MAP ItemImage_1[GAME_MAP_ITEM_KIND];  //1階のアイテム画像

MUSIC MUSIC_MY_TITLE;
MUSIC MUSIC_MY_BGM_1;
MUSIC MUSIC_MY_BOSS;

//######### グローバル変数 #######

//ウィンドウ関係
WNDPROC WndProc;			//ウィンドウプロシージャのアドレス
BOOL IsWM_CREATE = FALSE;   //WM_CREATEが正常に起動したか判断する

//FPS関連
int StartTimeFps;					//測定開始時刻
int CountFps;						//カウンタ
float CalcFps;						//計算結果
int SampleNumFps = GAME_FPS_SPEED;  //平均を取るサンプル

//キーボード関係
char AllKeyState[256];	//すべてのキーの状態が入る

//シーン関係
int GameSceneNow = (int)GAME_SCENE_TITLE;	//最初のゲーム画面をタイトル画面に設定
int GameMapNow = (int)GAME_MAP_SCENE_F1;

int MapNowPos = 0;  //現在のマップ
MAP MapDataKind[5];

//キャラ系
CHARAIMAGE CharaImage;		//キャラの画像
CHARADATA  Myplayer;		//キャラのデータ

CHARAIMAGE bossimage;             //ボスの画像
BOSS  oni;
BOSS boss[GAME_BOSS_NUM];   //ボス
//アイテム系
int MapKaidanKind[GAME_MAP_KAIDAN] = { 5 };	//階段の番号


int MapItemKind[GAME_MAP_ITEM_KIND] = { 0,1,2,3 };	//アイテムの番号
char ItemName[GAME_MAP_ITEM_KIND][128] = { "木の枝","銅","鉄","金" };	//アイテム名

bool itemdrowflag = false;

//プレイヤーのイメージ画像の番号を設定する
int PlayerImageNum[GAME_CHARA_MOTION_NUM];

int ScrollCntYoko = 0;	//スクロールカウンタ(横)
int ScrollDistPlusYoko = 1;  //スクロールする距離(横)


int ScrollCntTate = 0;  //スクロールカウンタ(縦)
int ScrollDistPlusTate = 1;  //スクロールする距離(縦)

BOOL IsActiveCheck = FALSE;	//画面のアクティブチェックの有効化

int StopActiveStartTime = 0;	//非アクティブ化の開始時間
int StopActiveStopTime = 0;		//非アクティブ化の終了時間
int StopActiveTotaTime = 0;		//非アクティブ化の経過時間

//####### プロトタイプ宣言 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM); //自作ウィンドウプロシージャ

VOID MY_FPS_UPDATE(VOID);		//FPS値を計測、更新をする関数
VOID MY_FPS_DRAW(VOID);			//FPS値を描画する関数
VOID MY_FPS_WAIT(VOID);			//FPS値を計測し、待つ関数

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キー入力状態を更新する関数

VOID MY_GAME_TITLE(VOID);		//タイトル画面
VOID MY_GAME_PROLOGUE(VOID);	//プロローグ画面
VOID MY_GAME_PLAY(VOID);		//プレイ画面
VOID MY_GAME_END(VOID);			//エンド画面

VOID MY_PLAY_BACKIMAGE_DRAW(VOID);	//背景画像を描画する関数

VOID MY_PLAY_MAP_DRAW(MAP);			//マップを表示する関数
VOID MY_PLAY_MAP_DRAW_ATARI(MAP *);		//マップの当たり判定を描画する関数
BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);			//画像を読み込む設定をする関数

BOOL MY_PLAY_INIT(VOID);	//初期化関数
VOID MY_PG_INIT(VOID);	//プロローグ画像位置初期化

BOOL MY_MAP_READ_CSV_KIND_SET(MAP *); //マップ判定の種類を設定する

BOOL MY_MAP_READ_CSV_NUM(MAP *, const char *, const char *);			//ゲームマップのF1CSVを読み込む関数

BOOL MY_MAP_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数


BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *, int, int, int, int, int, const char *);

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	//プレイヤーを初期化する関数
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);	//プレイヤーを表示する関数

VOID MY_PLAY_PLAYER_OPERATION(VOID);						//プレイヤーを操作する関数
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);			//プレイヤーをキー操作する関数

VOID MY_SET_PLAYER_ATARI(CHARADATA *);			//プレイヤーの当たり判定の領域を設定する関数

VOID MY_PLAY_ENEMY_DRAW_DETAIL(BOSS *);		//敵を表示する(詳細)関数
VOID MY_PLAY_ENEMY_DRAW(BOSS);						//敵を表示する関数

VOID MY_PLAY_ENEMY_OPERATION_DETAIL(BOSS *);	//敵を操作する(詳細)関数
VOID MY_PLAY_ENEMY_OPERATION(VOID);					//敵を操作する関数

VOID MY_SET_ENEMY_ATARI(BOSS *);			//敵の当たり判定の領域を設定する関数

VOID MY_PLAY_ENEMY_MAP_COLLISION(BOSS *);  //敵とマップとの接触関数

BOOL MY_INIT_ENEMY(BOSS *, CHARAIMAGE, int *, int, int, int, int, int, int, int, BOOL);	//敵を初期化する関数

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);		//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);

int MapData[GAME_MAP_TATE][GAME_MAP_YOKO];  //マップのデータfp
FILE *fp_map_csv;  //ファイルの管理番号(ポインタ)
int MapData_Init[GAME_MAP_TATE][GAME_MAP_YOKO]; //マップのデータ(初期化用)

VOID MY_PLAY_PLAYER_GETITEM(VOID);  //アイテムを取得する関数

VOID MY_MAP_SCENE_MOVE(VOID);	//階段に触れるとマップを移動させる関数

BOOL MY_MUSIC_LOAD(MUSIC *, const char *);

//############ プログラムで最初に実行される関数 ###########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR); //指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);		//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//タイトル文字

	if (DxLib_Init() == -1) {			//DXライブラリ初期化処理
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);		//Drow系関数は裏画面に表示

	//MY_MAP_READ_CSV_UE_KIND_SET(&MapImage_S);	//マップの上の種類を設定
	//MY_MAP_READ_CSV_NAKA_KIND_SET(&MapImage_W);	//マップの中の種類を設定
	//MY_MAP_READ_CSV_SITA_KIND_SET(&MapImage_U);	//マップの下の種類を設定
	MY_MAP_READ_CSV_KIND_SET(MapImage_A);

	MY_MAP_READ_CSV_NUM(&MapImage_W[GAME_MAP_SCENE_F1], GAME_MAP_CSV_1, GAME_MAP_F1);		    //マップ１の上を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_U[GAME_MAP_SCENE_F1], GAME_MAP_CSV_6, GAME_MAP_NAME_SITA);	   //マップ１の下を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_S[GAME_MAP_SCENE_F1], GAME_MAP_CSV_1_K, GAME_MAP_F1_K);		//マップ１の階段を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_A[GAME_MAP_SCENE_F1], GAME_MAP_CSV_1_A, GAME_MAP_F1);        //マップ１のatariを読み込み、当たり判定の領域をつくる

	MY_MAP_READ_CSV_NUM(&MapImage_W[GAME_MAP_SCENE_F2], GAME_MAP_CSV_2, GAME_MAP_F2);		    //マップ2の上を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_S[GAME_MAP_SCENE_F2], GAME_MAP_CSV_2_K, GAME_MAP_F2_K);		//マップ2の階段を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_A[GAME_MAP_SCENE_F2], GAME_MAP_CSV_2_A, GAME_MAP_F2);        //マップ2のatariを読み込み、当たり判定の領域をつくる

	MY_MAP_READ_CSV_NUM(&MapImage_W[GAME_MAP_SCENE_F3], GAME_MAP_CSV_3, GAME_MAP_F3);		    //マップ2の上を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_S[GAME_MAP_SCENE_F3], GAME_MAP_CSV_3_K, GAME_MAP_F3_K);		//マップ2の階段を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_A[GAME_MAP_SCENE_F3], GAME_MAP_CSV_3_A, GAME_MAP_F3);        //マップ2のatariを読み込み、当たり判定の領域をつくる

	MY_MAP_READ_CSV_NUM(&MapImage_W[GAME_MAP_SCENE_F4], GAME_MAP_CSV_4, GAME_MAP_F4);		    //マップ2の上を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_S[GAME_MAP_SCENE_F4], GAME_MAP_CSV_4_K, GAME_MAP_F4_K);		//マップ2の階段を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_A[GAME_MAP_SCENE_F4], GAME_MAP_CSV_4_A, GAME_MAP_F4);        //マップ2のatariを読み込み、当たり判定の領域をつくる

	MY_MAP_READ_CSV_NUM(&MapImage_W[GAME_MAP_SCENE_BOSS], GAME_MAP_CSV_5, GAME_MAP_BOSS);        //BossMapの上を読み込み,当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_A[GAME_MAP_SCENE_BOSS], GAME_MAP_CSV_BOSS, GAME_MAP_BOSS);     //BOSSmapの当たり判定を読み込み、当たり判定の領域をつくる

	MY_MAP_READ_CSV_NUM(&ItemImage_1[GAME_MAP_SCENE_F1], GAME_ITEMIMAGE_CSV_1, GAME_MAP_F1_ITEM);		    //マップ１のアイテムを読み込み、当たり判定の領域をつくる

	if (MY_GAZOU_LOAD(&BackGround, 0, 0, GAME_TITLE_BACKIMAGE) == FALSE) {  //タイトル背景画像を読み込む
		MessageBox(NULL, GAME_TITLE_BACKIMAGE, "NotFound", MB_OK);
		return -1;
	}


	if (MY_GAZOU_LOAD(&BackGround_T, 150, 200, GAME_TITLEIMAGE) == FALSE) {  //タイトル画像を読み込む
		MessageBox(NULL, GAME_TITLEIMAGE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_GAZOU_LOAD(&BackGround_P, 0, 0, GAME_PROLOGUE) == FALSE) {  //プロローグ画像を読み込む
		MessageBox(NULL, GAME_PROLOGUE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_GAZOU_LOAD(&Boss, 0, 0, GAME_ENE_BOSS_IMAGE) == FALSE) {  //BOSSを読み込む
		MessageBox(NULL, GAME_ENE_BOSS_IMAGE, "NotFound", MB_OK);
		return -1;
	}


	if (MY_MAP_LOAD_BUNKATSU(&MapImage_U[GAME_MAP_SCENE_F1], GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX, GAME_MAP_1_YOKO_MAX, GAME_MAP_1_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_1) == FALSE) {  //下地のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_1, "NotFound", MB_OK);
		return -1;
	}


	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W[GAME_MAP_SCENE_F1], GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //壁系のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W[GAME_MAP_SCENE_F2], GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //壁系のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W[GAME_MAP_SCENE_F3], GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //壁系のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W[GAME_MAP_SCENE_F4], GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //壁系のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W[GAME_MAP_SCENE_BOSS], GAME_MAP_2_YOKO_MAX*GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //ボスエリアのマップチップを読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S[GAME_MAP_SCENE_F1], GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //階段のマップチップを読み込む
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S[GAME_MAP_SCENE_F2], GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //階段のマップチップを読み込む
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S[GAME_MAP_SCENE_F3], GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //階段のマップチップを読み込む
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S[GAME_MAP_SCENE_F4], GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //階段のマップチップを読み込む
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}


	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) {   //GAME_CHARAを読み込む
		MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_LOAD_BUNKATSU(&ItemImage_1[GAME_MAP_SCENE_F1], GAME_ITEM_BUN_YOKO_CNT * GAME_ITEM_BUN_TATE_CNT, GAME_ITEM_BUN_YOKO_CNT, GAME_ITEM_BUN_TATE_CNT, GAME_ITEM_YOKO_SIZE, GAME_ITEM_TATE_SIZE, ITEM) == FALSE) {  //アイテムのマップチップ画像を読み込む
		MessageBox(NULL, ITEM, "NotFound", MB_OK);
		return -1;
	}

	//音を読み込む
	MY_MUSIC_LOAD(&MUSIC_MY_TITLE, GAME_MUSIC_OP);
	MY_MUSIC_LOAD(&MUSIC_MY_BGM_1, GAME_MUSIC_MAP_BGM);
	MY_MUSIC_LOAD(&MUSIC_MY_BOSS, GAME_MUSIC_BOSS);


	IsActiveCheck = TRUE;

	while (TRUE)		//無限ループ
	{
		if (ProcessMessage() != 0)	//メッセージ処理の結果がエラーのとき、強制終了
		{
			break;
		}

		if (ClearDrawScreen() != 0) {	//画面を消去できなかった時、強制終了
			break;
		}

		MY_ALL_KEYDOWN_UPDATE();		//キーの状態を取得

		/*if (GameSceneNow != (int)GAME_SCENE_MOVE_SCENE)
		{
			SceneBefore = GameSceneNow;
		}*/

		switch (GameSceneNow)	//シーン選択
		{
		case(int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

			MY_GAME_TITLE();	//タイトル画面の処理

			break;	//タイトル画面の処理ここまで


		case(int)GAME_SCENE_PUOLOGUE:	//プロローグ画面の処理ここから

			MY_GAME_PROLOGUE();	//プロローグ画面の処理

			break;	//プロローグ画面の処理ここまで

		case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

			MY_GAME_PLAY();	//プレイ画面の処理

			break;	//プレイ画面の処理ここまで

		case (int)GAME_SCENE_END:	//エンド画面の処理ここから

			MY_GAME_END();	//エンド画面の処理

			break;	//エンド画面の処理ここまで

		default:

			break;
		}
		MY_FPS_UPDATE();		//FPSの処理(更新)

		MY_FPS_DRAW();			//FPSの処理(描画)

		ScreenFlip();			//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();			//FPSの処理(待つ)

	}

	DeleteGraph(BackGround.Handle);	//背景のハンドルを削除

	DeleteGraph(BackGround_T.Handle);	//タイトル画像のハンドルを削除

	DeleteGraph(BackGround_P.Handle);	//プロローグ画像のハンドルを削除

	for (int mapCnt = 0; mapCnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_U[GAME_MAP_SCENE_F1].Handle[mapCnt]);	//マップ1のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W[GAME_MAP_SCENE_F1].Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W[GAME_MAP_SCENE_F2].Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W[GAME_MAP_SCENE_F3].Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W[GAME_MAP_SCENE_F4].Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W[GAME_MAP_SCENE_BOSS].Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S[GAME_MAP_SCENE_F1].Handle[mapCnt]);	//マップ4のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S[GAME_MAP_SCENE_F2].Handle[mapCnt]);	//マップ4のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S[GAME_MAP_SCENE_F3].Handle[mapCnt]);	//マップ4のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S[GAME_MAP_SCENE_F4].Handle[mapCnt]);	//マップ4のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_ITEM_BUN_YOKO_CNT * GAME_ITEM_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(ItemImage_1[GAME_MAP_SCENE_F1].Handle[mapCnt]);	//	アイテムのハンドルを削除
	}

	DeleteMusicMem(MUSIC_MY_TITLE.Handle);	    //音のハンドルを削除
	DeleteMusicMem(MUSIC_MY_BGM_1.Handle);	    //音のハンドルを削除
	DeleteMusicMem(MUSIC_MY_BOSS.Handle);		//音のハンドルを削除

	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;
}


//###### FPS値を計測、更新する関数 #######
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)	 //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)	//60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を描画する関数 #########
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(0, 0, 0), "FPS:%.1f", CalcFps);
	return;
}

//####### FPS値を計測し、待つ関数 #########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;	//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//待つべき時間

	if (waitTime > 0)	//指定のFPS値よりも早い場合
	{
		Sleep(waitTime);	//待つ
	}
	return;

}

//####### キー入力状態を更新する関数 ######
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];	//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey);	//すべてのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//######## タイトル画面の関数 #############
VOID MY_GAME_TITLE(VOID)
{

	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_TITLE.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_TITLE.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_TITLE.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_PUOLOGUE;	//プロローグ画面に遷移
		}
	}


	DrawGraph(BackGround.X, BackGround.Y, BackGround.Handle, TRUE);		//タイトル背景画像描画

	DrawGraph(BackGround_T.X, BackGround_T.Y, BackGround_T.Handle, TRUE);		//タイトル画像描画

	DrawString(0, 0, "タイトル画面(エンターキーを押してください)", GetColor(0, 0, 0));
	return;
}


//####### プロローグ画面の関数 ############# 
VOID MY_GAME_PROLOGUE(VOID)
{

	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_TITLE.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_TITLE.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_TITLE.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	if (AllKeyState[KEY_INPUT_SPACE] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//プレイ画面に遷移
	}

	DrawGraph(BackGround.X, BackGround.Y, BackGround.Handle, TRUE);		//タイトル背景画像描画

	MY_PLAY_BACKIMAGE_DRAW(); //プロローグ画像をスクロール

	DrawString(0, 550, "SPACEでスキップ", GetColor(0, 0, 0));

	return;
}

//########### プレイ画面の関数 ############
VOID MY_GAME_PLAY(VOID)
{
	StopSoundMem(MUSIC_MY_TITLE.Handle);

	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_BGM_1.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BGM_1.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_BGM_1.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	MY_PLAY_PLAYER_OPERATION();

	MY_PLAY_MAP_DRAW(MapImage_U[0]);	//マップを描画

	MY_PLAY_MAP_DRAW(MapImage_W[MapNowPos]);	//マップを描画

	MY_PLAY_MAP_DRAW(MapImage_S[MapNowPos]);	//マップを描画

	MY_PLAY_MAP_DRAW_ATARI(&MapImage_A[MapNowPos]); //当たり判定の設定

	MY_PLAY_MAP_DRAW(ItemImage_1[MapNowPos]);	//アイテムを描画

	MY_PLAY_PLAYER_DRAW(Myplayer);  //プレイヤーを描画

	MY_PLAY_ENEMY_DRAW(oni);		//敵を描画

	MY_PLAY_PLAYER_GETITEM();     //アイテムの取得

	MY_MAP_SCENE_MOVE();  //マップを切り替える

	//持っているアイテムを表示
	if (AllKeyState[KEY_INPUT_I] == 1)
	{
		if (!itemdrowflag)
		{
			itemdrowflag = true;
		}
		else
		{
			itemdrowflag = false;
		}
	}
	if (itemdrowflag)
	{
		for (int i = 0; i < GAME_MAP_ITEM_KIND; i++)
		{
			if (Myplayer.item[i] != 0)
			{
				DrawFormatString(0, i * 20 + 50, GetColor(255, 255, 255), "%s", ItemName[i]);
			}
		}
	}







	DrawString(0, 0, "プレイ画面(Aキーを押してください)", GetColor(255, 255, 255));

	if (AllKeyState[KEY_INPUT_A] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_END;
	}
}

VOID MY_GAME_END(VOID)
{
	BOOL IsAtari = FALSE;  //当たり判定

	if (AllKeyState[KEY_INPUT_BACK] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;
	}

	DrawString(0, 0, "エンド画面(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}

//########## 初期化関数 ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;	//スクロール量を初期化
	ScrollCntTate = 0;

	//プレイヤーの画像の番号を設定
	int StartNum = (int)CHARA_KIND_5;
	int soeji = 0;
	PlayerImageNum[soeji++] = StartNum + 0;
	PlayerImageNum[soeji++] = StartNum + 1;
	PlayerImageNum[soeji++] = StartNum + 2;
	PlayerImageNum[soeji++] = StartNum + 12;
	PlayerImageNum[soeji++] = StartNum + 13;
	PlayerImageNum[soeji++] = StartNum + 14;
	PlayerImageNum[soeji++] = StartNum + 24;
	PlayerImageNum[soeji++] = StartNum + 25;
	PlayerImageNum[soeji++] = StartNum + 26;
	PlayerImageNum[soeji++] = StartNum + 36;
	PlayerImageNum[soeji++] = StartNum + 37;
	PlayerImageNum[soeji++] = StartNum + 38;

	//プレイヤーを初期化
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE*GAME_CHARA_START_X, GAME_MAP_TATE_SIZE*GAME_CHARA_START_Y, GAME_CHARA_SPEED) == FALSE) {
		MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK);
		return FALSE;
	}

	MY_PG_INIT(); //プロローグ画像位置初期化

	return TRUE;
}

//########## プレイヤーを初期化する関数 ##########
//引　数：CHARADATA 構造体：設定するCHARADATA構造体
//引　数：CHARAIMAGE構造体：設定するCHARAIMAGE構造体
//引　数：int* 　　 　　　：使用する画像の番号（配列の先頭アドレスを引数とする）
//引　数：int　	　　　　　：画像の初期位置X
//引　数：int　	　　　　　：画像の初期位置Y
//引　数：int　	　　　　　：移動スピード
//戻り値：BOOL：エラー時：FALSE
BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num+0)ば配列の先頭アドレス
	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];	//画像のハンドルを見る
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];      //最初の画像の横幅を設定する
	charadata->Height = charaimage.Height[*(num + 0)];	  //最初の画像の高さを設定する
	charadata->C_Width = charaimage.C_Width[*(num + 0)];  //最初の画像の横幅の中心を設定する
	charadata->C_Height = charaimage.C_Height[*(num + 0)]; //最初の画像の高さを設定する

	//マップ一つあたりと同じ大きさにする
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//前向きの最初の画像
	charadata->NowHandleCnt = 0;	//画像カウンタを初期化

	charadata->NowHandleCntMAX = 6; //画像カウンタMAXを初期化

	//*************  パラメータ設定  ********************************
	charadata->Speed = speed;

	charadata->MoveDistX = x;		//今の距離をマップの最初から動いた距離として設定する
	charadata->MoveDistY = y;

	charadata->CanMoveUp = TRUE;		//上に移動できる
	charadata->CanMoveDown = TRUE;		//下に移動できる
	charadata->CanMoveLeft = TRUE;		//左に移動できる
	charadata->CanMoveRight = TRUE;		//右に移動できる

	charadata->ScrollOK_X = FALSE;	//移動できない
	charadata->ScrollOK_Y = FALSE;

	charadata->atariX = 4;				//当たり判定のX位置を丁度良く設定
	charadata->atariY = 10;				//当たり判定のY位置を丁度良く設定
	charadata->atariWidth = 18;			//当たり判定の幅を丁度良く設定
	charadata->atariHeight = 24;		//当たり判定の高さを丁度良く設定



	//アイテムの初期化
	for (int kind = 0; kind < (int)GAME_MAP_ITEM_KIND; kind++)
	{
		charadata->item[kind] = 0;	//アイテムを何も持っていない
	}

	MY_SET_PLAYER_ATARI(charadata);	//プレイヤーの当たり判定の領域を設定

	return TRUE;
}

//########## 敵を初期化する関数 ##########
//引　数：ENEMY 構造体　  ：設定するENEMY構造体
//引　数：CHAR構造体　　　：設定するCHARA構造体
//引　数：int* 　　 　　　：最初の画像の番号（配列の先頭アドレスを引数とする）
//引　数：int　	　　　　　：最初の画像の向き
//引　数：int　	　　　　　：敵の最初の位置X
//引　数：int　	　　　　　：敵の最初の位置Y
//引　数：int　	　　　　　：プレイヤーがこのX位置まで来ると敵が表示される
//引　数：int　	　　　　　：プレイヤーがこのY位置まで来ると敵が表示される
//引　数：int　	　　　　　：質量
//引　数：int　	　　　　　：移動スピード
//引　数：BOOL　	　　　：飛行できるか
//戻り値：BOOL：エラー時：FALSE
BOOL MY_INIT_ENEMY(BOSS *e, CHARAIMAGE c, int *num, int Muki, int x, int y, int startX, int startY, int speed, int mass, BOOL fly)
{
	//*(num + 0)は配列の先頭アドレス

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		e->Handle[mot] = c.Handle[*(num + mot)];	//画像のハンドルを入れる
	}

	e->X = x;								//敵の最初の位置X
	e->Y = y;								//敵の最初の位置Y
	e->SetFirstX = x;						//敵の初期表示位置X
	e->SetFirstY = y;						//敵の初期表示位置Y
	e->viewStartPointX = startX;			//プレイヤーがこのX位置まで来ると敵が表示される
	e->viewStartPointY = startY;			//プレイヤーがこのY位置まで来ると敵が表示される

	e->Width = c.Width[*(num + 0)];			//最初の画像の横幅を設定する
	e->Height = c.Height[*(num + 0)];		//最初の画像の高さを設定する
	e->C_Width = c.C_Width[*(num + 0)];		//最初の画像の横幅の中心を設定する
	e->C_Height = c.C_Height[*(num + 0)];	//最初の画像の高さの中心を設定する

	//マップひとつあたりと同じ大きさにする
	e->Width = GAME_MAP_YOKO_SIZE;
	e->Height = GAME_MAP_TATE_SIZE;
	e->C_Width = GAME_MAP_YOKO_SIZE / 2;
	e->C_Height = GAME_MAP_TATE_SIZE / 2;

	e->NowHandleNum = Muki;	//最初の画像の向きの設定
	e->muki = Muki;			//敵の向き
	e->SetFirstmuki = Muki;	//敵の最初の向き

	e->NowHandleCnt = 0;	//画像カウンタ(画像が変わる時間)を初期化
	e->NowHandleCntMAX = 4;	//画像カウンタ(画像が変わる時間)MAXを初期化

	//***** 以下、パラメータ設定 **************************************************
	e->Speed = speed;				//移動速度を設定する

	e->CanMoveLeft = TRUE;			//左に移動できる
	e->CanMoveRight = TRUE;			//右に移動できる

	e->IsAlive = TRUE;				//敵はまだ生きている
	e->IsView = FALSE;				//敵は表示できない

	e->IsPassed = FALSE;			//通過していない

	e->atariX = 2;			//当たり判定のX位置を、イイ感じに設定	※画像表示と当たり判定のX位置が同じとは、限らない
	e->atariY = 14;			//当たり判定のY位置を、イイ感じに設定	※画像表示と当たり判定のY位置が同じとは、限らない
	e->atariWidth = 24;		//当たり判定の幅　を、イイ感じに設定	※画像表示と当たり判定の幅が同じとは、限らない
	e->atariHeight = 18;	//当たり判定の高さを、イイ感じに設定	※画像表示と当たり判定の高さが同じとは、限らない

	MY_SET_ENEMY_ATARI(e);	//敵の当たり判定の領域を設定する

	return TRUE;
}

//####### プロローグ画像位置初期化 ###########
VOID MY_PG_INIT(VOID)
{
	BackGround_P.X = -BackGround_P.Width;
	BackGround_P.Y = 0;
}

//####### プロローグをスクロールする関数 #########
VOID MY_PLAY_BACKIMAGE_DRAW(VOID)
{

	// 描画ブレンドモードをアルファブレンド（５０％）にする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);	//255がMAX値

	DrawBox(0, GAME_HEIGHT / 8 * 1, GAME_WIDTH, GAME_HEIGHT / 8 * 7, GetColor(255, 255, 255), TRUE);

	//描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(BackGround_P.X, BackGround_P.Y, BackGround_P.Handle, TRUE);	//プロローグ画像描画

	BackGround_P.X += ScrollDistPlusYoko;	//背景の位置をずらす



	return;
}

//########## キャラクターとマップの当たり判定をする関数(当たった場所を知る) ##########
//引　数　：RECT	：当たり判定をする領域(キャラクター)
//引　数　：RECT	：当たり判定をする領域(マップ)
//引　数　：int 	：あたった場所(X位置)
//引　数　：int 	：あたった場所(Y位置)
//戻り値　：当たっている：TRUE / 当たっていない / FALSE
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			//キャラの当たっている場所を取得
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariYのアドレスが指す先の場所に、当たったモノの縦の位置を入れる
				*atariX = yoko;	//atariXのアドレスが指す先の場所に、当たったモノの縦の位置を入れる

				return TRUE;
			}
		}
	}
	return FALSE;	//当たってない
}

//######### 領域の当たり判定をする関数 #########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left<b.right&&
		a.top<b.bottom&&
		a.right>b.left&&
		a.bottom>b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;	//当たっていない
}

//########## プレイヤーの当たり判定の領域を設定する関数 ###########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//当たり判定の領域を設定
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;								//現在のX位置＋当たり判定のXの位置
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;								//現在のY位置＋当たり判定のYの位置
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//現在のX位置＋当たり判定のXの位置＋当たり判定の幅
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//現在のY位置＋当たり判定のYの位置＋当たり判定の高さ

	return;
}

//########## 敵の当たり判定の領域を設定する関数 ##########
VOID MY_SET_ENEMY_ATARI(BOSS *e)
{
	//当たり判定の領域の設定
	e->atariRect.left = e->X + e->atariX - ScrollCntYoko;						//現在のX位置 ＋ 当たり判定のX位置	- スクロールした分を戻す
	e->atariRect.top = e->Y + e->atariY;										//現在のY位置 ＋ 当たり判定のY位置
	e->atariRect.right = e->X + e->atariX + e->atariWidth - ScrollCntYoko - 1;	//現在のX位置 ＋ 当たり判定のX位置 ＋ 当たり判定の幅 - スクロールした分を戻す
	e->atariRect.bottom = e->Y + e->atariY + e->atariHeight - 1;				//現在のY位置 ＋ 当たり判定のY位置 ＋ 当たり判定の高さ

	return;
}

//########## プレイヤーを操作する関数 ###########
VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0;  //当たっているマップの場所
	int retAtariY = 0;

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//キーを押しているか判断

	return;
}

//########### プレイヤーをキー操作する関数 #########

BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;	//キーが押されたか

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーがおされていたとき
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveLeft = TRUE;	//左方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定領域を設定
		Myplayer.atariRect.left -= 4;	//少し当たり判定の領域を左にずらす
		Myplayer.atariRect.right -= 4;	//少し当たり判定の領域を左にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_A[MapNowPos].rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveLeft = FALSE;	//	左に行けない
		}


		if (Myplayer.CanMoveLeft == TRUE)	//左に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//スクロールできないとき
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//プレイヤーを左に移動
				}
			}
			else   //スクロールできるとき
			{
				if (ScrollCntYoko > 0)  //マップ外へスクロールしない
				{
					ScrollCntYoko -= Myplayer.Speed;	//画面を左にスクロール	
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;
			}

		}
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていたら
	{
		IsKeyDown = TRUE;

		Myplayer.CanMoveRight = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす
		Myplayer.atariRect.right += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_A[MapNowPos].rect_NG, x, y) == TRUE)	//右に行けないものと当たったとき
		{
			Myplayer.CanMoveRight = FALSE;	//右に行けない
		}


		if (Myplayer.CanMoveRight == TRUE)
		{
			if (Myplayer.ScrollOK_X == FALSE)
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE*GAME_MAP_YOKO)
				{
					ScrollCntYoko += Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE*GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;
			}
		}
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)		//上矢印キーが押されているとき
	{
		IsKeyDown = TRUE;

		Myplayer.CanMoveUp = TRUE;	//上方向にまだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.top -= 4;
		Myplayer.atariRect.bottom -= 4;

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_A[MapNowPos].rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveUp = FALSE;	//上に行けない
		}


		if (Myplayer.CanMoveUp == TRUE)		//上に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntTate > 0)
				{
					ScrollCntTate -= Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;
			}
		}
	}


	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
	{
		IsKeyDown = TRUE;

		Myplayer.CanMoveDown = TRUE;

		Myplayer.CanMoveDown = TRUE;	//上方向にまだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);
		Myplayer.atariRect.top += 4;
		Myplayer.atariRect.bottom += 4;

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_A[MapNowPos].rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveDown = FALSE;	//上に行けない
		}


		if (Myplayer.CanMoveDown == TRUE)	//下に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE*GAME_MAP_TATE)
				{
					ScrollCntTate += Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE*(GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;
			}
		}
	}

	//マップの左側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > 0 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//プレイヤーの動いた距離が一定以上であれば
	{
		Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップの真ん中あたりにいるときは、マップを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))
	{
		Myplayer.ScrollOK_X = TRUE;					//マップを動かす
	}

	//マップの右側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE*(GAME_MAP_YOKO - 15) &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
	{
		Myplayer.ScrollOK_X = FALSE;				//マップを止めて、プレイヤーを動かす
	}

	//マップの上側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > 0 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)
	{
		Myplayer.ScrollOK_Y = FALSE;				//マップを止めて、プレイヤーを動かす
	}

	//マップの真ん中あたりにいるときは、マップを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//プレイヤーの動いた距離が一定以上であれば(開始地点)
	{
		Myplayer.ScrollOK_Y = TRUE;				//マップを動かす
	}

	//マップの下側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE*(GAME_MAP_TATE - 9) &&	//プレイヤーの動いた距離が一定以上であれば(終了地点)
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)
	{
		Myplayer.ScrollOK_Y = FALSE;	//マップを止めて、プレイヤーを動かす
	}

	return IsKeyDown;
}

//########## 画像を読み込む設定をする関数 ##########
//引　数：画像構造体　：設定する画像構造体の変数
//引　数：int　：画像の横の位置
//引　数：int　：画像の縦の位置
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);						//ファイルパスをコピー
	g->Handle = LoadGraph(g->FilePath);					//画像をメモリに読み込み、ハンドルを取得

	if (g->Handle == -1) { return FALSE; }				//画像読み込みエラー

	GetGraphSize(g->Handle, &g->Width, &g->Height);		//画像サイズを取得
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;							//画像の横サイズの中心を取得
	g->C_Height = g->Height / 2;						//画像の縦サイズの中心を取得

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_A_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}


//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_3_YOKO_MAX * GAME_MAP_3_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## CHARAを分割して読み込む設定をする関数 ##########
//引　数：CHARAIMAGE構造体　：設定するCHARAIMAGE構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	wsprintf(c->FilePath, path);  //ファイルのパスをコピー


	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);	//画像をメモリに分割して読み込み、ハンドルを取得

	if (retLoad == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			c->Handle[cnt],		//ハンドルから、画像の幅と高さを取得し
			&c->Width[cnt],		//MAP構造体の幅に、画像の幅を設定する
			&c->Height[cnt]);	//MAP構造体の高さに、画僧の高さを設定する

		c->C_Width[cnt] = c->Width[cnt] / 2;	//画像の横サイズの中心位置を取得
		c->C_Height[cnt] = c->Width[cnt] / 2;	//画像の縦サイズの中心位置を取得
	}

	return TRUE;
}

//########## マップ(F1)判定の種類を設定する ########
BOOL MY_MAP_READ_CSV_KIND_SET(MAP *mapdata)

{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 4;
	mapdata->mapOKKind[Soeji++] = 5;	//階段の中心

	//通行できる種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}

	//通行できない
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 0;
	//通行できない種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = 0;
	}

	return TRUE;
}

//########## ゲームマップのCSVを読み込む関数 ##########
BOOL MY_MAP_READ_CSV_NUM(MAP *mapdata, const char *path, const char *mapname)
{

	FILE  *fp;

	if ((fp = fopen(path, "r")) == NULL)	//ファイルを読み込みモード(r)で開く
	{
		return FALSE;
	}//異常終了	

	 //ここから正常に読み込めたときの処理****************************************

	int result = 0;			//ファイルの最後かチェック
	int LoopCnt = 0;		//ループカウンタ

	//ファイルから数値を一つ読み込み(%d,)、配列に格納する
	while (fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]) != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		mapdata->mapdate_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO];  //値をコピー

		LoopCnt++;
	}
	fclose(fp);	//ファイルを閉じる

	wsprintf(mapdata->name, mapname); //マップの名称をコピー

	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			mapdata->rect_NG[tate][yoko].left = 0;
			mapdata->rect_NG[tate][yoko].top = 0;
			mapdata->rect_NG[tate][yoko].right = 0;
			mapdata->rect_NG[tate][yoko].bottom = 0;

			mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];

			mapdata->rect_OK[tate][yoko].left = 0;
			mapdata->rect_OK[tate][yoko].top = 0;
			mapdata->rect_OK[tate][yoko].right = 0;
			mapdata->rect_OK[tate][yoko].bottom = 0;

			mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];


		}
	}

	//マップを当たり判定の領域に変換
	int cnt;
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < GAME_MAP_NG_KIND; cnt++)	//通行できないマップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapNGKind[cnt])
				{
					mapdata->rect_NG[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_NG[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_NG[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_NG[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	//初期位置を設定する
				}
			}


			for (cnt = 0; cnt < GAME_MAP_OK_KIND; cnt++)		//通行できるマップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapOKKind[cnt])
				{
					mapdata->rect_OK[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_OK[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_OK[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_OK[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];
				}
			}

			for (cnt = 0; cnt < GAME_MAP_ITEM_KIND; cnt++)		//通行できるマップ
			{
				if (mapdata->data[tate][yoko] == MapItemKind[cnt])
				{
					mapdata->rectMap_Item[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rectMap_Item[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rectMap_Item[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rectMap_Item[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rectMap_Item_First[tate][yoko] = mapdata->rectMap_Item[tate][yoko];
				}
			}

			for (cnt = 0; cnt < GAME_MAP_KAIDAN; cnt++)		//通行できるマップ
			{
				if (mapdata->data[tate][yoko] == MapKaidanKind[cnt])
				{
					mapdata->rectMap_Kaidan[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rectMap_Kaidan[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rectMap_Kaidan[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rectMap_Kaidan[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rectMap_Kaidan_First[tate][yoko] = mapdata->rectMap_Kaidan[tate][yoko];
				}
			}
		}
	}

	return TRUE;
}


//########## マップを表示する関数 ##########
VOID MY_PLAY_MAP_DRAW(MAP MapImage)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&	//画面に写っているならばならば
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				) //画面に写っているならば
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,			//位置からスクロール量を引く
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapImage.data[tate][yoko]], TRUE);	//マップをスクロールしながら描画

			}
		}
	}
}

//########## マップの当たり判定を描画する関数 ##########
VOID MY_PLAY_MAP_DRAW_ATARI(MAP *map_naka)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//画面に写っているならば


				map_naka->rect_OK[tate][yoko].left = map_naka->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].right = map_naka->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].top = map_naka->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_OK[tate][yoko].bottom = map_naka->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rect_NG[tate][yoko].left = map_naka->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].right = map_naka->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].top = map_naka->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_NG[tate][yoko].bottom = map_naka->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rectMap_Item[tate][yoko].left = map_naka->rectMap_Item_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rectMap_Item[tate][yoko].right = map_naka->rectMap_Item_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rectMap_Item[tate][yoko].top = map_naka->rectMap_Item_First[tate][yoko].top - ScrollCntTate;
			map_naka->rectMap_Item[tate][yoko].bottom = map_naka->rectMap_Item_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rectMap_Kaidan[tate][yoko].left = map_naka->rectMap_Kaidan_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rectMap_Kaidan[tate][yoko].right = map_naka->rectMap_Kaidan_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rectMap_Kaidan[tate][yoko].top = map_naka->rectMap_Kaidan_First[tate][yoko].top - ScrollCntTate;
			map_naka->rectMap_Kaidan[tate][yoko].bottom = map_naka->rectMap_Kaidan_First[tate][yoko].bottom - ScrollCntTate;


		}
	}
}

//######### プレイヤーを表示する関数 ###########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//プレイヤーを描画	
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);


	if (AllKeyState[KEY_INPUT_LEFT] != 0)    //左矢印キーが押されていた時
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
			{
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 9; //一番最初の左向きの画像
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)  //右矢印キーが押されているとき
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
			{
				Myplayer.NowHandleNum++;	//次の右向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 3; //一番最初の右向きの画像
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されているとき
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
			{
				Myplayer.NowHandleNum++;	//次の上向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 0; //一番最初の上向きの画像
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
			{
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 6; //一番最初の左向きの画像
			}
		}
	}
	return;
}

//########## 敵を表示する(詳細)関数 ##########
//引　数　：BOSS * ：敵の先頭アドレス(ポインタ)
//引　数　：int		：敵の数
//戻り値　：なし
VOID MY_PLAY_ENEMY_DRAW_DETAIL(BOSS *boss)
{
		
			//プレイヤーを描画	
			DrawGraph(
				boss->X,
				boss->Y,
				boss->Handle[boss->NowHandleNum], TRUE);

				//画像をアニメーションさせる
				switch (boss -> muki)
				{
				case GAME_BOSS_FIRST_MUKI_U:

					if (boss ->NowHandleNum >= GAME_BOSS_FIRST_MUKI_U
						&& boss->NowHandleNum < GAME_BOSS_FIRST_MUKI_U + 2)
					{
						boss->NowHandleNum++;	//次の画像
					}
					else
					{
						boss->NowHandleNum = GAME_BOSS_FIRST_MUKI_U;	//最初の画像
					}

					break;

				case GAME_BOSS_FIRST_MUKI_R:

					if (boss->NowHandleNum >= GAME_BOSS_FIRST_MUKI_R
						&& boss->NowHandleNum < GAME_BOSS_FIRST_MUKI_R + 2)
					{
						boss->NowHandleNum++;	//次の画像
					}
					else
					{
						boss->NowHandleNum = GAME_BOSS_FIRST_MUKI_R;	//最初の画像
					}

					break;

				case GAME_BOSS_FIRST_MUKI_D:

					if (boss->NowHandleNum >= GAME_BOSS_FIRST_MUKI_D
						&& boss->NowHandleNum < GAME_BOSS_FIRST_MUKI_D + 2)
					{
						boss->NowHandleNum++;	//次の画像
					}
					else
					{
						boss->NowHandleNum = GAME_BOSS_FIRST_MUKI_D;
					}

					break;

				case GAME_BOSS_FIRST_MUKI_L:

					if (boss->NowHandleNum >= GAME_BOSS_FIRST_MUKI_L
						&& boss->NowHandleNum < GAME_BOSS_FIRST_MUKI_L + 2)
					{
						boss->NowHandleNum++;	//次の画像
					}
					else
					{
						boss->NowHandleNum = GAME_BOSS_FIRST_MUKI_L;
					}

					break;

				default:
					break;
				}

	return;
}

//########## 敵を表示する関数 ##########
VOID MY_PLAY_ENEMY_DRAW(BOSS boss)
{
	MY_PLAY_ENEMY_DRAW_DETAIL(&boss);

	return;
}

//########## 敵を操作する(詳細)関数 ##########
//引　数　：BOSS * ：敵の先頭アドレス(ポインタ)
//引　数　：int		：敵の数
//戻り値　：なし
VOID MY_PLAY_ENEMY_OPERATION_DETAIL(BOSS *boss)
{

	
		//if ( boss ->IsAlive == FALSE)
		//{
		//	continue;	//敵が生きてなければ、次の敵の処理をする
		//}

		if (Myplayer.MoveDistX == boss->viewStartPointX && Myplayer.MoveDistY==boss->viewStartPointY)	//プレイヤーの動いた距離を使って、敵を表示する
		{
			if (boss->IsView == FALSE)
			{
				boss->X = boss->SetFirstX;		//X位置を設定し直す
				boss->Y = boss->SetFirstY;		//Y位置を設定し直す
				boss->muki = boss->SetFirstmuki;	//向きを設定し直す
				

				boss->IsView = TRUE;				//敵を表示する
			}
		}

		if (boss->IsView == TRUE)	//敵が表示できるときは・・・
		{
			switch (boss->muki)
			{
			case GAME_BOSS_FIRST_MUKI_U:

				boss->Y -= boss->Speed;
				break;

			case GAME_BOSS_FIRST_MUKI_R:

				if (boss->CanMoveRight == TRUE)	//右に動けるときは・・・
				{
					
					boss->X += boss->Speed;
				}
				else
				{
					boss->muki = GAME_BOSS_FIRST_MUKI_L;	//向きを反転させる
				}
				break;

			case GAME_BOSS_FIRST_MUKI_D:

				boss->Y += boss->Speed;
				break;

			case GAME_BOSS_FIRST_MUKI_L:

				if (boss->CanMoveLeft == TRUE)	//左に動けるときは・・・
				{
						boss->X -= boss->Speed;
				}
				else
				{
					boss->muki = GAME_BOSS_FIRST_MUKI_R;	//向きを反転させる
				}
				break;

			default:
				break;
			}

			MY_PLAY_ENEMY_MAP_COLLISION(boss);	//敵とマップとの接触関数

		}

	return;
}

//########## 敵を操作する関数 ##########
VOID MY_PLAY_ENEMY_OPERATION(VOID)
{
	MY_PLAY_ENEMY_OPERATION_DETAIL(&boss[0]);	//bossの先頭アドレスを入れる

	return;
}

//########## 敵とマップとの接触関数 ##########
VOID MY_PLAY_ENEMY_MAP_COLLISION(BOSS *e)
{
	MY_SET_ENEMY_ATARI(e);

	//左方向に、まだ動ける
	(e)->CanMoveLeft = TRUE;

	MY_SET_ENEMY_ATARI(e);			//敵の当たり判定の領域を設定
	e->atariRect.left -= 4;			//少し、敵の当たり判定の領域を左にずらす
	e->atariRect.right -= 4;		//少し、敵の当たり判定の領域を左にずらす

	static int x = 0, y = 0;

	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(e->atariRect, MapImage_A[MapNowPos].rect_NG, &x, &y) == TRUE)	//左に行けないモノと当たったとき
	{
		e->CanMoveLeft = FALSE;	//左に行けない
	}

	//右方向に、まだ動ける
	(e)->CanMoveRight = TRUE;

	MY_SET_ENEMY_ATARI(e);			//敵の当たり判定の領域を設定
	e->atariRect.left += 4;			//少し、敵の当たり判定の領域を右にずらす
	e->atariRect.right += 4;		//少し、敵の当たり判定の領域を右にずらす

	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(e->atariRect, MapImage_A[MapNowPos].rect_NG, &x, &y) == TRUE)	//右に行けないモノと当たったとき
	{
		e->CanMoveRight = FALSE;	//右に行けない
	}

	//if ((e)->IsFlying == TRUE)
	//{
	//	return;	//飛行できる敵はここで処理終了(ジャンプをしないため)
	//}

	//if ((e)->IsJumpNow == TRUE)		//ジャンプしているとき
	//{
	//	(e)->JumpNowTime = GetNowCount();	//現在の時刻を取得
	//	double KeikaTime = ((e)->JumpNowTime - (e)->JumpStartTime) / 1000.0;	//ジャンプをしたときからの経過時間を取得

	//	double ConstAcceleMoveCalc =
	//		(
	//		(
	//			sqrt(2.0 * (e)->Weight * (e)->JumpValue)
	//			* KeikaTime
	//			- 0.5	// 1/2 
	//			* (e)->Weight * pow(KeikaTime, 2)
	//			)
	//			);

	//	//敵の位置を変更
	//	(e)->Y = (e)->JumpPrevY - ConstAcceleMoveCalc;
	//}

	//if ((e)->IsJumpNow == TRUE && (e)->IsJumpTop == TRUE)	//頂点に到達したら、あとは落ちるのみ
	//{
	//	MY_SET_ENEMY_ATARI(e);	//敵の当たり判定の領域を設定
	//	if (MY_CHECK_RECT_ATARI_CHARA_MAP((e)->atariRect, rectMap_DownNG) == TRUE)	//下に行けないモノと当たったとき
	//	{
	//		if ((e)->Y >= 0 && (e)->Y <= GAME_HEIGHT)	//敵が画面内にいるとき
	//		{
	//			int PullUpPlayer = (e)->Y / GAME_MAP_TATE_SIZE;	//引き上げるべき数値まで引き上げる
	//			while ((e)->Y > PullUpPlayer * GAME_MAP_TATE_SIZE)
	//			{
	//				(e)->Y--;
	//			}
	//		}

	//		//ジャンプ終了
	//		(e)->IsJumpNow = FALSE;
	//		(e)->IsJumpTop = FALSE;
	//	}
	//}

	//if ((e)->IsJumpNow == FALSE)
	//{
	//	MY_SET_ENEMY_ATARI(e);			//敵の当たり判定の領域を設定
	//	(e)->atariRect.top += 4;		//少し、敵の当たり判定の領域を下にずらす
	//	(e)->atariRect.bottom += 4;		//少し、敵の当たり判定の領域を下にずらす

	//	if (MY_CHECK_RECT_ATARI_CHARA_MAP((e)->atariRect, rectMap_DownNG) == FALSE)	//下に行けないモノと当たっていないとき
	//	{
	//		MY_PLAY_ENEMY_JUMP_PREV(e);	//ジャンプの準備
	//		(e)->JumpValue = 0;			//ジャンプ量を0にして、落ちるのみにする
	//		(e)->IsJumpNow = TRUE;		//ジャンプ済みにする
	//		(e)->IsJumpTop = TRUE;		//頂点まで行って、あとは落ちるのみ
	//	}
	//}

	return;
}

//######### アイテムを取得する関数 ###############
VOID MY_PLAY_PLAYER_GETITEM(VOID)
{
	MY_SET_PLAYER_ATARI(&Myplayer);

	int atariX;
	int atariY;


	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, ItemImage_1[GAME_MAP_SCENE_F1].rectMap_Item, &atariX, &atariY) == TRUE)
	{
		Myplayer.item[ItemImage_1[GAME_MAP_SCENE_F1].data[atariY][atariX]] ++;

		ItemImage_1[GAME_MAP_SCENE_F1].data[atariY][atariX] = (int)M_B;

		ItemImage_1[GAME_MAP_SCENE_F1].rectMap_Item[atariY][atariX].left = 0;
		ItemImage_1[GAME_MAP_SCENE_F1].rectMap_Item[atariY][atariX].top = 0;
		ItemImage_1[GAME_MAP_SCENE_F1].rectMap_Item[atariY][atariX].right = 0;
		ItemImage_1[GAME_MAP_SCENE_F1].rectMap_Item[atariY][atariX].bottom = 0;
	}
	return;
}

//############# マップをを切り替える関数 ###############
VOID MY_MAP_SCENE_MOVE(VOID)
{
	MY_SET_PLAYER_ATARI(&Myplayer);

	int atariX;
	int atariY;

	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_A[MapNowPos].rectMap_Kaidan, &atariX, &atariY))
	{
		MapNowPos++;

		switch (MapNowPos)
		{
		case GAME_MAP_SCENE_F1:


			break;
		case GAME_MAP_SCENE_F2:

			break;

		case GAME_MAP_SCENE_F3:

			break;

		case GAME_MAP_SCENE_F4:

			break;
		case GAME_MAP_SCENE_BOSS:
			Myplayer.X = 400;
			Myplayer.Y = 500;
			ScrollCntTate = 400;
			ScrollCntYoko = 400;

			StopSoundMem(MUSIC_MY_BGM_1.Handle);


			//MY_PLAY_ENEMY_DRAW();		//敵を描画

			//BGMが流れていないとき
			if (CheckSoundMem(MUSIC_MY_BOSS.Handle) == 0)
			{
				WaitTimer(5000);  //5秒待つ
				ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BOSS.Handle);	//BGMの音量を50％にする
				PlaySoundMem(MUSIC_MY_BOSS.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
			}

			break;
		default:
			break;
		}

	}

	return;
}

//########## 音を読み込む設定をする関数 ##########
//引　数：音構造体　	:設定する音構造体の変数
//引　数：const char *	:読み込む画像のファイルパス
//戻り値：BOOL			:TRUE:正常 / FALSE:異常
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//音を読み込む
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1) { return FALSE; }

	return TRUE;
}

//######### ウィンドウプロシージャ関数 ############
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT mgs, WPARAM wp, LPARAM lp)
{
	switch (mgs)
	{

	case WM_CREATE:	//ウィンドウの生成＆初期化

		IsWM_CREATE = TRUE;	//WM_CREATE正常終了

		return 0;

	case WM_CLOSE:	//閉じるボタンを押したとき

		MessageBox(hwnd, TEXT("ゲームを終了します。"), TEXT("終了メッセージ"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//マウスの右ボタンを押したとき

		SendMessage(hwnd, WM_CLOSE, 0, 0);	//WM_CLOSEメッセージキューに追加
		break;

	case WM_LBUTTONDOWN:

		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);		//WM_NCLBUTTONDOWN(タイトルバーでマウスの左ボタンを押した)
		break;

	case WM_ACTIVATE:

		if (IsActiveCheck == TRUE)	//画面のアクティブチェックの有効化
		{
			switch (wp)
			{
			case WA_INACTIVE:	//非アクティブ化

				StopActiveStartTime = GetNowCount();

				break;

			case WA_ACTIVE:	//キーボードなどでアクティブ化

				StopActiveStartTime = GetNowCount();

				break;

			case WA_CLICKACTIVE:

				StopActiveStopTime = GetNowCount();

				break;

			default:

				break;
			}
		}
		return 0;

	case WM_DESTROY:	//ウィンドウが破棄されたとき

		PostQuitMessage(0);	//メッセージキューに WM_QUIT を送る
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, mgs, wp, lp);
}